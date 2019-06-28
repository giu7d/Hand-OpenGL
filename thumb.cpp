#include <iostream>
#include <GL/glut.h>
#include "thumb.h"

Thumb::Thumb(float lenght, float width)
  : base(lenght*0.5, width), 
    tip(lenght*0.5, width)
{
  Thumb::base.setConnect(&tip, 0.0);
}

void Thumb:: draw()
{
  Thumb::base.draw();
}

void Thumb::setCurve(float curve)
{
  Thumb::base.setAngle(curve*0.9);
}

float Thumb::getCurve()
{
  return (Thumb::base.getAngle() * 0.9);
}