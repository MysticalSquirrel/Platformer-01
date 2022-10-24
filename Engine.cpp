#include "Engine.hpp"

void App::InitLibraries()
{
    // INIT LIBRARIES AND MAKE SURE THEY HAVE AN ERROR CATCHER.

    // SDL:

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        std::cout << SDL_GetError() << std::endl;
    }
    if (!(App::Window = SDL_CreateWindow("Platformer Game 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, App::Width, App::Height, SDL_WINDOW_SHOWN)))
    {
        std::cout << SDL_GetError() << std::endl;
    }
    if (!(App::Renderer = SDL_CreateRenderer(App::Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
    {
        std::cout << SDL_GetError() << std::endl;
    }

    // SDL_IMAGE:

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << IMG_GetError() << std::endl;
    }

    // SDL_MIXER:

    if (!(Mix_Init(AUDIO_S16SYS)))
    {
        std::cout << Mix_GetError() << std::endl;
    }
}

void App::Init()
{
    App::InitLibraries();
    App::FrameCount = 0;
    App::FpsTimer.Start();

    Mix_OpenAudio(48000, AUDIO_F32SYS, 2, 4096);

    App::LoadGraphics();
}

void App::ClearLibraries()
{
    // CLOSE LIBRARIES IN THE ORDER THEY WERE OPENED IN.

    // SLD_MIXER:

    Mix_Quit();

    // SDL_IMAGE:

    IMG_Quit();

    // SDL:

    SDL_DestroyRenderer(App::Renderer);
    SDL_DestroyWindow(App::Window);
    SDL_Quit();
}

void App::Quit()
{
    //CLOSE STUFF HERE THAT IS NOT RELATED TO THE LIBRARIES. (FUNCTIONNS, VARIABLES, ETC...)
    // GRAPHICS
    SDL_DestroyTexture(SpritesheetTexture);
    
    // AUDIO
    Mix_FreeMusic(App::CurrentMusic);
    Mix_FreeChunk(App::CurrentSound);

    Mix_CloseAudio();
    SDL_QuitSubSystem(SDL_INIT_AUDIO);

    // LIBRARIES
    ClearLibraries();
}

void App::InputManager()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                App::QuitGame = true;
                break;
            case SDLK_1:
                for (int y = 0; y < SpritesPerSheet.y; y++)
                {
                    for (int x = 0; x < SpritesPerSheet.y; x++)
                    {
                        SDL_Point TempPosition{x,y};
                        App::RenderTexture(App::SpritesheetTexture, App::Renderer, &ClipRects[x+(y*SpritesSize.x)], TempPosition);
                    }
                }
                break;
            case SDLK_2:
                App::PlaySound(App::LoadSoundFile(SoundFiles.PDeath), 0, 0, true);
                break;
            case SDLK_3:
                App::PlayMusic(App::LoadMusicFile(MusicFiles.Test), 0, 0, false);
                
                break;
            }
            break;
        case SDL_QUIT:
            App::QuitGame = true;
            break;
        }
    }
}

Mix_Chunk* App::LoadSoundFile(std::string fileName)
{
    return (Mix_Chunk*)Mix_LoadWAV((ResourcePaths.Sounds + fileName).c_str());
}

Mix_Music* App::LoadMusicFile(std::string fileName)
{
    return (Mix_Music*)Mix_LoadMUS((ResourcePaths.Musics + fileName).c_str());
}

float App::GlobalMusicVolume(bool IsMusic)
{
    if (IsMusic == true)
    {
        return (App::MusicVolume * (App::GlobalVolume / 100));
    }
    else
    {
        return (App::SoundsVolume * (App::GlobalVolume / 100));
    }
}

void App::PlayMusic(Mix_Music* Music, int Volume, float TimePosition, bool ForcePlay)
{
    if (App::CurrentMusic != NULL)
    {
        Mix_FreeMusic(App::CurrentMusic);
        App::MusicIsPlaying = false;
    }
    if (App::MusicIsPlaying == false || ForcePlay == true)
    {
        //Mix_PauseMusic();
        //Mix_FreeMusic(App::CurrentMusic);
        App::CurrentMusic = Music;
        Mix_VolumeMusic((int)GlobalMusicVolume(true));
        if (CurrentMusic != NULL)
        {
            Mix_PlayMusic(App::CurrentMusic, -1);
        }
        App::MusicIsPlaying = true;
    }
    //std::cout << Music << std::endl;
    //std::cout << MusicIsPlaying << " " << ForcePlay << std::endl;
}

