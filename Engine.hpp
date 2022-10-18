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
    std::string MainTheme = "MainTheme.ogg";
    std::string Level1 = "Level1.ogg";
    std::string Level2 = "Level2.ogg";
    std::string Level3 = "Level3.ogg";
    std::string Level4 = "Level4.ogg";
    std::string Level5 = "Level5.ogg";
    std::string Level6 = "Level6.ogg";
    std::string Level7 = "Level7.ogg";
    std::string Level8 = "Level8.ogg";
    std::string Level9 = "Level9.ogg";
    std::string Bonus = "Bonus.ogg";
    std::string Credits = "Credits.ogg";
    std::string Victory = "Victory.ogg";
    std::string GameOver = "GameOver.ogg";
    std::string Evolving = "Evolving.ogg";
} MusicFiles;

const struct SoundFiles
{
    std::string Test = "test.ogg";
    std::string MMGun = "MMGun.ogg";
    std::string MMFlame = "MMFlame.ogg";
    std::string MMPulse = "MMPulse.ogg";
    std::string MMLaser = "MMLaser.ogg";
    std::string MMMGun = "MMMGun.ogg";
    std::string ZGun = "ZGun.ogg";
    std::string ZSword = "ZSword.ogg";
    std::string ZDisc = "ZDisc.ogg";
    std::string ZPulse = "ZPulse.ogg";
    std::string ZCannon = "ZCannon.ogg";
    std::string PCharging = "PCharging.ogg";
    std::string PHoldingCharge = "PHoldingCharge.ogg";
    std::string PJump = "PJump.ogg";
    std::string PDash = "PDash.ogg";
    std::string PHurt = "PHurt.ogg";
    std::string PDeath = "PDeath.ogg";
    std::string PPickUp = "PPickUp.ogg";
    std::string PEvolve = "PEvolve.ogg";
    std::string PRun = "PRun.ogg";
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
    float GlobalVolume = 20.0f;
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

    Mix_Chunk* LoadSoundFile(std::string fileName);
    Mix_Music* LoadMusicFile(std::string fileName);

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
