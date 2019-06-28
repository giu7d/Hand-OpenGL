#include <iostream>
#include <GL/glut.h>
#include "bone.h"
#include "global.h"

Bone::Bone(float h, float w): width(w), height(h), connect(0) {}

void  Bone::setConnect(Bone *bone, float ang) 
{
  Bone::connect = bone;
  Bone::angle = ang;
}

void  Bone::setAngle(float ang)
{
  Bone::angle = ang;
}

float Bone::getAngle()
{
  return Bone::angle;
}

void  Bone::draw()
{
  glPushMatrix();  //salva o contexto(1)

    glTranslatef (0.0, Bone::height/2.0, 0.0); //vai para o meio do osso

    glPushMatrix();   //salva o contexto(2)
      glScalef (Bone::width, Bone::height, Bone::width);  //escala para o tamanho do osso
      glutSolidCube (Bone::width);    //desenha o osso
    glPopMatrix();    //restaura o contexto(2)

    glTranslatef (0.0, Bone::height/2.0, 0.0); // vai para a ponta do osso

    glutSolidSphere(0.85*Bone::width,8,8);        //desenha a bolinha

    if (Bone::connect)
    {
      if(!swingSideWays) {
        glRotatef(Bone::angle, 1.0, 0.0, 0.0); //rotaciona para o angulo da conexcao
      }
      Bone::connect->draw();              //desenha recursivamente
    }

  glPopMatrix();  //restaura o contexto(1)
}
