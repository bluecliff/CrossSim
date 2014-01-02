#include "cross.h"
#include <cstdlib>
#include <string>

cross::cross(void)
{
	//初始化十字路口的8个点
	for(int i=0;i<8;i++)
	{
		this->points[i].id=i;
		this->points[i].owner=this;
	}

	//初始化十字路口内部的可达路径
	for(int i=1;i<8;i+=2)
	{
		this->points[i].to[0]=NULL;
		this->points[i].to[1]=NULL;
		this->points[i].to[2]=NULL;
	}
	this->points[0].to[0]=&(this->points[1]);
	this->points[0].to[1]=&(this->points[7]);
	this->points[0].to[2]=&(this->points[5]);

	this->points[2].to[0]=&(this->points[1]);
	this->points[2].to[1]=&(this->points[7]);
	this->points[2].to[2]=&(this->points[3]);

	this->points[4].to[0]=&(this->points[1]);
	this->points[4].to[1]=&(this->points[3]);
	this->points[4].to[2]=&(this->points[5]);

	this->points[6].to[0]=&(this->points[5]);
	this->points[6].to[1]=&(this->points[3]);
	this->points[6].to[2]=&(this->points[7]);
}


cross::~cross(void)
{
}

void cross::set_name(std::string name)
{
	for(int i=0;i<8;i++)
	{
		this->points[i].name=name;
	}
}

void cross::set_path(int id,point* p)
{
	this->points[id].to[0]=p;
}

point* cross::get_point(int id)
{
	return &(this->points[id]);
}

void cross::set_color(int id,int color)
{
	this->points[id].color=color;
}

void cross::set_prev(int id,point* prev)
{
	this->points[id].prev=prev;
}

//int cross::get_point_size()
//{
//	return this->size;
//}