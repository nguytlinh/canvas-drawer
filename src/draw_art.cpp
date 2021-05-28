#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   canvas drawer(100, 100);
   drawer.background(0, 0, 0);
   for (int i = 0; i < 10; i++) {
	   drawer.begin(TRIANGLES);
	   drawer.color(255-2*i, 0, 255-2*i);
	   drawer.vertex(10+4*i, 0+5*i);
	   drawer.color(0, i+50, i+50);
	   drawer.vertex(90-3*i, 50-2*i);
	   drawer.color(255+20*i, 255-i*20, 0);
	   drawer.vertex(10+2*i, 90-2*i);
	   drawer.end();
   }


   drawer.save("arttest.png");
}

