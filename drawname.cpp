#include<stdio.h>
#include<graphics.h>
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


//print
void putpixels(float x, float y)
{
    float h = 450;
    float w = 550;
    putpixel(x+w/2, (h/2)-y, GREEN);
}

void drawCircle(int xc, int yc, int x, int y)
{
    float h = 450;
    float w = 550;

    putpixel(xc+x+w/2, (h/2)-(yc+y), GREEN);
    putpixel(xc-x+w/2, (h/2)-(yc+y), GREEN);
    putpixel(xc+x+w/2, (h/2)-(yc-y), GREEN);
    putpixel(xc-x+w/2, (h/2)-(yc-y), GREEN);
    putpixel(xc+y+w/2, (h/2)-(yc+x), GREEN);
    putpixel(xc-y+w/2, (h/2)-(yc+x), GREEN);
    putpixel(xc+y+w/2, (h/2)-(yc-x), GREEN);
    putpixel(xc-y+w/2, (h/2)-(yc-x), GREEN);
}

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

// Function for line generation
void bresenham(float x1, float y1, float x2, float y2)
{
    // Find Delta
    float dx = x2-x1;
    float dy = y2-y1;

    // Find Signs
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Get Initial Points
    float x = x1;
    float y = y1;

    // Flag to check if swapping happens
    int isSwaped = 0;

    // Swap if needed
    if(abs(dy) > abs(dx))
    {
        // swap dx and dy
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    // Decision parameter
    float p = 2*(abs(dy)) - abs(dx);

    //Print Initial Point
    putpixels(x,y);
    delay(20);

    // Loop for dx times
    for(int i = 0; i<= abs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                putpixels(x,y);
                delay(20);
            }
            else{
                y = y+sy;
                putpixels(x,y);
                delay(20);
            }
            p = p + 2*abs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            putpixels(x,y);
            delay(20);
            p = p + 2*abs(dy) - 2*abs(dx);
        }
    }
}

void circleBres(int xc, int yc, int r)
{
    // Put x = 0 and y =r
    // wtf
    int x = 0, y = r;

    // decision factor d
    int d = 3 - 2 * r;

    // Loop until y >= x
    while (y >= x)
    {
        // for each pixel we will draw all eight pixels
        drawCircle(xc, yc, x, y);
        x++;

        // check for decision parameter and correspondingly update d, x, y
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;   //AWWW
        }
        else
            d = d + 4 * x + 6;          //AWWWW

        drawCircle(xc, yc, x, y);
        delay(20);
    }
}

void drawOxy(){
	float h = 450;
    float w = 550;

    // Axis
    bresenham(-w/5,0, w/2, 0);

	int ox[2][4] =
    {
        {550, 547, 550, 547},
        {225, 222, 225, 228},
    };
    
	for(int i=0; i<4; i=i+2)
    {
        line(ox[0][i], ox[1][i], ox[0][i+1], ox[1][i+1]);
    }
    bresenham(0,h/3,0,-h/5);
    
	int oy[2][4] =
    {
        {275, 272, 275, 278},
        {75, 78, 75, 78},
    };
    
	for(int i=0; i<4; i=i+2)
    {
        line(oy[0][i], oy[1][i], oy[0][i+1], oy[1][i+1]);
    }
    delay(20)
	outtextxy(w-5,h/2+4, "x");
	outtextxy(w/2-10,h/6,"y");
	outtextxy(w/2-10,h/2+4,"O");
}

void draw(){
	
    //Input values
    int p[2][10] =
    {
        {75, 54, 96, 75, 104, 104, 104, 146, 146, 146},
        {50, 100, 100, 50, 100, 50, 50, 50, 100, 50},
    };

    for(int i=0; i<10; i=i+2)
    {
        bresenham(p[0][i], p[1][i], p[0][i+1], p[1][i+1]);
    }
    
    circleBres(175, 75, 25);
    
    int q[2][6] =
    {
        {204, 204, 204, 246, 246, 246},
        {50, 100, 100, 50, 100, 50},
    };
    
    for(int i=0; i<6; i=i+2)
    {
        bresenham(q[0][i], q[1][i], q[0][i+1], q[1][i+1]);
    }
    outtextxy(50, 50, "Nguyen Minh Vuon (4051050024)");
    
	delay(900);
}

// Driver program
int main()
{
    int gd = DETECT, gm;
    // Initialize graphics function
    initgraph (&gd, &gm, NULL);

	drawOxy();
    draw();

    cin.get();
    closegraph();
    
    return 0;
}
