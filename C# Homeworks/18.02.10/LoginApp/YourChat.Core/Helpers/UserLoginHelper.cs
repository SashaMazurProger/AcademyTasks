using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace YourChat.Core.Helpers
{
    public class UserLoginHelper
    {
        private IRepository<User> userRepository;

        public UserLoginHelper(IRepository<User> userRepository)
        {
            this.userRepository = userRepository;
        }
        public User GetUserByNickName(string nickName)
        {
            return userRepository.GetAll().Find(u => u.NickName == nickName);
        }
        public User GetUserByEmail(string email)
        {
            return userRepository.GetAll().Find(u => u.Email == email);
        }

        public bool RegisterNewUser(User newUser)
        {
            bool res = userRepository.Create(newUser);
            return res;
        }
    }
}
