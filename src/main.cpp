//iker barrios - 114703035
//main file of the bubble game
#include "raylib.h"
#include "bubble.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int width = 1000;
    const int high = 800;
    InitWindow(width, high, "Bubble Game");
    SetTargetFPS(60);

    vector<Bubble> bubbles; //set of bubbles in the game
    float spawnTimer = 0;
    int score = 0;

    while (!WindowShouldClose()) {
        //make the timer for spawn the bubbles
        spawnTimer += GetFrameTime();

        //spawn bubble every 2 seconds
        if (spawnTimer >= 2.0f) {

            //casting to float for the radius and position of the bubble
            float radius = static_cast<float>(10 + rand() % 50);

            int maxX = static_cast<int>(width - 2 * radius);
            int maxY = static_cast<int>(high - 2 * radius);

            //validate to avoid spawn bubbles outside the window
            if (maxX < 1) maxX = 1;
            if (maxY < 1) maxY = 1;

            //random position for bubble
            float x = radius + static_cast<float>(rand() % maxX);
            float y = radius + static_cast<float>(rand() % maxY);

            //random color for bubble
            Color color = {static_cast<unsigned char>(rand()%256), static_cast<unsigned char>(rand()%256), static_cast<unsigned char>(rand()%256), 255 };
            //add new bubble object to vector of bubbles
            bubbles.push_back(Bubble(x, y, radius, color));

            spawnTimer = 0;
        }

        // detect clicks before draw the bubbles
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            //get the position of the mouse click
            float mousex = GetMouseX();
            float mousey = GetMouseY();

            //check vector of bubbles if click is inside any bubble
            for (auto &b : bubbles) {
                if (b.IsClicked(mousex, mousey)) {
                    score = score + 1 ; // add point to the score
                }
            }
        }

        //draw in the canvas
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (auto &b : bubbles) {
            b.Draw();
        }

        DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}