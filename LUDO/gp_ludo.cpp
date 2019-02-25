#include<stdio.h>
#include<cstdlib>
#include<graphics.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<time.h>
#include <windows.h>
#include<bits/stdc++.h>

using namespace std;

float posx=617.5,posy=392.5;
char val[10];
char fst[]="1st",snd[]="2nd",trd[]="3rd",frt[]="4th",bck[]="BACK",stt[]="START",ScoreBoard[]="-:ScoreBoard:-";

int waitingTime=100;  /*Play Speed 1.5 sec*/
int waitingTime2=2000;

int randval[3],randval_x=710,randval_y=20;
int p1=0,p2=0,p3=0,p4=0,x=0,y=0,first=0,second=0,third=0,bonus=0;
int ptype[4];

struct keep_pos
{
    int guti_no_1;
    int guti_no_2;
    int guti_no_3;
    int guti_no_4;
    float mid_x;
    float mid_y;
}*main_array;

struct guti_info
{
    int player;
    int initial_pos;
    int current_pos;
    int length;
    int start_pos;
    int turn_after;
    int turn_into;
    int end_pos;
}*guti;

struct calculation
{
    int priority;
    int which_guti;
}*randval_123,*randval_12,*randval_1;

void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

/*Function Declaration*/
inline void keep_position();
inline void guti_info();
inline void graphics_body();
inline void scoreboard();
inline void safe_zone_1();
inline void safe_zone_2();
inline void safe_zone_3();
inline void safe_zone_4();

inline int player_1_put_guti(int pos);
inline int player_2_put_guti(int pos);
inline int player_3_put_guti(int pos);
inline int player_4_put_guti(int pos);

inline int priority(int g,int v1,int v2,int v3);

inline void random_value();
inline int random_value_1(int gutino);
inline int random_value_12(int gutino);
inline int random_value_123(int gutino);
inline int run_guti(int g,int v);

inline int player_1();
inline int player_2();
inline int player_3();
inline int player_4();
inline int human_1();
inline int human_2();
inline int human_3();
inline int human_4();

inline void next();
inline void play();
inline void about();
inline void homeScreen();


/*Setting all positions*/
inline void keep_position()
{
    for(int pos=0; pos<=104; pos++)
    {
        if(pos<=104)
        {
            if(pos<5)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*pos);
                main_array[pos].mid_y=posy;
            }
            else if(pos<11)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*5);
                main_array[pos].mid_y=posy+(45*(pos-4));
            }
            else if(pos==11)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*6);
                main_array[pos].mid_y=posy+(45*6);
            }
            else if(pos<18)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*7);
                main_array[pos].mid_y=posy+(45*(18-pos));
            }
            else if(pos<24)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(pos-10));
                main_array[pos].mid_y=posy;
            }
            else if(pos==24)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*13);
                main_array[pos].mid_y=posy-45;
            }
            else if(pos<31)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(38-pos));
                main_array[pos].mid_y=posy-90;
            }
            else if(pos<37)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*7);
                main_array[pos].mid_y=posy-(45*(pos-28));
            }
            else if(pos==37)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*6);
                main_array[pos].mid_y=posy-(45*8);
            }
            else if(pos<44)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*5);
                main_array[pos].mid_y=posy-(45*(46-pos));
            }
            else if(pos<50)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(48-pos));
                main_array[pos].mid_y=posy-(45*2);
            }
            else if(pos==50)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx+45;
                main_array[pos].mid_y=posy-45;
            }
            else if(pos==51)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx+45;
                main_array[pos].mid_y=posy;
            }
            else if(pos<57)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(pos-52));
                main_array[pos].mid_y=posy-45;
            }
            else if(pos<62)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*6);
                main_array[pos].mid_y=posy+(45*(62-pos));
            }
            else if(pos<67)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(74-pos));
                main_array[pos].mid_y=posy-45;
            }
            else if(pos<72)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*6);
                main_array[pos].mid_y=posy-(45*(74-pos));
            }
            else if(pos<76)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(pos-72));
                main_array[pos].mid_y=posy+(45*5);
            }
            else if(pos<80)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*12);
                main_array[pos].mid_y=posy+(45*(81-pos));
            }
            else if(pos<84)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(92-pos));
                main_array[pos].mid_y=posy-(45*7);
            }
            else if(pos<88)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx;
                main_array[pos].mid_y=posy-(45*(91-pos));
            }
            else if(pos<92)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(pos-88));
                main_array[pos].mid_y=posy+(45*2);
            }
            else if(pos<96)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*9);
                main_array[pos].mid_y=posy+(45*(97-pos));
            }
            else if(pos<100)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*(108-pos));
                main_array[pos].mid_y=posy-(45*4);
            }
            else if(pos<=103)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx-(45*3);
                main_array[pos].mid_y=posy-(45*(107-pos));
            }
            else if(pos==104)
            {
                main_array[pos].guti_no_1=-1;
                main_array[pos].guti_no_2=-1;
                main_array[pos].guti_no_3=-1;
                main_array[pos].guti_no_4=-1;
                main_array[pos].mid_x=posx+685;
                main_array[pos].mid_y=posy-290;
            }
        }
    }
}

/*Guti information setting...*/
inline void guti_info()
{
    for(int i=0; i<16; i++)
    {
        if((i>=0)&&(i<=3))
        {
            guti[i].player=1;
            guti[i].initial_pos=72+i;
            guti[i].current_pos=guti[i].initial_pos;
            guti[i].length=0;
            guti[i].start_pos=88;
            guti[i].turn_after=50;
            guti[i].turn_into=52;
            guti[i].end_pos=56;
        }
        else if((i>=4)&&(i<=7))
        {
            guti[i].player=2;
            guti[i].initial_pos=72+i;
            guti[i].current_pos=guti[i].initial_pos;
            guti[i].length=0;
            guti[i].start_pos=93;
            guti[i].turn_after=11;
            guti[i].turn_into=57;
            guti[i].end_pos=61;
        }
        else if((i>=8)&&(i<=11))
        {
            guti[i].player=3;
            guti[i].initial_pos=72+i;
            guti[i].current_pos=guti[i].initial_pos;
            guti[i].length=0;
            guti[i].start_pos=98;
            guti[i].turn_after=24;
            guti[i].turn_into=62;
            guti[i].end_pos=66;
        }
        else if((i>=12)&&(i<=15))
        {
            guti[i].player=4;
            guti[i].initial_pos=72+i;
            guti[i].current_pos=guti[i].initial_pos;
            guti[i].length=0;
            guti[i].start_pos=103;
            guti[i].turn_after=37;
            guti[i].turn_into=67;
            guti[i].end_pos=71;
        }
        main_array[72+i].guti_no_1=i;
    }
}


/*Designing...*/

/*Play Ground Making...*/
inline void graphics_body()
{
    /*court design*/
    setcolor(RED);
    setlinestyle(4, 0, 25);
    rectangle(425.5,425.5,672.5,672.5);  /*1st court*/
    setlinestyle(0, 0, 45);
    line(415,347.5,640,347.5);          /*1st bar*/
    setviewport(641,326,684,369,1);
    clearviewport();
    setviewport(0,0,1360,750,1);

    setcolor(GREEN);
    setlinestyle(4, 0, 25);
    rectangle(22.5,427.5,267.5,672.5);   /*2nd court*/
    setlinestyle(0, 0, 45);
    line(347.5,415,347.5,640);          /*2nd bar*/
    setviewport(326,641,369,684,1);
    clearviewport();
    setviewport(0,0,1360,750,1);

    setcolor(YELLOW);
    setlinestyle(4, 0, 25);
    rectangle(22.5,22.5,267.5,267.5);    /*3rd court*/
    setlinestyle(0, 0, 45);
    rectangle(55,347.5,280,347.5);      /*3rd bar*/
    setviewport(11,326,54,369,1);
    clearviewport();
    setviewport(0,0,1360,750,1);

    setcolor(BLUE);
    setlinestyle(4, 0, 25);
    rectangle(427.5,22.5,672.5,267.5);   /*4th court*/
    setlinestyle(0, 0, 45);
    rectangle(347.5,55,347.5,280);      /*4th bar*/
    setviewport(326,11,369,54,1);
    clearviewport();
    setviewport(0,0,1360,750,1);

    /*safe zone*/
    safe_zone_1();
    safe_zone_2();
    safe_zone_3();
    safe_zone_4();

    int x,y;

    /*for vertical*/
    setcolor(WHITE);
    setlinestyle(1, 0, 1);
    for(x=280; x<=370; x+=45)
        for(y=10; y<=685; y+=45)
        {
            if(y>280&&y<415)
                continue;
            line(x,y,x+45,y);
        }

    /*for horizontal*/
    setcolor(WHITE);
    setlinestyle(1, 0, 1);
    for(x=280; x<=370; x+=45)
        for(y=10; y<=685; y+=45)
        {
            if(y>280&&y<415)
                continue;
            line(y,x,y,x+45);
        }

    /*middle line*/
    setcolor(WHITE);
    setlinestyle(1, 0, 1);

    line(325,415,325,685);   /*1st*/
    line(370,415,370,685);
    line(10,325,280,325);   /*2nd*/
    line(10,370,280,370);
    line(325,10,325,280);   /*3rd*/
    line(370,10,370,280);
    line(415,325,685,325);   /*4th*/
    line(415,370,685,370);


    /*main block & 3d*/
    setcolor(LIGHTBLUE);
    setlinestyle(0, 0, 1);
    int block[]= {10,10,10,685,685,685,685,10,10,10};
    drawpoly(5,block);
    int right[]= {685,10,690,15,690,690,685,685};
    drawpoly(4,right);
    int down[]= {10,685,15,690,690,690,685,685};
    drawpoly(4,down);

    /*Back button*/
    setcolor(LIGHTGRAY);
    setlinestyle(1, 0, 1);
    settextstyle(6, HORIZ_DIR, 1);
    outtextxy(1270, 19, bck);
    ellipse(1307, 30,0,360, 45, 20);
    rectangle(1262,10,1352,50);


    /*Start button*/
    setcolor(LIGHTMAGENTA);
    setlinestyle(0, 0, 1);
    settextstyle(10, HORIZ_DIR, 2);
    outtextxy(316, 337, stt);
    ellipse(348, 349,0,360, 41, 20);


    /*initial guti*/
    float posxx;
    float posyy;
    int pos;
    for(int i=0; i<16; i++)
    {
        posxx=main_array[guti[i].initial_pos].mid_x;
        posyy=main_array[guti[i].initial_pos].mid_y;
        if((i>=0)&&(i<=3))
        {
            setcolor(RED);
            sector(posxx, posyy, 0, 360, 18, 18);
            setcolor(WHITE);
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",i+1);
            outtextxy(posxx-7, posyy-13, val);
            setlinestyle(0, 0, 2);
            setcolor(WHITE);
            circle(posxx, posyy,20);
        }
        else if((i>=4)&&(i<=7))
        {
            setcolor(GREEN);
            sector(posxx, posyy, 0, 360, 18, 18);
            setcolor(WHITE);
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",i-3);
            outtextxy(posxx-7, posyy-13, val);
            setlinestyle(0, 0, 2);
            setcolor(WHITE);
            circle(posxx, posyy,20);
        }
        else if((i>=8)&&(i<=11))
        {
            setcolor(YELLOW);
            sector(posxx, posyy, 0, 360, 18, 18);
            setcolor(WHITE);
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",i-7);
            outtextxy(posxx-7, posyy-13, val);
            setlinestyle(0, 0, 2);
            setcolor(WHITE);
            circle(posxx, posyy,20);
        }
        else if((i>=12)&&(i<=15))
        {
            setcolor(BLUE);
            sector(posxx, posyy, 0, 360, 18, 18);
            setcolor(WHITE);
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",i-11);
            outtextxy(posxx-7, posyy-13, val);
            setlinestyle(0, 0, 2);
            setcolor(WHITE);
            circle(posxx, posyy,20);
        }
    }


    /*score board*/
    setcolor(LIGHTGREEN);
    settextstyle(10, HORIZ_DIR, 6);
    outtextxy(randval_x+100, randval_y+340, ScoreBoard);

    scoreboard();
}

