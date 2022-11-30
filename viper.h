#ifndef VIPER_H
#define VIPER_H

#define VIPER_MAX_LENGTH 50

// Structure of coordinates in the map
typedef struct{
    int x;
    int y;
} Coordinate;

// Viper Structure
typedef struct {
    int head_x, head_y, head_px, head_py; // Location of the head of the viper
    int length; // length of the viper
    Coordinate locations[VIPER_MAX_LENGTH]; // Viper body locations
    int score; //Current score of the viper
    bool immortal; //immortality status of viper
    bool limp_score; //unable to gain score when this is true
} Viper;

// Initialize a viper structure
// You want to assign initial values to each of the variables defined above
// in the viper structure.
void viper_init (Viper* viper);


#endif VIPER_H  // VIPER_H