#pragma once
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> vector2D;

class CElevator
{
private:
	int			elev_pos;
	vector<int> elev_content;
	vector2D    floor_array;
	queue <int> floor_order;

public:
	void		load_array(vector2D ext_array);
	void		make_order();
	queue <int> get_order();
	void		make_turn();

};