/*Scoreboard Making...*/
inline void scoreboard()
{
    setcolor(RED);
    settextstyle(1, HORIZ_DIR, 10);
    if(p1<4)
    {
        sprintf(val,"%d",p1);
        outtextxy(randval_x+337, randval_y+518, val);
    }

    else
    {
        setviewport(randval_x+315,randval_y+530,randval_x+470,randval_y+645,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        settextstyle(1, HORIZ_DIR, 7);
        if(first==1)
            outtextxy(randval_x+322, randval_y+550, fst);
        else if(second==1)
        {
            settextstyle(1, HORIZ_DIR, 6);
            outtextxy(randval_x+324, randval_y+560, snd);
        }
        else if(third==1)
            outtextxy(randval_x+318, randval_y+550, trd);
        else
            outtextxy(randval_x+322, randval_y+550, frt);
    }

    setcolor(GREEN);
    settextstyle(1, HORIZ_DIR, 10);
    if(p2<4)
    {
        sprintf(val,"%d",p2);
        outtextxy(randval_x+182, randval_y+518, val);
    }
    else
    {
        setviewport(randval_x+160,randval_y+530,randval_x+315,randval_y+645,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        settextstyle(1, HORIZ_DIR, 7);
        if(first==2)
            outtextxy(randval_x+167, randval_y+550, fst);
        else if(second==2)
        {
            settextstyle(1, HORIZ_DIR, 6);
            outtextxy(randval_x+168, randval_y+560, snd);
        }
        else if(third==2)
            outtextxy(randval_x+162, randval_y+550, trd);
        else
            outtextxy(randval_x+167, randval_y+550, frt);
    }

    setcolor(YELLOW);
    settextstyle(1, HORIZ_DIR, 10);
    if(p3<4)
    {
        sprintf(val,"%d",p3);
        outtextxy(randval_x+182, randval_y+402, val);
    }
    else
    {
        setviewport(randval_x+160,randval_y+415,randval_x+315,randval_y+530,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        settextstyle(1, HORIZ_DIR, 7);
        if(first==3)
            outtextxy(randval_x+167, randval_y+434, fst);
        else if(second==3)
        {
            settextstyle(1, HORIZ_DIR, 6);
            outtextxy(randval_x+168, randval_y+444, snd);
        }
        else if(third==3)
            outtextxy(randval_x+162, randval_y+434, trd);
        else
            outtextxy(randval_x+167, randval_y+434, frt);
    }

    setcolor(BLUE);
    settextstyle(1, HORIZ_DIR, 10);
    if(p4<4)
    {
        sprintf(val,"%d",p4);
        outtextxy(randval_x+337, randval_y+402, val);
    }

    else
    {
        setviewport(randval_x+315,randval_y+415,randval_x+470,randval_y+530,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        settextstyle(1, HORIZ_DIR, 7);
        if(first==4)
            outtextxy(randval_x+322, randval_y+434, fst);
        else if(second==4)
        {
            settextstyle(1, HORIZ_DIR, 6);
            outtextxy(randval_x+324, randval_y+444, snd);
        }
        else if(third==4)
            outtextxy(randval_x+318, randval_y+434, trd);
        else
            outtextxy(randval_x+322, randval_y+434, frt);
    }

    setcolor(LIGHTRED);
    setlinestyle(0,0,5);
    rectangle(randval_x+160,randval_y+415,randval_x+470,randval_y+645);
    line(randval_x+315,randval_y+415,randval_x+315,randval_y+645);
    line(randval_x+160,randval_y+530,randval_x+470,randval_y+530);
}

/*Safe Zone Making...*/
inline void safe_zone_1()
{
    setcolor(RED);
    setlinestyle(0, 0, 22.50);
    rectangle(607,382,628.75,403.75);   /*1st*/
}

inline void safe_zone_2()
{
    setcolor(GREEN);
    setlinestyle(0, 0, 22.50);
    rectangle(292,607,313.75,628.75);   /*2nd*/
}

inline void safe_zone_3()
{
    setcolor(YELLOW);
    setlinestyle(0, 0, 22.50);
    rectangle(67,292,88.75,313.75);   /*3rd*/
}

inline void safe_zone_4()
{
    setcolor(BLUE);
    setlinestyle(0, 0, 22.50);
    rectangle(382,67,403.75,88.75);   /*4th*/
}


/*Gaming...*/

/*Home screen window*/
inline void homeScreen()
{
    setcolor(LIGHTGRAY);
    setlinestyle(1, 0, 1);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(610, 180, "Play");
    ellipse(673, 212,0,360, 85, 35);
    outtextxy(580, 280, "About");
    ellipse(676, 314,0,360, 110, 35);
    outtextxy(610, 380, "Exit");
    ellipse(673, 412,0,360, 85, 35);

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if((x>=588)&&(x<=758)&&(y>=177)&&(y<=247))
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            play();
        }
        else if((x>=566)&&(x<=786)&&(y>=279)&&(y<=349))
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            about();
        }
        else if((x>=588)&&(x<=758)&&(y>=377)&&(y<=447))
            exit(1);
    }
}

/*About window*/
inline void about()
{
    setcolor(LIGHTGRAY);
    setlinestyle(1, 0, 2);
    settextstyle(6, HORIZ_DIR, 5);
    outtextxy(100, 630, "Back");
    rectangle(92,630,242,680);
    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(40, 80, "This game is developed by......");
    settextstyle(6, HORIZ_DIR, 4);
    outtextxy(140, 150, "MD. TAHMID HASAN");
    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(140, 190, "B. Sc Engineering in CSE");
    outtextxy(140, 215, "Bangabandhu Sheikh Mujibur Rahman Science and Technology University (BSMRSTU)");
    outtextxy(140, 240, "Email: tahmidhasan.3003@gmail.com");

    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(40, 330, "Project Supervisor:");
    settextstyle(6, HORIZ_DIR, 4);
    outtextxy(140, 390, "SALEH AHMED");
    settextstyle(6, HORIZ_DIR, 2);
    outtextxy(140, 430, "Chairman and Assistant Professor,");
    outtextxy(140, 460, "Dept of CSE,");
    outtextxy(140, 490, "BSMRSTU");

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if((x>=92)&&(x<=242)&&(y>=630)&&(y<=680))
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            homeScreen();
        }
    }
}

/*Player type selection window*/
inline void play()
{
    setcolor(LIGHTGRAY);
    setlinestyle(1, 0, 1);
    settextstyle(6, HORIZ_DIR, 6);
    outtextxy(40, 50, "Select Player Type.....");

    outtextxy(1100, 600, "Next");
    outtextxy(100, 600, "Back");
    setlinestyle(3, 0, 6);
    rectangle(1092,600,1262,660);
    rectangle(92,600,262,660);

    setlinestyle(1, 0, 1);
    settextstyle(6, HORIZ_DIR, 4);
    outtextxy(140, 200, "#Player 1:");
    outtextxy(450, 200, "Human");
    outtextxy(700, 200, "Computer");
    outtextxy(1000, 200, "Inactive");

    outtextxy(140, 300, "#Player 2:");
    outtextxy(450, 300, "Human");
    outtextxy(700, 300, "Computer");
    outtextxy(1000, 300, "Inactive");

    outtextxy(140, 400, "#Player 3:");
    outtextxy(450, 400, "Human");
    outtextxy(700, 400, "Computer");
    outtextxy(1000, 400, "Inactive");

    outtextxy(140, 500, "#Player 4:");
    outtextxy(450, 500, "Human");
    outtextxy(700, 500, "Computer");
    outtextxy(1000, 500, "Inactive");

    setlinestyle(0,0,1);
    circle(430,218,10);
    circle(680,218,10);
    circle(980,218,10);

    circle(430,318,10);
    circle(680,318,10);
    circle(980,318,10);

    circle(430,418,10);
    circle(680,418,10);
    circle(980,418,10);

    circle(430,518,10);
    circle(680,518,10);
    circle(980,518,10);

    setlinestyle(0,0,8);
    circle(430,218,5);
    circle(680,318,5);
    circle(980,418,5);
    circle(980,518,5);

    ptype[0]=2;
    ptype[1]=1;
    ptype[2]=0;
    ptype[3]=0;

    //Player type selection......
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if((x>=92)&&(x<=262)&&(y>=600)&&(y<=660))
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            homeScreen();
        }
        else if((x>=1092)&&(x<=1262)&&(y>=600)&&(y<=660))
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            next();
        }
        else if((x>=420)&&(x<=440)&&(y>=208)&&(y<=228))
        {
            setviewport(670,208,690,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,218,10);

            setviewport(970,208,990,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,218,10);

            setlinestyle(0,0,8);
            circle(430,218,5);

            ptype[0]=2;
        }
        else if((x>=670)&&(x<=690)&&(y>=208)&&(y<=228))
        {
            setviewport(420,208,440,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,218,10);

            setviewport(970,208,990,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,218,10);

            setlinestyle(0,0,8);
            circle(680,218,5);

            ptype[0]=1;
        }
        else if((x>=970)&&(x<=990)&&(y>=208)&&(y<=228))
        {
            setviewport(670,208,690,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,218,10);

            setviewport(420,208,440,228,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,218,10);

            setlinestyle(0,0,8);
            circle(980,218,5);

            ptype[0]=0;
        }
        else if((x>=420)&&(x<=440)&&(y>=308)&&(y<=328))
        {
            setviewport(670,308,690,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,318,10);

            setviewport(970,308,990,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,318,10);

            setlinestyle(0,0,8);
            circle(430,318,5);

            ptype[1]=2;
        }
        else if((x>=670)&&(x<=690)&&(y>=308)&&(y<=328))
        {
            setviewport(420,308,440,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,318,10);

            setviewport(970,308,990,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,318,10);

            setlinestyle(0,0,8);
            circle(680,318,5);

            ptype[1]=1;
        }
        else if((x>=970)&&(x<=990)&&(y>=308)&&(y<=328))
        {
            setviewport(670,308,690,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,318,10);

            setviewport(420,308,440,328,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,318,10);

            setlinestyle(0,0,8);
            circle(980,318,5);

            ptype[1]=0;
        }
        else if((x>=420)&&(x<=440)&&(y>=408)&&(y<=428))
        {
            setviewport(670,408,690,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,418,10);

            setviewport(970,408,990,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,418,10);

            setlinestyle(0,0,8);
            circle(430,418,5);

            ptype[2]=2;
        }
        else if((x>=670)&&(x<=690)&&(y>=408)&&(y<=428))
        {
            setviewport(420,408,440,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,418,10);

            setviewport(970,408,990,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,418,10);

            setlinestyle(0,0,8);
            circle(680,418,5);

            ptype[2]=1;
        }
        else if((x>=970)&&(x<=990)&&(y>=408)&&(y<=428))
        {
            setviewport(670,408,690,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,418,10);

            setviewport(420,408,440,428,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,418,10);

            setlinestyle(0,0,8);
            circle(980,418,5);

            ptype[2]=0;
        }
        else if((x>=420)&&(x<=440)&&(y>=508)&&(y<=528))
        {
            setviewport(670,508,690,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,518,10);

            setviewport(970,508,990,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,518,10);

            setlinestyle(0,0,8);
            circle(430,518,5);

            ptype[3]=2;
        }
        else if((x>=670)&&(x<=690)&&(y>=508)&&(y<=528))
        {
            setviewport(420,508,440,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,518,10);

            setviewport(970,508,990,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(980,518,10);

            setlinestyle(0,0,8);
            circle(680,518,5);

            ptype[3]=1;
        }
        else if((x>=970)&&(x<=990)&&(y>=508)&&(y<=528))
        {
            setviewport(670,508,690,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(680,518,10);

            setviewport(420,508,440,528,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setlinestyle(0,0,1);
            circle(430,518,10);

            setlinestyle(0,0,8);
            circle(980,518,5);

            ptype[3]=0;
        }
    }
}

/*Play screen window*/
inline void next()
{
    keep_position();
    guti_info();
    graphics_body();

    int oncePlayed=0;
    //int terminate=0;

    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(0);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);

        if(x>=440&&x<=660&&y>=35&&y<=250)  /*4th Court Clicking*/
        {
            setcolor(BLUE);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+150, randval_y, "4th Player");
        }
        else if(x>=35&&x<=255&&y>=35&&y<=250)  /*3rd Court Clicking*/
        {
            setcolor(YELLOW);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+150, randval_y, "3rd Player");
        }
        else if(x>=35&&x<=255&&y>=440&&y<=660)  /*2nd Court Clicking*/
        {
            setcolor(GREEN);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+150, randval_y, "2nd Player");
        }
        else if(x>=440&&x<=660&&y>=440&&y<=660)  /*1st Court Clicking*/
        {
            setcolor(RED);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+150, randval_y, "1st Player");
        }
        else if(x>=307&&x<=389&&y>=329&&y<=369)  /*Start Button Clicking*/
        {
            /*Pause button*/
            setviewport(307,329,389,369,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setcolor(LIGHTMAGENTA);
            setlinestyle(0, 0, 1);
            settextstyle(10, HORIZ_DIR, 2);
            outtextxy(316, 337, "PAUSE");
            ellipse(348, 349,0,360, 41, 20);

            if(oncePlayed)
            {
                setviewport(0,0,1360,750,1);
                clearviewport();
                setviewport(0,0,1360,750,1);

                keep_position();
                guti_info();
                graphics_body();

                /*Pause button*/
                setviewport(307,329,389,369,1);
                clearviewport();
                setviewport(0,0,1360,750,1);
                setcolor(LIGHTMAGENTA);
                setlinestyle(0, 0, 1);
                settextstyle(10, HORIZ_DIR, 2);
                outtextxy(316, 337, "PAUSE");
                ellipse(348, 349,0,360, 41, 20);
            }

            srand(time(NULL));
            p1=p2=p3=p4=first=second=third=0;
            scoreboard();
            int qqq=0;
            for(int qq=0; qq<4; qq++)
            {
                if(ptype[qq]!=0)
                    qqq++;
            }
            if(qqq==0)
            {
                setviewport(0,0,1360,750,1);
                clearviewport();
                setviewport(0,0,1360,750,1);
                play();
            }
            while((p1<4)||(p2<4)||(p3<4)||(p4<4))  /*Game Running......*/
            {
                x=0;
                y=0;
                getmouseclick(WM_LBUTTONDOWN, x, y);

                if(x>=1262&&x<=1352&&y>=10&&y<=50)  /*Back Button Press*/
                {
                    setviewport(0,0,1360,750,1);
                    clearviewport();
                    setviewport(0,0,1360,750,1);
                    play();
                }
                else if(x>=307&&x<=389&&y>=329&&y<=369)  /*Pause Button Press*/
                {
                    /*Resume button*/
                    setviewport(307,329,389,369,1);
                    clearviewport();
                    setviewport(0,0,1360,750,1);
                    setcolor(LIGHTMAGENTA);
                    setlinestyle(0, 0, 1);
                    settextstyle(10, HORIZ_DIR, 2);
                    outtextxy(313, 337, "RESUME");
                    ellipse(348, 349,0,360, 41, 20);

                    while(1)
                    {
                        while(!ismouseclick(WM_LBUTTONDOWN))
                        {
                            delay(0);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if(x>=307&&x<=389&&y>=329&&y<=369)  /*Resume Button Press*/
                        {
                            /*Pause button*/
                            setviewport(307,329,389,369,1);
                            clearviewport();
                            setviewport(0,0,1360,750,1);
                            setcolor(LIGHTMAGENTA);
                            setlinestyle(0, 0, 1);
                            settextstyle(10, HORIZ_DIR, 2);
                            outtextxy(316, 337, "PAUSE");
                            ellipse(348, 349,0,360, 41, 20);

                            break;
                        }
                        else if(x>=1262&&x<=1352&&y>=10&&y<=50)  /*Back Button Press*/
                        {
                            setviewport(0,0,1360,750,1);
                            clearviewport();
                            setviewport(0,0,1360,750,1);
                            play();
                            //terminate=1;
                            //break;
                        }
                    }
                    /*if(terminate)
                        break;*/
                }


                /*Playing...*/
                if(p1<4)
                {
                    if(ptype[0]==1)
                        player_1();
                    else if(ptype[0]==2)
                        human_1();
                }
                if(p2<4)
                {
                    if(ptype[1]==1)
                        player_2();
                    else if(ptype[1]==2)
                        human_2();
                }
                if(p3<4)
                {
                    if(ptype[2]==1)
                        player_3();
                    else if(ptype[2]==2)
                        human_3();
                }
                if(p4<4)
                {
                    if(ptype[3]==1)
                        player_4();
                    else if(ptype[3]==2)
                        human_4();
                }

                if(qqq==1)
                {
                    if(first!=0)
                        break;
                }
                else if(qqq==2)
                {
                    if(first!=0)
                        break;
                }
                else if(qqq==3)
                {
                    if(second!=0)
                        break;
                }
                else if(qqq==4)
                {
                    if(third!=0)
                        break;
                }
            }

            /*if(terminate)
                break;*/

            /*Restart button*/
            setviewport(307,329,389,369,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setcolor(LIGHTMAGENTA);
            setlinestyle(0, 0, 1);
            settextstyle(10, HORIZ_DIR, 1);
            outtextxy(311, 337, "RESTART");
            ellipse(348, 349,0,360, 41, 20);

            /*declaring the result*/
            setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setcolor(DARKGRAY);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+5, randval_y+220, "Congratulation!!!");
            setcolor(LIGHTMAGENTA);
            settextstyle(10, HORIZ_DIR, 5);
            if(first==1)
                outtextxy(randval_x+5, randval_y+275, "Player 1 win this game...");
            else if(first==2)
                outtextxy(randval_x+5, randval_y+275, "Player 2 win this game...");
            else if(first==3)
                outtextxy(randval_x+5, randval_y+275, "Player 3 win this game...");
            else
                outtextxy(randval_x+5, randval_y+275, "Player 4 win this game...");

            oncePlayed=1;
        }
        else if(x>=1262&&x<=1352&&y>=10&&y<=50)  /*Back Button Press*/
        {
            setviewport(0,0,1360,750,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            play();
        }
    }
}

/*Player 1 (Computer) playing.....*/
inline int player_1()
{
    setcolor(RED);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "1st Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int tempx,tempy,tempz;
    if((randval[1]==0)&&(randval[2]==0))
    {
        tempx=random_value_1(0);
        run_guti(tempx,randval[0]);
        goto bonus1;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        tempx=random_value_12(0);
        if((tempx>99)&&(tempx<999))
        {
            run_guti((tempx/100)-1,randval[0]+randval[1]);
            goto bonus1;
        }
        else
        {
            tempy=tempx/100;
            tempx%=100;
            if(guti[(tempx/10)-1].current_pos==104)
                run_guti((tempy/10)-1,randval[(tempy%10)-1]+randval[(tempx%10)-1]);
            else if(guti[(tempy/10)-1].current_pos==104)
                run_guti((tempx/10)-1,randval[(tempx%10)-1]+randval[(tempy%10)-1]);
            else
            {
                run_guti((tempy/10)-1,randval[(tempy%10)-1]);
                run_guti((tempx/10)-1,randval[(tempx%10)-1]);
            }
            goto bonus1;
        }
    }
    else
    {
        tempx=random_value_123(0);
        if((tempx>999)&&(tempx<9999))
        {
            run_guti((tempx/1000)-1,randval[0]+randval[1]+randval[2]);
            goto bonus1;
        }
        else if((tempx>9999)&&(tempx<99999))
        {
            tempy=tempx/100;
            tempx%=100;
            tempz=tempy/100;
            tempy%=100;
            if(guti[(tempx/10)-1].current_pos==104)
                run_guti(tempz-1,randval[(tempy/10)-1]+randval[(tempy%10)-1]+randval[(tempx%10)-1]);
            else if(guti[tempz-1].current_pos==104)
                run_guti((tempx/10)-1,randval[(tempx%10)-1]+randval[(tempy/10)-1]+randval[(tempy%10)-1]);
            else
            {
                run_guti(tempz-1,randval[(tempy/10)-1]+randval[(tempy%10)-1]);
                run_guti((tempx/10)-1,randval[(tempx%10)-1]);
            }
            goto bonus1;
        }
        else
        {
            tempy=tempx/100;
            tempx%=100;
            tempz=tempy/100;
            tempy%=100;
            if((guti[(tempy/10)-1].current_pos==104)&&(guti[(tempx/10)-1].current_pos==104))
                run_guti((tempz/10)-1,randval[(tempz%10)-1]+randval[(tempy%10)-1]+randval[(tempx%10)-1]);
            else if((guti[(tempz/10)-1].current_pos==104)&&(guti[(tempx/10)-1].current_pos==104))
                run_guti((tempy/10)-1,randval[(tempz%10)-1]+randval[(tempy%10)-1]+randval[(tempx%10)-1]);
            else if((guti[(tempz/10)-1].current_pos==104)&&(guti[(tempy/10)-1].current_pos==104))
                run_guti((tempx/10)-1,randval[(tempz%10)-1]+randval[(tempy%10)-1]+randval[(tempx%10)-1]);
            else
            {
                run_guti((tempz/10)-1,randval[(tempz%10)-1]);
                run_guti((tempy/10)-1,randval[(tempy%10)-1]);
                run_guti((tempx/10)-1,randval[(tempx%10)-1]);
            }
            goto bonus1;
        }
    }

bonus1:
    if(bonus==1)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 1 got another throw...");
        delay(2000);
        player_1();
    }
}

