using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    public class UserManager : IUserManager
    {
        private readonly IRoleService _roleService;
        private readonly IUserService _userService;
        public UserManager(IRoleService roleService, IUserService userService)
        {
            _roleService = roleService;
            _userService = userService;
        }
        public User Add(User user, string roleName)
        {
            var role = _roleService.GetRoleByName(roleName);
            if(role==null)
            {
                role = new Role();
                role.Name = roleName;
                role=_roleService.Add(role);
            }
            user.RoleId = role.Id;
            var userAdd=_userService.Add(user);
            return userAdd;
        }


        public IEnumerable<User> Users()
        {
            return _userService.Users();
        }
    }
}
