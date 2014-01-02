#pragma once
#ifndef CROSS_H_
#define CROSS_H_
#include "intersection.h"

class cross:public intersection
{
private:
	point points[8];
	//int size=8;
public:
	void set_path(int id,point* p);
	point* get_point(int id);
	//int get_point_size();
	void set_color(int id,int color);
	void set_prev(int id,point* p);
	void set_name(std::string name);
	cross(void);
	~cross(void);
};

#endif