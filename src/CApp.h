#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"
 
class CApp : public CEvent {
    private:
        bool            Running;
        SDL_Surface*    Surf_Display;
        SDL_Surface*    Surf_Test;
    public:
        CApp();
 
        int OnExecute();
 
     public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnExit();

        void OnLoop();
        void OnRender();
        void OnCleanup();

};
 
#endif