/*Player 2 (Computer) playing.....*/
inline int player_2()
{
    setcolor(GREEN);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "2nd Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        x=random_value_1(4);
        run_guti(4+x,randval[0]);
        goto bonus2;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        x=random_value_12(4);
        if((x>99)&&(x<999))
        {
            run_guti(4+(x/100)-1,randval[0]+randval[1]);
            goto bonus2;
        }
        else
        {
            y=x/100;
            x%=100;

            if(guti[4+(x/10)-1].current_pos==104)
                run_guti(4+(y/10)-1,randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[4+(y/10)-1].current_pos==104)
                run_guti(4+(x/10)-1,randval[(x%10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(4+(y/10)-1,randval[(y%10)-1]);
                run_guti(4+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus2;
        }
    }
    else
    {
        x=random_value_123(4);
        if((x>999)&&(x<9999))
        {
            run_guti(4+(x/1000)-1,randval[0]+randval[1]+randval[2]);
            goto bonus2;
        }
        else if((x>9999)&&(x<99999))
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;
            if(guti[4+(x/10)-1].current_pos==104)
                run_guti(4+z-1,randval[(y/10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[4+z-1].current_pos==104)
                run_guti(4+(x/10)-1,randval[(x%10)-1]+randval[(y/10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(4+z-1,randval[(y/10)-1]+randval[(y%10)-1]);
                run_guti(4+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus2;
        }
        else
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;
            if((guti[4+(y/10)-1].current_pos==104)&&(guti[4+(x/10)-1].current_pos==104))
                run_guti(4+(z/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[4+(z/10)-1].current_pos==104)&&(guti[4+(x/10)-1].current_pos==104))
                run_guti(4+(y/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[4+(z/10)-1].current_pos==104)&&(guti[4+(y/10)-1].current_pos==104))
                run_guti(4+(x/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else
            {
                run_guti(4+(z/10)-1,randval[(z%10)-1]);
                run_guti(4+(y/10)-1,randval[(y%10)-1]);
                run_guti(4+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus2;
        }
    }

bonus2:
    if(bonus==2)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 2 got another throw...");
        delay(2000);
        player_2();
    }
}

/*Player 3 (Computer) playing.....*/
inline int player_3()
{
    setcolor(YELLOW);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "3rd Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        x=random_value_1(8);
        run_guti(8+x,randval[0]);
        goto bonus3;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        x=random_value_12(8);
        if((x>99)&&(x<999))
        {
            run_guti(8+(x/100)-1,randval[0]+randval[1]);
            goto bonus3;
        }
        else
        {
            y=x/100;
            x%=100;

            if(guti[8+(x/10)-1].current_pos==104)
                run_guti(8+(y/10)-1,randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[8+(y/10)-1].current_pos==104)
                run_guti(8+(x/10)-1,randval[(x%10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(8+(y/10)-1,randval[(y%10)-1]);
                run_guti(8+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus3;
        }
    }
    else
    {
        x=random_value_123(8);
        if((x>999)&&(x<9999))
        {
            run_guti(8+(x/1000)-1,randval[0]+randval[1]+randval[2]);
            goto bonus3;
        }
        else if((x>9999)&&(x<99999))
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;
            if(guti[8+(x/10)-1].current_pos==104)
                run_guti(8+z-1,randval[(y/10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[8+z-1].current_pos==104)
                run_guti(8+(x/10)-1,randval[(x%10)-1]+randval[(y/10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(8+z-1,randval[(y/10)-1]+randval[(y%10)-1]);
                run_guti(8+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus3;
        }
        else
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;
            if((guti[8+(y/10)-1].current_pos==104)&&(guti[8+(x/10)-1].current_pos==104))
                run_guti(8+(z/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[8+(z/10)-1].current_pos==104)&&(guti[8+(x/10)-1].current_pos==104))
                run_guti(8+(y/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[8+(z/10)-1].current_pos==104)&&(guti[8+(y/10)-1].current_pos==104))
                run_guti(8+(x/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else
            {
                run_guti(8+(z/10)-1,randval[(z%10)-1]);
                run_guti(8+(y/10)-1,randval[(y%10)-1]);
                run_guti(8+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus3;
        }
    }

bonus3:
    if(bonus==3)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 3 got another throw...");
        delay(2000);
        player_3();
    }
}

/*Player 4 (Computer) playing.....*/
inline int player_4()
{
    setcolor(BLUE);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "4th Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        x=random_value_1(12);
        run_guti(12+x,randval[0]);
        goto bonus4;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        x=random_value_12(12);
        if((x>99)&&(x<999))
        {
            run_guti(12+(x/100)-1,randval[0]+randval[1]);
            goto bonus4;
        }
        else
        {
            y=x/100;
            x%=100;

            if(guti[12+(x/10)-1].current_pos==104)
                run_guti(12+(y/10)-1,randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[12+(y/10)-1].current_pos==104)
                run_guti(12+(x/10)-1,randval[(x%10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(12+(y/10)-1,randval[(y%10)-1]);
                run_guti(12+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus4;
        }
    }
    else
    {
        x=random_value_123(12);
        if((x>999)&&(x<9999))
        {
            run_guti(12+(x/1000)-1,randval[0]+randval[1]+randval[2]);
            goto bonus4;
        }
        else if((x>9999)&&(x<99999))
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;
            if(guti[12+(x/10)-1].current_pos==104)
                run_guti(12+z-1,randval[(y/10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if(guti[12+z-1].current_pos==104)
                run_guti(12+(x/10)-1,randval[(x%10)-1]+randval[(y/10)-1]+randval[(y%10)-1]);
            else
            {
                run_guti(12+z-1,randval[(y/10)-1]+randval[(y%10)-1]);
                run_guti(12+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus4;
        }
        else
        {
            y=x/100;
            x%=100;
            z=y/100;
            y%=100;

            if((guti[12+(y/10)-1].current_pos==104)&&(guti[12+(x/10)-1].current_pos==104))
                run_guti(12+(z/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[12+(z/10)-1].current_pos==104)&&(guti[12+(x/10)-1].current_pos==104))
                run_guti(12+(y/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else if((guti[12+(z/10)-1].current_pos==104)&&(guti[12+(y/10)-1].current_pos==104))
                run_guti(12+(x/10)-1,randval[(z%10)-1]+randval[(y%10)-1]+randval[(x%10)-1]);
            else
            {
                run_guti(12+(z/10)-1,randval[(z%10)-1]);
                run_guti(12+(y/10)-1,randval[(y%10)-1]);
                run_guti(12+(x/10)-1,randval[(x%10)-1]);
            }
            goto bonus4;
        }
    }

bonus4:
    if(bonus==4)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 4 got another throw...");
        delay(1500);
        player_4();
    }
}

/*Player 1 (Human) playing.....*/
inline int human_1()
{
    int selectGuti = -1, selectValue = -1, blockValue = -1, blockValue2 = -1;
    int hp;
    //int rx,ry,hp,hval,lx,ly;
    setcolor(RED);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "1st Player");

    random_value();
    if(randval[2]==6)
        return 0;
    //int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))    /*For one random value*/
    {
        if((priority(0,randval[0],0,0)==-1000)&&(priority(1,randval[0],0,0)==-1000)&&(priority(2,randval[0],0,0)==-1000)&&(priority(3,randval[0],0,0)==-1000))
            return 0;

        selectGuti = -1;
        selectValue = randval[0];
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp!= -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }
        //run_guti(selectGuti,selectValue);
        //goto hbonus1;
    }
    else if((randval[1]!=0)&&(randval[2]==0))   /*For two random value*/
    {
        //lx=ly=rx=ry=0;

        /*1st selection*/
        selectGuti = -1;
        selectValue = -1;
        blockValue = -1;
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);
            //getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+8)&&(y<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                //rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                //hval=randval[0];
                selectValue = randval[0];
                blockValue = 0;
            }
            else if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+67+8)&&(y<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                //rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                //hval=randval[1];
                selectValue = randval[1];
                blockValue = 1;
            }
            else if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp != -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }

        /*2nd selection*/
        selectGuti = -1;
        if(blockValue == 0)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);

            setlinestyle(1,0,2);
            setcolor(CYAN);
            rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
            selectValue = randval[1];
        }
        else if(blockValue == 1)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);

            setlinestyle(1,0,2);
            setcolor(CYAN);
            rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
            selectValue = randval[0];
        }
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp != -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }
        //goto hbonus1;
    }
    else if(randval[2]!=0)                    /*For three random value*/
    {
        /*1st selection*/
        selectGuti = -1;
        selectValue = -1;
        blockValue = -1;
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+8)&&(y<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                selectValue = randval[0];
                blockValue = 0;
            }
            else if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+67+8)&&(y<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                selectValue = randval[1];
                blockValue = 1;
            }
            else if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+134+8)&&(y<=randval_y+134+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
                selectValue = randval[2];
                blockValue = 2;
            }
            else if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp != -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }

        /*2nd selection*/
        selectGuti = -1;
        selectValue = -1;
        blockValue2 = -1;
        if(blockValue == 0)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
        }
        else if(blockValue == 1)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
        }
        else if(blockValue == 2)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
        }
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+8)&&(y<=randval_y+75)&&(blockValue != 0))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                if(blockValue != 1)
                    rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                if(blockValue != 2)
                    rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                selectValue = randval[0];
                blockValue2 = 0;
            }
            else if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+67+8)&&(y<=randval_y+67+75)&&(blockValue != 1))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                if(blockValue != 0)
                    rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                if(blockValue != 2)
                    rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                selectValue = randval[1];
                blockValue2 = 1;
            }
            else if((x>=randval_x)&&(x<=randval_x+50)&&(y>=randval_y+134+8)&&(y<=randval_y+134+75)&&(blockValue != 2))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                if(blockValue != 0)
                    rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                if(blockValue != 1)
                    rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);

                setlinestyle(1,0,2);
                setcolor(CYAN);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
                selectValue = randval[2];
                blockValue2 = 2;
            }
            else if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp != -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }

        /*3rd selection*/
        selectGuti = -1;
        if(blockValue2 == 0)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
        }
        else if(blockValue2 == 1)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
        }
        else if(blockValue2 == 2)
        {
            setlinestyle(1,0,2);
            setcolor(RED);
            rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
        }

        if((blockValue != 0) && (blockValue2 != 0))
        {
            selectValue = randval[0];
        }
        else if((blockValue != 1) && (blockValue2 != 1))
        {
            selectValue = randval[1];
        }
        else if((blockValue != 2) && (blockValue2 != 2))
        {
            selectValue = randval[2];
        }

        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, x, y);

            if((x>=main_array[guti[0].current_pos].mid_x-22.5)&&(x<=main_array[guti[0].current_pos].mid_x+22.5)&&(y>=main_array[guti[0].current_pos].mid_y-22.5)&&(y<=main_array[guti[0].current_pos].mid_x+22.5))
            {
                selectGuti = 0;
            }
            else if((x>=main_array[guti[1].current_pos].mid_x-22.5)&&(x<=main_array[guti[1].current_pos].mid_x+22.5)&&(y>=main_array[guti[1].current_pos].mid_y-22.5)&&(y<=main_array[guti[1].current_pos].mid_x+22.5))
            {
                selectGuti = 1;
            }
            else if((x>=main_array[guti[2].current_pos].mid_x-22.5)&&(x<=main_array[guti[2].current_pos].mid_x+22.5)&&(y>=main_array[guti[2].current_pos].mid_y-22.5)&&(y<=main_array[guti[2].current_pos].mid_x+22.5))
            {
                selectGuti = 2;
            }
            else if((x>=main_array[guti[3].current_pos].mid_x-22.5)&&(x<=main_array[guti[3].current_pos].mid_x+22.5)&&(y>=main_array[guti[3].current_pos].mid_y-22.5)&&(y<=main_array[guti[3].current_pos].mid_x+22.5))
            {
                selectGuti = 3;
            }

            hp=priority(selectGuti,selectValue,0,0);
            if(hp != -1000)
            {
                run_guti(selectGuti,selectValue);
                break;
            }
        }
        //goto hbonus1;
    }

    setlinestyle(1,0,3);
    setcolor(BLACK);
    rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
    rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
    rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

