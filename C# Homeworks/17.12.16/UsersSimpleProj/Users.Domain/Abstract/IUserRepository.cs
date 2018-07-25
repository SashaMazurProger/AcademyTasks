using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Users.Domain.Entities;

namespace Users.Domain.Abstract
{
    public interface IUserRepository
    {
        IEnumerable<User> GetListUsers();
        User GetUser(int id);
        void Create(User user);
        void Update(User user);
        void Delete(User user);
    }
}
