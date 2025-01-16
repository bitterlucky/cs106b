#include "Plotter.h"
#include "GUI/SimpleTest.h"
#include "strlib.h"
using namespace std;
void PenUp(PenStyle& penStyle, bool& penUp);
void PenDown(PenStyle& penStyle, bool& penUp);
void MoveAbs(double& x0, double& y0, double x1, double y1, PenStyle& penStyle);
void MoveRel(double& x0, double& y0, double dx, double dy, PenStyle& penStyle);
void PenColor(string color, PenStyle& penStyle);
void PenWidth(double width, PenStyle& penStyle);
void runPlotterScript(istream& input) {
    PenStyle penStyle = {1.0, "black"};
    double x0 = 0;
    double y0 = 0;
    //penUp 为true表示笔抬起，为False则表示笔落下
    bool penUp = true;
    for (string line; getline(input, line);) {
        Vector<string> vectors = stringSplit(line, " ");
        string command = toLowerCase(vectors[0]);
        if (command == "penup") {
            PenUp(penStyle, penUp);
        } else if (command == "pendown") {
            PenDown(penStyle, penUp);
        } else if (command == "moveabs") {
            MoveAbs(x0, y0, stringToReal(vectors[1]), stringToReal(vectors[2]), penStyle);
        } else if (command == "moverel") {
            MoveRel(x0, y0, stringToReal(vectors[1]), stringToReal(vectors[2]), penStyle);
        } else if (command == "pencolor") {
            PenColor(vectors[1], penStyle);
        } else if (command == "penwidth") {
            PenWidth(stringToReal(vectors[1]), penStyle);
        }
    }
}
void PenUp(PenStyle& penStyle, bool& penUp) {
    penUp = true;
}
void PenDown(PenStyle& penStyle, bool& penUp) {
    penUp = false;
}
void MoveAbs(double& x0, double& y0, double x1, double y1, PenStyle& penStyle) {
    drawLine(x0, y0, x1, y1, penStyle);
    x0 = x1;
    y0 = y1;
}
void MoveRel(double& x0, double& y0, double dx, double dy, PenStyle& penStyle) {
    drawLine(x0, y0, x0 + dx, y0 + dy, penStyle);
    x0 = x0 + dx;
    y0 = y0 + dy;
}
void PenColor(string color, PenStyle& penStyle) {
    penStyle.color = color;
}
void PenWidth(double width, PenStyle& penStyle) {
    penStyle.width = width;
}
