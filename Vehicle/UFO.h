//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_UFO_H
#define P3_UFO_H

#include "Arc.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Group.h"
#include "Line.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Semi.h"
#include "Triangle.h"

class UFO : public Group {
   private:
    Semi body;
    Triangle light;
    Arc bodyupleft, bodyupright, bodydownleft, bodydownright;
    Ellipse lightdown, bodyring;
    Circle defense;

   public:
    UFO(Vec anchor = {0, 0});
    void effect() override;
    void rotate(float ang) override;
};

#endif  //P3_UFO_H
