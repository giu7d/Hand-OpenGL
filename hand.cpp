#include <iostream>
#include <GL/glut.h>
#include <unistd.h>
#include "hand.h"
#include "global.h"

Hand::Hand(float gros)
  : grossura(gros),
    mindinho(4*grossura,grossura),
    anelar(6*grossura,grossura),
    maior(7*grossura,grossura),
    indicador(6*grossura,grossura),
    dedao(4*grossura,grossura)
{
    for (int i=0;i<5;i++)
    {
        curvatura[i] = 0;
        zRotation[i] = 0;
    }
}

void Hand::draw()
{   
	bool change = false;

	if (swingSideWays){
		swingSideWays = false;
		change = true;
	}
  glPushMatrix();
    glTranslatef(0.0,6.0*grossura,0.0);
    glPushMatrix();
      glTranslatef(-3*grossura,0.0,0.0);
      glutSolidSphere(grossura,8,8);
      glRotatef(curvatura[0]*0.9,1.0,0.0,0.0);
      mindinho.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-1.5*grossura,0.0,0.0);
      glutSolidSphere(grossura,8,8);
      glRotatef(curvatura[1]*0.9,1.0,0.0,0.0);
      anelar.draw();
    glPopMatrix();
    glPushMatrix();
      glutSolidSphere(grossura,8,8);
      glRotatef(curvatura[2]*0.9,1.0,0.0,0.0);
      maior.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(1.5*grossura,0.0,0.0);
      glutSolidSphere(grossura,8,8);
      glRotatef(curvatura[3]*0.9,1.0,0.0,0.0);
			glRotatef(zRotation[3]*0.9, 0, 0, 1);
			if (change)
			{
        swingSideWays = true;
			}
			indicador.draw();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(2*grossura,-4*grossura,0.0);
      glRotatef(-80,0.0,0.0,1.0);
      glRotatef(-20,0.0,1.0,0.0);
      glRotatef(curvatura[4]*0.5,1.0,0.0,0.0);
      glScalef(1.5,1,1);
      glutSolidSphere(grossura,8,8);
			if (change)
			{
				swingSideWays = false;
				change = false;
      }
			dedao.draw();
    glPopMatrix();
  glPopMatrix();
  glPushMatrix();
      glTranslatef(-0.75*grossura,3.0*grossura,0.0);
      glScalef(5.5*grossura,6.0*grossura,1.25*grossura);
      glutSolidCube(1.0);
  glPopMatrix();
}

void Hand::setCurve(int dedo,float curv)
{
    curvatura[dedo] = curv;

    switch(dedo)
    {
        case 0: mindinho.setCurve(curv); break;
        case 1: anelar.setCurve(curv); break;
        case 2: maior.setCurve(curv); break;
        case 3: indicador.setCurve(curv); break;
        case 4: dedao.setCurve(curv); break;
    }
}

float Hand::getCurve(int dedo)
{
 return curvatura[dedo];
}

void Hand::open(bool tudoJunto)
{
    if (tudoJunto)
        for (int j=getCurve(1);j>=0;j-=5)
        {
            for (int i=4;i>=0;i--)
            {
                setCurve(i,j);

            }
            display();
        }
    else
        for (int i=4;i>=0;i--)
        {
            for (int j=getCurve(i);j>=0;j-=5)
            {
                setCurve(i,j);
                display();
            }
        }

}

void Hand::close(bool tudoJunto)
{
    if (tudoJunto)
    for (int j=getCurve(1);j<=100;j+=5)
    {
        for (int i=0;i<5;i++)
        {
            setCurve(i,j);
        }
        display();
    }
    else
    for (int i=0;i<5;i++)
    {
        for (int j=getCurve(i);j<=100;j+=5)
        {
            setCurve(i,j);
            display();
        }
    }
}

void Hand::bye()
{
    open(true);
    for(int j = 0 ;j < 3 ; j++)
    {
        ang3 += 5;
        display();
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0 ;j < 6 ; j++)
        {
            ang3 -= 5;
            display();
        }
        for(int j = 0 ;j < 6 ; j++)
        {
            ang3 += 5;
            display();
        }
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang3 -= 5;
        display();
    }
}

