//
// Created by maxwell on 2019/12/7.
//

#ifndef P3_PARKINGLOT_H
#define P3_PARKINGLOT_H
#define GL_SILENCE_DEPRECATION
#include <ctime>
#include <cmath>
#include "Group.h"
#include "Rocket.h"

using namespace std;

class ParkingLot {
private:
vector<Group*> Vs;//Vehicles
vector<Group*> Ts;//Teleports
vector<Vec> Ps;//Final Slots of Vehicles
public:
    ParkingLot(){};
    void drawBG();
    void drawDoor(int &open);
    void drawV();
    void genP();
    Vec getT();
    void genV();
    int getV(){return Vs.size();}
    void moveV();
    void effV();
    void boomV(Rocket* player);
    bool seekV(Rocket* player);
    int checkV();
    ~ParkingLot(){};
};


#endif //P3_PARKINGLOT_H
