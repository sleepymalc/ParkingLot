//
//  main.cpp
//  project3 partB
//
//  Created by 胡平邦 on 2019/12/16.
//  Copyright © 2019 胡平邦. All rights reserved.
//
#define GL_SILENCE_DEPRECATION
#include "general.h"
#include "classes.h"

using namespace std;

namespace data {
    Game game;
}


void TimeStep(int n) {
    glutTimerFunc(33,TimeStep,1);
    glutPostRedisplay();
}

void my_Draw(){//$ where to declare static rgb 0~1!!!!!
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    data::game.Init();
    data::game.Draw();
    data::game.Change();
    data::game.ifShot();
    data::game.ifImp();
    data::game.ifLose();
    data::game.ifWin();
    glutSwapBuffers();
    glFlush();
}

void my_Keyboard(unsigned char key, int x, int y){
    static float v = 2;
    switch(key){
        case 27:
            exit(0);break;
        case ' ':
            data::game.getP()->setshoot(1);
            break;
        case 'w':
            data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
            break;
        case 's':
            data::game.getP()->move({-v*Cos(data::game.getP()->getAng()),-v*Sin(data::game.getP()->getAng())});
            break;
        case 'a':
            data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
            data::game.getP()->rotate(5);data::game.getP()->newAng(5);
            break;
        case 'd':
            data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
            data::game.getP()->rotate(-5);data::game.getP()->newAng(-5);
            break;
    }
}

void my_Mouse(int x,int y,int w,int h){
    ;
}

void my_sKeyboard(int key, int x, int y){
        static float v = 2;

        switch(key){
            case GLUT_KEY_UP:
                data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
                break;
            case GLUT_KEY_DOWN:
                data::game.getP()->move({-v*Cos(data::game.getP()->getAng()),-v*Sin(data::game.getP()->getAng())});
                break;
            case GLUT_KEY_LEFT:
                data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
                data::game.getP()->rotate(5);data::game.getP()->newAng(5);
                break;
            case GLUT_KEY_RIGHT:
                data::game.getP()->move({v*Cos(data::game.getP()->getAng()),v*Sin(data::game.getP()->getAng())});
                data::game.getP()->rotate(-5);data::game.getP()->newAng(-5);
                break;
            case GLUT_KEY_HOME:
                data::game.getP()->moveto({(float)(x-999)/3.75f,(float)(y-716.5)/-3.56f});break;
            case GLUT_KEY_END:
                data::game.getP()->setshoot(1);
                break;
        }
}

void ChangeSize(int w, int h)
{
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-200.0f*w/h, 200.0f*w/h, -220.0f, 200.0f, -100.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc,char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE);//use double buffers
    glutInitWindowSize(2000,1500);
    glutInitWindowPosition(400,150);
    glutCreateWindow("ParkingLot");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutReshapeFunc(ChangeSize);
    glEnable(GLUT_MULTISAMPLE);
    glutDisplayFunc(my_Draw);
    glutMouseFunc(my_Mouse);
    glutKeyboardFunc(my_Keyboard);
    glutSpecialFunc(my_sKeyboard);
    glutTimerFunc(33,TimeStep,1);
    glutMainLoop();
    return 0;
}

