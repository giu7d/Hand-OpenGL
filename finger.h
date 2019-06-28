#ifndef Finger_H
#define Finger_H

#include "bone.h"

class Finger
{
  public:
    Finger(float lenght, float width);
    void draw();
    void setCurve(float curve);
    float getCurve();

  protected:
    Bone base, middle, tip;
};

#endif