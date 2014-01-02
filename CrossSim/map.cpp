#include "map.h"
#include <queue>

#define ROAD_LENGTH_ENDPOINT 2
#define ROAD_LENGTH_CROSS 5
#define ROAD_LENGTH_EAST 15
#define ROAD_LENGTH_WEST 15
#define ROAD_LENGTH_MIDDLE 60
#define ROAD_LENGTH_NORTH 5
#define ROAD_LENGTH_SOURTH 20 


map::map(void)
{
	//初始化各个路口

	this->crosses[0].set_name("CR1");
	this->crosses[1].set_name("CR2");
	this->halfcrosses[0].set_name("EHW");
	this->halfcrosses[1].set_name("BSN");
	this->halfcrosses[2].set_name("TBN");
	this->halfcrosses[3].set_name("EHE");
	this->halfcrosses[4].set_name("TBS");
	this->halfcrosses[5].set_name("BSS");

	//初始化交通信号灯
	this->signal_lights[0].set_color(false);
	this->signal_lights[2].set_color(false);
	this->signal_lights[1].set_color(true);
	this->signal_lights[3].set_color(true);
	this->signal_lights[1].set_time(60);
	this->signal_lights[0].set_time(60);

	for(int i=0;i<6;i++)
	{
		this->halfcrosses[i].id=i;
	}
	this->crosses[0].id=0;
	this->crosses[1].id=1;
	
	

 	this->halfcrosses[0].set_path(0,this->halfcrosses[0].get_point(1));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[0].get_point(0),this->halfcrosses[0].get_point(1)
		),road(ROAD_LENGTH_ENDPOINT))
		);
	
	this->halfcrosses[3].set_path(0,this->halfcrosses[3].get_point(1));   
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[3].get_point(0),this->halfcrosses[3].get_point(1)
		),road(ROAD_LENGTH_ENDPOINT))
		);

	this->halfcrosses[0].set_path(1,this->crosses[0].get_point(6));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[0].get_point(1),this->crosses[0].get_point(6)
		),road(ROAD_LENGTH_WEST))
		);

	this->halfcrosses[1].set_path(1,this->crosses[0].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[1].get_point(1),this->crosses[0].get_point(0)
		),road(ROAD_LENGTH_NORTH))
		);

	this->halfcrosses[2].set_path(1,this->crosses[1].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[2].get_point(1),this->crosses[1].get_point(0)
		),road(ROAD_LENGTH_NORTH))
		);

	this->halfcrosses[3].set_path(1,this->crosses[1].get_point(2));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[3].get_point(1),this->crosses[1].get_point(2)
		),road(ROAD_LENGTH_EAST))
		);

	this->halfcrosses[4].set_path(1,this->crosses[1].get_point(4));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[4].get_point(1),this->crosses[1].get_point(4)
		),road(ROAD_LENGTH_SOURTH))
		);

	this->halfcrosses[5].set_path(1,this->crosses[0].get_point(4));
	this->roads.insert(std::make_pair(
		std::make_pair(this->halfcrosses[5].get_point(1),this->crosses[0].get_point(4)
		),road(ROAD_LENGTH_SOURTH))
		);

	this->crosses[0].set_path(7,this->halfcrosses[0].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[0].get_point(7),this->halfcrosses[0].get_point(0)
		),road(ROAD_LENGTH_WEST))
		);

	this->crosses[0].set_path(1,this->halfcrosses[1].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[0].get_point(1),this->halfcrosses[1].get_point(0)
		),road(ROAD_LENGTH_NORTH))
		);

	this->crosses[0].set_path(3,this->crosses[1].get_point(6));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[0].get_point(3),this->crosses[1].get_point(6)
		),road(ROAD_LENGTH_MIDDLE))
		);

	this->crosses[0].set_path(5,this->halfcrosses[5].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[0].get_point(5),this->halfcrosses[5].get_point(0)
		),road(ROAD_LENGTH_SOURTH))
		);
	
	this->crosses[1].set_path(1,this->halfcrosses[2].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[1].get_point(1),this->halfcrosses[2].get_point(0)
		),road(ROAD_LENGTH_NORTH))
		);
	this->crosses[1].set_path(3,this->halfcrosses[3].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[1].get_point(3),this->halfcrosses[3].get_point(0)
		),road(ROAD_LENGTH_EAST))
		);
	this->crosses[1].set_path(5,this->halfcrosses[4].get_point(0));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[1].get_point(5),this->halfcrosses[4].get_point(0)
		),road(ROAD_LENGTH_SOURTH))
		);
	this->crosses[1].set_path(7,this->crosses[0].get_point(2));
	this->roads.insert(std::make_pair(
		std::make_pair(this->crosses[1].get_point(7),this->crosses[0].get_point(2)
		),road(ROAD_LENGTH_MIDDLE))
		);
	
	this->init_road();
	
	this->init_path();

	//this->roads[0].init(this->halfcrosses[0].get_point());
}

