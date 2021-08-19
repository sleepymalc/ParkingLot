//
// Created by maxwell on 2019/12/15.
//

#ifndef P3_GAME_H
#define P3_GAME_H

#include "ParkingLot.h"
#include "Rocket.h"

class Game {
   private:
    ParkingLot* lot;
    Rocket* player;

   public:
    Game() {
        lot = new ParkingLot();
        lot->genP();
        float tmpx = (lot->getT().getX() * 50 - 125) * lot->getT().getY();
        float tmpy = lot->getT().getY() * (-130);
        player = new Rocket({tmpx, tmpy});
    };
    void Init();
    void Draw();
    void Change();
    void ifShot();
    void ifImp();
    void ifLose();
    void ifWin();
    Rocket* getP() { return player; }
    ~Game(){};
};

#endif  //P3_GAME_H
