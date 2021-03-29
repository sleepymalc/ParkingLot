//
// Created by maxwell on 2019/11/28.
//
#include "Group.h"
#include <cmath>

void Step0(Group *v,bool &s1,bool &s2){
    if(v->getS(1)){
        v->move({0,2});
        if(v->getAnchor().getY()>-100){
            v->setS(1,false);
            v->setS(2,true);
        }
    }
    if(v->getS(2)){
        v->moveAnchorto({-130,-100});
        v->rotate(-1);
        if(v->getpoint().getX()>-130){
            v->resetS();
            s1 = false;
            s2 = true;
        }
    }

}

void Step1(Group *v,int x,int y,bool &s){
    if(v->getS(1)){//move
        v->move({2.0f*y,0});
        if(v->getpoint().getX()*y>-75+50.0f*x){
            v->setS(1,false);
            v->setS(2,true);
        }
    }
    if(v->getS(2)) {//rotate
        v->moveAnchorto({(-80+50.0f*x)*y, -100.0f*y});
        v->rotate(1);
        if(v->getpoint().getX()*y<-125+50.0f*x){
            v->setS(2,false);
            v->setS(3,true);
        }
    }
    if(v->getS(3)){//backward
        v->move({0,-2.0f*y});
        if(v->getpoint().getY()*y<-125){
            v->resetS();
            s = false;
        }
    }
}

void Step2(Group *v,bool &s2,bool &s3){
    if(v->getS(1)){
        v->move({2.0f,0});
        if(v->getpoint().getX()>60){
            v->setS(1,false);
            v->setS(2,true);
        }
    }
    if(v->getS(2)) {
        v->moveAnchorto({60, 0});
        v->rotate(1.5);
        if(v->getpoint().getY()>54.9){
            v->resetS();
            s2 = false;
            s3 = true;
        }
    }
}

void Step3(Group *v,bool &s){
    if(v->getS(1)){
        v->move({2.0f,0});
        if(v->getpoint().getX()>70){
            v->setS(1,false);
            v->setS(2,true);
        }
    }
    if(v->getS(2)) {
        v->moveAnchorto({70, 0});
        v->rotate(1.5);
        if(v->getpoint().getX()>124.9){
            v->setS(2,false);
            v->setS(3,true);
        }
    }
    if(v->getS(3)){
        v->move({0,-2.0f});
        if(v->getpoint().getY()<-125){
            v->resetS();
            s = false;
        }
    }
}

void Group::setAnchor(Vec anchor){
    this->Figure::setAnchor(anchor);
    for(auto i : this->figs){
        i->setAnchor(anchor);
    };
}

float Group::getAng(){
    return gesture;
}

void Group::newAng(float ang){
    gesture+=ang;
}

void Group::moveAnchorto(Vec newanchor){
    group_moveAnchorTo(newanchor);

}

void Group::draw() {
    for(auto i : this->figs){
        i->draw();
    }
}

void Group::move(Vec dir) {
    setAnchor(getAnchor()+dir);
    for(auto i : this->figs){
        i->move(dir);
        i->setAnchor(getpoint());
    }
}

void Group::moveto(Vec des) {
    setAnchor(des);
    for(auto i : this->figs){
        i->setAnchor(getpoint());
    }
}

void Group::zoom(float k){
    zoomRe(k);
    dre*=k;
    for(auto i : figs){
        i->zoom(k);
    }
}

void Group::rotate(float ang) {
    turnRe(ang);
    dre<<ang;
    for(auto i : figs){
        i->rotate(ang);
        i->setAnchor(getpoint());
    }

}

void Group::moveV(Vec p) {
Group *v = this;
int x = p.getX(), y = p.getY();//define: y=-1 then upper, y=1 then lower.
if (y > 0) {
    if (x >= 0 && x <= 4) {
        if (s[0]) {
            Step0(v, s[0], s[1]);
        }
        if (s[1]) {
            Step1(v, x, y, s[1]);//false false false
        }
    } else {
        if (s[0]) {
            Step0(v, s[0], s[1]);
        }
        if (s[1]) {
            Step3(v, s[1]);//false false false
        }
    }
}

if (y < 0) {
    if (s[0]) {
        Step0(v, s[0], s[1]);
    }
    if (s[1]) {
        Step2(v, s[1], s[2]);
    }
    if (s[2]) {
        Step1(v, x, y, s[2]);
    }
}


}

bool Group::ifStop(){
    if(!(s[0]|s[1]|s[2]))return true;
    return false;
}