void map::init_road()
{
	for(int i=0;i<2;i++)
	{
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(0),this->crosses[i].get_point(5)
			),road(ROAD_LENGTH_CROSS,true,&signal_lights[2*i]))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(0),this->crosses[i].get_point(7)
			),road(ROAD_LENGTH_CROSS))
			);

		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(4),this->crosses[i].get_point(1)
			),road(ROAD_LENGTH_CROSS,true,&signal_lights[2*i]))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(4),this->crosses[i].get_point(3)
			),road(ROAD_LENGTH_CROSS))
			);

		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(2),this->crosses[i].get_point(7)
			),road(ROAD_LENGTH_CROSS,true,&signal_lights[2*i+1]))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(2),this->crosses[i].get_point(1)
			),road(ROAD_LENGTH_CROSS))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(2),this->crosses[i].get_point(3)
			),road(ROAD_LENGTH_CROSS))
			);

		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(6),this->crosses[i].get_point(3)
			),road(ROAD_LENGTH_CROSS,true,&signal_lights[2*i+1]))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(6),this->crosses[i].get_point(7)
			),road(ROAD_LENGTH_CROSS))
			);
		this->roads.insert(std::make_pair(
			std::make_pair(this->crosses[i].get_point(6),this->crosses[i].get_point(5)
			),road(ROAD_LENGTH_CROSS))
			);
	}
}

void map::init_path()
{
	for(int i=0;i<6;i++)
	{
		this->bfs(&(this->halfcrosses[i]));
	}
}

map::~map(void)
{

}

std::list<point*> map::get_path(int start,int end)
{
	return this->path[start][end];
}

void map::bfs(intersection* start)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<8;j++)
		{
			this->crosses[i].set_color(j,0);
			this->crosses[i].set_prev(j,NULL);
		}
	}
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<2;j++)
		{
			this->halfcrosses[i].set_color(j,0);
			this->halfcrosses[i].set_prev(j,NULL);
		}
	}
	start->set_color(1,1);
	std::queue<point*> Q;
	Q.push(start->get_point(1));
	while(!Q.empty())
	{
		point* p=Q.front();
		Q.pop();
		for(int j=0;j<3;j++)
		{
			if(p->to[j]!=NULL && p->to[j]->color==0)
			{
				p->to[j]->color=1;
				p->to[j]->prev=p;
				Q.push(p->to[j]);
			}
		}
		p->color=2;
	}
	
	for(int i=0;i<6;i++)
	{
		if(start->id!=i)
		{
			point* p=this->halfcrosses[i].get_point(0);
			this->path[start->id][i].push_front(p);
			while(p->prev!=NULL)
			{
				p=p->prev;
				this->path[start->id][i].push_front(p);
			}
		}
	}
}

road* map::get_road(point* start,point* end)
{
	std::map<std::pair<point*,point*>,road,comp>::iterator iter;
	iter = roads.find(std::make_pair(start,end));
	if(iter == roads.end())
	{
		return NULL;
	}
	else
	{
		return &(iter->second);
	}
}

//响应时间，移动车辆

void map::update(road* r)
{
	if(r->is_moved)
	{
		return;
	}
	car* front_car = r->front_car();
	if(front_car==NULL)
	{
		r->move_car();
		return;
	}
	if(front_car->path.size()==2)
	{
		car* tmp = r->remove_car();
		delete tmp;
		tmp=NULL;
		r->move_car();
		return;
	}
	std::list<point*>::iterator iter=(front_car->path).begin();
	point* p1 = *(++iter);
	point* p2 = *(++iter);
	std::map<std::pair<point*,point*>,road,comp>::iterator roads_iter;
	roads_iter=this->roads.find(std::make_pair(p1,p2));
	if(roads_iter == roads.end())
	{
#ifdef DEBUG
		std::cout<<"error: find NULL point in roads"<<std::endl;
#endif
	}
	else
	{
		update(&(roads_iter->second));
		if((roads_iter->second).has_signal_light && !((roads_iter->second).psignal)->get_color())
		{
			r->move_car();
		}
		else
		{
			if((roads_iter->second).is_addable())
			{
				car* tmp = r->remove_car();
				tmp->path.pop_front();
				(roads_iter->second).add_car(tmp);
				r->move_car();

			}
			else
			{
				r->move_car();
			}
		}
	}
}

void map::move_car()
{
	std::map<std::pair<point*,point*>,road,comp>::iterator iter;
	for(iter=roads.begin();iter!=roads.end();iter++)
	{
		(iter->second).is_moved=false;
	}
	for(iter=roads.begin();iter!=roads.end();iter++)
	{
		update(&(iter->second));
	}
}

void map::on_clock()
{
	for(int i=0;i<4;i++)
	{
		this->signal_lights[i].increase_time();
	}
	if(signal_lights[1].get_time()==120)
	{
		signal_lights[1].set_color(false);
		signal_lights[0].set_color(true);
	}
	if(signal_lights[1].get_time()==140)
	{
		signal_lights[1].reset_time();
		signal_lights[0].reset_time();
		signal_lights[1].set_color(true);
		signal_lights[0].set_color(false);
	}
	if(signal_lights[3].get_time()==120)
	{
		signal_lights[3].set_color(false);
		signal_lights[2].set_color(true);
	}
	if(signal_lights[3].get_time()==140)
	{
		signal_lights[3].reset_time();
		signal_lights[2].reset_time();
		signal_lights[3].set_color(true);
		signal_lights[2].set_color(false);
	}
	this->move_car();
}