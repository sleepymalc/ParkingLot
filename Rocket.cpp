//
// Created by maxwell on 2019/11/28.
//

#include "Rocket.h"

Rocket::Rocket(Vec anchor) {
    dre={0,-10};
    this->setAnchor(anchor);
    this->setRelation({0, 0});
    this->bodyr = Arc(anchor,{-20,-15},{20.01,28.71},55.12,0.8,0.8,0.8,0);
    this->bodyl = Arc(anchor,{20,-15},{-20.01,28.71},-55.12,0.8,0.8,0.8,0);//right is food.
    this->wingr = Arc(anchor,{-20,-20},{32.97,-16.80},-27,0.5,0.5,0.5,0);
    this->wingl = Arc(anchor,{20,-20},{-32.97,-16.80},27,0.5,0.5,0.5,0);
    this->flamero = Arc(anchor,{-80,-20},{79.89,-25.96},-18.,1,0,0,1);
    this->flamelo = Arc(anchor,{80,-20},{-79.89,-25.96},18,1,0,0,1);
    this->flameri = Arc(anchor,{-80,-20},{79.99,-20.98},-14.7,1,0.76,0,1);
    this->flameli = Arc(anchor,{80,-20},{-79.99,-20.98},14.7,1,0.76,0,1);
    this->bodyu = Rectangle(anchor,{-15,-20},{30,0},{0,5},0.2,0.2,1,0);
    this->bodym = Rectangle(anchor,{-15,-22},{30,0},{0,2},0.9,0.9,0.1,0);
    this->bodyb = Rectangle(anchor,{-4,-24},{8,0},{0,2},0,0,0,0);
    this->wing = Triangle(anchor,{-1.5,-21},{3,0},{-1.5,-16.8},0.5,0.5,0.5,0);
    this->c2 = Circle(anchor,{0,0},6,0.29,0.75,1.0,0);
    this->c1 = Circle(anchor,{0,0},4,0.059,0.584,1.0,1);
    this->light = Ellipse(anchor, {0,14}, {3,0.6}, 0, 0, 1, 1);
    this->lazer = Rectangle(anchor, {-2,23}, {4,0}, {0,500}, 0, 0.5, 0.5);
    this->defense=Circle(anchor,dre, 22, 0.77734, 0.8632, 1,0);

    figs.push_back(&defense);
    figs.push_back(&flamelo);
    figs.push_back(&flamero);
    figs.push_back(&flameli);
    figs.push_back(&flameri);
    figs.push_back(&bodyr);
    figs.push_back(&bodyl);
    figs.push_back(&wingr);
    figs.push_back(&wingl);
    figs.push_back(&bodyu);
    figs.push_back(&bodym);
    figs.push_back(&bodyb);
    figs.push_back(&wing);
    figs.push_back(&c2);
    figs.push_back(&c1);
    figs.push_back(&lazer);
    figs.push_back(&light);
    this->light.zoom(0.001);
    this->lazer.zoom(0.001);
    eff = 0.98;
}

void Rocket::effect() {
    if(timer%12==11){eff = 1/eff;}
    this->flameli.zoom(eff);
    this->flamelo.zoom(eff);
    this->flameri.zoom(eff);
    this->flamero.zoom(eff);
    timer++;
    if(timer>666666)timer = 0;
}

void Rocket::shoot(){
    
    if(shoot_t==0){
        this->light.zoom(1000);
        shoot_t++;
    }else if(shoot_t<14){
        this->light.zoom(1.04);
        shoot_t++;
    }else if(shoot_t==14){
        this->lazer.zoom(1000);
        shoot_t++;
    }else if(shoot_t<20){
        this->lazer.setColor(0, 0.5+0.015*shoot_t, 0.5+0.015*shoot_t);
        shoot_t++;
    }else if(shoot_t==20){
        shoot_t=0;
        this->setshoot(false);
        this->light.zoom(0.6);
        this->light.zoom(0.001);
        this->lazer.zoom(0.001);
        this->lazer.setColor(0, 0.5, 0.5);
    }
}
