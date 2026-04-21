//bubble class methods implementation
//iker barrios - 114703035
#include "bubble.h"
//constructor
Bubble::Bubble(float _x, float _y, float _r, Color c)
    : x(_x), y(_y), radio(_r), color(c), activa(true) {}

void Bubble::Draw() const {
    if (!activa) return; //check if the bubble is active before draw
    DrawCircleV({ x, y }, radio, color);
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