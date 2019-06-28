#include <iostream>
#include <GL/glut.h>
#include "finger.h"

Finger::Finger(float lenght, float width)
  : base(lenght*0.4, width), 
    middle(lenght*0.35, width), 
    tip(lenght*0.25, width)
{
  Finger::base.setConnect(&middle, 0.0);
  Finger::middle.setConnect(&tip,0.0);
}

void Finger:: draw()
{
  Finger::base.draw();
}

void Finger::setCurve(float curve)
{
  Finger::base.setAngle(curve*0.9);
  Finger::middle.setAngle(curve*0.9);
}

float Finger::getCurve()
{
  return (Finger::base.getAngle() * 0.9);
}