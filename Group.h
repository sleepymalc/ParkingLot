//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_GROUP_H
#define P3_GROUP_H

#include <vector>

#include "ColoredFig.h"
#include "Figure.h"

using namespace std;

class Group : public Figure {
   protected:
    vector<ColoredFig*> figs;
    bool s[3] = {true, false, false};
    bool s0[3] = {true, false, false};
    int timer = 0;
    float eff;
    float gesture = 90;
    Vec dre;

   public:
    void setAnchor(Vec anchor) override;
    float getAng();
    void newAng(float ang);
    void moveAnchorto(Vec newanchor) override;
    void draw() override;
    void zoom(float k) override;
    void move(Vec dir) override;
    virtual void moveto(Vec des);
    void rotate(float ang) override;
    virtual void effect() = 0;
    void moveV(Vec p);
    bool getS(int n) { return s0[n - 1]; }
    void setS(int n, bool v) { s0[n - 1] = v; }
    void resetS() {
        s0[0] = true;
        s0[1] = false;
        s0[2] = false;
    }
    Vec getdre() { return dre; }
    bool ifStop();
    ~Group(){};
};

#endif  //P3_GROUP_H
