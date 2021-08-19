//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_TELEPORT_H
#define P3_TELEPORT_H

#include "Arc.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Group.h"
#include "Line.h"
#include "Polygon.h"
#include "Rectangle.h"
#include "Semi.h"
#include "Triangle.h"

class Teleport : public Group {
   private:
    Circle bound;
    Polygon self;

   public:
    Teleport(Vec anchor);
    void effect() override;
};
#endif  //P3_TELEPORT_H
