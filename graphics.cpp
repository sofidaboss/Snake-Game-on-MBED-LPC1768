#include "graphics.h"

#include "globals.h"

int drawings[4][11*11] = {
//0 viper head
{
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00,
0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00,
0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00, 0xff00, 0xff0000, 0xff0000, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00,
},
//1 chest
{
0x0, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x0, 0x0, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0xcddc39, 0xcddc39, 0x3e2723, 0xcddc39, 0xcddc39, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0xcddc39, 0xcddc39, 0x3e2723, 0xcddc39, 0xcddc39, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0xcddc39, 0xcddc39, 0x3e2723, 0xcddc39, 0xcddc39, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 0x3e2723, 0x607d8b, 
0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 0x455a64, 
},
//2 viper tail
{
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
0x0, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0xff00, 0x0, 0xff00, 0xff00, 0x0,
},
//3 wall
{
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0xff00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0xff00, 0xf44336, 0xff00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0xff00, 0xf44336, 0xf44336, 0xf44336, 0xff00, 0x0, 0x0, 0x0, 0x0, 0x0, 
0xff00, 0xf44336, 0xf44336, 0xff, 0xf44336, 0xf44336, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 
0x0, 0xff00, 0xf44336, 0xf44336, 0xf44336, 0xff00, 0x0, 0x0, 0xff00, 0x0, 0xff00, 
0x0, 0x0, 0xff00, 0xf44336, 0xff00, 0x0, 0x0, 0x0, 0xff00, 0x0, 0xff00, 
0x0, 0x0, 0x0, 0xff00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
},
};

void draw_nothing(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, BLACK);
}

void draw_img(int u, int v, const char* img)
{
    int colors[11*11];
    for (int i = 0; i < 11*11; i++)
    {
        if (img[i] == 'R') colors[i] = RED;
        else if (img[i] == 'Y') colors[i] = 0xFFFF00;   // Yellow
        else if (img[i] == 'G') colors[i] = GREEN;
        else if (img[i] == 'D') colors[i] = 0xD2691E;   // "Dirt"
        else if (img[i] == '5') colors[i] = LGREY;      // 50% grey
        else if (img[i] == '3') colors[i] = DGREY;
        else colors[i] = BLACK;
    }
    uLCD.BLIT(u, v, 11, 11, colors);
    wait_us(250); // Recovery time!
}

void draw_wall(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    uLCD.filled_rectangle(u, v, u+10, v+10,0xa020f0);
}

void draw_plant(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    uLCD.filled_rectangle(u, v, u+10, v+10, GREEN);
}

void draw_chest(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    uLCD.filled_rectangle(u, v, u+10, v+10, 0x0000ff);
}

void draw_viper_body(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper
    uLCD.filled_rectangle(u, v, u+10, v+10, GREEN);
}

void draw_viper_head(int u, int v)
{
    // TODO: Implement
    //May need to design a viper head sprite
    //Tile still need to be designed on paper

    uLCD.BLIT(u, v, 11, 11, drawings[0]);
}

void draw_viper_tail(int u, int v)
{
    // TODO: Implement
    //May need to design a viper tail sprite
    //Tile still need to be designed on paper
    uLCD.BLIT(u, v, 11, 11, drawings[2]);
}

void draw_boost_up(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, 0xffff00);
}

void draw_boost_down(int u, int v)
{
    uLCD.filled_rectangle(u, v, u+10, v+10, 0xff0000);
}