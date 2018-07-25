using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    public class BankDB
    {
        private List<User> users;
        public BankDB()
        {
            users = new List<User>();

            users.Add(new User { Id = 1, Name = "Mazur Oleksandr", Money = 12000m });
            //    new User{Id=2, Name="Kondratyuk Vasyl", Money=5500.45m},
            //    new User{ Id=3,Name="Ivanov Ivan",Money=100m}
            //};
        }
        public List<User> GetUsers()
        {
            return users;
        }
    }
}
