#include "map.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include "road.h"

//在EHW和EHE点随机生成汽车的频度，每frequency秒产生一辆汽车
const int frequency=2;
//汽车的ID
int car_id=0;
//模拟时间
const int MAX_TIME=300;

void print(map* pmap)
{
	std::map<std::pair<point*,point*>,road,comp>::iterator iter;
	for(iter=pmap->roads.begin();iter!=pmap->roads.end();++iter)
	{
		std::cout << (((iter->first).first)->name)<<"("<<(((iter->first).first)->id)<<") to "
			<<(((iter->first).second)->name)<<"("<<(((iter->first).second)->id)<<")"<<std::endl;
		if(iter->second.has_signal_light)
		{
			std::string color=iter->second.psignal->get_color()?"green":"red";
			std::cout<<color<<std::endl;
		}
		iter->second.out();
		std::cout<<std::endl;
	}
}

void init_car(map* pmap,road* roads[])
{
	int start_point;
	int destination_point;
	if(roads[0]->is_addable() && rand()%frequency==0)
	{
		start_point=0;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[0]->add_car(c);
	}
	if(roads[3]->is_addable() && rand()%frequency==0)
	{
		start_point=3;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[3]->add_car(c);
	}

	if(roads[1]->is_addable() && rand()%(frequency*3)==0)
	{
		start_point=1;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[1]->add_car(c);
	}
	if(roads[2]->is_addable() && rand()%(frequency*3)==0)
	{
		start_point=2;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[2]->add_car(c);
	}
	if(roads[4]->is_addable() && rand()%(frequency*3)==0)
	{
		start_point=4;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[4]->add_car(c);
	}
	if(roads[5]->is_addable() && rand()%(frequency*3)==0)
	{
		start_point=5;
		destination_point = rand()%6;
		while(destination_point ==start_point)
		{
			destination_point = rand()%6;
		}
		std::list<point*> path=pmap->get_path(start_point,destination_point);
		car* c=new car(car_id,path);
		car_id++;
		roads[5]->add_car(c);
	}
}

void simulation()
{
	map my_map;
	
	road* roads[6];
	roads[0]=my_map.get_road(my_map.halfcrosses[0].get_point(1),my_map.crosses[0].get_point(6));
	roads[1]=my_map.get_road(my_map.halfcrosses[1].get_point(1),my_map.crosses[0].get_point(0));
	roads[2]=my_map.get_road(my_map.halfcrosses[2].get_point(1),my_map.crosses[1].get_point(0));
	roads[3]=my_map.get_road(my_map.halfcrosses[3].get_point(1),my_map.crosses[1].get_point(2));
	roads[4]=my_map.get_road(my_map.halfcrosses[4].get_point(1),my_map.crosses[1].get_point(4));
	roads[5]=my_map.get_road(my_map.halfcrosses[5].get_point(1),my_map.crosses[0].get_point(4));
	

	int time_past=0;
	while(time_past<MAX_TIME)
	{
		init_car(&my_map,roads);
		print(&my_map);
		my_map.on_clock();
		Sleep(1000);
		time_past++;
	}
}