//hbonus1:
    if(bonus==1)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 1 got another throw...");
        delay(waitingTime2);
        human_1();
    }
}

/*Player 2 (Human) playing.....*/
inline int human_2()
{
    int rx,ry,hp,hval,lx,ly;
    setcolor(GREEN);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "2nd Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[4].current_pos].mid_x-22.5)&&(rx<=main_array[guti[4].current_pos].mid_x+22.5)&&(ry>=main_array[guti[4].current_pos].mid_y-22.5)&&(ry<=main_array[guti[4].current_pos].mid_x+22.5))
            {
                hp=priority(4,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(4,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[5].current_pos].mid_x-22.5)&&(rx<=main_array[guti[5].current_pos].mid_x+22.5)&&(ry>=main_array[guti[5].current_pos].mid_y-22.5)&&(ry<=main_array[guti[5].current_pos].mid_x+22.5))
            {
                hp=priority(5,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(5,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[6].current_pos].mid_x-22.5)&&(rx<=main_array[guti[6].current_pos].mid_x+22.5)&&(ry>=main_array[guti[6].current_pos].mid_y-22.5)&&(ry<=main_array[guti[6].current_pos].mid_x+22.5))
            {
                hp=priority(6,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(6,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[7].current_pos].mid_x-22.5)&&(rx<=main_array[guti[7].current_pos].mid_x+22.5)&&(ry>=main_array[guti[7].current_pos].mid_y-22.5)&&(ry<=main_array[guti[7].current_pos].mid_x+22.5))
            {
                hp=priority(7,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(7,randval[0]);
                    break;
                }
            }
        }
        goto hbonus2;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[4].current_pos].mid_x-22.5)&&(rx<=main_array[guti[4].current_pos].mid_x+22.5)&&(ry>=main_array[guti[4].current_pos].mid_y-22.5)&&(ry<=main_array[guti[4].current_pos].mid_x+22.5))
            {
                hp=priority(4,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(4,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[5].current_pos].mid_x-22.5)&&(rx<=main_array[guti[5].current_pos].mid_x+22.5)&&(ry>=main_array[guti[5].current_pos].mid_y-22.5)&&(ry<=main_array[guti[5].current_pos].mid_x+22.5))
            {
                hp=priority(5,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(5,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[6].current_pos].mid_x-22.5)&&(rx<=main_array[guti[6].current_pos].mid_x+22.5)&&(ry>=main_array[guti[6].current_pos].mid_y-22.5)&&(ry<=main_array[guti[6].current_pos].mid_x+22.5))
            {
                hp=priority(6,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(6,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[7].current_pos].mid_x-22.5)&&(rx<=main_array[guti[7].current_pos].mid_x+22.5)&&(ry>=main_array[guti[7].current_pos].mid_y-22.5)&&(ry<=main_array[guti[7].current_pos].mid_x+22.5))
            {
                hp=priority(7,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(7,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
        }
        goto hbonus2;
    }
    else
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
                hval=randval[2];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[4].current_pos].mid_x-22.5)&&(rx<=main_array[guti[4].current_pos].mid_x+22.5)&&(ry>=main_array[guti[4].current_pos].mid_y-22.5)&&(ry<=main_array[guti[4].current_pos].mid_x+22.5))
            {
                hp=priority(4,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(4,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[5].current_pos].mid_x-22.5)&&(rx<=main_array[guti[5].current_pos].mid_x+22.5)&&(ry>=main_array[guti[5].current_pos].mid_y-22.5)&&(ry<=main_array[guti[5].current_pos].mid_x+22.5))
            {
                hp=priority(5,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(5,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[6].current_pos].mid_x-22.5)&&(rx<=main_array[guti[6].current_pos].mid_x+22.5)&&(ry>=main_array[guti[6].current_pos].mid_y-22.5)&&(ry<=main_array[guti[6].current_pos].mid_x+22.5))
            {
                hp=priority(6,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(6,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[7].current_pos].mid_x-22.5)&&(rx<=main_array[guti[7].current_pos].mid_x+22.5)&&(ry>=main_array[guti[7].current_pos].mid_y-22.5)&&(ry<=main_array[guti[7].current_pos].mid_x+22.5))
            {
                hp=priority(7,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(7,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
        }
        goto hbonus2;
    }

hbonus2:
    if(bonus==2)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 2 got another throw...");
        delay(2000);
        human_2();
    }
}

/*Player 3 (Human) playing.....*/
inline int human_3()
{
    int rx,ry,hp,hval,lx,ly;
    setcolor(YELLOW);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "3rd Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[8].current_pos].mid_x-22.5)&&(rx<=main_array[guti[8].current_pos].mid_x+22.5)&&(ry>=main_array[guti[8].current_pos].mid_y-22.5)&&(ry<=main_array[guti[8].current_pos].mid_x+22.5))
            {
                hp=priority(8,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(8,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[9].current_pos].mid_x-22.5)&&(rx<=main_array[guti[9].current_pos].mid_x+22.5)&&(ry>=main_array[guti[9].current_pos].mid_y-22.5)&&(ry<=main_array[guti[9].current_pos].mid_x+22.5))
            {
                hp=priority(9,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(9,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[10].current_pos].mid_x-22.5)&&(rx<=main_array[guti[10].current_pos].mid_x+22.5)&&(ry>=main_array[guti[10].current_pos].mid_y-22.5)&&(ry<=main_array[guti[10].current_pos].mid_x+22.5))
            {
                hp=priority(10,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(10,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[11].current_pos].mid_x-22.5)&&(rx<=main_array[guti[11].current_pos].mid_x+22.5)&&(ry>=main_array[guti[11].current_pos].mid_y-22.5)&&(ry<=main_array[guti[11].current_pos].mid_x+22.5))
            {
                hp=priority(11,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(11,randval[0]);
                    break;
                }
            }
        }
        goto hbonus3;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[8].current_pos].mid_x-22.5)&&(rx<=main_array[guti[8].current_pos].mid_x+22.5)&&(ry>=main_array[guti[8].current_pos].mid_y-22.5)&&(ry<=main_array[guti[8].current_pos].mid_x+22.5))
            {
                hp=priority(8,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(8,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[9].current_pos].mid_x-22.5)&&(rx<=main_array[guti[9].current_pos].mid_x+22.5)&&(ry>=main_array[guti[9].current_pos].mid_y-22.5)&&(ry<=main_array[guti[9].current_pos].mid_x+22.5))
            {
                hp=priority(9,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(9,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[10].current_pos].mid_x-22.5)&&(rx<=main_array[guti[10].current_pos].mid_x+22.5)&&(ry>=main_array[guti[10].current_pos].mid_y-22.5)&&(ry<=main_array[guti[10].current_pos].mid_x+22.5))
            {
                hp=priority(10,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(10,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[11].current_pos].mid_x-22.5)&&(rx<=main_array[guti[11].current_pos].mid_x+22.5)&&(ry>=main_array[guti[11].current_pos].mid_y-22.5)&&(ry<=main_array[guti[11].current_pos].mid_x+22.5))
            {
                hp=priority(11,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(11,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
        }
        goto hbonus3;
    }
    else
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
                hval=randval[2];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[8].current_pos].mid_x-22.5)&&(rx<=main_array[guti[8].current_pos].mid_x+22.5)&&(ry>=main_array[guti[8].current_pos].mid_y-22.5)&&(ry<=main_array[guti[8].current_pos].mid_x+22.5))
            {
                hp=priority(8,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(8,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[9].current_pos].mid_x-22.5)&&(rx<=main_array[guti[9].current_pos].mid_x+22.5)&&(ry>=main_array[guti[9].current_pos].mid_y-22.5)&&(ry<=main_array[guti[9].current_pos].mid_x+22.5))
            {
                hp=priority(9,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(9,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[10].current_pos].mid_x-22.5)&&(rx<=main_array[guti[10].current_pos].mid_x+22.5)&&(ry>=main_array[guti[10].current_pos].mid_y-22.5)&&(ry<=main_array[guti[10].current_pos].mid_x+22.5))
            {
                hp=priority(10,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(10,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[11].current_pos].mid_x-22.5)&&(rx<=main_array[guti[11].current_pos].mid_x+22.5)&&(ry>=main_array[guti[11].current_pos].mid_y-22.5)&&(ry<=main_array[guti[11].current_pos].mid_x+22.5))
            {
                hp=priority(11,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(11,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
        }
        goto hbonus3;
    }

hbonus3:
    if(bonus==3)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 3 got another throw...");
        delay(2000);
        human_3();
    }
}

/*Player 4 (Human) playing.....*/
inline int human_4()
{
    int rx,ry,hp,hval,lx,ly;
    setcolor(BLUE);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(randval_x+150, randval_y, "4th Player");

    random_value();
    if(randval[2]==6)
        return 0;
    int x,y,z;
    if((randval[1]==0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[12].current_pos].mid_x-22.5)&&(rx<=main_array[guti[12].current_pos].mid_x+22.5)&&(ry>=main_array[guti[12].current_pos].mid_y-22.5)&&(ry<=main_array[guti[12].current_pos].mid_x+22.5))
            {
                hp=priority(12,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(12,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[13].current_pos].mid_x-22.5)&&(rx<=main_array[guti[13].current_pos].mid_x+22.5)&&(ry>=main_array[guti[13].current_pos].mid_y-22.5)&&(ry<=main_array[guti[13].current_pos].mid_x+22.5))
            {
                hp=priority(13,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(13,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[14].current_pos].mid_x-22.5)&&(rx<=main_array[guti[14].current_pos].mid_x+22.5)&&(ry>=main_array[guti[14].current_pos].mid_y-22.5)&&(ry<=main_array[guti[14].current_pos].mid_x+22.5))
            {
                hp=priority(14,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(14,randval[0]);
                    break;
                }
            }
            else if((rx>=main_array[guti[15].current_pos].mid_x-22.5)&&(rx<=main_array[guti[15].current_pos].mid_x+22.5)&&(ry>=main_array[guti[15].current_pos].mid_y-22.5)&&(ry<=main_array[guti[15].current_pos].mid_x+22.5))
            {
                hp=priority(15,randval[0],0,0);
                if(hp!= -1000)
                {
                    run_guti(15,randval[0]);
                    break;
                }
            }
        }
        goto hbonus4;
    }
    else if((randval[1]!=0)&&(randval[2]==0))
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[12].current_pos].mid_x-22.5)&&(rx<=main_array[guti[12].current_pos].mid_x+22.5)&&(ry>=main_array[guti[12].current_pos].mid_y-22.5)&&(ry<=main_array[guti[12].current_pos].mid_x+22.5))
            {
                hp=priority(12,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(12,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[13].current_pos].mid_x-22.5)&&(rx<=main_array[guti[13].current_pos].mid_x+22.5)&&(ry>=main_array[guti[13].current_pos].mid_y-22.5)&&(ry<=main_array[guti[13].current_pos].mid_x+22.5))
            {
                hp=priority(13,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(13,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[14].current_pos].mid_x-22.5)&&(rx<=main_array[guti[14].current_pos].mid_x+22.5)&&(ry>=main_array[guti[14].current_pos].mid_y-22.5)&&(ry<=main_array[guti[14].current_pos].mid_x+22.5))
            {
                hp=priority(14,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(14,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[15].current_pos].mid_x-22.5)&&(rx<=main_array[guti[15].current_pos].mid_x+22.5)&&(ry>=main_array[guti[15].current_pos].mid_y-22.5)&&(ry<=main_array[guti[15].current_pos].mid_x+22.5))
            {
                hp=priority(15,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(15,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[1]==0)
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if(randval[0]==0)
                            break;
                    }
                }
            }
        }
        goto hbonus4;
    }
    else
    {
        while(1)
        {
            while(!ismouseclick(WM_LBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_LBUTTONDOWN, lx, ly);

            if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                hval=randval[0];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                hval=randval[1];
            }
            else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75))
            {
                setlinestyle(1,0,3);
                setcolor(BLACK);
                rectangle(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75);
                rectangle(randval_x,randval_y+8,randval_x+50,randval_y+75);

                setcolor(CYAN);
                rectangle(randval_x,randval_y+134+8,randval_x+50,randval_y+134+75);
                hval=randval[2];
            }

            while(!ismouseclick(WM_RBUTTONDOWN))
            {
                delay(0);
            }
            getmouseclick(WM_RBUTTONDOWN, rx, ry);

            if((rx>=main_array[guti[12].current_pos].mid_x-22.5)&&(rx<=main_array[guti[12].current_pos].mid_x+22.5)&&(ry>=main_array[guti[12].current_pos].mid_y-22.5)&&(ry<=main_array[guti[12].current_pos].mid_x+22.5))
            {
                hp=priority(12,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(12,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[13].current_pos].mid_x-22.5)&&(rx<=main_array[guti[13].current_pos].mid_x+22.5)&&(ry>=main_array[guti[13].current_pos].mid_y-22.5)&&(ry<=main_array[guti[13].current_pos].mid_x+22.5))
            {
                hp=priority(13,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(13,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[14].current_pos].mid_x-22.5)&&(rx<=main_array[guti[14].current_pos].mid_x+22.5)&&(ry>=main_array[guti[14].current_pos].mid_y-22.5)&&(ry<=main_array[guti[14].current_pos].mid_x+22.5))
            {
                hp=priority(14,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(14,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
            else if((rx>=main_array[guti[15].current_pos].mid_x-22.5)&&(rx<=main_array[guti[15].current_pos].mid_x+22.5)&&(ry>=main_array[guti[15].current_pos].mid_y-22.5)&&(ry<=main_array[guti[15].current_pos].mid_x+22.5))
            {
                hp=priority(15,hval,0,0);
                if(hp!= -1000)
                {
                    run_guti(15,hval);
                    if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+8)&&(ly<=randval_y+75)&&(hval==randval[0]))
                    {
                        randval[0]=0;
                        setviewport(randval_x,randval_y+8,randval_x+50,randval_y+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[1]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+67+8)&&(ly<=randval_y+67+75)&&(hval==randval[1]))
                    {
                        randval[1]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[2]==0))
                            break;
                    }
                    else if((lx>=randval_x)&&(lx<=randval_x+50)&&(ly>=randval_y+134+8)&&(ly<=randval_y+134+75)&&(hval==randval[2]))
                    {
                        randval[2]=0;
                        setviewport(randval_x,randval_y+67+8,randval_x+50,randval_y+67+75,1);
                        clearviewport();
                        setviewport(0,0,1360,750,1);
                        if((randval[0]==0)&&(randval[1]==0))
                            break;
                    }
                }
            }
        }
        goto hbonus4;
    }

