#include "stdafx.h"
#include <vector>
#include <queue>
#include "elevator.h"

//TODO
/*
aktualizacja poprzedniego pietra
algorytm windy
wsiadajacy ludzie
*/

using namespace std;

CElevator::CElevator(int floors_number)
{
	elev_pos = 0;
	floor_amount = floors_number;

	vector<int> new_raw;
	vector<vector<int>>::iterator line_it = floor_array.begin();

	for (int i = 0; i < floor_amount; i++)
	{
		elev_content.push_back(0);

		floor_array.push_back(new_raw);

		for (int i = 0; i < floor_amount; i++)
		{
			(*line_it).push_back(0);
		}

		line_it++;
	}

}


void CElevator::load_array(vector2D_t ext_array)
{
	floor_array = ext_array;
}

void CElevator::clear_order()
{
	while (!floor_order.empty())  floor_order.pop();
		
}


void CElevator::make_order()
{
	vector<vector<int>>::iterator line_it = floor_array.begin();
	vector<int>::iterator col_it;
	/*for (; line_it != floor_array.end(); line_it++)
	{

		for (col_it = (*line_it).begin(); col_it != (*line_it).end(); col_it++)
		{


		}

	} */

	clear_order();

	for (int i = 0; i < 10; i++)
	{
		floor_order.push(i%3);
	}
	
	
}


bool CElevator::check_array(vector2D_t ext_array)
{
	if (floor_array == ext_array) return true;
	else return false;
}

TFloor CElevator::translate_floor(int floor_number)
{
	switch (floor_number)
	{
	case 1: return first;
	case 2:return second;
	default: return ground;
	}
}

int CElevator::sum_in_people()
{
	int people_sum = 0;

	vector<vector<int>>::iterator line_it = floor_array.begin() + get_next_floor();
	vector<int>::iterator col_it;

	for (col_it = (*line_it).begin(); col_it != (*line_it).end(); col_it++)
	{
		people_sum += *col_it;
	}

	return people_sum;
}

int CElevator::sum_out_people()
{
	return elev_content[floor_order.front()];
}

int CElevator::get_next_floor()
{
	return floor_order.front();
}
	


void CElevator::load_people()
{
	vector<vector<int>>::iterator line_it = floor_array.begin() + get_next_floor();
	vector<int>::iterator col_it;
	vector<int>::iterator elev_it = elev_content.begin();


	for (col_it = (*line_it).begin(); col_it != (*line_it).end(); col_it++, elev_it++)
	{
		*elev_it += *col_it;
	}

}


void CElevator::unload_people()
{
	elev_content[get_next_floor()] = 0;
}

elev_out_t CElevator::make_turn(vector2D_t ext_array)
{
	if (!check_array(ext_array))
	{
		load_array(ext_array);
		make_order();
	}

	load_people();                                                         //wsiadaj¹cy ludzie
	unload_people();												              // wysiadajacy ludzie

	return make_elev_out();
} 



elev_out_t CElevator::make_elev_out()
{
	elev_out_t buffer;

	buffer.next_floor = translate_floor(get_next_floor());
	buffer.prev_floor = translate_floor(elev_pos);
	buffer.elev_content = elev_content;
	buffer.people_in = sum_in_people();
	buffer.people_out = sum_out_people();
	buffer.load = get_load();
	buffer.people_elev = sum_elev_people();

	elev_pos = get_next_floor();								   // aktualizacja poprzedniego piêtra
	floor_order.pop();                                             //zabieranie elementu z kolejki po wykonaniu tury - musi byc tu bo po zapisaniu do struktury

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