using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    public interface IRoleService
    {
        Role Add(Role role);
        void Remove(int id);
        Role GetRoleByName(string name);
        Role[] Roles();
    }
}
