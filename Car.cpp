#include "Car.h"

Car::Car(Vec anchor){
    dre={7,0};
    
    this->setAnchor(anchor);
    this->setRelation({0,0});
    this->body=Rectangle(anchor, {-2,-6}, {19,0}, {0,14}, 0.5, 0.5, 0.5);
    this->bodyleft=Triangle(anchor, {-2,8}, {0,-14},{-4,14}, 0.5, 0.5, 0.5);
    this->bodyrdown=Semi(anchor, {16.14,-5.2},{0,-0.8}, 180, 0.5, 0.5, 0.5);
    this->bodyrightdown=Triangle(anchor, {16.4,-5.2}, {0,10.7}, {0.8,-11}, 0.5, 0.5, 0.5);
    this->bodyrightup=Triangle(anchor, {16.4,5.58}, {2,0.3}, {-1.2,-11.2}, 0.5, 0.5, 0.5);
    this->bodyrup=Semi(anchor, {16.14,6}, {0,2}, 180, 0.5, 0.5, 0.5);
    this->bottom=Rectangle(anchor, {-6,-8}, {0,-2}, {22,0}, 1, 1, 0);
    this->handle1=Rectangle(anchor, {-12.2,9.2}, {2.2,0.8}, {6.2,-19.2}, 1, 1, 0);
    this->handle2=Rectangle(anchor, {-18,8}, {8,0}, {0,2}, 1, 1, 0);
    this->wheelleft=Circle(anchor, {0,-12}, 2, 0, 1, 1);
    this->wheelright=Circle(anchor, {14,-12}, 2, 0, 1, 1);


    this->windmillstick=Rectangle(anchor, {15.5,15}, {1,0}, {0,-7}, 0, 1, 0);
    this->windmill=Circle(anchor, {16,15}, 0.5, 1, 1, 0);
    this->windmillswing1=Triangle(anchor, {16,15}, {2,2}, {2,-2}, 0, 0.519, 1);
    this->windmillswing2=Triangle(anchor, {16,15}, {-2,2}, {2,2}, 0, 0.519, 1);
    this->windmillswing3=Triangle(anchor, {16,15}, {-2,-2}, {-2,2}, 0, 0.519, 1);
    this->windmillswing4=Triangle(anchor, {16,15}, {2,-2}, {-2,-2}, 0, 0.519, 1);

    this->defense=Circle(anchor,dre, 14, 0.77734, 0.8632, 0.9414,0);
    
    figs.push_back(&defense);
    figs.push_back(&body);
    figs.push_back(&bodyleft);
    figs.push_back(&bodyrdown);
    figs.push_back(&bodyrightdown);
    figs.push_back(&bodyrightup);
    figs.push_back(&bodyrup);
    figs.push_back(&bottom);
    figs.push_back(&handle1);
    figs.push_back(&handle2);
    figs.push_back(&wheelleft);
    figs.push_back(&wheelright);
    figs.push_back(&windmillstick);
    figs.push_back(&windmillswing1);
    figs.push_back(&windmillswing2);
    figs.push_back(&windmillswing3);
    figs.push_back(&windmillswing4);
    figs.push_back(&windmill);
    
    this->eff=-2;
    this->rotate(90);
    this->zoom(1.5);
}

void Car::effect(){


    this->windmillswing1.rotate(eff);
    this->windmillswing2.rotate(eff);
    this->windmillswing3.rotate(eff);
    this->windmillswing4.rotate(eff);
    this->windmillswing1.turnRe(-eff);
    this->windmillswing2.turnRe(-eff);
    this->windmillswing3.turnRe(-eff);
    this->windmillswing4.turnRe(-eff);
    timer++;
    if(timer>666666)timer = 0;
}
