#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
 #define PI 3.1415926535898
using namespace std;

static int rightarm1 = -90, rightelbow1 = 0, leftarm1=-90,leftelbow1=0,body1=90,head1=0, shoulder1=0, hip1=0, rightknee1=90,  leftknee1=90;
static int rightarm2 = -90, rightelbow2 = 0, leftarm2=-90,leftelbow2=0,body2=90,head2=0, shoulder2=0, hip2=0, rightknee2=90, leftknee2=90;
static int rightarm3 = -90, rightelbow3 = 0, leftarm3=-90,leftelbow3=0,body3=90,head3=0, shoulder3=0, hip3=0, rightknee3=90, leftknee3=90;
static int rightarm11= -90, rightelbow11 = 0, leftarm11=20,leftelbow11=0,body11=0,head11=0, shoulder11=0, hip11=0, rightleg11=0, rightknee11=0, leftleg11=0, leftknee11=0,leftshoe11=0, rightshoe11=0;
static int rightarm33 = -90, rightelbow33 = 0, leftarm33=-90,leftelbow33=0,body33=90,head33=0, shoulder33=0, hip33=0, rightknee33=90, leftknee33=90;
static int rightarm22 = -90, rightelbow22 = 0, leftarm22=-90,leftelbow22=0,body22=90,head22=0, shoulder22=0, hip22=0, rightknee22=90,  leftknee22=90;
static int pup1=0, pup2=0, pup3=0;
static float movex1=0, movex2=0, movex3=0;
static float movey1=0, movey2=0, movey3=0;
GLfloat mat_specular[4];
GLfloat mat_shininess[1];
GLfloat light_position[4];
GLfloat white_light[4]={1,1,1,1};
GLfloat lmodel_ambient[4];

