#include "CApp.h"
#include "CSurface.h"
#include <iostream>
 
CApp::CApp() {
    Surf_Display = NULL;
    Surf_Grid    = NULL;
    Surf_X       = NULL;
    Surf_O       = NULL;
    Running = true;
}

bool CApp::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }
    
    Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(Surf_Display == NULL){
        return false;
    }

    Surf_Grid = CSurface::OnLoad("resources/grid.bmp");
    if(Surf_Grid == NULL){
        return false;
    }

    Surf_X = CSurface::OnLoad("resources/X.bmp");
    if(Surf_Grid == NULL){
        return false;
    }
    Surf_O = CSurface::OnLoad("resources/O.bmp");
    if(Surf_Grid == NULL){
        return false;
    }

    CSurface::Transparent(Surf_X, Surf_X, 255, 0, 255);
    CSurface::Transparent(Surf_O, Surf_O, 255, 0, 255);
    Reset();

    return true;
}

int CApp::OnExecute() {
    if(OnInit() == false){
        return -1;
    }

    SDL_Event Event;

    while(Running){
        while(SDL_PollEvent(&Event)){
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();
    return 0;
}

void CApp::Reset(){
    for(int i = 0; i < 9; i++){
        Grid[i] = GRID_TYPE_NONE;
    }
    CurrentPlayer = 0;
    Moves = 0;
}

void CApp::SetCell(int ID, int Type){
    if(ID < 0 || ID > 9) return;
    if(Type < 0 || Type > GRID_TYPE_O) return;

    Grid[ID] = Type;
    Moves++;
}

int main(int argc, char* argv[]) {
    CApp theApp;
 
    return theApp.OnExecute();
}
