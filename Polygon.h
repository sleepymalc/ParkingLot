//
// Created by maxwell on 2019/11/28.
//

#ifndef P3_POLYGON_H
#define P3_POLYGON_H

#include <vector>

#include "ColoredFig.h"

using namespace std;

class Polygon : public ColoredFig {
   private:
    vector<Vec> Vs;
    int N;
    float R;

   public:
    Polygon(){};
    Polygon(Vec anchor, Vec re, int N, float R, float r, float g, float b);
    void draw() override;
    void zoom(float k) override;
    void rotate(float ang) override;
    void transform(int k, int &t);
    void transcolor();
    int getN() { return N; }
};

#endif  //P3_POLYGON_H
