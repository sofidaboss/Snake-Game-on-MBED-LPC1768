#ifndef GRAPHICS_H
#define GRAPHICS_H

/**
 * Takes a string image and draws it to the screen. The string is 121 characters
 * long, and represents an 11x11 tile in row-major ordering (across, then down,
 * like a regular multi-dimensional array). The available colors are:
 *      R = Red
 *      Y = Yellow
 *      G = Green
 *      D = Brown ("dirt")
 *      5 = Light grey (50%)
 *      3 = Dark grey (30%)
 *      Any other character is black
 * More colors can be easily added by following the pattern already given.
 */
void draw_img(int u, int v, const char* img);

/**
 * DrawFunc functions. 
 * These can be used as the MapItem draw functions.
 */
void draw_nothing(int u, int v);
void draw_plant(int u, int v);
void draw_wall(int u, int v);
void draw_chest(int u, int v);
void draw_viper_body(int u, int v);
void draw_viper_head(int u, int v);
void draw_viper_tail(int u, int v);
void draw_boost_up(int u, int v);
void draw_boost_down(int u, int v);


#endif // GRAPHICS_H