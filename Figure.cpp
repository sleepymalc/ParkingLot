#include "Figure.h"

Vec Figure::getAnchor() {
    return anchor;
}

void Figure::moveAnchorto(Vec a) {
    re += anchor - a;
    anchor = a;
}

void Figure::group_moveAnchorTo(Vec a) {
    re += anchor - a;
    anchor = a;
}

void Figure::setAnchor(Vec a) {
    anchor = a;
}

void Figure::setRelation(Vec b) {
    re = b;
}

Vec Figure::getpoint() {
    return anchor + re;
}

void Figure::zoomRe(float scale) {
    re *= scale;
}

void Figure::turnRe(float angle) {
    re <<= angle;
}
void Figure::move(Vec dir) {
    anchor += dir;
}