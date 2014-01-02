#pragma once

#ifndef CAR_H_

#include <list>
struct point;
class car
{
public:
	car(int,std::list<point*>&);
	~car(void);
	std::list<point*> path;
	void increase_pos();
	int get_pos();
	void reset_pos();
	int id;
private:
	int pos;
	
	point* start_point;
	point* end_point;
};

#endif