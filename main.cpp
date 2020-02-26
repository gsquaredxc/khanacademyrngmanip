#include <iostream>
#include <math.h>

#define znew  ((z=36969*(z&65535)+(z>>16))&65535)
#define wnew  ((w=18000*(w&65535)+(w>>16))&65535)
#define random ((((znew&65535)<<16) | (wnew&65535)) & 4294967295) / 4294967296.0
//change these two before compile to get the correct generator
#define largestValue 7
#define smallestValue 1
#define randomMOD random * (largestValue - smallestValue) + smallestValue
static unsigned long z=362436069, w=521288629;
void setseed(unsigned long i1,unsigned long i2){z=i1; w=i2;}
//seeds between 1-1872166911 will come in pairs with seeds 2422800384-4294967295
//seeds between 1872166912-2422800383 are singular
int main(){
    std::cout<<"Input the first 3 random numbers"<<std::endl;
    double firstNumber, secondNumber, thirdNumber;
    std::cin>>firstNumber;
    std::cin>>secondNumber;
    std::cin>>thirdNumber;
    std::cout<<"finding seed"<<std::endl;
    long seeds[2];
    int seedsCount = 0;
    for (long i = 0; i<4294967296;i++){
        setseed(i,521288629);
        if (randomMOD == firstNumber){ //eliminates most seeds
            if (randomMOD == secondNumber){ //should remove all seeds but 1 or 2
                if (randomMOD == thirdNumber){ //just in case
                    try{
                        seeds[seedsCount] = i;
                    }catch(...){
                        std::cout<<"Too many seeds!";
                    }
                    seedsCount++;
                }
            }
        }
    }
    std::cout << seeds[0] << '\n';
    if (seeds[1]){
        std::cout << seeds[1] << '\n';
    }
}
