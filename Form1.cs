using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        int current_floor = 0;
        const int lift_position = 557;
        List<int> floor_queue = new List<int>();
        int[] floor_height = new int[4] {536-131,405-131,274-131,143-131};
        List<ludek> ludek_arr = new List<ludek>();
        bool lift_going_up = true;

        public class ludek
        {
            public int from;
            public int to;
             
            public PictureBox pic;
            
            public bool in_lift;
        }

        public void liftEnqueue(int from)
        {
            if( from > 19 && lift_going_up && Lift.Location.Y < floor_height[from % 10]) // if is going up
            {
                floor_queue.Insert(0, 8);
                floor_queue.Insert(0, from % 10);
            }else if (from > 9 && !lift_going_up && Lift.Location.Y < floor_height[from % 10])// is going down
            {
                floor_queue.Insert(0, 8);
                floor_queue.Insert(0, from % 10);
            }else
            {
                floor_queue.Add(from % 10);
                floor_queue.Add(8);
            }
        }



        public ludek createLudek(int floor_from, int floor_to)
        {
            PictureBox newpic = new PictureBox();
            if (floor_to == 0)
            {
                //newpic.Image = global::WindowsFormsApplication1.Properties.Resources.ludek0;
                newpic.BackColor = Color.Black;
                newpic.Size = new Size(100, 100);
                newpic.Location = new Point(10, floor_height[0]);
            }
            if (floor_to == 1)
            {
                newpic.Image = global::WindowsFormsApplication1.Properties.Resources.ludek1;
                newpic.Location = new Point(10, floor_height[1]);
                newpic.BackColor = Color.Black;
                newpic.Size = new Size(100, 100);
            }
            if (floor_to == 2)
            {
                newpic.Image = global::WindowsFormsApplication1.Properties.Resources.ludek2;
                newpic.Location = new Point(10, floor_height[2]);
                newpic.BackColor = Color.Black;
                newpic.Size = new Size(100, 100);
            }
            if (floor_to == 3)
            {
                newpic.Image = global::WindowsFormsApplication1.Properties.Resources.ludek3;
                newpic.Location = new Point(10, floor_height[3]);
                newpic.BackColor = Color.Black;
                newpic.Size = new Size(100, 100);
            }
            ludek newludek = new ludek();
            newludek.from = floor_from;
            newludek.to = floor_to;
            newludek.pic = newpic;
            newludek.in_lift = false;
            return newludek;
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public void moveLift(int floor)
        {
            if (floor > current_floor)
                Lift.Location = new Point(Lift.Location.X, Lift.Location.Y - 1);
            else if(floor < current_floor)
                Lift.Location = new Point(Lift.Location.X, Lift.Location.Y + 1);
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (floor_queue.Count != 0)
            {
                if (floor_queue[0] != 8)
                {
                    int floor = floor_queue[0] % 10;
                    moveLift(floor);
                    if (Lift.Location.Y == floor_height[floor])
                    {
                        current_floor = floor;
                        floor_queue.RemoveAt(0);
                    } 
                }
                else
                {
                    floor_queue.RemoveAt(0);
                }
            }
        }

        private void fromFloor0to1_Click(object sender, EventArgs e)
        {
            ludek_arr.Add(createLudek(0, 1));
        }

        private void fromFloor0to2_Click(object sender, EventArgs e)
        {
            floor_queue.Add(0);
            floor_queue.Add(2);
        }

        private void fromFloor0to3_Click(object sender, EventArgs e)
        {
            floor_queue.Add(0);
            floor_queue.Add(3);
        }

        private void fromFloor1to0_Click(object sender, EventArgs e)
        {
            floor_queue.Add(1);
            floor_queue.Add(0);
        }

        private void fromFloor1to2_Click(object sender, EventArgs e)
        {
            floor_queue.Add(1);
            floor_queue.Add(2);
        }

        private void fromFloor1to3_Click(object sender, EventArgs e)
        {
            floor_queue.Add(1);
            floor_queue.Add(3);
        }

        private void fromFloor2to0_Click(object sender, EventArgs e)
        {
            floor_queue.Add(2);
            floor_queue.Add(0);
        }

        private void fromFloor2to1_Click(object sender, EventArgs e)
        {
            floor_queue.Add(2);
            floor_queue.Add(1);
        }

        private void fromFloor2to3_Click(object sender, EventArgs e)
        {
            floor_queue.Add(2);
            floor_queue.Add(3);
        }

        private void fromFloor3to0_Click(object sender, EventArgs e)
        {
            floor_queue.Add(3);
            floor_queue.Add(0);
        }

        private void fromFloor3to1_Click(object sender, EventArgs e)
        {
            floor_queue.Add(3);
            floor_queue.Add(1);
        }

        private void fromFloor3to2_Click(object sender, EventArgs e)
        {
            floor_queue.Add(3);
            floor_queue.Add(2);
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
    }
}
