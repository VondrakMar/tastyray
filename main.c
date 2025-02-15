#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"


#define screenWidth 300
#define screenHeight 300
#define recW 30
#define recH 30


double random_double(double min, double max){//double prev, double current, double followed){
    double res = min + (max - min)* ((double)rand() / RAND_MAX);
    return res;
}

int main(void){

    InitWindow(screenWidth, screenHeight, "Heat equation");
    SetTargetFPS(10);
    const int startX = 0;
    const int startY =0;
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        /* for ( */
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                int r = (int)random_double(0.0,255.0);
                int g = (int)random_double(0.0,255.0);
                int b = (int)random_double(0.0,255.0);
                DrawRectangle(startX+i*recW,startY+j*recH,recH,recW,CLITERAL(Color){r,g,b,255});
            }
        }

        /* DrawText("Hello seaman",100,100,20,SKYBLUE); */
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