void Hand::fuck()
{
    for(int i = 0 ; i < 180; i+=20)
    {
        ang += 20;
        display();
    }

    close(true);
    for (int j=getCurve(2);j>=0;j-=20)
    {
        setCurve(2,j);
        display();
    }
}

void Hand::hangloose()
{
    close(true);
    for (int j=getCurve(2);j>=0;j-=20)
    {
        setCurve(0,j);
        setCurve(4,j);
        ang3 += 3;
        display();
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang += 5;
        display();
    }
    for(int i = 0; i< 3; i++)
    {
        for(int j = 0 ;j < 6 ; j++)
        {
            ang -= 5;
            display();
        }
        for(int j = 0 ;j < 6 ; j++)
        {
            ang += 5;
            display();
        }
    }
    for(int j = 0 ;j < 3 ; j++)
    {
        ang -= 5;
        display();
    }
    for(int j = 0 ;j < 6 ; j++)
    {
        ang3 -= 3;
        display();
    }
}

void Hand::vemProPau()
{
    open(true);
    for(int i = 0 ; i < 180; i+=20)
    {
        ang += 20;
        ang2 -=10;
        display();
    }
    for (int j=getCurve(1);j<=30;j+=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurve(i,j);
        }
        display();
    }
    for (int j=30;j>=0;j-=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurve(i,j);
        }
        display();
    }

    for (int j=getCurve(1);j<=30;j+=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurve(i,j);
        }
        display();
    }

    for (int j=30;j>=0;j-=10)
    {
        for (int i=0;i<4;i++)
        {
            setCurve(i,j);
        }
        display();
    }
}

void Hand::home()
{

    open(true);
    
    for (int i = 0; i < 5; i++)
    {
        zRotation[i] = 0;
    }

    if (ang < 0)
        ang += 360;
    if (ang2< 0)
        ang2+= 360;
    if (ang3< 0)
        ang3+= 360;


    while (ang > 0)
    {
        ang-= 10;
        display();
    }
    ang = 0;
    while (ang2 > 0)
    {
        ang2-= 10;
        display();
    }
    ang2 = 0;
    while (ang3 > 0)
    {
        ang3-= 10;
        display();
    }
    ang3 = 0;
    display();

}

void Hand::dedoDuro()
{
    home();
    for (int i = 0; i < 91; i++)
    {
        ang = i/10;
        ang2 = i;
        ang3 = i;
        display();
    }
    close(true);
    display();

    for (int i = getCurve(3); i >= 0; i-=10)
    {
        setCurve(3, i);
        display();
    }

    // 
    // Shake
    // 
    bool isShaking = true;
    for (int i = 0; i < 6; i++)
    {
        ang = (isShaking) ? ang + 5 : ang -5;
        isShaking = !isShaking;
        display();
        usleep(100000);
    }
}

void Hand::positivo()
{
    home();
    for (int i = 0; i < 16; i++)
    {
        ang = i/2;
        ang2 = i*5;
        ang3 = i*5;
        display();
    }
    close(true);
    display();

    // 
    // Open Thumb
    // 
    for (int i = getCurve(4); i >= 0; i-=10)
    {
        setCurve(4, i);
        display();
    }
}


void Hand::chavesPattern()
{
    home();
    for (int i = 0; i < 100; i++)
    {
        ang2 = i*0.6f;
        display();
    }
    close(true);
    display();

    for (int j = 0; j < 6; j++){
        for (int i = getCurve(4); i >= 0; i-=10)
        {
            swingSideWays = true;
            setCurve(3, i);
            display();
            usleep(10000);
        }
        for (int i = getCurve(4); i <= 40; i+=10)
        {
            swingSideWays = false;
            setCurve(3, i);
            display();
            usleep(10000);
        }
    }

}

void Hand::nao()
{
    home();
    close(true);
    // Indicador
    setCurve(3, 0);
    display();

    for (int j = 0; j < 6; j++)
    {
        
        for (int i = -10 ; i >= 10; i++)
        {
            zRotation[3] = i;
            swingSideWays = true;
            display();
            usleep(50000);
        }

        for (int i = getCurve(3); i >= -10; i--)
        {
            zRotation[3] = i;
            swingSideWays = false;
            display();
            usleep(50000);
        }
    }
    zRotation[3] = 0;
    display();
}

