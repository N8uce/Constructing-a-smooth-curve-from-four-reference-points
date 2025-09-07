#ifndef TASK_H
#define TASK_H


struct Point
{
int x,y;
};

void getpoint(int,int);
void bezier();
Point Point_bezie (Point , Point, Point, Point, double);
void chaiykin();
void save();

#endif