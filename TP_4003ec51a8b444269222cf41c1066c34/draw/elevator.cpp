#include "stdafx.h"
#include <vector>
#include <queue>
#include "elevator.h"


using namespace std;

CElevator::CElevator()
{
	elev_pos = 0;
}


void CElevator::load_array(vector2D_t ext_array)
{
	floor_array = ext_array;
}


void CElevator::make_order()
{
	vector<vector<int>>::iterator line_it = floor_array.begin();
	vector<int>::iterator col_it;
	for (; line_it != floor_array.end(); line_it++)
	{

		for (col_it = (*line_it).begin(); col_it != (*line_it).end(); col_it++)
		{

		}

	}

}


bool CElevator::check_array(vector2D_t ext_array)
{
	if (floor_array == ext_array) return true;
	else return false;
}

int CElevator::select_floor()
{
	int next_floor;
	next_floor = floor_order.front();
	floor_order.pop();

	return next_floor;
}

int CElevator::load_people()
{
	int people_sum = 0;

	vector<vector<int>>::iterator line_it = floor_array.begin() + floor_order.front();
	vector<int>::iterator col_it;

	for (col_it = (*line_it).begin(); col_it != (*line_it).end(); col_it++)
	{
		people_sum += *col_it;
	}

	return people_sum;
}


int CElevator::unload_people()
{
	return elev_content[floor_order.front()];
}


elev_out_t CElevator::make_turn(vector2D_t ext_array)
{
	if (!check_array(ext_array))
	{
		load_array(ext_array);
		make_order();
	}

	return make_elev_out();
} 


elev_out_t CElevator::make_elev_out()
{
	elev_out_t buffer;

	buffer.next_floor = select_floor();
	buffer.elev_content = elev_content;
	buffer.people_in = load_people();
	buffer.people_out = unload_people();
	buffer.load = get_load();

	return buffer;
}


int CElevator::sum_elev_people()
{
	int people_amount = 0;
	vector<int>::iterator it;

	for (it = elev_content.begin(); it != elev_content.end(); it++)
	{
		people_amount += *it;
	}
	
	return people_amount;
}

int CElevator::get_load()
{
	return sum_elev_people() * HUMAN_WEIGHT;
}

bool CElevator::check_load()
{
	if ((get_load() + HUMAN_WEIGHT) < MAX_LOAD )  return true;  // + HUMAN_WEIGHT zeby sprawdzic, czy ktos sie jeszcze zmiesci
	else return false;
}