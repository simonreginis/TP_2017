#include <vector>
#include <queue>
#include "elevator.h"
#include "stdafx.h"

using namespace std;

void CElevator::load_array(vector2D ext_array)
{
	floor_array = ext_array;
}

queue <int> CElevator::get_order()
{
	return floor_order;
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

/*void CElevator::make_turn()
{


} */
