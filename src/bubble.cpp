//bubble class methods implementation
//iker barrios - 114703035
#include "bubble.h"
#include <cstdlib>
//constructor
Bubble::Bubble(float _x, float _y, float _r, Color c)
    : x(_x), y(_y), radio(_r), color(c), activa(true) {
        // velocidad aleatoria más lenta (entre -1 y 1)
        vx = ((rand() % 5));
        vy = ((rand() % 5));
    }

void Bubble::Draw() const {
    if (!activa) return; //check if the bubble is active before draw
    DrawCircleV({ x, y }, radio, color);
}


//extra more feature: movement of the bubbles
void Bubble::Update() {
    if (!activa) return;

    //Actualization of position of the bubble with the velocity
    x += vx;
    y += vy;

    //Validation for the borders
    if (x - radio < 0) {
        x = radio;
        vx = -vx; //bounce back
    }
    if (x + radio > GetScreenWidth()) {
        x = GetScreenWidth() - radio;
        vx = -vx;//bounce back
    }
    if (y - radio < 0) {
        y = radio;
        vy = -vy;//bounce back
    }
    if (y + radio > GetScreenHeight()) {
        y = GetScreenHeight() - radio;
        vy = -vy;//bounce back
    }
}

bool Bubble::IsClicked(float moux, float mouy) {
    if (!activa) return false; //check if the bubble is active or not
  
    //usage of distance formula check if click is inside the object bubble
    float dx = moux - x;
    float dy = mouy - y;
    float distancia = dx*dx + dy*dy; 

    if (distancia <= radio * radio) {
        activa = false;
        return true;
    }
    return false;
}