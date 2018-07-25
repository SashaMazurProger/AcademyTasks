using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace YourChat.Core.Repositories
{
    public class UserDbRepository : IRepository<User>
    {
        private ChatContext _context;

        public UserDbRepository(ChatContext context)
        {
            _context = context;
        }

        public List<User> GetAll()
        {
            return _context.Users.ToList();
        }

        public bool Create(User item)
        {
            try
            {
                _context.Users.Add(item);
            }
            catch (Exception e)
            {
                return false;
            }
            _context.SaveChanges();
            return true;
        }

        public void Delete(User item)
        {
            _context.Users.Remove(item);
            _context.SaveChanges();
        }

        public void Update(User item)
        {
            _context.Entry(item).State = EntityState.Modified;
            _context.SaveChanges();
        }
    }
}