hbonus4:
    if(bonus==4)
    {
        bonus=0;

        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);

        setcolor(DARKGRAY);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
        setcolor(LIGHTMAGENTA);
        settextstyle(10, HORIZ_DIR, 4);
        outtextxy(randval_x+5, randval_y+275, "Player 4 got another throw...");
        delay(1500);
        human_4();
    }
}

/*Random Value Generating*/
inline void random_value()
{
    randval[0]=(rand()%6)+1;
    randval[1]=0;
    randval[2]=0;
    //randval[0]=6;
    setcolor(CYAN);
    settextstyle(10, HORIZ_DIR, 8);
    sprintf(val,"%d",randval[0]);
    outtextxy(randval_x, randval_y, val);
    if(randval[0]==6)
    {
        randval[1]=(rand()%6)+1;
        //randval[1]=6;
        setcolor(CYAN);
        settextstyle(10, HORIZ_DIR, 8);
        sprintf(val,"%d",randval[1]);
        outtextxy(randval_x, randval_y+67, val);
        if(randval[1]==6)
        {
            randval[2]=(rand()%6)+1;
            //randval[2]=6;
            setcolor(CYAN);
            settextstyle(10, HORIZ_DIR, 8);
            sprintf(val,"%d",randval[2]);
            outtextxy(randval_x, randval_y+134, val);
            if(randval[2]==6)
            {
                setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
                clearviewport();
                setviewport(0,0,1360,750,1);

                setcolor(DARKGRAY);
                settextstyle(10, HORIZ_DIR, 5);
                outtextxy(randval_x+5, randval_y+220, "Oooopppss!!!");
                //outtextxy(randval_x+5, randval_y+220, "Excellent!!!");
                setcolor(LIGHTMAGENTA);
                settextstyle(10, HORIZ_DIR, 5);
                outtextxy(randval_x+5, randval_y+275, "What a bad luck...");

                setcolor(WHITE);
                setlinestyle(1, 0, 1);
                //rectangle(randval_x-5,randval_y+215,randval_x+630,randval_y+325);

                randval[0]=randval[1]=randval[2]=0;
            }
            else
            {
                setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
                clearviewport();
                setviewport(0,0,1360,750,1);
                setcolor(DARKGRAY);
                settextstyle(10, HORIZ_DIR, 5);
                outtextxy(randval_x+5, randval_y+220, "Super!!!");
            }
        }
        else
        {
            setviewport(randval_x,randval_y+145,randval_x+50,randval_y+210,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
            clearviewport();
            setviewport(0,0,1360,750,1);
            setcolor(DARKGRAY);
            settextstyle(10, HORIZ_DIR, 5);
            outtextxy(randval_x+5, randval_y+220, "Wow!!!");
            randval[2]=0;
        }
    }
    else
    {
        setviewport(randval_x,randval_y+75,randval_x+50,randval_y+210,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        setviewport(randval_x-5,randval_y+215,randval_x+630,randval_y+325,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        randval[1]=0;
        randval[2]=0;
    }
    delay(waitingTime);
}


/*Checking the priority and find the best guti to run*/

/*For one random value*/
inline int random_value_1(int gutino)
{
    int i;
    for(i=0; i<4; i++)
    {
        randval_1[i].which_guti=i;
        randval_1[i].priority=priority(gutino+i,randval[0],0,0);
    }
    int maxi,posi=0;
    maxi=randval_1[posi].priority;
    for(i=0; i<4; i++)
    {
        if(maxi<randval_1[i].priority)
        {
            maxi=randval_1[i].priority;
            posi=i;
        }
    }
    return randval_1[posi].which_guti;
}

/*For two random value*/
inline int random_value_12(int gutino)
{
    randval_12[0].which_guti=112;
    randval_12[0].priority=priority(gutino,randval[0],randval[1],0);
    randval_12[1].which_guti=212;
    randval_12[1].priority=priority(gutino+1,randval[0],randval[1],0);
    randval_12[2].which_guti=312;
    randval_12[2].priority=priority(gutino+2,randval[0],randval[1],0);
    randval_12[3].which_guti=412;
    randval_12[3].priority=priority(gutino+3,randval[0],randval[1],0);

    randval_12[4].which_guti=1122;
    randval_12[4].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+1,randval[1],0,0);
    randval_12[5].which_guti=1132;
    randval_12[5].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+2,randval[1],0,0);
    randval_12[6].which_guti=1142;
    randval_12[6].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+3,randval[1],0,0);

    randval_12[7].which_guti=1221;
    randval_12[7].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+1,randval[0],0,0);
    randval_12[8].which_guti=1231;
    randval_12[8].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+2,randval[0],0,0);
    randval_12[9].which_guti=1241;
    randval_12[9].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+3,randval[0],0,0);

    randval_12[10].which_guti=2132;
    randval_12[10].priority=priority(gutino+1,randval[0],0,0)+priority(gutino+2,randval[1],0,0);
    randval_12[11].which_guti=2142;
    randval_12[11].priority=priority(gutino+1,randval[0],0,0)+priority(gutino+3,randval[1],0,0);

    randval_12[12].which_guti=2231;
    randval_12[12].priority=priority(gutino+1,randval[1],0,0)+priority(gutino+2,randval[0],0,0);
    randval_12[13].which_guti=2241;
    randval_12[13].priority=priority(gutino+1,randval[1],0,0)+priority(gutino+3,randval[0],0,0);

    randval_12[14].which_guti=3142;
    randval_12[14].priority=priority(gutino+2,randval[0],0,0)+priority(gutino+3,randval[1],0,0);
    randval_12[15].which_guti=3241;
    randval_12[15].priority=priority(gutino+2,randval[1],0,0)+priority(gutino+3,randval[0],0,0);

    int maxi,posi=0,i;
    maxi=randval_12[posi].priority;
    for(i=0; i<16; i++)
    {
        if(maxi<randval_12[i].priority)
        {
            maxi=randval_12[i].priority;
            posi=i;
        }
    }
    return randval_12[posi].which_guti;
}

/*For three random value*/
inline int random_value_123(int gutino)
{
    randval_123[0].which_guti=1123;
    randval_123[0].priority=priority(gutino+0,randval[0],randval[1],randval[2]);
    randval_123[1].which_guti=2123;
    randval_123[1].priority=priority(gutino+1,randval[0],randval[1],randval[2]);
    randval_123[2].which_guti=3123;
    randval_123[2].priority=priority(gutino+2,randval[0],randval[1],randval[2]);
    randval_123[3].which_guti=4123;
    randval_123[3].priority=priority(gutino+3,randval[0],randval[1],randval[2]);

    randval_123[4].which_guti=11223;
    randval_123[4].priority=priority(gutino+0,randval[0],randval[1],0)+priority(gutino+1,randval[2],0,0);
    randval_123[5].which_guti=11233;
    randval_123[5].priority=priority(gutino+0,randval[0],randval[1],0)+priority(gutino+2,randval[2],0,0);
    randval_123[6].which_guti=11243;
    randval_123[6].priority=priority(gutino+0,randval[0],randval[1],0)+priority(gutino+3,randval[2],0,0);

    randval_123[7].which_guti=12321;
    randval_123[7].priority=priority(gutino+0,randval[1],randval[2],0)+priority(gutino+1,randval[0],0,0);
    randval_123[8].which_guti=12331;
    randval_123[8].priority=priority(gutino+0,randval[1],randval[2],0)+priority(gutino+2,randval[0],0,0);
    randval_123[9].which_guti=12341;
    randval_123[9].priority=priority(gutino+0,randval[1],randval[2],0)+priority(gutino+3,randval[0],0,0);

    randval_123[10].which_guti=11322;
    randval_123[10].priority=priority(gutino+0,randval[0],randval[2],0)+priority(gutino+1,randval[1],0,0);
    randval_123[11].which_guti=11332;
    randval_123[11].priority=priority(gutino+0,randval[0],randval[2],0)+priority(gutino+2,randval[1],0,0);
    randval_123[12].which_guti=11342;
    randval_123[12].priority=priority(gutino+0,randval[0],randval[2],0)+priority(gutino+3,randval[1],0,0);

    randval_123[13].which_guti=21213;
    randval_123[13].priority=priority(gutino+1,randval[0],randval[1],0)+priority(gutino+0,randval[2],0,0);
    randval_123[14].which_guti=21233;
    randval_123[14].priority=priority(gutino+1,randval[0],randval[1],0)+priority(gutino+2,randval[2],0,0);
    randval_123[15].which_guti=21243;
    randval_123[15].priority=priority(gutino+1,randval[0],randval[1],0)+priority(gutino+3,randval[2],0,0);

    randval_123[16].which_guti=22311;
    randval_123[16].priority=priority(gutino+1,randval[1],randval[2],0)+priority(gutino+0,randval[0],0,0);
    randval_123[17].which_guti=22331;
    randval_123[17].priority=priority(gutino+1,randval[1],randval[2],0)+priority(gutino+2,randval[0],0,0);
    randval_123[18].which_guti=22341;
    randval_123[18].priority=priority(gutino+1,randval[1],randval[2],0)+priority(gutino+3,randval[0],0,0);

    randval_123[19].which_guti=21312;
    randval_123[19].priority=priority(gutino+1,randval[0],randval[2],0)+priority(gutino+0,randval[1],0,0);
    randval_123[20].which_guti=21332;
    randval_123[20].priority=priority(gutino+1,randval[0],randval[2],0)+priority(gutino+2,randval[1],0,0);
    randval_123[21].which_guti=21342;
    randval_123[21].priority=priority(gutino+1,randval[0],randval[2],0)+priority(gutino+3,randval[1],0,0);

    randval_123[22].which_guti=31213;
    randval_123[22].priority=priority(gutino+2,randval[0],randval[1],0)+priority(gutino+0,randval[2],0,0);
    randval_123[23].which_guti=31223;
    randval_123[23].priority=priority(gutino+2,randval[0],randval[1],0)+priority(gutino+1,randval[2],0,0);
    randval_123[24].which_guti=31243;
    randval_123[24].priority=priority(gutino+2,randval[0],randval[1],0)+priority(gutino+3,randval[2],0,0);

    randval_123[25].which_guti=32311;
    randval_123[25].priority=priority(gutino+2,randval[1],randval[2],0)+priority(gutino+0,randval[0],0,0);
    randval_123[26].which_guti=32321;
    randval_123[26].priority=priority(gutino+2,randval[1],randval[2],0)+priority(gutino+1,randval[0],0,0);
    randval_123[27].which_guti=32341;
    randval_123[27].priority=priority(gutino+2,randval[1],randval[2],0)+priority(gutino+3,randval[0],0,0);

    randval_123[28].which_guti=31312;
    randval_123[28].priority=priority(gutino+2,randval[0],randval[2],0)+priority(gutino+0,randval[1],0,0);
    randval_123[29].which_guti=31322;
    randval_123[29].priority=priority(gutino+2,randval[0],randval[2],0)+priority(gutino+1,randval[1],0,0);
    randval_123[30].which_guti=31342;
    randval_123[30].priority=priority(gutino+2,randval[0],randval[2],0)+priority(gutino+3,randval[1],0,0);

    randval_123[31].which_guti=41213;
    randval_123[31].priority=priority(gutino+3,randval[0],randval[1],0)+priority(gutino+0,randval[2],0,0);
    randval_123[32].which_guti=41223;
    randval_123[32].priority=priority(gutino+3,randval[0],randval[1],0)+priority(gutino+1,randval[2],0,0);
    randval_123[33].which_guti=41233;
    randval_123[33].priority=priority(gutino+3,randval[0],randval[1],0)+priority(gutino+2,randval[2],0,0);

    randval_123[34].which_guti=42311;
    randval_123[34].priority=priority(gutino+3,randval[1],randval[2],0)+priority(gutino+0,randval[0],0,0);
    randval_123[35].which_guti=42321;
    randval_123[35].priority=priority(gutino+3,randval[1],randval[2],0)+priority(gutino+1,randval[0],0,0);
    randval_123[36].which_guti=42331;
    randval_123[36].priority=priority(gutino+3,randval[1],randval[2],0)+priority(gutino+2,randval[0],0,0);

    randval_123[37].which_guti=41312;
    randval_123[37].priority=priority(gutino+3,randval[0],randval[2],0)+priority(gutino+0,randval[1],0,0);
    randval_123[38].which_guti=41322;
    randval_123[38].priority=priority(gutino+3,randval[0],randval[2],0)+priority(gutino+1,randval[1],0,0);
    randval_123[39].which_guti=41332;
    randval_123[39].priority=priority(gutino+3,randval[0],randval[2],0)+priority(gutino+2,randval[1],0,0);

    randval_123[40].which_guti=112233;
    randval_123[40].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+1,randval[1],0,0)+priority(gutino+2,randval[2],0,0);
    randval_123[41].which_guti=112243;
    randval_123[41].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+1,randval[1],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[42].which_guti=112332;
    randval_123[42].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+1,randval[2],0,0)+priority(gutino+2,randval[1],0,0);
    randval_123[43].which_guti=112342;
    randval_123[43].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+1,randval[2],0,0)+priority(gutino+3,randval[1],0,0);

    randval_123[44].which_guti=122133;
    randval_123[44].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+1,randval[0],0,0)+priority(gutino+2,randval[2],0,0);
    randval_123[45].which_guti=122143;
    randval_123[45].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+1,randval[0],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[46].which_guti=122331;
    randval_123[46].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+1,randval[2],0,0)+priority(gutino+2,randval[0],0,0);
    randval_123[47].which_guti=122341;
    randval_123[47].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+1,randval[2],0,0)+priority(gutino+3,randval[0],0,0);

    randval_123[48].which_guti=132132;
    randval_123[48].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+1,randval[0],0,0)+priority(gutino+2,randval[1],0,0);
    randval_123[49].which_guti=132142;
    randval_123[49].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+1,randval[0],0,0)+priority(gutino+3,randval[1],0,0);
    randval_123[50].which_guti=132231;
    randval_123[50].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+1,randval[1],0,0)+priority(gutino+2,randval[0],0,0);
    randval_123[51].which_guti=132241;
    randval_123[51].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+1,randval[1],0,0)+priority(gutino+3,randval[0],0,0);

    randval_123[52].which_guti=113243;
    randval_123[52].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+2,randval[1],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[53].which_guti=113342;
    randval_123[53].priority=priority(gutino+0,randval[0],0,0)+priority(gutino+2,randval[2],0,0)+priority(gutino+3,randval[1],0,0);
    randval_123[54].which_guti=123143;
    randval_123[54].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+2,randval[0],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[55].which_guti=123341;
    randval_123[55].priority=priority(gutino+0,randval[1],0,0)+priority(gutino+2,randval[2],0,0)+priority(gutino+3,randval[0],0,0);
    randval_123[56].which_guti=133142;
    randval_123[56].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+2,randval[0],0,0)+priority(gutino+3,randval[1],0,0);
    randval_123[57].which_guti=133241;
    randval_123[57].priority=priority(gutino+0,randval[2],0,0)+priority(gutino+2,randval[1],0,0)+priority(gutino+3,randval[0],0,0);

    randval_123[58].which_guti=213243;
    randval_123[58].priority=priority(gutino+1,randval[0],0,0)+priority(gutino+2,randval[1],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[59].which_guti=213342;
    randval_123[59].priority=priority(gutino+1,randval[0],0,0)+priority(gutino+2,randval[2],0,0)+priority(gutino+3,randval[1],0,0);

    randval_123[60].which_guti=223143;
    randval_123[60].priority=priority(gutino+1,randval[1],0,0)+priority(gutino+2,randval[0],0,0)+priority(gutino+3,randval[2],0,0);
    randval_123[61].which_guti=223341;
    randval_123[61].priority=priority(gutino+1,randval[1],0,0)+priority(gutino+2,randval[2],0,0)+priority(gutino+3,randval[0],0,0);

    randval_123[62].which_guti=233142;
    randval_123[62].priority=priority(gutino+1,randval[2],0,0)+priority(gutino+2,randval[0],0,0)+priority(gutino+3,randval[1],0,0);
    randval_123[63].which_guti=233241;
    randval_123[63].priority=priority(gutino+1,randval[2],0,0)+priority(gutino+2,randval[1],0,0)+priority(gutino+3,randval[0],0,0);


    int maxi,posi=0,i;
    maxi=randval_123[posi].priority;
    for(i=0; i<64; i++)
    {
        if(maxi<randval_123[i].priority)
        {
            maxi=randval_123[i].priority;
            posi=i;
        }
    }
    return randval_123[posi].which_guti;
}

