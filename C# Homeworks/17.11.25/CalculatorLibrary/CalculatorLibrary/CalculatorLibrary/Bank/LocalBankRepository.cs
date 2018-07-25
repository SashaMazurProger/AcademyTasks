using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    public class LocalBankRepository:IUserRepository
    {
        private BankDB db;
        public LocalBankRepository()
        {
            db = new BankDB();
        }
        public List<User> GetUsers()
        {
            return db.GetUsers();
        }
        public User GetUser(int id)
        {
            return (User)db.GetUsers().Where(u => u.Id == id);
        }
    }
}
