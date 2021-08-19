#include "classes.h"

#include "general.h"

float pi_angle(float a) { return ((a / 180) * PI); }
float Sin(float a) { return sin(pi_angle(a)); }
float Cos(float a) { return cos(pi_angle(a)); }
float Tan(float a) { return tan(pi_angle(a)); }
