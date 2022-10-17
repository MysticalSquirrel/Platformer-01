#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

#include "Timer.hpp"

const struct ResourcePaths
{
    std::string Graphics = "Resources\\Graphics\\";
    std::string Audio = "Resources\\Audio\\";
    std::string Musics = "Resources\\Audio\\Musics\\";
    std::string Sounds = "Resources\\Audio\\Sounds\\";
} ResourcePaths;

const struct MusicFiles
{
    std::string Test = "test.ogg";
    std::string MainTheme = "test.ogg";
    std::string Level1 = "test.ogg";
    std::string Level2 = "test.ogg";
    std::string Level3 = "test.ogg";
    std::string Level4 = "test.ogg";
    std::string Level5 = "test.ogg";
    std::string Level6 = "test.ogg";
    std::string Level7 = "test.ogg";
    std::string Level8 = "test.ogg";
    std::string Level9 = "test.ogg";
    std::string Bonus = "test.ogg";
    std::string Credits = "test.ogg";
    std::string Victory = "test.ogg";
    std::string GameOver = "test.ogg";
    std::string Evolving = "test.ogg";
} MusicFiles;

const struct SoundFiles
{
    std::string Test = "test.ogg";
    std::string MMGun = "test.ogg";
    std::string MMFlame = "test.ogg";
    std::string MMPulse = "test.ogg";
    std::string MMDisc = "test.ogg";
    std::string MMMGun = "test.ogg";
    std::string ZGun = "test.ogg";
    std::string ZSword = "test.ogg";
    std::string ZPulse = "test.ogg";
    std::string ZLaser = "test.ogg";
    std::string ZCannon = "test.ogg";
    std::string PCharging = "test.ogg";
    std::string PJump = "test.ogg";
    std::string PDash = "test.ogg";
    std::string PHurt = "test.ogg";
    std::string PDeath = "test.ogg";
    std::string PPickUp = "test.ogg";
    std::string PEvolve = "test.ogg";
    std::string PRun = "test.ogg";
} SoundFiles;

const struct SpriteIds
{
    int Player = 0;
    int PlayerAnim1 = 1;
    int PlayerAnim2 = 2;
    int PlayerAnim3 = 3;
    int PlayerAnim4 = 4;
    int PlayerAnim5 = 5;
    int PlayerAnim6 = 6;
    int PlayerAnim7 = 7;
};

class App
{
public:
    // Screen Variables
    const int Width = 1280;
    const int Height = 720;
    SDL_Window* Window = NULL;
    SDL_Renderer* Renderer = NULL;

    // Framerate Variables
    const int FpsCap = 60;
    const int TicksPerFrame = 1000 / FpsCap;
    int FrameTicks = 0;
    float CurrentFps = 0;
    int FrameCount = 0;

    Timer FpsTimer;
    Timer CapTimer;

    // Audio Variables
    float GlobalVolume = 10.0f;
    float MusicVolume = 20.0f;
    float MusicCurrentTime = 0.0f;
    bool MusicIsPlaying = false;
    Mix_Music *CurrentMusic = NULL;
    Mix_Music *CurrentMusicHighRes = NULL;
    float SoundsVolume = 20.0f;
    bool SoundIsPlaying = false;
    Mix_Chunk *CurrentSound = NULL;
    Mix_Chunk *CurrentSoundHighRes = NULL;

    float GlobalMusicVolume();
    void PlayMusic(Mix_Music* music, int Volume, float TimePosition, bool ForcePlay);
    void PlaySound(Mix_Chunk* sound, int Volume, float TimePosition, bool ForcePlay);

    Mix_Music* Musics[20];
    Mix_Chunk* Sounds[20];

    Mix_Chunk* LoadSoundFile(std::string fileName);
    Mix_Music* LoadMusicFile(std::string fileName);
    void LoadMusics();
    void LoadSounds();

    // Graphics Stuff
    
    SDL_Surface* SpritesheetSurface = NULL;
    SDL_Texture* SpritesheetTexture = NULL;
    SDL_Rect ClipRects[800]{0};

    SDL_Surface* Spritesheet = NULL;
    SDL_Point SpritesheetSize{0,0};
    SDL_Point SpritesSize{32,32};
    SDL_Point SpritesPerSheet{20,20};

    void LoadSpritesheetTexture();
    void LoadClips();
    void LoadGraphics();
    SDL_Surface* LoadGraphicFile(std::string fileName);

    void RenderTexture(SDL_Texture* texture, SDL_Renderer* Renderer, SDL_Rect* Clip, SDL_Point Position);
    void UpdateRender();

    // Engine Stuff

    bool QuitGame = false;

    void InitLibraries();
    void Init();
    void ClearLibraries();
    void Quit();
    void InputManager();
};
