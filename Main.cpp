#include "Engine.hpp"

/* TODO LIST
* --- LOAD IMAGE (SPRITESHEET) (DONE)
* --- SPLIT IMAGE INTO CLIPS (DONE (MIGHT NEED SOME FIXING))
* --- FIX CLIPS (DONE)
* ASSIGN CLIPS TO IDS.
* 
* ADD PLAYER CONTROLS
* ADD SAVE/LOAD FEATURES
* 
* ADD AUDIO (MUSICS/SFX/ETC...) (PARTIALLY DONE - ADD DIFFERENT MUSICS AND SOUNDS NEXT)
* --- FIX AUDIO (DONE)
* 
* MAKE A WORLD/LEVEL TEMPLATE
* ADD LAYERS TO ALLOW FOR PARALAX OR LAYERING OF EVENTS AND SUCH ON TOP OF EACH OTHERS
* MAKE A WORLD/LEVEL EDITOR
* 
* ADD EVENTS (LOAD DIFFERENT LEVEL/ETC...)
* 
* ADD PLAYER CUSTOMIZATION/PROGRESSION
* 
* ADD MENUES (MAIN MENU/LEVEL SELECTOR/IN_GAME_UI/ETC...)
* ADD OPTIONS TO ALLOW CUSTOMIZING THE RESOLUTION AND OTHER SETTINGS.
* ADD A SAVE/LOAD FEATURE TO THE OPTIONS SO THEY CAN BE KEPT AFTER REOPENING THE GAME.
* 
* --- CAP FRAMERATE (DONE)
*/

int main(int argc, char* argv[])
{
    App app;
    app.Init();


    while (app.QuitGame != true)
    {
        app.CapTimer.Start();
        app.CurrentFps = app.FrameCount / (app.FpsTimer.GetTicks() / 1000.0f);
        if (app.CurrentFps > 2000000)
        {
            app.CurrentFps = 0;
        }

        app.FrameCount++;

        app.FrameTicks = app.CapTimer.GetTicks();
        if (app.FrameTicks < app.TicksPerFrame)
        {
            SDL_Delay(app.TicksPerFrame - app.FrameTicks);
        }

        if (app.CurrentMusic == NULL)
        {
            //app.PlayMusic(app.Musics[0], 0, 0, false);
        }

        app.UpdateRender();
    }

    app.Quit();
    return 0;
}


