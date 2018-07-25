using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    public interface IUserService
    {
        /// <summary>
        /// Додати нового користувача
        /// </summary>
        /// <param name="user"></param>
        /// <returns>Новий користувач із id</returns>
        User Add(User user);
        User[] FindUsers(UserSearch search);
        int Count();
        void Remove(int id);
        User[] Users();
    }
}
