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
    std::string Maps = "Resources\\Maps\\";
} ResourcePaths;

const struct MusicFiles
{
    std::string Test = "test.wav";
    std::string MainTheme = "MainTheme.wav";
    std::string Level1 = "Level1.wav";
    std::string Level2 = "Level2.wav";
    std::string Level3 = "Level3.wav";
    std::string Level4 = "Level4.wav";
    std::string Level5 = "Level5.wav";
    std::string Level6 = "Level6.wav";
    std::string Level7 = "Level7.wav";
    std::string Level8 = "Level8.wav";
    std::string Level9 = "Level9.wav";
    std::string Bonus = "Bonus.wav";
    std::string Credits = "Credits.wav";
    std::string Victory = "Victory.wav";
    std::string GameOver = "GameOver.wav";
    std::string Evolving = "Evolving.wav";
} MusicFiles;

const struct SoundFiles
{
    std::string Test = "test.wav";
    std::string MMGun = "MMGun.wav";
    std::string MMFlame = "MMFlame.wav";
    std::string MMPulse = "MMPulse.wav";
    std::string MMLaser = "MMLaser.wav";
    std::string MMMGun = "MMMGun.wav";
    std::string ZGun = "ZGun.wav";
    std::string ZSword = "ZSword.wav";
    std::string ZDisc = "ZDisc.wav";
    std::string ZPulse = "ZPulse.wav";
    std::string ZCannon = "ZCannon.wav";
    std::string PCharging = "PCharging.wav";
    std::string PHoldingCharge = "PHoldingCharge.wav";
    std::string PJump = "PJump.wav";
    std::string PDash = "PDash.wav";
    std::string PHurt = "PHurt.wav";
    std::string PDeath = "PDeath.wav";
    std::string PPickUp = "PPickUp.wav";
    std::string PEvolve = "PEvolve.wav";
    std::string PRun = "PRun.wav";
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
} SpriteIds;

const struct Maps
{
    std::string Level1 = "Level1.map";
    std::string Level2 = "Level2.map";
    std::string Level3 = "Level3.map";
    std::string Level4 = "Level4.map";
    std::string Level5 = "Level5.map";
    std::string Level6 = "Level6.map";
    std::string Level7 = "Level7.map";
    std::string Level8 = "Level8.map";
    std::string Level9 = "Level9.map";
    std::string Bonus = "Bonus.map";
} Maps;

struct Tile
{
    int Id = 0;
    SDL_Rect Clip;
};

struct Map
{
    int Id = 0;
    std::string Name = "";
    std::string Music = "";
};

const struct MapTileIds
{
    int test = 0;
} MapTileIds;

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
    SDL_Rect ClipRects[500]{0};

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

    // Map Stuff

    bool LoadMap(Map map);

    Tile Tiles[500]{0};


    // Engine Stuff

    bool QuitGame = false;

    void InitLibraries();
    void Init();
    void ClearLibraries();
    void Quit();
    void InputManager();
};
