#pragma once
#include <SDL_timer.h>

class Timer
{
public:
    Timer();

    void Start();
    void Stop();
    void Pause();
    void Resume();

    Uint32 GetTicks();

    bool IsRunning();
    bool IsPaused();

private:
    Uint32 StartTicks = 0;
    Uint32 PausedTicks = 0;
    bool Paused = false;
    bool Running = false;
};