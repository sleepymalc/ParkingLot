#ifndef P3_TELEPORT_H
#define P3_TELEPORT_H

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../ColoredFig/Arc.h"
#include "../ColoredFig/Circle.h"
#include "../ColoredFig/Ellipse.h"
#include "../ColoredFig/Line.h"
#include "../ColoredFig/Polygon.h"
#include "../ColoredFig/Rectangle.h"
#include "../ColoredFig/Semi.h"
#include "../ColoredFig/Triangle.h"
#include "../Group.h"

class Teleport : public Group {
   private:
    Circle bound;
    Polygon self;

   public:
    Teleport(Vec anchor);
    void effect() override;
};
#endif  //P3_TELEPORT_H
