#include "raylib.h"

class Car{
public:
    Vector2 size;
    Vector2 pos;
    int speed;
    float direction;
    Texture2D sprite;
    Rectangle frameRec;

    void Draw(){
        //DrawRectangle(pos.x - 30, pos.y - 50, size.x, size.y, WHITE);
        DrawTextureRec(sprite, frameRec, pos, WHITE);
    }

    void Update(){
        pos.y+= speed;
    }

    void Input(){
        if(IsKeyDown(KEY_UP)){
            
        }
    }
};

Car car;

int main(){
    int screen_size_x = 1280;
    int screen_size_y = 720;

    car.pos.x = (screen_size_x/2) - 12;
    car.pos.y = (screen_size_y/2) - 20;
    car.size.x = 24;
    car.size.y = 40;
    car.speed = 0;
    car.direction = 0.0;

    InitWindow(screen_size_x, screen_size_y, "My First game");
    SetTargetFPS(60);

    car.sprite = LoadTexture("sprites/car.png");
    car.frameRec = { 0, 0, car.size.x, car.size.y };

    // GameLoop
    while(WindowShouldClose() == false){
        // 1. Event Handling
        car.Input();

        // 2. Updating Positions
        car.Update();

        // 3. Drawing
        BeginDrawing();

        ClearBackground(BLACK);

        car.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}