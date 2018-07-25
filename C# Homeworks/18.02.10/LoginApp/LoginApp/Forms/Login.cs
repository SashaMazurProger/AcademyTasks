using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using YourChat.Core.Helpers;
using YourChat.Core.Models;
using YourChat.Core.Repositories;

namespace LoginApp
{
    public partial class Login : Form
    {
        private UserManager userManager;

        private UserLoginHelper loginHelper;
        public Login()
        {
            InitializeComponent();
            userManager = UserManager.GetINSTANCE();
            loginHelper=new UserLoginHelper(new UserDbRepository(new ChatContext()));
        }

        private void buttonLogin_Click(object sender, EventArgs e)
        {

            string boxEmail=textBoxEmail.Text;

            string boxPass=textBoxPassword.Text;

            if(String.IsNullOrEmpty(boxEmail)||String.IsNullOrEmpty(boxPass))
            {
                MessageBox.Show("Please, enter login and password",
                    "Error",
                    buttons:MessageBoxButtons.OK,
                    icon:MessageBoxIcon.Information);
            }
            else
            {

                User curUser =userManager.GetCurrentUser();

                if (curUser == null)
                {
                    User userByEmail = loginHelper.GetUserByEmail(boxEmail);

                    if (userByEmail != null)
                    {
                        if (userByEmail.Email == boxEmail && userByEmail.Password == boxPass)
                        {
                            //////

                            userManager.SetCurrentUser(userByEmail);

                            UserDetails details = new UserDetails();
                            details.Show();

                            this.Close();
                        }
                        else
                        {
                            MessageBox.Show("Login or password incorrect.\nPlease, try again",
                                "Error",
                                buttons: MessageBoxButtons.OK,
                                icon: MessageBoxIcon.Information);
                        }
                    }

                    else
                    {
                        MessageBox.Show("A user witn these login and password don't exist.\nPlease, register",
                        "Error",
                        buttons: MessageBoxButtons.OK,
                        icon: MessageBoxIcon.Information);
                    }
                }
            }
            
        }

        private void pictureBoxEmail_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void buttonExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void textBoxEmail_TextChanged(object sender, EventArgs e)
        {
            
        }
    }
}
