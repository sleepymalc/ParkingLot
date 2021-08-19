#ifndef P3_UFO_H
#define P3_UFO_H

#include "../ColoredFig/Arc.h"
#include "../ColoredFig/Circle.h"
#include "../ColoredFig/Ellipse.h"
#include "../ColoredFig/Line.h"
#include "../ColoredFig/Polygon.h"
#include "../ColoredFig/Rectangle.h"
#include "../ColoredFig/Semi.h"
#include "../ColoredFig/Triangle.h"
#include "../Group.h"

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
