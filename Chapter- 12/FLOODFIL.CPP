#include<iostream.h>
#include<graphics.h>
#include<dos.h>

void Flood_Fill(int x,int y,int old_Color,int new_Color)
{
if(getpixel(x,y) == old_Color)
{
putpixel(x,y,new_Color);
Flood_Fill(x+1,y,old_Color,new_Color);
Flood_Fill(x,y+1,old_Color,new_Color);
Flood_Fill(x-1,y,old_Color,new_Color);
Flood_Fill(x,y-1,old_Color,new_Color);
}
}

int main()
{
int gm,gd=DETECT,r;
int x,y;
cout<<"Enter x and y positions for the circle :\n";
cin>>x>>y;
cout<<"Enter radius of the circle :\n";
cin>>r;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
circle(x,y,r);
Flood_Fill(x,y,0,10);
closegraph();
return 0;
}
