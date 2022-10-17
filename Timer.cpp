#include "Timer.hpp"

// TIMER

Timer::Timer()
{
    StartTicks = 0;
    PausedTicks = 0;
    Paused = false;
    Running = false;
}

void Timer::Start()
{
    Running = true;
    Paused = false;
    StartTicks = SDL_GetTicks();
    PausedTicks = 0;
}

void Timer::Stop()
{
    Running = false;
    Paused = false;

    StartTicks = 0;
    PausedTicks = 0;
}

void Timer::Pause()
{
    if (Running and !Paused)
    {
        Paused = true;
        PausedTicks = SDL_GetTicks() - StartTicks;
        StartTicks = 0;
    }
}

void Timer::Resume()
{
    if (Running && Paused)
    {
        Paused = false;
        StartTicks = SDL_GetTicks() - PausedTicks;
        PausedTicks = 0;
    }
}

Uint32 Timer::GetTicks()
{
    Uint32 time = 0;
    if (Running)
    {
        if (Paused)
        {
            time = PausedTicks;
        }
        else
        {
            time = SDL_GetTicks() - StartTicks;
        }
    }

    return time;
}

bool Timer::IsRunning()
{
    return Running;
}

bool Timer::IsPaused()
{
    return Paused && Running;
}