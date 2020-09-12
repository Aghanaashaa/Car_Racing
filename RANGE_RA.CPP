#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void enemycar(int x, int y)
{
setcolor(15);
rectangle(x+1,y,x+49,y+100);
rectangle(x+1,y+25,x+49,y+75);
setfillstyle(2,BLUE);
floodfill((x+x+50)/2,(y+y+100)/2,15);
setfillstyle(1,YELLOW);
floodfill((x+x+50)/2,(y+y+40)/2,15);
floodfill((x+x+50)/2,(y+y+160)/2,15);
}

void mycar(int x,int y)
{
setcolor(15);
rectangle(x+1,y,x+49,y+100);
rectangle(x+1,y+25,x+49,y+75);
setfillstyle(1,8);
floodfill((x+x+50)/2,(y+y+100)/2,8);
floodfill((x+x+50)/2,(y+y+40)/2,8);
floodfill((x+x+50)/2,(y+y+160)/2,8);
}

void enemyclear(int x, int y)
{
setcolor(8);
rectangle(x+1,y,x+49,y+100);
rectangle(x+1,y+25,x+489,y+75);
//line(x+1,y,x+1,y+100);
//delay(500);
}

void main()
{ int d,g;
d=DETECT;
initgraph(&d,&g,"..\\BGI");
int x=300,y=350,ch,life=3,score=0;
char choice;
delay(200);
for(int m=1;m<25;m++)
{
for(int n=1;n<80;n++)
{
gotoxy(n,m);
cout<<"";
}
setcolor(RED);
rectangle(20,60,200,120);
rectangle(20,30,200,420);
gotoxy(5,21);
cout<<"Avoid incoming cars!!";
gotoxy(5,22);
cout<<"Save yourself!!";
gotoxy(5,23);
cout<<"Use arrow keys";
gotoxy(5,24);
cout<<"AA";
rectangle(249,0,401,getmaxy());
setfillstyle(1,8);
floodfill(325,getmaxy()/2,RED);
setcolor(RED);
rectangle(20,200,200,250);
gotoxy(5,15);
cout<<"Press <Esc> to Exit";
for(int level=1;(level<=5)&&(life>0);level++)
{
if(level==1){
gotoxy(5,5);
cout<<"--STARTS NOW--";
gotoxy(5,7);
cout<<" Good Luck!    ";
delay(1000);
gotoxy(5,5);
cout<<"     ";
gotoxy(5,7);
cout<<"     ";
}
else
{
gotoxy(5,5);
cout<<"Next Level";
delay(500);
gotoxy(5,5);
cout<<"";
}
for(int i=0;(i<15)&&(life>0);i++)
{
if((level==5)&&(i==14))
{
gotoxy(5,5);
cout<<"You Won!";
gotoxy(5,6);
cout<<"Wanna Continue<y/n>";
choice=getch();
if((choice=='y')||(choice=='Y'))
main();
else
exit(0);
}
setcolor(RED);
rectangle(420,125,600,175);
gotoxy(55,10);
cout<<"Level ="<<level;
rectangle(420,350,600,400);
gotoxy(55,18);
cout<<"Lives="<<life;
rectangle(420,350,600,400);
gotoxy(55,24);
cout<<"Score="<<score;
int accident=0;
int y1=1,x1=250+((rand()%3)*50);
int y2=1,x2=250+((rand()%3)*50);
score+=10;
while(y1<getmaxy()-1)
{
enemyclear(x1,y1);
enemyclear(x2,y2);
y1++;
y2++;
if(accident==1)
break;
enemycar(x1,y1);
enemycar(x2,y2);
mycar(x,y);
delay(5-level);
if(kbhit())
{
mycar(x,y);
ch=getch();
switch(ch)
{
case 27:exit(0);
break;
case 75:mycar(x,y);
if(x>250)
x=x-50;
if((x==x1)||(x==x2))
if(  ( ( (y-y1)<100) && ((y-y1) >0) ) ||( ( (y-y2)<100) && ((y-y2)>0) ))
{
accident=1;
x=x+50;
mycar(x,y);
goto Next1;
}
mycar(x,y);
break;
case 77: mycar(x,y);
if(x<350)
if((x==x1)||(x==x2))
if( ( ((y-y1)<100) && ((y-y1)>0) ) ||(((y-y2)<100) && ((y-y2) >0 ) ))
{accident=1;
x=x-50;
mycar(x,y);
goto Next1;
}
mycar(x,y);
break;
case 72:mycar(x,y);
if(y>0)
y=y-5;
mycar(x,y);
break;
case 80: mycar(x,y);
if(y<getmaxy()-105)
y=y+5;
mycar(x,y);
break;
}
}
if((x==x1)||(x==x2))
if(((y-y1)<100)&((y-y1)>0)&&(y-y2<100)&&((y-y2)>0))
accident=1;

Next1:
if(accident==1)
{
life=life-1;
score-=10;
if(life==0)
{
gotoxy(5,5);
cout<<"GAME OVER   ";
gotoxy(5,6);
cout<<"Could'nt save ";
gotoxy(5,7);
cout<<" yourself";
break;
}
gotoxy(5,6);
cout<<"1 Life lost";
delay(500);
gotoxy(5,5);
cout<<" ";
}
}
}
}
getch();
}
}   //End of main

