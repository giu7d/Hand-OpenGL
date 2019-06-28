#ifndef Hand_H
#define Hand_H

#include "finger.h"

class Hand
{
  public:
    Hand(float grossura);
    void draw();
    void setCurve(int dedo,float curv);
    float getCurve(int dedo);
    void open(bool tudoJunto = false);
    void close(bool tudoJunto = false);
    void bye();
    void fuck();
    void hangloose();
    void vemProPau();
    void home();
    void dedoDuro();
    void positivo();
    void chavesPattern();
    void nao();



  
  protected:
    float curvatura[5];
    float zRotation[5];
    float grossura;
    Finger mindinho;
    Finger anelar;
    Finger maior;
    Finger indicador;
    Finger dedao;
};

#endif