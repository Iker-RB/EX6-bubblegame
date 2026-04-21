//bubble class definition
//iker barrios - 114703035
#include "raylib.h"

class Bubble {
public:
    //Constructor
    Bubble(float px, float py, float r, Color c);

    //Draw the bubble
    void Draw() const;

    //Check for the bubble still active
    bool IsClicked(float moux, float mouy);

private:
    bool activa;
    float x;
    float y;
    float radio;
    Color color; //color of the bubble - special data type from raylib
    
};