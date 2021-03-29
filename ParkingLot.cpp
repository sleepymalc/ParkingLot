//
// Created by maxwell on 2019/12/7.
//
#include "ParkingLot.h"
#include "Car.h"
#include "Rocket.h"
#include "UFO.h"
#include "Teleport.h"

bool judge(Group* source,Group* target){
    float A,B,C,x0,y0,x1,y1;
    if(target==NULL)return false;
    x0 = source->getpoint().getX()+source->getdre().getX();
    y0 = source->getpoint().getY()+source->getdre().getY();
    x1 = target->getpoint().getX()+target->getdre().getX();
    y1 = target->getpoint().getY()+target->getdre().getY();
    if(Vec(x1-x0,y1-y0)*Vec(Cos(source->getAng()),Sin(source->getAng()))<=0)return false;
    A = Tan(source->getAng());
    B = 1;
    C = y0-A*x0;
    if((abs(A*x1-B*y1+C)/sqrt(A*A+B*B)<=20))return true;
    else return false;
}

float dis(Group* source,Group* target){
    Vec loc1,loc2;
    loc1 = source->getpoint()+source->getdre();
    loc2 = target->getpoint()+target->getdre();
    return     sqrt(pow(loc1.getX()-loc2.getX(),2)+pow(loc1.getY()-loc2.getY(),2));
}

//enter anchor: -175,-180,width:from -200 to 150,height:from -190 to 170
void ParkingLot::drawBG() {
    glColor3f(0,0,0);
    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    Vec o[6] = {{-200,-190},{-200,170},{150,170},{150,-170},{-150,-170},{-150,-190}};
    for(int i=0;i<6;i++){
        point(o[i]);
    }
    glEnd();
    glBegin(GL_LINES);
    for(int i=0;i<6;i++){
        point({-150.0f+50.0f*i,170});
        point({-150.0f+50.0f*i,100});
        point({-150.0f+50.0f*i,-100});
        point({-150.0f+50.0f*i,-170});
    }
    glEnd();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_R);
    glRectf(-130,-10,80,10);
    glEnd();
}
//this draw the parkinglot self;
void ParkingLot::drawDoor(int &open) {
    static Rectangle door({-200,-190},{0,0},{50,0},{0,-10},0,0,0);
    door.draw();
    if(open==1){
        door.rotate(-1);
        if(door.getSide().getX()<0)open = 0;
    }
    if(open==-1){
        door.rotate(1);
        if(door.getSide().getY()>0)open = 0;
    }
}
//this control the door;
void ParkingLot::drawV() {
    for(auto i : Vs){
        i->draw();
    }
    for(auto i : Ts){
        i->draw();
    }
}
//this draw all vehicles;
void ParkingLot::effV() {
    for(auto i : Vs){
        i->effect();
    }
    for(auto i : Ts){
        i->effect();
    }
}
//this add all characteristic effects;
void ParkingLot::genP(){
    Vec position[12];
    for(int i=0;i<6;i++){
        position[i]={(float)i,-1};
        position[i+6]={(float)i,1};
    }
    for(int i=0;i<50;i++){
        int j=rand()%12;
        int k=rand()%12;
        if(j==k){
            continue;
        }
        Vec temp=position[j];
        position[j]=position[k];
        position[k]=temp;
    }
    for(int i=0;i<12;i++){
        Ps.push_back(position[i]);
    }
    //Below pre-decide where to put Teleports, i.e.Be occupied.
    srand(time(NULL));
    int tnum = rand()%4+1;Group* tmp;float tmpx,tmpy;
    for(int i=0;i<tnum;i++){
        tmpx = (Ps.at(i).getX()*50-125)*Ps.at(i).getY();
        tmpy = Ps.at(i).getY()*(-130);
        tmp = new Teleport({tmpx,tmpy});
        Ts.push_back(tmp);
    }
}
//this decide the positions and also deal with teleports occupying positions;
void ParkingLot::genV(){
    srand(time(NULL));
    static int open = 1;
    static int cur = 0;
    static int t = 0;
    //open is the judgement condition, 0 means opened, then add new car; 1 means opening; -1 means closing;
    if(open==0&&cur<=12-(int)Ts.size()){
        if(t>rand()%100+66){
            Group * tmp ;
            int type = rand()%3;
            switch (type){
                case 0:
                    tmp = new Rocket({-175,-180});break;
                case 1:
                    tmp = new Car({-175,-180});break;
                case 2:
                    tmp = new UFO({-175,-180});break;
            }
            t = 0;
            cur++;
            if(cur>12-(int)Ts.size()){open = -1;}
            else{Vs.push_back(tmp);}
        }
    }
    this->drawDoor(open);
    t++;
}
//this generate all the cars(regarding the door's state);
void ParkingLot::moveV() {
    int j = 0;
    for(auto i : Vs){
        i->moveV(Ps.at(j+Ts.size()));
        j++;
    }
}
//this calc vehecles' movement;
void ParkingLot::boomV(Rocket* player) {
    vector<Group*>::iterator it;
    vector<Vec>::iterator itp;
    for(it=Vs.begin(),itp = Ps.begin();it!=Vs.end();++it,++itp){
        if(Vs.size()>0){
            if(judge(player,*it) && player->getshoot_t()>=14){
                Vs.erase(it);
                Ps.erase(itp);
                break;
                //player->setshoot(false);
            }
        }
    }

}
//use to check boomed vehicles;
bool ParkingLot::seekV(Rocket *player) {
    vector<Group *>::iterator it;
    for (it = Vs.begin(); it != Vs.end(); ++it) {
        if (dis(*it, player) <= 2 * 15) {
            return true;
        }
    }
    return false;
}
//use to check collipsed vehicles;
int ParkingLot::checkV(){
    int count = 0;
    for(auto i : Vs){
        if(i->ifStop())count++;
    }
    return count;
}

Vec ParkingLot::getT() {
    return Ps.at(0);
}



