using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{ 
    public interface IUserManager
    {
        User Add(User user, string roleName);
        IEnumerable<User> Users();
    }
}
