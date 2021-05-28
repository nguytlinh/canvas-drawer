#ifndef canvas_H_
#define canvas_H_

#include <string>
#include <vector>
#include "ppm_image.h"

using namespace std;

namespace agl
{
    struct Point {
        int x;
        int y;
        ppm_pixel color;
    };
   enum PrimitiveType {UNDEFINED, LINES, TRIANGLES};
   class canvas
   {

   private:
       ppm_image _canvas;
       PrimitiveType primType;
       vector<Point> v;
       ppm_pixel _color;

   public:
      canvas(int w, int h);
      virtual ~canvas();

      // Save to file
      void save(const std::string& filename);

      // Draw primitives with a given type (either LINES or TRIANGLES)
      // For example, the following draws a red line followed by a green line
      // begin(LINES);
      //    color(255,0,0);
      //    vertex(0,0);
      //    vertex(100,0);
      //    color(0,255,0);
      //    vertex(0, 0);
      //    vertex(0,100);
      // end();
      void begin(PrimitiveType type);
      void end();

      // Specifiy a vertex at raster position (x,y)
      // x corresponds to the column; y to the row
      void vertex(int x, int y);

      // Specify a color. Color components are in range [0,255]
      void color(unsigned char r, unsigned char g, unsigned char b);

      // Fill the canvas with the given background color
      void background(unsigned char r, unsigned char g, unsigned char b);

      // draw a line between points
      void drawLine(Point a, Point b);

      ppm_pixel interLine(ppm_pixel c1, ppm_pixel c2, float t);

      // draw triangle
      void drawTri(Point a, Point b, Point c);
      
      int cal(Point p1, Point p2, Point p3);

      ppm_pixel interTri(ppm_pixel c1, ppm_pixel c2, ppm_pixel c3,
                             float alpha, float beta, float gamma);

   };
}

#endif


