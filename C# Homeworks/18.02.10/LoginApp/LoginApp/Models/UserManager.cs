using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace LoginApp
{
    public class UserManager
    {
        private static UserManager INSTANCE;

        private User currentUser;
        public User GetCurrentUser()
        {
            return currentUser;
        }

        private UserManager()
        {
        }

        public static UserManager GetINSTANCE()
        {
            if (INSTANCE == null)
            {
                object obj = new object();
                lock (obj)
                {
                    INSTANCE = new UserManager();
                }

            }

            return INSTANCE;
        }

        public void SetCurrentUser(User user)
        {
            object obj = new object();
            lock (obj)
            {
                currentUser = user;
            }
        }
    }
}
