#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum windowSubState{closed, mainMenu, redMenu, greenMenu, blueMenu, graphMenu};

Color customGray = Color{20,30,40,255};
Color customRed = Color{120,0,0,255};
Color customGreen = Color{0,120,0,255};
Color customBlue = Color{0,0,120,255};
Color bg = customGray;
int mainW = 1280; int mainH = 800;
int centerW = mainW/2; int centerH = mainH/2;

int main(){
    enum windowSubState subState;
    subState = mainMenu;

    InitWindow(mainW, mainH, "demo");
    Texture2D greenBG = LoadTexture("greenHumor.png");
    Texture2D graphBG = LoadTexture("graph.png");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 32);
    while(subState){
        BeginDrawing();
        ClearBackground(bg);
        switch(subState){
        case(mainMenu):
            bg = customGray;
            GuiLabel((Rectangle){centerW-100, centerH-200, 200, 80}, "MAIN MENU");
            if(GuiButton((Rectangle){centerW-100, centerH-100, 200, 80}, "RED")){
                subState = redMenu;
            }
            if(GuiButton((Rectangle){0, 0, 200, 80}, "GRAPH")){
                subState = graphMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH, 200, 80}, "GREEN")){
                subState = greenMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+100, 200, 80}, "BLUE")){
                subState = blueMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+300, 200, 80}, "EXIT")){
                subState = closed;
            }
            break;
        case(redMenu):
            bg = customRed;
            GuiLabel((Rectangle){centerW-100, centerH-200, 200, 80}, "RED MENU");
            if(GuiButton((Rectangle){centerW-100, centerH-100, 200, 80}, "GREEN")){
                subState = greenMenu;
            }
            if(GuiButton((Rectangle){0, 0, 200, 80}, "GRAPH")){
                subState = graphMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH, 200, 80}, "BLUE")){
                subState = blueMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+100, 200, 80}, "BACK")){
                subState = mainMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+300, 200, 80}, "EXIT")){
                subState = closed;
            }
            break;
        case(greenMenu):
            bg = customGreen;
            DrawTexture(greenBG, 0, mainH-566, WHITE);
            GuiLabel((Rectangle){centerW-100, centerH-200, 200, 80}, "GREEN MENU");
            if(GuiButton((Rectangle){centerW-100, centerH-100, 200, 80}, "RED")){
                subState = redMenu;
            }
            if(GuiButton((Rectangle){0, 0, 200, 80}, "GRAPH")){
                subState = graphMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH, 200, 80}, "BLUE")){
                subState = blueMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+100, 200, 80}, "BACK")){
                subState = mainMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+300, 200, 80}, "EXIT")){
                subState = closed;
            }
            break;
        case(blueMenu):
            bg = customBlue;
            GuiLabel((Rectangle){centerW-100, centerH-200, 200, 80}, "BLUE MENU");
            if(GuiButton((Rectangle){centerW-100, centerH-100, 200, 80}, "RED")){
                subState = redMenu;
            }
            if(GuiButton((Rectangle){0, 0, 200, 80}, "GRAPH")){
                subState = graphMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH, 200, 80}, "GREEN")){
                subState = greenMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+100, 200, 80}, "BACK")){
                subState = mainMenu;
            }
            if(GuiButton((Rectangle){centerW-100, centerH+300, 200, 80}, "EXIT")){
                subState = closed;
            }
            break;
        case(graphMenu):
            bg = WHITE;
            DrawTexture(graphBG, mainW-979, mainH-738, WHITE);
            GuiLabel((Rectangle){200, 0, 200, 80}, "GRAPH MENU");
            if(GuiButton((Rectangle){mainW-200, 0, 200, 80}, "BACK")){
                subState = mainMenu;
            }
            break;
        default:
            subState = mainMenu;
            break;
        }
        EndDrawing();
    }
    CloseWindow();
}
