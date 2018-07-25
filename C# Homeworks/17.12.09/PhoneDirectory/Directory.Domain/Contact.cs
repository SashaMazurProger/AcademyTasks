using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain
{
    public class Contact
    {
        public int Id { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Telephone { get; set; }
        public string Address { get; set; }
        public Contact()
        {
            FirstName = "unknown";
            LastName = "unknown";
            Telephone = "unknown";
            Address = "unknown";
        }
    }
}
