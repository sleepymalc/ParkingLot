//
// Created by maxwell on 2019/12/15.
//
//static const int Rb = 5;
#include "Game.h"

void Game::Init() {
    lot->genV();
}

void Game::Draw() {

    lot->drawBG();
    lot->drawV();
    player->draw();
}

void Game::Change() {
    //lot:
    if(player->getshoot()){
        player->shoot();
    }
    lot->moveV();
    lot->effV();
    player->effect();
}

//the radius of laser is 2.

void Game::ifShot(){
    if(player->getshoot())lot->boomV(player);
}

void Game::ifImp() {
    if(lot->seekV(player)){
        cerr<<"Your rocket collapsed!"<<endl<<"Game Overrr~"<<endl;
        exit(0);
    }
}

void Game::ifLose(){
    if(lot->checkV()>=3){
        cerr<<"Oh! You missed 3 vehicles!"<<endl<<"Game Overrr~"<<endl;exit(0);
    }
}

void Game::ifWin(){
    static bool j = false;
    if(lot->getV()>3)j = true;
    if(j){
        if(lot->getV()==0){
            cerr<<"Nice! You made it!"<<"Game End."<<endl;exit(0);
        }
    }

}