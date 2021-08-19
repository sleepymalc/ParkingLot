//
// Created by maxwell on 2019/11/28.
//
#ifndef P3_FIGURE_H
#define P3_FIGURE_H

#include "Vec.h"

class Figure {
   protected:
    Vec anchor;
    Vec re;  //relation vector
    // Vec abs;//absolute vector
   public:
    Figure() : anchor(0, 0), re(0, 0){};
    Vec getAnchor();
    void zoomRe(float scale);
    void turnRe(float angle);
    virtual void setAnchor(Vec a);
    virtual void moveAnchorto(Vec a);
    void group_moveAnchorTo(Vec a);
    void setRelation(Vec b);
    Vec getpoint();
    //void updateAbs();
    virtual void draw() = 0;
    virtual void move(Vec dir);
    virtual void rotate(float ang) = 0;
    virtual void zoom(float k) = 0;
};

#endif  //P3_FIGURE_H
