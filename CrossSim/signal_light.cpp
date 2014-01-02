#include "signal_light.h"


signal_light::signal_light(void)
{
	this->color=true;
	this->time=0;
}

signal_light::~signal_light(void)
{

}
int signal_light::get_time()
{
	return this->time;
}
void signal_light::reset_time()
{
	this->time=0;
}
void signal_light::set_time(int t)
{
	this->time=t;
}
void signal_light::change_color()
{
	this->color= !(this->color);
}
void signal_light::increase_time()
{
	this->time++;
}
bool signal_light::get_color()
{
	return this->color;
}
void signal_light::set_color(bool color)
{
	this->color=color;
}