#ifndef P3_FIGURE_H
#define P3_FIGURE_H

#include "Vec.h"

class Figure {
   protected:
    Vec anchor;
    Vec re;

   public:
    Figure() : anchor(0, 0), re(0, 0){};

    Vec getpoint();
    Vec getAnchor();

    virtual void setAnchor(Vec a);
    virtual void moveAnchorto(Vec a);

    void group_moveAnchorTo(Vec a);
    void zoomRe(float scale);
    void turnRe(float angle);
    void setRelation(Vec b);

    virtual void draw() = 0;
    virtual void move(Vec dir);
    virtual void rotate(float ang) = 0;
    virtual void zoom(float k) = 0;
};

#endif  //P3_FIGURE_H
