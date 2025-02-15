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

void fill_randoms(int* arr,int arr_size){
    for (int i = 0; i < arr_size; i++){
        arr[i] = GetRandomValue(0, 255);
    }
}

int main(void){

    InitWindow(screenWidth, screenHeight, "Heat equation");
    SetTargetFPS(60);
    const int startX = 0;
    const int startY =0;
    const int num_X = 10;
    const int num_Y = 10;
    unsigned int frameCounter = 0;
    /* int r = (int)random_double(0.0,255.0); */
    /* int g = (int)random_double(0.0,255.0); */
    /* int b = (int)random_double(0.0,255.0); */
    int* r = (int*)malloc(num_X*num_Y*sizeof(int));
    int* g = (int*)malloc(num_X*num_Y*sizeof(int));
    int* b = (int*)malloc(num_X*num_Y*sizeof(int));
    fill_randoms(r, num_X*num_Y);
    fill_randoms(g, num_X*num_Y);
    fill_randoms(b, num_X*num_Y);
    while(!WindowShouldClose()){
        frameCounter++;
        if (((frameCounter/30)%2)==1){
            fill_randoms(r, num_X*num_Y);
            fill_randoms(g, num_X*num_Y);
            fill_randoms(b, num_X*num_Y);
            frameCounter = 0;
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                DrawRectangle(startX+i*recW,startY+j*recH,recH,recW,CLITERAL(Color){r[i*num_X+j],g[i*num_X+j],b[i*num_X+j],255});
            }
        }

        /* DrawText("Hello seaman",100,100,20,SKYBLUE); */
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
