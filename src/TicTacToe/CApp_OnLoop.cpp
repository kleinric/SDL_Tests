#include "CApp.h"
#include <iostream>

void CApp::OnLoop(){
    int winner;

    winner = CheckWinner();
    if(winner == GRID_TYPE_X){
        std::cout << "Well Done X!\n";
        Reset();
    }else if(winner == GRID_TYPE_O){
        std::cout << "Well Done O!\n";
        Reset();
    }else if(Moves == 9){
        std::cout << "Draw.\n";
        Reset();
    }

}

int CApp::CheckWinner(){
    // Row 1
    if(Grid[0] == Grid[1] && Grid[1] == Grid[2]){
        return Grid[0];
    // Row 2
    }else if(Grid[3] == Grid[4] && Grid[4] == Grid[5]){
        return Grid[3];
    // Row 3
    }else if(Grid[6] == Grid[7] && Grid[7] == Grid[8]){
        return Grid[6];
    // Col 1
    }else if(Grid[0] == Grid[3] && Grid[3] == Grid[6]){
        return Grid[0];
    // Col 2
    }else if(Grid[1] == Grid[4] && Grid[4] == Grid[7]){
        return Grid[1];
    // Col 3
    }else if(Grid[2] == Grid[5] && Grid[5] == Grid[8]){
        return Grid[2];
    // Diag 1
    }else if(Grid[0] == Grid[4] && Grid[4] == Grid[8]){
        return Grid[0];
    // Diag 2
    }else if(Grid[2] == Grid[4] && Grid[4] == Grid[6]){
        return Grid[2];
    }else{
        return GRID_TYPE_NONE;
    }
}