/*Calculating Priority*/
inline int priority(int g,int v1,int v2,int v3)
{
    int gain=0;
    if(v1 == -1  || g == -1)
    {
        gain = -1000;
        return gain;
    }

    int i,c,v,j;
    int five,six;
    int max_length,max_guti_no;
    i=guti[g].initial_pos;
    c=guti[g].current_pos;

    if(c==104)
    {
        gain=-1000;
        return gain;
    }
    else if(i==c)
    {
        if(v1==6)
        {
            gain+=10;
            v1=0;
        }
        else if(v1<6)
        {
            gain=-1000;
            return gain;
        }
    }
    int ttx=guti[g].current_pos+v1+v2+v3;
    for(int ttt=guti[g].current_pos+1; ttt<=ttx; ttt++)
    {
        if(ttt>51)
        {
            ttt-=52;
            ttx-=52;
        }

        if((main_array[ttt].guti_no_1!=-1)&&(guti[main_array[ttt].guti_no_1].player!=guti[g].player))
        {
            if((main_array[ttt].guti_no_1==main_array[ttt].guti_no_2)||(main_array[ttt].guti_no_1==main_array[ttt].guti_no_3)||(main_array[ttt].guti_no_1==main_array[ttt].guti_no_4))
            {
                gain=-1000;
                return gain;
            }
        }
        if((main_array[ttt].guti_no_2!=-1)&&(guti[main_array[ttt].guti_no_2].player!=guti[g].player))
        {
            if((main_array[ttt].guti_no_2==main_array[ttt].guti_no_3)||(main_array[ttt].guti_no_2==main_array[ttt].guti_no_4))
            {
                gain=-1000;
                return gain;
            }
        }
        if((main_array[ttt].guti_no_3!=-1)&&(guti[main_array[ttt].guti_no_3].player!=guti[g].player))
        {
            if(main_array[ttt].guti_no_3==main_array[ttt].guti_no_4)
            {
                gain=-1000;
                return gain;
            }
        }
    }



    if(guti[g].length+v1+v2+v3<57)
    {
        if(c==0)
        {
            gain-=10;
            if(guti[g].player==1)
            {
                if(main_array[88].guti_no_2==-1)
                    gain-=10;
                if((main_array[89].guti_no_1==-1)&&(main_array[90].guti_no_1==-1)&&(main_array[91].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==2)
            {
                if(main_array[89].guti_no_2==-1)
                    gain-=10;
                if((main_array[88].guti_no_1==-1)&&(main_array[90].guti_no_1==-1)&&(main_array[91].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==3)
            {
                if(main_array[90].guti_no_2==-1)
                    gain-=10;
                if((main_array[88].guti_no_1==-1)&&(main_array[89].guti_no_1==-1)&&(main_array[91].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==4)
            {
                if(main_array[91].guti_no_2==-1)
                    gain-=10;
                if((main_array[88].guti_no_1==-1)&&(main_array[89].guti_no_1==-1)&&(main_array[90].guti_no_1==-1))
                    gain+=10;
            }
        }
        else if(c==13)
        {
            gain-=10;
            if(guti[g].player==1)
            {
                if(main_array[92].guti_no_2==-1)
                    gain-=10;
                if((main_array[93].guti_no_1==-1)&&(main_array[94].guti_no_1==-1)&&(main_array[95].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==2)
            {
                if(main_array[93].guti_no_2==-1)
                    gain-=10;
                if((main_array[92].guti_no_1==-1)&&(main_array[94].guti_no_1==-1)&&(main_array[95].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==3)
            {
                if(main_array[94].guti_no_2==-1)
                    gain-=10;
                if((main_array[92].guti_no_1==-1)&&(main_array[93].guti_no_1==-1)&&(main_array[95].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==4)
            {
                if(main_array[95].guti_no_2==-1)
                    gain-=10;
                if((main_array[92].guti_no_1==-1)&&(main_array[93].guti_no_1==-1)&&(main_array[94].guti_no_1==-1))
                    gain+=10;
            }
        }
        else if(c==26)
        {
            gain-=10;
            if(guti[g].player==1)
            {
                if(main_array[96].guti_no_2==-1)
                    gain-=10;
                if((main_array[97].guti_no_1==-1)&&(main_array[98].guti_no_1==-1)&&(main_array[99].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==2)
            {
                if(main_array[97].guti_no_2==-1)
                    gain-=10;
                if((main_array[96].guti_no_1==-1)&&(main_array[98].guti_no_1==-1)&&(main_array[99].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==3)
            {
                if(main_array[98].guti_no_2==-1)
                    gain-=10;
                if((main_array[96].guti_no_1==-1)&&(main_array[97].guti_no_1==-1)&&(main_array[99].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==4)
            {
                if(main_array[99].guti_no_2==-1)
                    gain-=10;
                if((main_array[96].guti_no_1==-1)&&(main_array[97].guti_no_1==-1)&&(main_array[98].guti_no_1==-1))
                    gain+=10;
            }
        }
        else if(c==39)
        {
            gain-=10;
            if(guti[g].player==1)
            {
                if(main_array[100].guti_no_2==-1)
                    gain-=10;
                if((main_array[101].guti_no_1==-1)&&(main_array[102].guti_no_1==-1)&&(main_array[103].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==2)
            {
                if(main_array[101].guti_no_2==-1)
                    gain-=10;
                if((main_array[100].guti_no_1==-1)&&(main_array[102].guti_no_1==-1)&&(main_array[103].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==3)
            {
                if(main_array[102].guti_no_2==-1)
                    gain-=10;
                if((main_array[100].guti_no_1==-1)&&(main_array[101].guti_no_1==-1)&&(main_array[103].guti_no_1==-1))
                    gain+=10;
            }
            else if(guti[g].player==4)
            {
                if(main_array[103].guti_no_2==-1)
                    gain-=10;
                if((main_array[100].guti_no_1==-1)&&(main_array[101].guti_no_1==-1)&&(main_array[102].guti_no_1==-1))
                    gain+=10;
            }
        }
        else
            gain+=5;

        five=0;
        six=0;
        for(j=1; j<7; j++)
        {
            if(c-j>=0)
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[c-j].guti_no_1].player)
                        five=1;
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[c-j].guti_no_1].player)
                        six=1;
                }
            }
            else
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[c-j+52].guti_no_1].player)
                        five=1;
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[c-j+52].guti_no_1].player)
                        six=1;
                }
            }
        }
        if(five==1)
        {
            gain+=8;
            if((guti[g].length>39)&&(guti[g].length<51))
                gain+=6;
            else if((guti[g].length>26)&&(guti[g].length<39))
                gain+=3;
            else if((guti[g].length>13)&&(guti[g].length<26))
                gain+=2;
        }
        else
        {
            if(six==1)
            {
                gain+=6;
                if((guti[g].length>39)&&(guti[g].length<51))
                    gain+=6;
                else if((guti[g].length>26)&&(guti[g].length<39))
                    gain+=3;
                else if((guti[g].length>13)&&(guti[g].length<26))
                    gain+=2;
            }
        }


        v=c+v1+v2+v3;
        if(v>51)
            v-=52;


        if(guti[g].length+v1+v2+v3>=13)
            gain+=(guti[g].length+v1+v2+v3-13);


        if(guti[g].length+v1+v2+v3==13)
            gain+=19;
        else if(guti[g].length+v1+v2+v3==26)
            gain+=21;
        else if(guti[g].length+v1+v2+v3==39)
            gain+=25;


        if((guti[g].length+v1+v2+v3>=51)&&(guti[g].length<=50))
        {
            if(guti[g].length+v1+v2+v3<56)
                gain+=40;
            else if(guti[g].length+v1+v2+v3==56)
                gain+=42;
        }
        else if((guti[g].length+v1+v2+v3>=51)&&(guti[g].length>50))
        {
            if(guti[g].length+v1+v2+v3<56)
                gain-=5;
            else if(guti[g].length+v1+v2+v3==56)
                gain--;
        }


        if((guti[g].player!=guti[main_array[v].guti_no_1].player)||(guti[g].player!=guti[main_array[v].guti_no_2].player)||(guti[g].player!=guti[main_array[v].guti_no_3].player)||(guti[g].player!=guti[main_array[v].guti_no_4].player))
        {
            gain+=50;
            if(guti[main_array[v].guti_no_1].length>39)
            {
                if(guti[g].length>=39)
                    gain+=20;
                else if(guti[g].length>=26)
                    gain+=22;
                else if(guti[g].length>=13)
                    gain+=24;
                else if(guti[g].length>=0)
                    gain+=26;
            }
            else if(guti[main_array[v].guti_no_1].length>=26)
            {
                if(guti[g].length>=39)
                    gain+=15;
                else if(guti[g].length>=26)
                    gain+=17;
                else if(guti[g].length>=13)
                    gain+=19;
                else if(guti[g].length>=0)
                    gain+=21;
            }
            else if(guti[main_array[v].guti_no_1].length>=13)
            {
                if(guti[g].length>=39)
                    gain+=10;
                else if(guti[g].length>=26)
                    gain+=12;
                else if(guti[g].length>=13)
                    gain+=14;
                else if(guti[g].length>=0)
                    gain+=16;
            }
            else if(guti[main_array[v].guti_no_1].length>=0)
            {
                if(guti[g].length>=39)
                    gain+=5;
                else if(guti[g].length>=26)
                    gain+=7;
                else if(guti[g].length>=13)
                    gain+=9;
                else if(guti[g].length>=0)
                    gain+=11;
            }
        }


        five=0;
        six=0;
        for(j=1; j<7; j++)
        {
            if(v-j>=0)
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[v-j].guti_no_1].player)
                        five=1;
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[v-j].guti_no_1].player)
                        six=1;
                }
            }
            else
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[v-j+52].guti_no_1].player)
                        five=1;
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[v-j+52].guti_no_1].player)
                        six=1;
                }
            }
        }
        if(five==1)
        {
            gain-=8;
            if((guti[g].length>=39)&&(guti[g].length<51))
                gain-=9;
            else if((guti[g].length>=26)&&(guti[g].length<39))
                gain-=6;
            else if((guti[g].length>=13)&&(guti[g].length<26))
                gain-=3;
        }
        else
        {
            if(six==1)
            {
                gain-=6;
                if((guti[g].length>=39)&&(guti[g].length<51))
                    gain-=9;
                else if((guti[g].length>=26)&&(guti[g].length<39))
                    gain-=6;
                else if((guti[g].length>=13)&&(guti[g].length<26))
                    gain-=3;
            }
        }


        five=0;
        six=0;
        max_length=-10;
        for(j=1; j<7; j++)
        {
            if(v+j<52)
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[v+j].guti_no_1].player)
                    {
                        five=1;
                        if(max_length<guti[main_array[v+j].guti_no_1].length)
                        {
                            max_length=guti[main_array[v+j].guti_no_1].length;
                            max_guti_no=main_array[v+j].guti_no_1;
                        }
                    }
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[v+j].guti_no_1].player)
                    {
                        six=1;
                        if(max_length<guti[main_array[v+j].guti_no_1].length)
                        {
                            max_length=guti[main_array[v+j].guti_no_1].length;
                            max_guti_no=main_array[v+j].guti_no_1;
                        }
                    }
                }
            }
            else
            {
                if((j>0)&&(j<6))
                {
                    if(guti[g].player!=guti[main_array[v+j-52].guti_no_1].player)
                    {
                        five=1;
                        if(max_length<guti[main_array[v+j-52].guti_no_1].length)
                        {
                            max_length=guti[main_array[v+j-52].guti_no_1].length;
                            max_guti_no=main_array[v+j-52].guti_no_1;
                        }
                    }
                }
                else if(j==6)
                {
                    if(guti[g].player!=guti[main_array[v+j-52].guti_no_1].player)
                    {
                        six=1;
                        if(max_length<guti[main_array[v+j-52].guti_no_1].length)
                        {
                            max_length=guti[main_array[v+j-52].guti_no_1].length;
                            max_guti_no=main_array[v+j-52].guti_no_1;
                        }
                    }
                }
            }

        }
        if(five==1)
        {
            gain+=7;
            if((guti[g].length>=39)&&(guti[g].length<51))
            {
                if(guti[max_guti_no].length<13)
                    gain++;
                else if(guti[max_guti_no].length<26)
                    gain+=2;
                else if(guti[max_guti_no].length<39)
                    gain+=3;
                else if(guti[max_guti_no].length<51)
                    gain+=4;
            }
            else if((guti[g].length>=26)&&(guti[g].length<39))
            {
                if(guti[max_guti_no].length<13)
                    gain+=3;
                else if(guti[max_guti_no].length<26)
                    gain+=4;
                else if(guti[max_guti_no].length<39)
                    gain+=5;
                else if(guti[max_guti_no].length<51)
                    gain+=6;
            }
            else if((guti[g].length>=13)&&(guti[g].length<26))
            {
                if(guti[max_guti_no].length<13)
                    gain+=5;
                else if(guti[max_guti_no].length<26)
                    gain+=6;
                else if(guti[max_guti_no].length<39)
                    gain+=7;
                else if(guti[max_guti_no].length<51)
                    gain+=8;
            }
            else if((guti[g].length>=0)&&(guti[g].length<13))
            {
                if(guti[max_guti_no].length<13)
                    gain+=8;
                else if(guti[max_guti_no].length<26)
                    gain+=9;
                else if(guti[max_guti_no].length<39)
                    gain+=11;
                else if(guti[max_guti_no].length<51)
                    gain+=12;
            }
        }
        else
        {
            if(six==1)
            {
                gain+=5;
                if((guti[g].length>=39)&&(guti[g].length<51))
                {
                    if(guti[max_guti_no].length<13)
                        gain++;
                    else if(guti[max_guti_no].length<26)
                        gain+=2;
                    else if(guti[max_guti_no].length<39)
                        gain+=3;
                    else if(guti[max_guti_no].length<51)
                        gain+=4;
                }
                else if((guti[g].length>=26)&&(guti[g].length<39))
                {
                    if(guti[max_guti_no].length<13)
                        gain+=3;
                    else if(guti[max_guti_no].length<26)
                        gain+=4;
                    else if(guti[max_guti_no].length<39)
                        gain+=5;
                    else if(guti[max_guti_no].length<51)
                        gain+=6;
                }
                else if((guti[g].length>=13)&&(guti[g].length<26))
                {
                    if(guti[max_guti_no].length<13)
                        gain+=5;
                    else if(guti[max_guti_no].length<26)
                        gain+=6;
                    else if(guti[max_guti_no].length<39)
                        gain+=7;
                    else if(guti[max_guti_no].length<51)
                        gain+=8;
                }
                else if((guti[g].length>=0)&&(guti[g].length<13))
                {
                    if(guti[max_guti_no].length<13)
                        gain+=8;
                    else if(guti[max_guti_no].length<26)
                        gain+=9;
                    else if(guti[max_guti_no].length<39)
                        gain+=11;
                    else if(guti[max_guti_no].length<51)
                        gain+=12;
                }
            }
        }
    }
    else
        gain=-1000;

    return gain;
}

