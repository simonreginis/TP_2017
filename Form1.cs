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

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void toFloor3_Click(object sender, EventArgs e)
        {
            floor_queue.Add(0);
            floor_queue.Add(3);
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
                moveLift(floor_queue[0]);
                if (Lift.Location.Y == floor_height[floor_queue[0]])
                    floor_queue.RemoveAt(0);
            }
        }
    }
}
