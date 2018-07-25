using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain.Abstract
{
    public interface ISaveContacts
    {
        bool Save(IEnumerable<Contact> contacts,string pathToFile);
    }
}
