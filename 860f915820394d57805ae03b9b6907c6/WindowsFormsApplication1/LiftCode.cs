using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LiftApp
{

    

    public partial class LiftWindow : Form
    {
        int current_floor = 0;
        int time = 0;
        int n = 0;
        int check1 = 0;
        int check2 = 0;
        const int lift_position = 557;
        List<int> floor_queue = new List<int>();
        public static readonly int[] floor_height = { 667 - 131, 536 - 131, 405 - 131, 274 - 131, 143 - 131 };
        List<ludek> ludek_arr = new List<ludek>();
        bool lift_going_up = true;
        public class ludek
        {
            public int from;
            public int to;

            public PictureBox pic;

            public bool in_lift;

            public void move(int x, int y)
            {
                pic.Location = new Point(pic.Location.X + x, pic.Location.Y + y);
            }

            public ludek(int floor_from, int floor_to, PictureBox picture)
            {
                PictureBox temppic = new PictureBox();
                temppic.Image = picture.Image;
                temppic.Size = new Size(45, 69);


              //  pic.SizeMode = PictureBoxSizeMode.StretchImage;

                pic = temppic;
                pic.Visible = true;
                pic.BringToFront();
                pic.BackColor = Color.Transparent;
                if(floor_from % 2 == 0)
                {
                    pic.Location = new Point(100, floor_height[floor_from]+63);
                }else
                {
                    pic.Location = new Point(800, floor_height[floor_from] + 63);
                }

                from = floor_from;
                to = floor_to;
                in_lift = false;
            }
        }
        public ludek createLudek(int from, int to, PictureBox pic)
        {
            ludek ludeknew = new ludek(from, to, pic);
            this.Controls.Add(ludeknew.pic);

            return ludeknew;
        }
        public void liftEnqueue(int from)
        {
            int q = 0;

            if (floor_queue.Count != 0)
            {
                if (floor_queue[0] == 8)
                q = 1;
            else
                q = 0;
            }


            bool check_if_added = false;

            if (from > 19 && lift_going_up && Lift.Location.Y > floor_height[from % 10]) // if is going up
            {
                for (int i = q; i < floor_queue.Count; i = i + 2)
                {
                    if (floor_queue[i] == from % 10)
                    {
                        check_if_added = true;
                        break;
                    }

                    if (floor_queue[i] > from % 10)
                    {
                        floor_queue.Insert(i, 8);
                        floor_queue.Insert(i, from % 10);
                        check_if_added = true;
                        break;
                    }
                }
            }
            else if (from < 19 && !lift_going_up && Lift.Location.Y < floor_height[from % 10])// is going down
            {
                for (int i = q; i < floor_queue.Count; i = i + 2)
                {
                    if (floor_queue[i] == from % 10)
                    {
                        check_if_added = true;
                        break;
                    }

                    if (floor_queue[i] < from % 10)
                    {
                        floor_queue.Insert(i, 8);
                        floor_queue.Insert(i, from % 10);
                        check_if_added = true;
                        break;
                    }
                }
            }
            else
                for (int i = q; i < floor_queue.Count; i = i + 2)
                    if (floor_queue[i] == from % 10)
                    {
                        check_if_added = true;
                        break;
                    }

            if (!check_if_added)
            {
                floor_queue.Add(from % 10);
                floor_queue.Add(8);
            }
        }
        public LiftWindow()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Background1.SendToBack();
        }


        public void moveLift(int floor)
        {
            if (floor > current_floor)
            {
                Lift.Location = new Point(Lift.Location.X, Lift.Location.Y - 1);
                lift_going_up = true;

                foreach (var gostek in ludek_arr)
                {
                    if(gostek.in_lift)
                    {
                        gostek.move(0, - 1);
                    }
                }
            }
            else if (floor < current_floor)
            {
                Lift.Location = new Point(Lift.Location.X, Lift.Location.Y + 1);
                lift_going_up = false;

                foreach (var gostek in ludek_arr)
                {
                    if (gostek.in_lift)
                    {
                        gostek.move(0, + 1);
                    }
                }
            }
        }


       
        public void insert_ludek(int i)
        {
            bool check_if_added = false;
            if (ludek_arr[i].to > current_floor)
                for (int j = 1; j < floor_queue.Count; j = j + 2)
                {
                    if (floor_queue[j] == ludek_arr[i].to)
                    {
                        check_if_added = true;
                        break;
                    }
                    else if (floor_queue[j] > ludek_arr[i].to)
                    {
                        floor_queue.Insert(j, 8);
                        floor_queue.Insert(j, ludek_arr[i].to);
                        check_if_added = true;
                        break;
                    }
                }
            else if (ludek_arr[i].to < current_floor)
                for (int j = 1; j < floor_queue.Count; j = j + 2)
                {
                    if (floor_queue[j] == ludek_arr[i].to)
                    {
                        check_if_added = true;
                        break;
                    }
                    else if (floor_queue[j] < ludek_arr[i].to)
                    {
                        floor_queue.Insert(j, 8);
                        floor_queue.Insert(j, ludek_arr[i].to);
                        check_if_added = true;
                        break;
                    }
                }
            if (!check_if_added)
            {
                floor_queue.Add(ludek_arr[i].to);
                floor_queue.Add(8);
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (floor_queue.Count != 0)
            {
                time = 0;
                if (floor_queue[0] != 8)
                {
                    int floor = floor_queue[0];
                    moveLift(floor);
                    if (Lift.Location.Y == floor_height[floor])
                    {
                        current_floor = floor;
                        floor_queue.RemoveAt(0);
                    }                              
                }
                else
                {
                    bool end = true;
                    if (ludek_arr.Count != 0)
                    {
                        for (int i = 0; i < ludek_arr.Count; i++)
                        {
                            if (ludek_arr[i].from == current_floor && !ludek_arr[i].in_lift)
                            {
                                end = false;
                                if(n > check1*40)
                                    moveLudek(true, i);
                                insert_ludek(i);
                                check1++;
                            }
                            else if (ludek_arr[i].to == current_floor && ludek_arr[i].in_lift)
                            {
                                end = false;
                                if(n > check2*40)
                                    moveLudek(false, i);
                                check2++;
                            }
                        }
                    }
                    check1 = 0;
                    check2 = 0;
                    n++;

                    if (end)
                    {
                        floor_queue.RemoveAt(0);
                        n = 0;
                    }
                }
            }
            else
            {
                time++;
                if (time == 340)
                {
                    floor_queue.Add(0);
                    time = 0;
                }
            }
        }

        public void moveLudek(bool is_going_in, int which_ludek)
        {
            if (is_going_in && current_floor % 2 == 0 && ludek_arr[which_ludek].pic.Location.X != Lift.Location.X + 20)
                ludek_arr[which_ludek].move(1, 0);

            if (is_going_in && current_floor % 2 == 1 && ludek_arr[which_ludek].pic.Location.X != Lift.Location.X + 20)
                ludek_arr[which_ludek].move(-1, 0);

            if (ludek_arr[which_ludek].pic.Location.X == Lift.Location.X + 20)
                ludek_arr[which_ludek].in_lift = true;

            if (!is_going_in && current_floor % 2 == 0 )
            {
                ludek_arr[which_ludek].move(-1, 0);
            }
            if (!is_going_in && current_floor % 2 == 1 )
            {
                ludek_arr[which_ludek].move(1, 0);
            }
            if (ludek_arr[which_ludek].pic.Location.X == Lift.Location.X + 20)
                ludek_arr[which_ludek].in_lift = true;

            if (ludek_arr[which_ludek].pic.Location.X > 800 || ludek_arr[which_ludek].pic.Location.X < 100)
            {
                ludek_arr[which_ludek].pic.Dispose();
                ludek_arr.RemoveAt(which_ludek);
            }

        }

        private void fromFloor0to1_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(0, 1,ludek1));
        }

        private void fromFloor0to2_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(0,2,ludek2));
        }

        private void fromFloor0to3_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(0,3, ludek3));
        }

        private void fromFloor1to0_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(1,0, ludek0));
        }

        private void fromFloor1to2_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(1,2, ludek2));
        }

        private void fromFloor1to3_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(1,3, ludek3));
        }

        private void fromFloor2to0_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(2,0, ludek0));
        }

        private void fromFloor2to1_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(2,1, ludek1));
        }

        private void fromFloor2to3_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(2,3, ludek3));
        }

        private void fromFloor3to0_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(3,0, ludek0));
        }

        private void fromFloor3to1_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(3,1, ludek1));
        }

        private void fromFloor3to2_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(3,2, ludek2));
        }

        private void fromFloor2to4_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(2,4, ludek4));
        }

        private void fromFloor1to4_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(1,4, ludek4));
        }

        private void fromFloor0to4_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(0,4, ludek4));
        }

        private void fromFloor4to3_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(4,3, ludek3));
        }

        private void fromFloor4to2_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(4,2, ludek2));
        }

        private void fromFloor4to1_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(4,1, ludek1));
        }

        private void fromFloor4to0_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(4,0, ludek0));
        }

        private void fromFloor3to4_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(3,4, ludek4));
        }

        private void floor3Down_Click(object sender, EventArgs e)
        {
            liftEnqueue(13);
        }

        private void floor2Up_Click(object sender, EventArgs e)
        {
            liftEnqueue(22);
        }

        private void floor2Down_Click(object sender, EventArgs e)
        {
            liftEnqueue(12);
        }

        private void floor1Up_Click(object sender, EventArgs e)
        {
            liftEnqueue(21);
        }

        private void floor1Down_Click(object sender, EventArgs e)
        {
            liftEnqueue(11);
        }

        private void floor0Up_Click(object sender, EventArgs e)
        {
            liftEnqueue(20);
        }

        private void floor4Down_Click(object sender, EventArgs e)
        {
            liftEnqueue(14);
        }

        private void floor3Up_Click(object sender, EventArgs e)
        {
            liftEnqueue(23);
        }

    }
}
