using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Users.Domain.Entities
{
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Hobby { get; set; }
        public int Age { get; set; }
        public int RoleId { get; set; }
    }
}
