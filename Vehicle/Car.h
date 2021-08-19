#ifndef P3_CAR_H
#define P3_CAR_H

#include "../ColoredFig/Arc.h"
#include "../ColoredFig/Circle.h"
#include "../ColoredFig/Ellipse.h"
#include "../ColoredFig/Line.h"
#include "../ColoredFig/Polygon.h"
#include "../ColoredFig/Rectangle.h"
#include "../ColoredFig/Semi.h"
#include "../ColoredFig/Triangle.h"
#include "../Group.h"

class Car : public Group {
   private:
    Rectangle handle1, handle2, bottom, body, windmillstick, windmillbody;
    Triangle bodyleft, bodyrightup, bodyrightdown, windmillswing1, windmillswing2, windmillswing3, windmillswing4;
    Circle wheelleft, wheelright, windmill;
    Semi bodyrup, bodyrdown;
    Circle defense;

   public:
    Car(Vec anchor = {0, 0});
    void effect() override;
};

#endif  //P3_CAR_H
