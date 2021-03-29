//
// Created by maxwell on 2019/11/28.
//

#include "Teleport.h"




Teleport::Teleport(Vec anchor) {
    setAnchor(anchor);
    setRelation({0,0});
    bound = Circle(anchor,{0,0},30,0.6,0.7,1.0,0);
    self = Polygon(anchor,{0,0},6,15,0.2,0.2,0.2);
    figs.push_back(&bound);
    figs.push_back(&self);
    this->zoom(0.6);
    eff = 1;timer = 0;
}

void Teleport::effect(){
    srand(time(NULL));
    if(this->self.getN()>8||this->self.getN()<4){eff*=-1;}
    if(eff>0){
        this->self.transform(9,timer);
    }
    if(eff<0){
        this->self.transform(3,timer);
    }
    this->self.transcolor();
}