/*Run the best guti*/
inline int run_guti(int g,int v)
{
    float posxx;
    float posyy;

    if((guti[g].current_pos==guti[g].initial_pos)&&(v>=6))
    {
        posxx=main_array[guti[g].initial_pos].mid_x;
        posyy=main_array[guti[g].initial_pos].mid_y;

        setviewport(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5,1);
        clearviewport();
        setviewport(0,0,1360,750,1);
        main_array[guti[g].initial_pos].guti_no_1=-1;

        guti[g].current_pos=guti[g].start_pos;
        v-=6;

        if(v==0)
        {
            if(main_array[guti[g].current_pos].guti_no_1==-1)
                main_array[guti[g].current_pos].guti_no_1=g;
            else if(main_array[guti[g].current_pos].guti_no_2==-1)
                main_array[guti[g].current_pos].guti_no_2=g;
            else if(main_array[guti[g].current_pos].guti_no_3==-1)
                main_array[guti[g].current_pos].guti_no_3=g;
            else if(main_array[guti[g].current_pos].guti_no_4==-1)
                main_array[guti[g].current_pos].guti_no_4=g;

            if(guti[g].player==1)
                player_1_put_guti(guti[g].current_pos);
            else if(guti[g].player==2)
                player_2_put_guti(guti[g].current_pos);
            else if(guti[g].player==3)
                player_3_put_guti(guti[g].current_pos);
            else if(guti[g].player==4)
                player_4_put_guti(guti[g].current_pos);

            return 0;
        }
    }
    else if((guti[g].current_pos==guti[g].initial_pos)&&(v<6))
        return 0;
    else if((guti[g].length+v>56)||(guti[g].length>56))
        return 0;
    else if(guti[g].current_pos>=104)
        return 0;

    posxx=main_array[guti[g].current_pos].mid_x;
    posyy=main_array[guti[g].current_pos].mid_y;

    setviewport(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5,1);
    clearviewport();
    setviewport(0,0,1360,750,1);

    if((guti[g].current_pos>51)&&(guti[g].current_pos<57))
    {
        posxx=main_array[guti[g].current_pos].mid_x;
        posyy=main_array[guti[g].current_pos].mid_y;

        setcolor(RED);
        rectangle(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5);
        setfillstyle(SOLID_FILL, RED);
        floodfill(posxx, posyy, RED);
        setviewport(0,0,1360,750,1);
        setcolor(BLACK);
    }
    else if((guti[g].current_pos>56)&&(guti[g].current_pos<62))
    {
        posxx=main_array[guti[g].current_pos].mid_x;
        posyy=main_array[guti[g].current_pos].mid_y;

        setcolor(GREEN);
        rectangle(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(posxx, posyy, GREEN);
        setviewport(0,0,1360,750,1);
        setcolor(BLACK);
    }
    else if((guti[g].current_pos>61)&&(guti[g].current_pos<67))
    {
        posxx=main_array[guti[g].current_pos].mid_x;
        posyy=main_array[guti[g].current_pos].mid_y;

        setcolor(YELLOW);
        rectangle(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5);
        setfillstyle(SOLID_FILL, YELLOW);
        floodfill(posxx, posyy, YELLOW);
        setviewport(0,0,1360,750,1);
        setcolor(BLACK);
    }
    else if((guti[g].current_pos>66)&&(guti[g].current_pos<72))
    {
        posxx=main_array[guti[g].current_pos].mid_x;
        posyy=main_array[guti[g].current_pos].mid_y;

        setcolor(BLUE);
        rectangle(posxx-20.5,posyy-20.5,posxx+21.5,posyy+21.5);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill(posxx, posyy, BLUE);
        setviewport(0,0,1360,750,1);
        setcolor(BLACK);
    }

    if(main_array[guti[g].current_pos].guti_no_1==g)
        main_array[guti[g].current_pos].guti_no_1=-1;
    else if(main_array[guti[g].current_pos].guti_no_2==g)
        main_array[guti[g].current_pos].guti_no_2=-1;
    else if(main_array[guti[g].current_pos].guti_no_3==g)
        main_array[guti[g].current_pos].guti_no_3=-1;
    else if(main_array[guti[g].current_pos].guti_no_4==g)
        main_array[guti[g].current_pos].guti_no_4=-1;

    if(guti[g].player==1)
        player_1_put_guti(guti[g].current_pos);
    else if(guti[g].player==2)
        player_2_put_guti(guti[g].current_pos);
    else if(guti[g].player==3)
        player_3_put_guti(guti[g].current_pos);
    else if(guti[g].player==4)
        player_4_put_guti(guti[g].current_pos);

    if(v!=0)
    {
        if((guti[g].current_pos>87)&&(guti[g].current_pos<92))
        {
            if((guti[g].length+v)>50)
            {
                if((guti[g].length+v)==56)
                {
                    guti[g].current_pos=104;
                    guti[g].length+=v;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
                else
                {
                    guti[g].current_pos=0+v-guti[g].turn_after+guti[g].turn_into-1;
                    guti[g].length+=v;
                }
            }
            else
            {
                guti[g].current_pos=0+v;
                guti[g].length+=v;
            }
            if(guti[g].current_pos==13)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=92;
                else if(guti[g].player==2)
                    guti[g].current_pos=93;
                else if(guti[g].player==3)
                    guti[g].current_pos=94;
                else if(guti[g].player==4)
                    guti[g].current_pos=95;
            }
        }
        else if((guti[g].current_pos>91)&&(guti[g].current_pos<96))
        {
            if((guti[g].length+v)>50)
            {
                if((guti[g].length+v)==56)
                {
                    guti[g].current_pos=104;
                    guti[g].length+=v;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
                else
                {
                    guti[g].current_pos=13+v-guti[g].turn_after+guti[g].turn_into-1;
                    guti[g].length+=v;
                }
            }
            else
            {
                guti[g].current_pos=13+v;
                guti[g].length+=v;
            }
            if(guti[g].current_pos==26)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=96;
                else if(guti[g].player==2)
                    guti[g].current_pos=97;
                else if(guti[g].player==3)
                    guti[g].current_pos=98;
                else if(guti[g].player==4)
                    guti[g].current_pos=99;
            }
        }
        else if((guti[g].current_pos>95)&&(guti[g].current_pos<100))
        {
            if((guti[g].length+v)>50)
            {
                if((guti[g].length+v)==56)
                {
                    guti[g].current_pos=104;
                    guti[g].length+=v;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
                else
                {
                    guti[g].current_pos=26+v-guti[g].turn_after+guti[g].turn_into-1;
                    guti[g].length+=v;
                }
            }
            else
            {
                guti[g].current_pos=26+v;
                guti[g].length+=v;
            }
            if(guti[g].current_pos==39)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=100;
                else if(guti[g].player==2)
                    guti[g].current_pos=101;
                else if(guti[g].player==3)
                    guti[g].current_pos=102;
                else if(guti[g].player==4)
                    guti[g].current_pos=103;
            }
        }
        else if((guti[g].current_pos>99)&&(guti[g].current_pos<104))
        {
            if((guti[g].length+v)>50)
            {
                if((guti[g].length+v)==56)
                {
                    guti[g].current_pos=104;
                    guti[g].length+=v;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
                else
                {
                    guti[g].current_pos=39+v-guti[g].turn_after+guti[g].turn_into-1;
                    guti[g].length+=v;
                }
            }
            else
            {
                guti[g].current_pos=39+v;
                guti[g].length+=v;
            }

            if((guti[g].current_pos>51)&&(guti[g].length<51))
                guti[g].current_pos-=52;

            if(guti[g].current_pos==0)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=88;
                else if(guti[g].player==2)
                    guti[g].current_pos=89;
                else if(guti[g].player==3)
                    guti[g].current_pos=90;
                else if(guti[g].player==4)
                    guti[g].current_pos=91;
            }
        }
        else
        {
            if(((guti[g].length+v)>50)&&(guti[g].length<=50))
            {
                if((guti[g].length+v)==56)
                {
                    guti[g].current_pos=104;
                    guti[g].length+=v;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
                else
                {
                    guti[g].current_pos=guti[g].current_pos+v-guti[g].turn_after+guti[g].turn_into-1;
                    guti[g].length+=v;
                }
            }
            else
            {
                guti[g].current_pos=guti[g].current_pos+v;
                guti[g].length+=v;

                if(guti[g].length==56)
                {
                    guti[g].current_pos=104;

                    if(guti[g].player==1)
                    {
                        p1++;
                        if(p1==4)
                        {
                            if(first==0)
                                first=1;
                            else if(second==0)
                                second=1;
                            else if(third==0)
                                third=1;
                        }
                    }
                    else if(guti[g].player==2)
                    {
                        p2++;
                        if(p2==4)
                        {
                            if(first==0)
                                first=2;
                            else if(second==0)
                                second=2;
                            else if(third==0)
                                third=2;
                        }
                    }
                    else if(guti[g].player==3)
                    {
                        p3++;
                        if(p3==4)
                        {
                            if(first==0)
                                first=3;
                            else if(second==0)
                                second=3;
                            else if(third==0)
                                third=3;
                        }
                    }
                    else if(guti[g].player==4)
                    {
                        p4++;
                        if(p4==4)
                        {
                            if(first==0)
                                first=4;
                            else if(second==0)
                                second=4;
                            else if(third==0)
                                third=4;
                        }
                    }
                    scoreboard();
                }
            }

            if((guti[g].current_pos>51)&&(guti[g].length<51))
                guti[g].current_pos-=52;

            if(guti[g].current_pos==0)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=88;
                else if(guti[g].player==2)
                    guti[g].current_pos=89;
                else if(guti[g].player==3)
                    guti[g].current_pos=90;
                else if(guti[g].player==4)
                    guti[g].current_pos=91;
            }
            else if(guti[g].current_pos==13)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=92;
                else if(guti[g].player==2)
                    guti[g].current_pos=93;
                else if(guti[g].player==3)
                    guti[g].current_pos=94;
                else if(guti[g].player==4)
                    guti[g].current_pos=95;
            }
            else if(guti[g].current_pos==26)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=96;
                else if(guti[g].player==2)
                    guti[g].current_pos=97;
                else if(guti[g].player==3)
                    guti[g].current_pos=98;
                else if(guti[g].player==4)
                    guti[g].current_pos=99;
            }
            else if(guti[g].current_pos==39)
            {
                if(guti[g].player==1)
                    guti[g].current_pos=100;
                else if(guti[g].player==2)
                    guti[g].current_pos=101;
                else if(guti[g].player==3)
                    guti[g].current_pos=102;
                else if(guti[g].player==4)
                    guti[g].current_pos=103;
            }
        }

        /*replace enemy guti*/
        if(main_array[guti[g].current_pos].guti_no_1!=-1)
        {
            if((guti[g].player!=guti[main_array[guti[g].current_pos].guti_no_1].player)&&(guti[g].current_pos!=104))
            {


                guti[main_array[guti[g].current_pos].guti_no_1].current_pos=guti[main_array[guti[g].current_pos].guti_no_1].initial_pos;
                guti[main_array[guti[g].current_pos].guti_no_1].length=0;

                main_array[guti[main_array[guti[g].current_pos].guti_no_1].current_pos].guti_no_1=main_array[guti[g].current_pos].guti_no_1;

                if(guti[main_array[guti[g].current_pos].guti_no_1].player==1)
                    player_1_put_guti(guti[main_array[guti[g].current_pos].guti_no_1].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_1].player==2)
                    player_2_put_guti(guti[main_array[guti[g].current_pos].guti_no_1].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_1].player==3)
                    player_3_put_guti(guti[main_array[guti[g].current_pos].guti_no_1].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_1].player==4)
                    player_4_put_guti(guti[main_array[guti[g].current_pos].guti_no_1].current_pos);

                main_array[guti[g].current_pos].guti_no_1=-1;

                if(guti[g].player==1)
                    bonus=1;
                else if(guti[g].player==2)
                    bonus=2;
                else if(guti[g].player==3)
                    bonus=3;
                else if(guti[g].player==4)
                    bonus=4;
            }
        }
        else if(main_array[guti[g].current_pos].guti_no_2!=-1)
        {
            if((guti[g].player!=guti[main_array[guti[g].current_pos].guti_no_2].player)&&(guti[g].current_pos!=104))
            {


                guti[main_array[guti[g].current_pos].guti_no_2].current_pos=guti[main_array[guti[g].current_pos].guti_no_2].initial_pos;
                guti[main_array[guti[g].current_pos].guti_no_2].length=0;

                main_array[guti[main_array[guti[g].current_pos].guti_no_2].current_pos].guti_no_1=main_array[guti[g].current_pos].guti_no_2;

                if(guti[main_array[guti[g].current_pos].guti_no_2].player==1)
                    player_1_put_guti(guti[main_array[guti[g].current_pos].guti_no_2].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_2].player==2)
                    player_2_put_guti(guti[main_array[guti[g].current_pos].guti_no_2].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_2].player==3)
                    player_3_put_guti(guti[main_array[guti[g].current_pos].guti_no_2].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_2].player==4)
                    player_4_put_guti(guti[main_array[guti[g].current_pos].guti_no_2].current_pos);

                main_array[guti[g].current_pos].guti_no_2=-1;

                if(guti[g].player==1)
                    bonus=1;
                else if(guti[g].player==2)
                    bonus=2;
                else if(guti[g].player==3)
                    bonus=3;
                else if(guti[g].player==4)
                    bonus=4;
            }
        }
        else if(main_array[guti[g].current_pos].guti_no_3!=-1)
        {
            if((guti[g].player!=guti[main_array[guti[g].current_pos].guti_no_3].player)&&(guti[g].current_pos!=104))
            {


                guti[main_array[guti[g].current_pos].guti_no_3].current_pos=guti[main_array[guti[g].current_pos].guti_no_3].initial_pos;
                guti[main_array[guti[g].current_pos].guti_no_3].length=0;

                main_array[guti[main_array[guti[g].current_pos].guti_no_3].current_pos].guti_no_1=main_array[guti[g].current_pos].guti_no_3;

                if(guti[main_array[guti[g].current_pos].guti_no_3].player==1)
                    player_1_put_guti(guti[main_array[guti[g].current_pos].guti_no_3].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_3].player==2)
                    player_2_put_guti(guti[main_array[guti[g].current_pos].guti_no_3].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_3].player==3)
                    player_3_put_guti(guti[main_array[guti[g].current_pos].guti_no_3].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_3].player==4)
                    player_4_put_guti(guti[main_array[guti[g].current_pos].guti_no_3].current_pos);

                main_array[guti[g].current_pos].guti_no_3=-1;

                if(guti[g].player==1)
                    bonus=1;
                else if(guti[g].player==2)
                    bonus=2;
                else if(guti[g].player==3)
                    bonus=3;
                else if(guti[g].player==4)
                    bonus=4;
            }
        }
        else if(main_array[guti[g].current_pos].guti_no_4!=-1)
        {
            if((guti[g].player!=guti[main_array[guti[g].current_pos].guti_no_4].player)&&(guti[g].current_pos!=104))
            {


                guti[main_array[guti[g].current_pos].guti_no_4].current_pos=guti[main_array[guti[g].current_pos].guti_no_4].initial_pos;
                guti[main_array[guti[g].current_pos].guti_no_4].length=0;

                main_array[guti[main_array[guti[g].current_pos].guti_no_4].current_pos].guti_no_1=main_array[guti[g].current_pos].guti_no_4;

                if(guti[main_array[guti[g].current_pos].guti_no_4].player==1)
                    player_1_put_guti(guti[main_array[guti[g].current_pos].guti_no_4].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_4].player==2)
                    player_2_put_guti(guti[main_array[guti[g].current_pos].guti_no_4].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_4].player==3)
                    player_3_put_guti(guti[main_array[guti[g].current_pos].guti_no_4].current_pos);
                else if(guti[main_array[guti[g].current_pos].guti_no_4].player==4)
                    player_4_put_guti(guti[main_array[guti[g].current_pos].guti_no_4].current_pos);

                main_array[guti[g].current_pos].guti_no_4=-1;

                if(guti[g].player==1)
                    bonus=1;
                else if(guti[g].player==2)
                    bonus=2;
                else if(guti[g].player==3)
                    bonus=3;
                else if(guti[g].player==4)
                    bonus=4;
            }
        }
    }

    if(main_array[guti[g].current_pos].guti_no_1==-1)
        main_array[guti[g].current_pos].guti_no_1=g;
    else if(main_array[guti[g].current_pos].guti_no_2==-1)
        main_array[guti[g].current_pos].guti_no_2=g;
    else if(main_array[guti[g].current_pos].guti_no_3==-1)
        main_array[guti[g].current_pos].guti_no_3=g;
    else if(main_array[guti[g].current_pos].guti_no_4==-1)
        main_array[guti[g].current_pos].guti_no_4=g;

    if(guti[g].player==1)
        player_1_put_guti(guti[g].current_pos);
    else if(guti[g].player==2)
        player_2_put_guti(guti[g].current_pos);
    else if(guti[g].player==3)
        player_3_put_guti(guti[g].current_pos);
    else if(guti[g].player==4)
        player_4_put_guti(guti[g].current_pos);
}

