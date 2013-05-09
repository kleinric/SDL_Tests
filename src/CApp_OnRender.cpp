#include "CApp.h"

void CApp::OnRender(){
    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Test, 10, 10, 0, 0, 50, 50);

    SDL_Flip(Surf_Display);

}
