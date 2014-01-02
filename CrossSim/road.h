#pragma once
#ifndef ROAD_H_
#define ROAD_H_
#include "car.h"
#include "signal_light.h"
#include<list>
struct point;

class road
{
private:
	//point* start;
	//point* end;
	int length;
	
	
public:
	std::list<car*> car_list;
	void out();
	signal_light* psignal;
	bool is_moved;
	bool has_signal_light;
	road(int length,bool has_signal=false,signal_light* psignal=NULL);
	~road(void);
	void init(int length);
	void move_car();
	bool add_car(car*);
	car* remove_car();
	car* front_car();
	bool is_addable();
};

#endif