/*Putting the guti for player 1*/
inline int player_1_put_guti(int pos)
{
    float posxx;
    float posyy;

    if(pos==104)
        return 0;

    int values=0;
    if(main_array[pos].guti_no_1!=-1)
    {
        values*=10;
        values=values+main_array[pos].guti_no_1+1;
    }
    if(main_array[pos].guti_no_2!=-1)
    {
        values*=10;
        values=values+main_array[pos].guti_no_2+1;
    }
    if(main_array[pos].guti_no_3!=-1)
    {
        values*=10;
        values=values+main_array[pos].guti_no_3+1;
    }
    if(main_array[pos].guti_no_4!=-1)
    {
        values*=10;
        values=values+main_array[pos].guti_no_4+1;
    }
    if(values!=0)
    {
        posxx=main_array[pos].mid_x;
        posyy=main_array[pos].mid_y;

        setcolor(RED);
        sector(posxx, posyy, 0, 360, 18, 18);
        setcolor(WHITE);
        if(values<9)
        {
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",values);
            outtextxy(posxx-7, posyy-13, val);
        }
        else if(values<99)
        {
            settextstyle(10, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-12, posyy-12, val);
        }
        else if(values<999)
        {
            settextstyle(10, HORIZ_DIR, 1);
            sprintf(val,"%d",values);
            outtextxy(posxx-16, posyy-12, val);
        }
        else if(values<9999)
        {
            settextstyle(11, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-15, posyy-8, val);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        circle(posxx, posyy,20);
    }
}

/*Putting the guti for player 2*/
inline int player_2_put_guti(int pos)
{
    float posxx;
    float posyy;

    if(pos==104)
        return 0;

    int values=0;
    if(main_array[pos].guti_no_1!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_1-3);
    }
    if(main_array[pos].guti_no_2!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_2-3);
    }
    if(main_array[pos].guti_no_3!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_3-3);
    }
    if(main_array[pos].guti_no_4!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_4-3);
    }

    if(values!=0)
    {
        posxx=main_array[pos].mid_x;
        posyy=main_array[pos].mid_y;

        setcolor(GREEN);
        sector(posxx, posyy, 0, 360, 18, 18);
        setcolor(WHITE);
        if(values<9)
        {
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",values);
            outtextxy(posxx-7, posyy-13, val);
        }
        else if(values<99)
        {
            settextstyle(10, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-12, posyy-12, val);
        }
        else if(values<999)
        {
            settextstyle(10, HORIZ_DIR, 1);
            sprintf(val,"%d",values);
            outtextxy(posxx-16, posyy-12, val);
        }
        else if(values<9999)
        {
            settextstyle(11, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-15, posyy-8, val);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        circle(posxx, posyy,20);
    }
}

/*Putting the guti for player 3*/
inline int player_3_put_guti(int pos)
{
    float posxx;
    float posyy;

    if(pos==104)
        return 0;

    int values=0;
    if(main_array[pos].guti_no_1!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_1-7);
    }
    if(main_array[pos].guti_no_2!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_2-7);
    }
    if(main_array[pos].guti_no_3!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_3-7);
    }
    if(main_array[pos].guti_no_4!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_4-7);
    }

    if(values!=0)
    {
        posxx=main_array[pos].mid_x;
        posyy=main_array[pos].mid_y;

        setcolor(YELLOW);
        sector(posxx, posyy, 0, 360, 18, 18);
        setcolor(WHITE);
        if(values<9)
        {
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",values);
            outtextxy(posxx-7, posyy-13, val);
        }
        else if(values<99)
        {
            settextstyle(10, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-12, posyy-12, val);
        }
        else if(values<999)
        {
            settextstyle(10, HORIZ_DIR, 1);
            sprintf(val,"%d",values);
            outtextxy(posxx-16, posyy-12, val);
        }
        else if(values<9999)
        {
            settextstyle(11, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-15, posyy-8, val);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        circle(posxx, posyy,20);
    }
}

/*Putting the guti for player 4*/
inline int player_4_put_guti(int pos)
{
    float posxx;
    float posyy;

    if(pos==104)
        return 0;

    int values=0;
    if(main_array[pos].guti_no_1!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_1-11);
    }
    if(main_array[pos].guti_no_2!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_2-11);
    }
    if(main_array[pos].guti_no_3!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_3-11);
    }
    if(main_array[pos].guti_no_4!=-1)
    {
        values*=10;
        values=values+(main_array[pos].guti_no_4-11);
    }

    if(values!=0)
    {
        posxx=main_array[pos].mid_x;
        posyy=main_array[pos].mid_y;

        setcolor(BLUE);
        sector(posxx, posyy, 0, 360, 18, 18);
        setcolor(WHITE);
        if(values<9)
        {
            settextstyle(10, HORIZ_DIR, 3);
            sprintf(val,"%d",values);
            outtextxy(posxx-7, posyy-13, val);
        }
        else if(values<99)
        {
            settextstyle(10, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-12, posyy-12, val);
        }
        else if(values<999)
        {
            settextstyle(10, HORIZ_DIR, 1);
            sprintf(val,"%d",values);
            outtextxy(posxx-16, posyy-12, val);
        }
        else if(values<9999)
        {
            settextstyle(11, HORIZ_DIR, 2);
            sprintf(val,"%d",values);
            outtextxy(posxx-15, posyy-8, val);
        }
        setlinestyle(0, 0, 2);
        setcolor(WHITE);
        circle(posxx, posyy,20);
    }
}

int main()
{
    initwindow(1360,710);

    main_array=(struct keep_pos*)malloc(sizeof(struct keep_pos)*105);
    guti=(struct guti_info*)malloc(sizeof(struct guti_info)*16);
    randval_123=(struct calculation*)malloc(sizeof(struct calculation)*64);
    randval_12=(struct calculation*)malloc(sizeof(struct calculation)*16);
    randval_1=(struct calculation*)malloc(sizeof(struct calculation)*4);

    homeScreen();

    return 0;
}

