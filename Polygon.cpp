//
// Created by maxwell on 2019/11/28.
//
#include "Polygon.h"

#include <cmath>

#include "draw.h"

Polygon::Polygon(Vec anchor, Vec re, int N, float R, float r, float g, float b) {
    this->R = R;
    this->N = N;
    setRelation(re);
    setAnchor(anchor);
    setColor(r, g, b);
    float tmpx, tmpy;
    for (int i = 0; i < N; i++) {
        tmpx = R * Cos(360 * i / N);
        tmpy = R * Sin(360 * i / N);
        Vs.push_back({tmpx, tmpy});
    }
}

void Polygon::draw() {
    color();
    beginDraw();
    for (auto i : Vs) {
        point(getpoint() + i);
    }
    endDraw();
}

void Polygon::zoom(float k) {
    zoomRe(k);
    for (auto i : Vs) {
        i *= k;
    }
}

void Polygon::rotate(float ang) {
    turnRe(ang);
    for (auto i : Vs) {
        i <<= ang;
    }
}

void Polygon::transform(int k, int &t) {
    if (N == k) return;
    float delta;
    if (N < k) {
        delta = 360 * (1.0 / N - 1.0 / (N + 1));
        if (t <= 0) {
            t = 66;
            Vs.push_back(*(Vs.end() - 1));
        }
        for (int i = 1; i < (int)Vs.size() - 1; i++) {
            Vs.at(i) >>= i * delta / 66;
        }
        Vs.at(Vs.size() - 1) <<= delta / 66;
        t--;
        if (t <= 0) {
            N++;
        }
    } else if (N > k) {
        delta = 360 * (1.0 / (N - 1) - 1.0 / N);
        if (t <= 0) {
            t = 66;
        }
        for (int i = 1; i < (int)Vs.size() - 1; i++) {
            Vs.at(i) <<= i * delta / 66;
        }
        Vs.at(Vs.size() - 1) >>= delta / 66;
        t--;
        if (t <= 0) {
            N--;
            Vs.pop_back();
        }
    }
}

void Polygon::transcolor() {
    static float red = rand() % 10;
    setColor((sin(red / 500) + 1) / 2, .5, .5);
    red++;
}
//todo: understand why this is correct:
//void Polygon::transform(int k){
//    if(N==k)return;
//    float delta;
//    static int t = 0;
//    if(N<k){
//        delta = 360*(1.0/N-1.0/(N+1));
//        if(t<=0){t = 66;Vs.push_back(*(Vs.end()-1));}
//        for(int i=1;i<(int)Vs.size()-1;i++){
//            Vs.at(i)>>=i*delta/66;
//        }
//        Vs.at(Vs.size()-1)<<=delta/66;
//        t--;
//        if(t<=0){N++;}
//    }
//    else if(N>k){
//        delta = 360*(1.0/(N-1)-1.0/N);
//        if(t<=0){t = 66;}
//        for(int i=1;i<(int)Vs.size()-1;i++){
//            Vs.at(i)<<=i*delta/66;
//        }
//        Vs.at(Vs.size()-1)>>=delta/66;
//        t--;
//        if(t<=0){N--;Vs.pop_back();}
//    }
//
//}