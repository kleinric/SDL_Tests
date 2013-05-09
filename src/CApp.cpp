#include "CApp.h"
#include "CSurface.h"
 
CApp::CApp() {
    Surf_Display = NULL;
    Surf_Test    = NULL;
    Running = true;
}

bool CApp::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }
    
    Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if(Surf_Display == NULL){
        return false;
    }

    Surf_Test = CSurface::OnLoad("bin/myimage.bmp");
    if(Surf_Test == NULL){
        return false;
    }

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
 
int main(int argc, char* argv[]) {
    CApp theApp;
 
    return theApp.OnExecute();
}
