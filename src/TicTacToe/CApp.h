#ifndef _CAPP_H_
    #define _CAPP_H_
 
#include <SDL/SDL.h>
#include "CSurface.h"
#include "CEvent.h"

enum {
    GRID_TYPE_NONE = 0,
    GRID_TYPE_X,
    GRID_TYPE_O  
};
 
class CApp : public CEvent {
    private:
        bool            Running;
        SDL_Surface*    Surf_Display;
        SDL_Surface*    Surf_Grid;
        SDL_Surface*    Surf_X;
        SDL_Surface*    Surf_O;

        int Grid[9];
        int Moves;
        int CurrentPlayer;
        int CheckWinner();
    public:
        CApp();
 
        int OnExecute();
 
     public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
            void OnExit();
            void OnLButtonDown(int mX, int mY);

        void OnLoop();
        void OnRender();
        void OnCleanup();

        void Reset();
        void SetCell(int ID, int Type);
};
 
#endif
