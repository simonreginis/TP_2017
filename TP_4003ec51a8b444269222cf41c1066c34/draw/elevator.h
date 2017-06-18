#pragma once
#include <vector>
#include <queue>

using namespace std;

#define MAX_LOAD 600
#define HUMAN_WEIGHT 70

typedef vector<vector<int>> vector2D_t;
struct elev_out_t
{
	vector <int> elev_content;
	int			 prev_floor;
	int			 next_floor;
	int			 people_in;
	int			 people_out;
	int			 load;
};

class CElevator
{
private:
	int			elev_pos;
	vector<int> elev_content;
	vector2D_t  floor_array;
	queue <int> floor_order;

public:
	CElevator();

	elev_out_t	make_turn(vector2D_t ext_array);
	void		load_array(vector2D_t ext_array);
	bool		check_array(vector2D_t ext_array);
	void		make_order();
	int			select_floor();

	elev_out_t  make_elev_out();
	int		    load_people();
	int		    unload_people();
	int			sum_elev_people();
	int			get_load();
	bool		check_load();
};