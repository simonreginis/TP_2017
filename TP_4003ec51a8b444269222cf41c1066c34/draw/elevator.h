#pragma once
#include <vector>
#include <queue>

using namespace std;

#define MAX_LOAD 600
#define HUMAN_WEIGHT 70

typedef vector<vector<int>> vector2D_t;

enum TFloor { ground = 416, first = 216, second = 16 };

struct elev_out_t
{
	vector <int> elev_content;
	TFloor		 prev_floor;
	TFloor		 next_floor;
	int			 people_elev;
	int			 people_in;
	int			 people_out;
	int			 load;
};

class CElevator
{
private:
	bool        new_array;
	int			floor_amount;
	int			elev_pos;
	vector<int> elev_content;
	vector2D_t  floor_array;
	queue <int> floor_order;

public:

	CElevator(int floors_number);

	elev_out_t	make_turn();
	void		clear_order();
	void		load_array(vector2D_t ext_array);
	void		make_order();
	bool		check_array(vector2D_t ext_array);
	bool		check_load();
	int			get_load();
	TFloor		translate_floor(int floor_number);

	elev_out_t  make_elev_out();
	void		load_people();
	void	    unload_people();
	int			sum_in_people();
	int			sum_out_people();
	int			sum_elev_people();
	int			get_next_floor();
	
};