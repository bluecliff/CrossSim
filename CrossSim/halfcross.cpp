#include "halfcross.h"
#include <string>

halfcross::halfcross(void)
{
	this->points[0].id=0;
	this->points[0].owner=this;
	//this->points[0].to[0]=&(this->points[1]);
	this->points[0].to[0]=NULL;
	this->points[0].to[1]=NULL;
	this->points[0].to[2]=NULL;

	this->points[1].id=1;
	this->points[1].owner=this;
	this->points[1].to[0]=NULL;
	this->points[1].to[1]=NULL;
	this->points[1].to[2]=NULL;
}

void halfcross::set_name(std::string name)
{
	this->points[0].name=name;
	this->points[1].name=name;
}

halfcross::~halfcross(void)
{
}

void halfcross::set_path(int id,point* p)
{
	this->points[id].to[0]=p;
}

point* halfcross::get_point(int id)
{
	return &(this->points[id]);
}

void halfcross::set_color(int id,int color)
{
	this->points[id].color=color;
}

void halfcross::set_prev(int id,point* prev)
{
	this->points[id].prev=prev;
}

//int halfcross::get_point_size()
//{
//	return this->size;
//}