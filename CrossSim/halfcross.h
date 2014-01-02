#pragma once
#ifndef HALFCROSS_H_
#define HALFCROSS_H_

#include <cstdlib>
#include "intersection.h"

class halfcross :
	public intersection
{
private:
	point points[2];
	//int size=2;
public:
	void set_name(std::string name);
	void set_path(int id,point*);
	point* get_point(int id);
	//int get_point_size();
	void set_color(int id,int color);
	void set_prev(int id,point* prev);
	halfcross(void);
	~halfcross(void);
};

#endif
