using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Users.Domain.Entities;

namespace Users.Domain.Abstract
{
    public interface IRoleRepository
    {
        IEnumerable<Role> GetListRoles();
        User GetRole(int id);
        void Create(Role role);
        void Update(Role role);
        void Delete(Role role);
    }
}
