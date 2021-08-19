#ifndef P3_VEC_H
#define P3_VEC_H

float Cos(float a);
float Sin(float a);
float Tan(float a);

class Vec {
   private:
    float x, y;

   public:
    Vec(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    Vec operator+(Vec dv) {  //prepare to move.
        return (Vec(x + dv.getX(), y + dv.getY()));
    }

    Vec operator-(Vec dv) {
        return (Vec(x - dv.getX(), y - dv.getY()));
    }

    Vec operator*(float scale) {  //prepare for geometric zoom.
        return (Vec(x * scale, y * scale));
    }

    float operator*(Vec v) {  //calc scalar product.
        return x * v.getX() + y * v.getY();
    }

    Vec operator<<(float ang) {  //anti-clockwise rotation. #use degree as unit for our convinience.
        return (Vec(x * Cos(ang) - y * Sin(ang), y * Cos(ang) + x * Sin(ang)));
    }

    Vec operator>>(float ang) {
        return (this->operator<<(-ang));
    }

    void operator+=(Vec dv) {  //prepare to move.
        x += dv.getX();
        y += dv.getY();
    }

    void operator-=(Vec dv) {
        x -= dv.getX();
        y -= dv.getY();
    }

    void operator*=(float scale) {  //prepare for geometric zoom.
        x *= scale;
        y *= scale;
    }

    void operator<<=(float ang) {  //anti-clockwise rotation. #use degree as unit for our convenience.
        float tempX = x * Cos(ang) - y * Sin(ang);
        y = y * Cos(ang) + x * Sin(ang);
        x = tempX;
    }

    void operator>>=(float ang) {
        *this <<= -ang;
    }
};

#endif  //P3_VEC_H
