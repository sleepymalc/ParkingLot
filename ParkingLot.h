#ifndef P3_PARKINGLOT_H
#define P3_PARKINGLOT_H
#define GL_SILENCE_DEPRECATION

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Group.h"
#include "Vehicle/Car.h"
#include "Vehicle/Rocket.h"
#include "Vehicle/Teleport.h"
#include "Vehicle/UFO.h"

using namespace std;

class ParkingLot {
   private:
    vector<Group*> Vs;  //Vehicles
    vector<Group*> Ts;  //Teleports
    vector<Vec> Ps;     //Final Slots of Vehicles
   public:
    ParkingLot(){};
    void drawBG();
    void drawDoor(int& open);
    void drawV();
    void genP();
    Vec getT();
    void genV();
    int getV() { return Vs.size(); }
    void moveV();
    void effV();
    void boomV(Rocket* player);
    bool seekV(Rocket* player);
    int checkV();
    ~ParkingLot(){};
};

#endif  //P3_PARKINGLOT_H
