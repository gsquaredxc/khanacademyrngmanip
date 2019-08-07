#include <iostream>
#include <math.h>

#define znew  ((z=36969*(z&65535)+(z>>16))&65535)
#define wnew  ((w=18000*(w&65535)+(w>>16))&65535)
#define random ((((znew&65535)<<16) | (wnew&65535)) & 4294967295) / 4294967296.0
static unsigned long z=362436069, w=521288629;
void setseed(unsigned long i1,unsigned long i2){z=i1; w=i2;}

int main(){
    setseed(2,521288629);
    for (long i = 1; i<4294967296;i++){
        setseed(i,521288629);
        if (random == 0.5109447021968663){ //first
            if (random == 0.3095569028519094){ //second
                if (random == 0.22901016473770142){ //third
                std::cout<<i<<'\n';
                }
            }
        }
    }
}
