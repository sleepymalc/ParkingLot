//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_ROCKET_H
#define P3_ROCKET_H
#include "Group.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Semi.h"
#include "Arc.h"
#include "Ellipse.h"


class Rocket : public Group {
private:
    int shoot_t=0;
    bool shootb=false;
    Circle c1,c2;
    Arc bodyl,bodyr,wingl,wingr,flamelo,flameli,flamero,flameri;
    Rectangle bodyu,bodym,bodyb,lazer;
    Triangle wing;
    Ellipse light;
    Circle defense;
public:
    Rocket(Vec anchor = {0,0});
    void effect() override ;
    void shoot();
    void setshoot(bool k){shootb=k;}
    bool getshoot(){return shootb;}
    int getshoot_t(){return shoot_t;}
};






#endif //P3_ROCKET_H

