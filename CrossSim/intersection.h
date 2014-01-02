#pragma once

#ifndef INTERSECTION_H_
#define INTERSECTION_H_
#include <string>

struct point;
class intersection
{
public:
	intersection(void);
	virtual ~intersection(void);
	virtual void set_color(int id,int color)=0;
	virtual void set_prev(int id,point* prev)=0;
	virtual point* get_point(int id)=0;
	virtual void set_path(int id, point* p)=0;
	int id;
	//virtual int get_point_size();
};

struct point
{
	int id;
	std::string name;
	intersection *owner;
	//可达节点
	point *to[3];
	
	//做bfs搜索时的前趋和标色
	point *prev;
	int color;
};

#endif