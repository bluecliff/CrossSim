#include "road.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

road::road(int length,bool has_signal,signal_light* psignal)
{
	this->init(length);
	this->has_signal_light=has_signal;
	this->psignal=psignal;
	this->is_moved=false;
}

void road::out()
{
	std::list<car*>::iterator iter;
	for(iter=car_list.begin();iter!=car_list.end();++iter)
	{
		if((*iter)!=NULL)
		{
			std::cout<<std::setw(4)<<(*iter)->id;
		}
		else
		{
			std::cout<<std::setw(4)<<"*";
		}
	}
}

road::~road(void)
{
}

void road::init(int length)
{
	this->length=length;
	this->car_list.resize(length,NULL);
}

void road::move_car()
{
	std::list<car*>::iterator iter;
	std::list<car*>::iterator tmp;
	for(iter=car_list.begin();iter!=(--car_list.end());iter++)
	{
		if((*iter)!=NULL)
		{
			continue;
		}
		else
		{
			tmp=iter;
			(*iter)= *(++tmp);
			*tmp = NULL;
			if(*iter!=NULL)
			{
				(*iter)->increase_pos();
			}
		}
	}
	/*std::list<car*>::iterator first=this->car_list.begin();
	if((*first)!=NULL)
	{
		this->is_moved=true;
		return false;
	}
	this->car_list.pop_front();
	this->car_list.push_back(NULL);
	this->is_moved=true;
	return true;*/
}

bool road::add_car(car* new_car)
{
	std::list<car*>::reverse_iterator rfirst=this->car_list.rbegin();
	if((*rfirst)!=NULL)
	{
		return false;
	}
	(*rfirst)=new_car;
	(*rfirst)->reset_pos();
	return true;
}
bool road::is_addable()
{
	std::list<car*>::reverse_iterator rfirst=this->car_list.rbegin();
	if((*rfirst)!=NULL)
	{
		return false;
	}
	return true;
}

car* road::remove_car()
{
	std::list<car*>::iterator first=this->car_list.begin();
	car* tmp = (*first);
	(*first)=NULL;
	return tmp;
}


car* road::front_car()
{
	std::list<car*>::iterator first=this->car_list.begin();
	return *first;
}