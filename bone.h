#ifndef Bone_H
#define Bone_H

class Bone {
  
  public:
    Bone(float h, float w);
    void draw();
    void setConnect(Bone *bone, float ang);
    void setAngle(float ang);
    float getAngle();

  protected:
    float width;
    float height;
    float angle;
    Bone *connect;

};

#endif