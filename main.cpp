#include "raylib.h"
#include <cmath>
#include <iostream>

class Car{
public:
    Vector2 size;
    Vector2 pos;
    Vector2 origin;
    int speed;
    int speed_rot;
    float direction;
    float rad;
    Texture2D sprite;
    Rectangle dest_rec;
    Rectangle src_rec;

    void Draw(){
        //DrawRectangle(pos.x - 30, pos.y - 50, size.x, size.y, WHITE);
        DrawTexturePro(sprite, src_rec, dest_rec, origin, direction, WHITE);
    }

    void Update(){
        dest_rec.x = pos.x;
        dest_rec.y = pos.y;
    }

    void Input(){
        if(IsKeyDown(KEY_UP)) {
            rad = direction * (3.14f / 180.0f);

            pos.x += sin(rad) * speed;
            pos.y += -cos(rad) * speed;

            if(IsKeyDown(KEY_LEFT)){
                direction -= speed_rot;

                if (direction >= 360) direction -= 360;
                if (direction < 0) direction += 360;    

            } else if(IsKeyDown(KEY_RIGHT)){
                direction += speed_rot;

                if (direction >= 360) direction -= 360;
                if (direction < 0) direction += 360;
            }
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
    car.speed = 5;
    car.direction = 0.0;
    car.speed_rot = 3;

    InitWindow(screen_size_x, screen_size_y, "My First game");
    SetTargetFPS(60);

    car.sprite = LoadTexture("sprites/car.png");
    car.dest_rec = {screen_size_x / 2.0f, screen_size_y / 2.0f, car.size.x * 3, car.size.y * 3};
    car.origin = {car.dest_rec.width / 2.0f, car.dest_rec.height / 2.0f};
    car.src_rec = { 0.0f, 0.0f, (float)car.size.x, (float)car.size.y };

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

    UnloadTexture(car.sprite);  

    CloseWindow();
    return 0;
}