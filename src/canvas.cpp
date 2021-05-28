#include "canvas.h"
#include <cassert>

using namespace std;
using namespace agl;

canvas::canvas(int w, int h) : _canvas(w, h)
{
}

canvas::~canvas()
{
}

void canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
	primType = type;
}

void canvas::end()
{
	if (primType == LINES) 
    {
        for (int i = 0; i < v.size() - 1; i += 2) 
        {
            drawLine(v[i], v[i + 1]);
        }
    }
    else if (primType == TRIANGLES) 
    {
        for (int i = 0; i < v.size() - 2; i += 3)
        {
            drawTri(v[i], v[i + 1], v[i + 2]);
        }
    }
    v.clear();
}

void canvas::vertex(int x, int y)
{
    v.push_back(Point{ x,y,_color });
}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
    _color = ppm_pixel{ r,g,b };
}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
    for (int i = 0; i < _canvas.height(); i++) 
    {
        for (int j = 0; j < _canvas.width(); j++) 
        {
            _canvas.set(i, j, ppm_pixel{ r,g,b });
        }
    }
}

void canvas::drawLine(Point a, Point b)
{
    int width = b.x - a.x;
    int height = b.y - a.y;
    Point temp;
    ppm_pixel color;
    float t;
    int inc = 1;

    if (height < width) {
        if (width < 0) {
            temp = a;
            a = b;
            b = temp;
        }

        int aY = a.y;
        int wid = b.x - a.x;
        int hei = b.y - a.y;

        if (hei < 0) {
            inc = -1;
            hei = -hei;
        }
        int f = (hei - wid) * 2;
        for (int i = a.x; i <= b.x; i++) {
            t = (i - a.x) / (float)(b.x - a.x);
            color = interLine(a.color, b.color, t);
            _canvas.set(aY, i, color);
            if (f > 0) {
                aY += inc;
                f += 2 * (hei - wid);
            }
            else {
                f += 2 * hei;
            }
        }
    }
    else { 
        if (height < 0) { 
            temp = a;
            a = b;
            b = temp;
        }
        int aX = a.x;
        int wid = b.x - a.x;
        int hei = b.y - a.y;
        if (wid < 0) {
            inc = -1;
            wid = -wid;
        }
        int f = (wid - hei) * 2;
        for (int i = a.y; i <= b.y; i++) {
            t = (i - a.y) / (float)(b.y - a.y);
            color = interLine(a.color, b.color, t);
            _canvas.set(i, aX, color);
            if (f > 0) {
                aX += inc;
                f += (wid - hei) * 2;
            }
            else {
                f += 2 * wid;
            }
        }
    }
}

ppm_pixel canvas::interLine(ppm_pixel c1, ppm_pixel c2, float t)
{
    unsigned char red = (unsigned char)((1 - t) * c1.r + c2.r * t);
    unsigned char green = (unsigned char)((1 - t) * c1.g + c2.g * t);
    unsigned char blue = (unsigned char)((1 - t) * c1.b + c2.b * t);
    return ppm_pixel{ red,green,blue };
}


void canvas::drawTri(Point a, Point b, Point c) {
    Point p;
    ppm_pixel color;

    int alpha = cal(b, c, a);
    int beta = cal(a, c, b);
    int gamma = cal(a, b, c);
    int min_x = min(min(a.x, b.x), c.x);
    int max_x = max(max(a.x, b.x), c.x);
    int min_y = min(min(a.y, b.y), c.y);
    int max_y = max(max(a.y, b.y), c.y);

    for (int hei = min_y; hei < max_y; hei++) {
        for (int wid = min_x; wid < max_x; wid++) {
            p = { wid,hei,ppm_pixel{0,0,0} };
            if (cal(b, c, p) / (float)alpha >= 0 &&
                cal(a, c, p) / (float)beta >= 0 &&
                cal(a, b, p) / (float)gamma >= 0) 
            { 
                Point p1 = { -1,-1, ppm_pixel{0,0,0} };
                if (0 < alpha || 0 < cal(a, c, p1) * alpha ||
                    0 < cal(a, b, p1) * alpha || 0 < cal(b, c, p1) * alpha) 
                { 
                    color = interTri(a.color, b.color, c.color,
                        cal(b, c, p) / (float)alpha,
                        cal(a, c, p) / (float)beta,
                        cal(a, b, p) / (float)gamma);
                    _canvas.set(hei, wid, color);
                }
            }
        }
    }
}

int canvas::cal(Point p1, Point p2, Point p3) {
    int height = p2.y - p1.y;
    int width = p2.x - p1.x;

    return height * (p3.x - p1.x) - width * (p3.y - p1.y);
}

ppm_pixel canvas::interTri(ppm_pixel c1, ppm_pixel c2, ppm_pixel c3,
    float alpha, float beta, float gamma)
{
    unsigned char red = (unsigned char)(alpha * c1.r + beta * c2.r + gamma * c3.r);
    unsigned char green = (unsigned char)(alpha * c1.g + beta * c2.g + gamma * c3.g);
    unsigned char blue = (unsigned char)(alpha * c1.b + beta * c2.b + gamma * c3.b);

    return ppm_pixel{ red,green,blue };
}

