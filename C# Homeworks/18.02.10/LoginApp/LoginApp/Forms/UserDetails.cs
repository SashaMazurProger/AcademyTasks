using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using YourChat.Core.Models;

namespace LoginApp
{
    public partial class UserDetails : Form
    {
        public UserDetails()
        {
            InitializeComponent();

            UserManager manager = UserManager.GetINSTANCE();

            User curUser = manager.GetCurrentUser();

            if (curUser != null)
            {
                string time;

                if (DateTime.Now.Hour < 5)
                {
                    time = "Good night, ";
                }
                else if(DateTime.Now.Hour<12)
                {
                    time = "Good morning, ";
                }
                else if (DateTime.Now.Hour < 17)
                {
                    time = "Have a good day, ";
                }
                else
                {
                    time = "Good evening, ";
                }

                labelUserName.Text = time + curUser.FirstName;
            }
        }
    }
}
