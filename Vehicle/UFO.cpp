#include "UFO.h"

UFO::UFO(Vec anchor) {
    dre = {0, 0};
    this->setAnchor(anchor);
    this->setRelation({0, 0});
    this->body = Semi(anchor, {0, 0}, {15, 0}, -180, 0.078, 0.7617, 0.9648, 0);
    this->bodyupleft = Arc(anchor, {0, 48}, {-14, -48}, -16.36, 0.078, 0.7617, 0.9648, 0);
    this->bodyupright = Arc(anchor, {0, 48}, {14, -48}, 16.36, 0.078, 0.7617, 0.9648, 0);
    this->bodyring = Ellipse(anchor, {0, -0.28}, {20, 5}, 0, 0.8, 0.8, 0.8, 0);
    this->bodydownright = Arc(anchor, {0, 17.91}, {12, -22}, 30.14, 0.6, 0.6, 0.6, 0);
    this->bodydownleft = Arc(anchor, {0, 17.91}, {-12, -22}, -30.14, 0.6, 0.6, 0.6, 0);
    this->light = Triangle(anchor, {0, 5}, {-10, -25}, {20, 0}, 1, 1, 0.632, 1);
    this->lightdown = Ellipse(anchor, {0, -20}, {10, 1.789}, 0, 0.6328, 0.6328, 0.36, 1);
    this->defense = Circle(anchor, dre, 17, 0.77734, 0.8632, 0.9414, 0);

    figs.push_back(&defense);
    figs.push_back(&light);
    figs.push_back(&lightdown);
    figs.push_back(&bodydownright);
    figs.push_back(&bodydownleft);
    figs.push_back(&bodyring);
    figs.push_back(&body);
    figs.push_back(&bodyupleft);
    figs.push_back(&bodyupright);
    eff = 0.4;
    this->zoom(1.2);
}
void UFO::effect() {
    if (timer % 33 == 32) {
        eff *= -1;
    }
    this->body.rotate(eff);
    this->bodyupright.rotate(eff);
    this->bodydownleft.rotate(eff);
    this->bodyring.rotate(eff);
    this->bodyupleft.rotate(eff);
    this->bodydownright.rotate(eff);
    timer++;
    if (timer > 666666) timer = 0;
}

void UFO::rotate(float ang) {
    this->turnRe(ang);
    for (auto i : figs) {
        i->setAnchor(getpoint());
    }
}
