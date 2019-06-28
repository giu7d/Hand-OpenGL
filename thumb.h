#ifndef Thumb_H
#define Thumb_H

#include "bone.h"

class Thumb
{
  public:
    Thumb(float lenght, float width);
    void draw();
    void setCurve(float curve);
    float getCurve();

  protected:
    Bone base, tip;
};

#endif