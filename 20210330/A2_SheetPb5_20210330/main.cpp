#include <iostream>
#include <cstdlib>
#include "GameOfLife.h"
using namespace std;



int main(){
    // create an object of class Universe
    Universe universe;
    // run the game
    universe.run(1000);
    return 0;
}