void light(){
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
}
void specular(float i, float j, float k, float l){
    mat_specular[0]=i;
    mat_specular[1]=j;
    mat_specular[2]=k;
    mat_specular[3]=l;
}
void position(float i, float j, float k, float l){
    light_position[0]=i;
    light_position[1]=j;
    light_position[2]=k;
    light_position[3]=l;
}
void ambience(float i, float j, float k, float l){
    lmodel_ambient[0]=i;
    lmodel_ambient[1]=j;
    lmodel_ambient[2]=k;
    lmodel_ambient[0]=l;
}
void displayWelcome(){

    glDisable(GL_LIGHTING);
    glColor3f(0.8,0.6,0.3);
// W
    glPushMatrix();                     // |
    glTranslatef(-1.0, 2.6, 0.0);
    glScalef(0.05, 0.6, 0);
    glutSolidCube(0.8);
    glPopMatrix();

    glPushMatrix();                     // /
    glTranslatef(-.9, 2.5, 0.0);
    glRotatef(-45, 0.0, 0.0, 1.0);
    glScalef(0.06,.4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     /* \ */
    glTranslatef(-.7, 2.5, 0.0);
    glRotatef(45, 0.0, 0.0, 1.0);
    glScalef(0.06,.4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // |
    glTranslatef(-.6, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();
//E
    glPushMatrix();                     // |
    glTranslatef(-.5, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(-.35, 2.84, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(-.35, 2.6, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // _
    glTranslatef(-.35, 2.4, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();
// L
    glPushMatrix();                     // |
    glTranslatef(-.1, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // _
    glTranslatef(0.02, 2.4, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();
//C
    glPushMatrix();                     // -
    glTranslatef(0.4, 2.84, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // |
    glTranslatef(0.27, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // _
    glTranslatef(0.4, 2.4, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();
// O
    glPushMatrix();                     // |
    glTranslatef(0.62, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(.8, 2.84, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // |
    glTranslatef(.96, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(.8, 2.4, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();
// M
    glPushMatrix();                     // |
    glTranslatef(1.11, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     /* \ */
    glTranslatef(1.2, 2.7, 0.0);
    glRotatef(45, 0.0, 0.0, 1.0);
    glScalef(0.06,.4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // /
    glTranslatef(1.4, 2.7, 0.0);
    glRotatef(-45, 0.0, 0.0, 1.0);
    glScalef(0.06,.4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();
//E
    glPushMatrix();                     // |
    glTranslatef(1.6, 2.6, 0.0);
    glScalef(0.05, .6, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(1.73, 2.84, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // -
    glTranslatef(1.73, 2.6, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();

    glPushMatrix();                     // _
    glTranslatef(1.73, 2.4, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glScalef(0.05, .4, 0);
    glutSolidCube(.8);
    glPopMatrix();
}

void loadScreen(){                      // For the stage set up
    displayWelcome();
    glEnable(GL_LIGHTING);
    glColor3f(0.8,0.6,0.3);
    specular(10,10,10,0);
    mat_shininess[0]=100;
    position(0,1,1,0);
    ambience(0.1,0.05,0.1,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    for(int i=-3;i<3.5;i+=1){
        for(int j=4;j>=-4;j-=8){
            if(j==-4){
                position(0,1,1,0);
            }
            glPushMatrix();
            glTranslatef(j,i,0);
            glScalef(0.2, 0.2, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(j,i+0.25,0);
            glScalef(0.2, 0.2, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(j,i-0.25,0);
            glScalef(0.2, 0.2, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();
        }

        glPushMatrix();
        glTranslatef(-3.9,i,0);
        glScalef(0.3, 0.3, 0);
        glutSolidSphere(0.5,20,5);
        glPopMatrix();
    }
    for(int i=-3.5;i<3.5;i+=1){
        for(float j=4.1;j>=-4.1;j-=8.2){
            glPushMatrix();
            glTranslatef(j,i,0);
            glScalef(0.3, 0.3, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(j,i+0.25,0);
            glScalef(0.3, 0.3, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(j,i-0.25,0);
            glScalef(0.3, 0.3, 0);
            glutSolidSphere(0.5,20,5);
            glPopMatrix();
        }
        glPushMatrix();
        glTranslatef(3.9,i,0);
        glScalef(0.3, 0.3, 0);
        glutSolidSphere(0.5,20,5);
        glPopMatrix();

    }
    glColor3f(0.2,0.2,0.2);
    specular(10,10,10,0);
    mat_shininess[0]=100;
    position(1,0,1,0);
    ambience(1,0.05,0.1,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
      for(float i=-3;i<-2.5;i+=0.4){
          for(float j=-2.7;j<4;j+=1.2){
            glPushMatrix();
            glTranslatef(j,i,0);
            glScalef(0.3, 0.3, 0);
            glutSolidTeapot(0.5);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(j-0.4,i,0);
            glRotatef(-180,0,1,0);
            glScalef(0.3, 0.3, 0);
            glutSolidTeapot(0.5);
            glPopMatrix();
        }
    }
    glPushMatrix();
    glTranslatef(-3,3,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.6,2.7,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.2,2.4,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.75,2.1,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3,1.8,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8,1.6,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4,1.5,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1,1.45,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6,1.45,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1,1.5,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6,1.65,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,1.8,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.45,2,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,2.3,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.15,2.6,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3.55,2.9,0);
    glRotatef(-180,0,0,1);
    glScalef(0.3, 0.3, 0);
    glutSolidCone(1,2,12,20);
    glPopMatrix();
}
void puppet1(){                             // First puppet
    glColor3f(0.5,0.3,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-2.0, 0.2, 0.0);
    glRotatef((GLfloat) shoulder1, 0.0, 0.0, 1.0);
    glScalef(1.3, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0, -1, 0.0);
    glRotatef((GLfloat) hip1, 0.0, 0.0, 1.0);
    glScalef(0.8, 0.35, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-2.0, 0.57, 0.0);
    glRotatef((GLfloat) head1, 0.0, 0.0, 1.0);
    glScalef(0.6, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5, 0.0, 0.0);
    glRotatef((GLfloat) leftarm1, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(2.5,0,0);
    glTranslatef(-2.28, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) leftelbow1, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0);
    glRotatef((GLfloat) rightarm1, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) rightelbow1, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();



    glColor3f(0.2,0.2,0.2);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-2.0, -0.4, 0.0);
    glRotatef((GLfloat) body1, 0.0, 0.0, 1.0);
    glScalef(1.3, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
//First puppet's left arm's rope
/*
    glPushMatrix();
    glTranslatef(-2.3, 3, 0.0);
    glRotatef((GLfloat) leftarm11-10, 0.0, 0.0, 1.0);
    glTranslatef(0, 1, 0);
    glScalef(0.05, 10, 0);
    glutSolidCube(0.8);
    glPopMatrix();
*/
    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-1.8, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) rightknee1, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-2.2, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) leftknee1, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();
}
void puppet2(){                             // Second puppet
    glColor3f(0.5,0.3,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(0, 0.2, 0.0);
    glRotatef((GLfloat) shoulder2, 0.0, 0.0, 1.0);
    glScalef(1.3, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -1, 0.0);
    glRotatef((GLfloat) hip2, 0.0, 0.0, 1.0);
    glScalef(0.8, 0.35, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glColor3f(0.2,0.2,0.2);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(0, -0.07, 0.0);
    glRotatef((GLfloat) body2, 0.0, 0.0, 1.0);
    glScalef(0.4, 0.8, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.5, 0.0);
    glRotatef((GLfloat) body2, 0.0, 0.0, 1.0);
    glScalef(0.8, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glColor3f(0.8,0.6,0.3);
    specular(10,10,10,0);
    mat_shininess[0]=100;
    position(1,0,1,0);
    ambience(0.1,0.05,0.1,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(0, 0.57, 0.0);
    glRotatef((GLfloat) head2, 0.0, 0.0, 1.0);
    glScalef(0.6, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat) leftarm2, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(-0.5,0,0);
    glTranslatef(0.7, 0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) leftelbow2, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat) rightarm2, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(-0.5,0,0);
    glTranslatef(0.7, 0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) rightelbow2, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(-0.2, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) rightknee2, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(0.2, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) leftknee2, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    specular(10,0,10,0);
    mat_shininess[0]=100;
    position(1,0,1,0);
    ambience(0.1,0.05,0.1,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();
}
void puppet3(){                         // Third puppet
    glColor3f(0.5,0.3,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(2, 0.2, 0.0);
    glRotatef((GLfloat) shoulder3, 0.0, 0.0, 1.0);
    glScalef(1.3, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -1, 0.0);
    glRotatef((GLfloat) hip3, 0.0, 0.0, 1.0);
    glScalef(0.8, 0.35, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glColor3f(0.2,0.2,0.2);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(2, -0.4, 0.0);
    glRotatef((GLfloat) body3, 0.0, 0.0, 1.0);
    glScalef(1.3, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(2, 0.57, 0.0);
    glRotatef((GLfloat) head3, 0.0, 0.0, 1.0);
    glScalef(0.6, 0.6, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef((GLfloat) leftarm3, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(-1.5,0,0);
    glTranslatef(1.69, 0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) leftelbow3, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5, 0.0, 0.0);
    glRotatef((GLfloat) rightarm3, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(1, 0.4, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glTranslatef(-2.5,0,0);
    glTranslatef(2.7, 0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) rightelbow3, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.15, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(1.8, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) rightknee3, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();

    glColor3f(0,0,0);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glDisable(GL_COLOR_MATERIAL);
    glPushMatrix();
    glTranslatef(2.2, -0.9, 0.0);
    glRotatef(180,0,0,1);
    glRotatef((GLfloat) leftknee3, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.9, 0.5, 0);
    glutSolidSphere(0.25,10,4);
    glPopMatrix();
    glColor3f(0.8,0.6,0.3);
    glEnable(GL_COLOR_MATERIAL);
    light();
    glTranslatef(1.5,0,0);
    glTranslatef(-1.3, 0.0, 0.0);
    glRotatef(180,0,0,0);
    glRotatef((GLfloat) 0, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.2, 0);
    glutSolidSphere(0.5,20,5);
    glPopMatrix();
    glPopMatrix();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glDisable(GL_LIGHTING);
    loadScreen();
    glEnable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(movex1,movey1,0);
    glTranslatef(2,0.57,0);
    glRotatef((GLfloat) pup1, 0.0, 0.0, 1.0);
    glTranslatef(-2,-0.57,0);
    puppet1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(movex3,movey3,0);
    glRotatef((GLfloat) pup3, 0.0, 0.0, 1.0);
    puppet3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(movex2,movey2,0);
    glRotatef((GLfloat) pup2, 0.0, 0.0, 1.0);
    puppet2();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}
void keyboard(unsigned char key, int x, int y)        //
{
switch (key) {
    case '1':
        movex1= movex1+0.1;
        if(movex1>1)
            movex1=0;
        glutPostRedisplay();
        break;
    case '!':
        movex1= movex1-0.1;
        if(movex1<-1)
            movex1=0;
        glutPostRedisplay();
        break;
    case '2':
        movey1= movey1+0.1;
        if(movey1>1)
            movey1=0;
        glutPostRedisplay();
        break;
    case '@':
        movey1= movey1-0.1;
        if(movey1<-1)
            movey1=0;
        glutPostRedisplay();
        break;
    case '3':
        movex2= movex2+0.1;
        if(movex2>1)
            movex2=0;
        glutPostRedisplay();
        break;
    case '#':
        movex2= movex2-0.1;
        if(movex2<-1)
            movex2=0;
        glutPostRedisplay();
        break;
    case '4':
        movey2= movey2+0.1;
        if(movey2>1)
            movey2=0;
        glutPostRedisplay();
        break;
    case '$':
        movey2= movey2-0.1;
        if(movey2<-1)
            movey2=0;
        glutPostRedisplay();
        break;
    case '5':
        movex3= movex3+0.1;
        if(movex3>1)
            movex3=0;
        glutPostRedisplay();
        break;
    case '%':
        movex3= movex3-0.1;
        if(movex3<-1)
            movex3=0;
        glutPostRedisplay();
        break;
    case '6':
        movey3= movey3+0.1;
        if(movey3>1)
            movey3=0;
        glutPostRedisplay();
        break;
    case '^':
        movey3= movey3-0.1;
        if(movey3<-1)
            movey3=0;
        glutPostRedisplay();
        break;
    case '7':
        pup1= (pup1+5)% 360;
        glutPostRedisplay();
        break;
    case '&':
        pup1=(pup1-5)%360;
        glutPostRedisplay();
        break;
    case '8':
        pup2=(pup2+5)% 90;
        glutPostRedisplay();
        break;
    case '*':
        pup2=(pup2-5)%90;
        glutPostRedisplay();
        break;
    case '9':
        pup3=(pup3+5)% 360;
        glutPostRedisplay();
        break;
    case '(':
        pup3=(pup3-5)%360;
        glutPostRedisplay();
        break;
    case 'e':
        head1 = (head1 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'd':
        rightarm1 = (rightarm1 + 5) % 100 - 20;
        glutPostRedisplay();
        break;
    case 'f':
        rightelbow1 = (rightelbow1 + 5) % 120;
        glutPostRedisplay();
        break;
    case 's':
        leftarm1 = -70+(leftarm1 + 5) % 120 - 20;
       // leftarm11 = (leftarm11 + 3) % 10 ;        // For the rope
        glutPostRedisplay();
        break;
    case 'a':
        leftelbow1 = (leftelbow1+5)% 120;
        glutPostRedisplay();
        break;
    case 'c':
        rightknee1 = 100+(rightknee1 + 5) % 90 - 30;
        glutPostRedisplay();
        break;
    case 'x':
        leftknee1 = 100+(leftknee1 + 5) % 90 -80;
        glutPostRedisplay();
        break;
    case 'y':
        head3 = (head3 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'j':
        rightarm3 = (rightarm3 + 5) % 100 - 20;
        glutPostRedisplay();
        break;
    case 'k':
        rightelbow3 = (rightelbow3 + 5) % 120;
        glutPostRedisplay();
        break;
    case 'h':
        leftarm3 = -70+(leftarm3 + 5) % 120 - 20;
        glutPostRedisplay();
        break;
    case 'g':
        leftelbow3 = (leftelbow3 + 5) % 120;
        glutPostRedisplay();
        break;
    case 'b':
        rightknee3 = 100+(rightknee3 + 5) % 90 -80;
        glutPostRedisplay();
        break;
    case 'n':
        leftknee3 = 100 +(leftknee3 + 5) % 90 -30;
        glutPostRedisplay();
        break;
    case 'q':
        head2 = (head2 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'o':
        rightarm2 = (rightarm2 + 5) % 100 - 20;
        glutPostRedisplay();
        break;
    case 'p':
        rightelbow2 = (rightelbow2 + 5) % 120;
        glutPostRedisplay();
        break;
    case 'i':
        leftarm2 = -70+(leftarm2 + 5) % 120 - 20;
        glutPostRedisplay();
        break;
    case 'u':
        leftelbow2 = (leftelbow2 + 5) % 120;
        glutPostRedisplay();
        break;
    case 'm':
        rightknee2 = 100+(rightknee2 + 5) % 90 - 80;
        glutPostRedisplay();
        break;
    case 'z':
        leftknee2 = 100+(leftknee2 + 5) % 90 - 30;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}
void init(void){
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
   // PlaySound("LOG.mp3", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
