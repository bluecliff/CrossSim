#include "car.h"
#include "gloable.h"


car::car(int id,std::list<point*>& path)
{
	this->id=id;
	this->pos=0;
	//this->start_point=start_point;
	//this->end_point=end_point;
	this->path.assign(path.begin(),path.end());
}

car::~car(void)
{
#ifdef DEBUG
	std::cout<<"delete car(id="<<this->id<<")"<<std::endl;
#endif
}

int car::get_pos()
{
	return pos;
}

void car::increase_pos()
{
	pos++;
}

void car::reset_pos()
{
	pos=0;
}