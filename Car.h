//
// Created by maxwell on 2019/11/28.
//
#ifndef P3_CAR_H
#define P3_CAR_H

#include "Group.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Semi.h"
#include "Arc.h"
#include "Line.h"
#include "Polygon.h"
#include "Ellipse.h"


class Car : public Group {
private:
    Rectangle handle1,handle2,bottom,body,windmillstick,windmillbody;
    Triangle bodyleft,bodyrightup,bodyrightdown,windmillswing1,windmillswing2,windmillswing3,windmillswing4;
    Circle wheelleft,wheelright,windmill;
    Semi bodyrup,bodyrdown;
    Circle defense;
public:
    Car(Vec anchor= {0,0});
    void effect() override;
};

#endif //P3_CAR_H
