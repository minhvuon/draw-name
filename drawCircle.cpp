// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <stdio.h>
#include <graphics.h>

// Function to put pixels at subsequence points
void drawCircle(int xc, int yc, int x, int y)
{
    float h = 450;
    float w = 550;

    putpixel(xc+x+w/2, (h/2)-(yc+y), RED);
    putpixel(xc-x+w/2, (h/2)-(yc+y), RED);
    putpixel(xc+x+w/2, (h/2)-(yc-y), RED);
    putpixel(xc-x+w/2, (h/2)-(yc-y), RED);
    putpixel(xc+y+w/2, (h/2)-(yc+x), RED);
    putpixel(xc-y+w/2, (h/2)-(yc+x), RED);
    putpixel(xc+y+w/2, (h/2)-(yc-x), RED);
    putpixel(xc-y+w/2, (h/2)-(yc-x), RED);
}

// Function for circle-generation
// using Bresenham's algorithm
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
        delay(50);
    }
}


// driver function
int main()
{
    int xc = 0, yc = 0, r2 = 100;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // initialize graph
    float h = 450;
    float w = 550;

    // Axis
    line(0,h/2, w, h/2);
    line(w/2,0,w/2,h);

    circleBres(50, 50, 23);    // function call
    //circleBres(xc, yc, 50);    // function call
    getch();
    return 0;
}
