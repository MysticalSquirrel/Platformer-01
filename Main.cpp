#include "Engine.hpp"

/* ENVIRONMENT SETUP
* Please refer to the GITHUB repository or the README.md file present in the project's main folder.
*/

/* TODO LIST
* --- LOAD IMAGE (SPRITESHEET) (DONE)
* -- SPLIT IMAGE INTO CLIPS (DONE (MIGHT NEED SOME FIXING))
* --- FIX CLIPS (DONE)
* -- ASSIGN CLIPS TO IDS. (NEEDS TO FINISH ASSIGNING THE CLIPS)
* 
* ADD PLAYER CONTROLS
* ADD SAVE/LOAD FEATURES
* 
* -- ADD AUDIO (MUSICS/SFX/ETC...) (PARTIALLY DONE - ADD DIFFERENT MUSICS AND SOUNDS NEXT)
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
    App *app = new App();
    app->Init();


    while (app->QuitGame != true)
    {
        app->CapTimer.Start();
        app->CurrentFps = app->FrameCount / (app->FpsTimer.GetTicks() / 1000.0f);
        if (app->CurrentFps > 2000000)
        {
            app->CurrentFps = 0;
        }

        app->FrameCount++;

        app->FrameTicks = app->CapTimer.GetTicks();
        if (app->FrameTicks < app->TicksPerFrame)
        {
            SDL_Delay(app->TicksPerFrame - app->FrameTicks);
        }

        app->UpdateRender();
    }

    app->Quit();
    delete(app);
    return 0;
}


