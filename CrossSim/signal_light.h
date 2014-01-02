#pragma once

#ifndef SIGNAL_LIGHT_H_

class signal_light
{
public:
	signal_light(void);
	~signal_light(void);
	bool get_color();
	int get_time();
	void set_color(bool color);
	void reset_time();
	void set_time(int);
	void increase_time();
	void change_color();
private:
	//true=green,false=red
	bool color;
	int time;
};

#endif