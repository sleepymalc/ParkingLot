//
//  main.cpp
//  project3 partA
//
//  Created by 胡平邦 on 2019/12/16.
//  Copyright © 2019 胡平邦. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <string>
using namespace std;


class vehicles{
    double time;//store the time for departure
    double cost;//cost(formula=time/(type*10000)
    int type;//type:1->van,2->car,3->moto,4->bike
public:
    vehicles(int ty,double t,double c){time=t;type=ty;cost=c;};
    ~vehicles(){};
    int gettype(){return type;};
    double gettime(){return time;};
    double getcost(){return cost;};
};

typedef struct _floor{
    vehicles* ptr;
    int num;
}floor;
class parkinglot{
    floor *fptr;//fptr->ptr(floor array->slot array)
    int n;//total floors
public:
    parkinglot(int);
    ~parkinglot(){};
    int getspace(int);
    void departure(time_t);
    void park(vehicles,int,int);
    void dispark(vehicles,int,int);
};


parkinglot::parkinglot(int f){//form a parkinglot
    srand((int)time(NULL));
    n=f;
    fptr=(floor*)malloc(sizeof(floor*)*f);
    for(int i=0;i<f;i++){
        (fptr+i)->num=4+rand()%46;
        (fptr+i)->ptr=(vehicles*)calloc((fptr+i)->num, sizeof(vehicles));
    }
    for(int f=0;f<n;f++){
        for(int l=0;l<(fptr+f)->num;l++){
            vehicles v(0,0,0);
            park(v, f, l);
            }
        }
    }

void parkinglot::park(vehicles v,int f,int l){//park a vehicle
    vehicles temp=v;
    *((fptr+f)->ptr+l)=temp;
}

void parkinglot::dispark(vehicles v,int f,int l){//for a vehicle to departure(replace by a empty vehicle
    vehicles temp(0,0,0);
    *((fptr+f)->ptr+l)=temp;
    //v.~vehicles();
}

int parkinglot::getspace(int ty){//search for the empty slot  output format:first floor first slot: 1 0 1, second floor first slot: 2 0 1,etc.
    int f=0;
    if(n>1){
        if(ty==1||ty==2){
            f++;
            while(f<n){
                for(int i=((fptr)->num*(ty-1))/2.0;i<((fptr)->num*ty)/2.0;i++){
                    if(((fptr+f)->ptr+i)->gettype()==0){
                        return (f+1)*100+i+1;
                    }
                }
                f++;
            }
            return 0;
        }else{
                for(int i=((fptr)->num*(ty-3))/2.0;i<((fptr)->num*(ty-2))/2.0;i++){
                    if(((fptr+f)->ptr+i)->gettype()==0){
                        return (f+1)*100+i+1;
                    }
                }
                f++;
            return 0;
        }
    }else{
        for(int i=((fptr)->num*(ty-1))/4.0;i<((fptr)->num*ty)/4.0;i++){
            if(((fptr+f)->ptr+i)->gettype()==0){
                return (f+1)*100+i+1;
            }
        }
        return 0;
    }
    return 0;
}

void printarrival(vehicles tempv,int loc){
    string vtype[]={"Van","Car","Motorbike","Bicycle"};
    time_t t=time(0); char tmp[64]; clock_t start; start = clock();
    printf("-------------------------------\n");
    time(&t);
    strftime( tmp, sizeof(tmp), "  %Y/%m/%d %X %A  ",localtime(&t)); puts(tmp);
    printf("    %s\n The slot is at:\n          Floor %d Number %d\n\
-------------------------------\n",vtype[tempv.gettype()-1].c_str(),loc/100,loc-(loc/100)*100);
}


void printdeparture(vehicles tempv,int loc){
    string vtype[]={"Van","Car","Motorbike","Bicycle"};
        time_t t=time(0); char tmp[64]; clock_t start; start = clock();
        printf("-------------------------------\n");
        time(&t);
        strftime( tmp, sizeof(tmp), "  %Y/%m/%d %X %A  ",localtime(&t)); puts(tmp);
    printf("     %s\n Parking time: \n         %d seconds\n           Cost:  %d\n\
-------------------------------\n",vtype[tempv.gettype()-1].c_str(),(int)(tempv.getcost())*(tempv.gettype())/CLOCKS_PER_SEC,(int)tempv.getcost()/10000);
}

void parkinglot::departure(time_t now){
for(int f=0;f<n;f++){
    for(int l=0;l<(fptr+f)->num;l++){
        if(((fptr+f)->ptr+l)->gettype()!=0 && ((fptr+f)->ptr+l)->gettime()<=now){
            printdeparture(*((fptr+f)->ptr+l), f*100+l);
            dispark(*((fptr+f)->ptr+l),f,l);
            }
        }
    }
}


void demo(){
    int f=0,num=0;
    time_t t=0;
    printf("Floor:"); scanf("%d",&f);
    printf("Time(s):"); scanf("%ld",&t);
    parkinglot p(f);
    string vtype[]={"Van","Car","Motorbike","Bicycle"};
    clock_t start, temp;
    start = clock();
    temp=clock()-start;
    while(temp<t*CLOCKS_PER_SEC){
        temp=clock()-start;
        if(temp%(CLOCKS_PER_SEC)<=10&& rand()%100>=70){//generate a car for a second(p=0.7)
            int type=rand()%4+1;
            int loc=p.getspace(type);
            if(loc!=0){
                double _t=(rand()%9+1)*CLOCKS_PER_SEC;
                vehicles tempv(type,_t+temp,_t/type);//vehicles.time is the exactly time for this vehicles to leave
                p.park(tempv, loc/100-1,loc-(loc/100)*100-1);
                printarrival(tempv,loc);
                num++;
            }else{
                printf("No slot available for %s now..\n",vtype[type-1].c_str());
            }
        }
        p.departure(temp);
    }
    p.~parkinglot();
}

int main(int argc, const char * argv[]) {
    demo();
    return 0;
}

