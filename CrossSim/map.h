#pragma once

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <list>

#include "cross.h"
#include "halfcross.h"
#include "road.h"
#include <map>

struct comp{
	typedef std::pair<point*,point*> value_type;
	bool operator()(const value_type& ls,const value_type& rs){
	
		return ls.first < rs.first || (ls.first == rs.first && ls.second < rs.second);  
		/*if(((ls.first)->id)<((rs.first)->id))
		{
			return true;
		}
		else if(((ls.first)->id)==((rs.first)->id))
		{
			return ((ls.second)->id)<((rs.second)->id);
		}
		else
		{
			return false;
		}*/
	}
};

class map
{
private:
	//cross crosses[2];
	//halfcross halfcrosses[6];
	//road roads[14];
	
	//std::map<std::pair<point*,point*>,road,comp> roads;
	
	std::list<point*> path[6][6];

	signal_light signal_lights[4];
	
	void bfs(intersection* start);
	void init_path();
	void init_road();
	void update(road*);
public:
	cross crosses[2];
	halfcross halfcrosses[6];
	std::map<std::pair<point*,point*>,road,comp> roads;
	std::list<point*> get_path(int start,int end);
	road* get_road(point* start,point* end);
	void move_car();
	void on_clock();
	map(void);
	~map(void);
};

#endif