void App::PlaySound(Mix_Chunk* Sound, int Volume, float TimePosition, bool ForcePlay)
{
    if (App::CurrentSound != NULL)
    {
        Mix_FreeChunk(App::CurrentSound);
        SoundIsPlaying = false;
    }
    if (Sound != NULL)
    {
        if (App::SoundIsPlaying == false || ForcePlay == true)
        {
            //Mix_Pause(0);
            //Mix_FreeChunk(App::CurrentSound);
            App::CurrentSound = Sound;
            Mix_VolumeChunk(App::CurrentSound,(int)GlobalMusicVolume(false));
            if (CurrentSound != NULL)
            {
                Mix_PlayChannel(0, App::CurrentSound, 0);
            }
            App::SoundIsPlaying = true;
        }
    }
    
}

void App::LoadSpritesheetTexture()
{
    App::SpritesheetSurface = (SDL_Surface *)App::LoadGraphicFile("Spritesheet.png");
    App::SpritesheetTexture = SDL_CreateTextureFromSurface(App::Renderer, App::SpritesheetSurface);
    SDL_FreeSurface(App::SpritesheetSurface);
    
    App::SpritesheetSize.x = App::SpritesSize.x * App::SpritesPerSheet.x;
    App::SpritesheetSize.y = App::SpritesSize.y * App::SpritesPerSheet.y;
}

void App::LoadClips()
{
    for (int y = 0; y < App::SpritesPerSheet.y; y++)
    {
        for (int x = 0; x < App::SpritesPerSheet.x; x++)
        {
            SDL_Rect temp;
            if (&temp != NULL)
            {
                temp.x = x * SpritesSize.x;
                temp.y = y * SpritesSize.y;
                temp.w = App::SpritesSize.x;
                temp.h = App::SpritesSize.y;
                App::ClipRects[x + (y * App::SpritesSize.x)].x = temp.x;
                App::ClipRects[x + (y * App::SpritesSize.x)].y = temp.y;
                App::ClipRects[x + (y * App::SpritesSize.x)].w = temp.w;
                App::ClipRects[x + (y * App::SpritesSize.x)].h = temp.h;
            }
            //std::cout << "x:" << ClipRects[x, y]->x << ", y:" << ClipRects[x, y]->y << ", w:" << ClipRects[x, y]->w << ", h:" << ClipRects[x, y]->h << std::endl;
        }
    }
    //std::cout << ClipRects[0]->x + " " << ClipRects[0]->y + " " << ClipRects[0]->w + " " << ClipRects[0]->h<< std::endl;
}

bool App::LoadMap(Map map)
{
    bool result = false;


    return result;
}

SDL_Surface* App::LoadGraphicFile(std::string fileName)
{
    return IMG_Load((ResourcePaths.Graphics + fileName).c_str());
}

void App::LoadGraphics()
{
    App::LoadSpritesheetTexture();
    App::LoadClips();
}

void App::RenderTexture(SDL_Texture* texture, SDL_Renderer* Renderer, SDL_Rect* Clip, SDL_Point Position)
{
    SDL_Rect destination{0};
    destination.x = Position.x * SpritesSize.x;
    destination.y = Position.y * SpritesSize.y;
    if (Clip != nullptr)
    {
        destination.w = Clip->w;
        destination.h = Clip->h;
    }
    else
    {
        destination.w = SpritesSize.x;
        destination.h = SpritesSize.y;
    }
    SDL_RenderCopy(Renderer, texture, Clip, &destination);
}

void App::UpdateRender()
{
    SDL_SetRenderDrawColor(App::Renderer, 0, 0, 0, 255);
    App::InputManager();
    SDL_RenderPresent(App::Renderer);
}
