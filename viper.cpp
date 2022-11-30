#include "viper.h"

void viper_init (Viper * v)
{
    // TODO: Implement
    //1. Set starting coordinates for your viper head and previous
    
    //2. Initialize all location for your maximum viper body (loop through the viper)

    //3. Set starting length of your viper

    //4. Set starting coordinates for the rest of viper body from starting length

    //5. Initialize viper status
    v->head_x = 5;
    v->head_y = 5;
    v->head_px = 5;
    v->head_py = 5;
    
    for (int i = 0; i < 50; i++) {
        (v->locations[i]).x = 0-i;
        (v->locations[i]).y = 0-i;
    }
    
    v->length = 3;
    
    for (int i = 0; i < v->length; i++) {
        (v->locations[i]).x = 5-i;
        (v->locations[i]).y = 5;
    }
    
    v->score = 0;
    v->immortal = false;
    v->limp_score = false;
}
