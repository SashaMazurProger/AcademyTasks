using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain.Abstract
{
    public interface ILoadContacts
    {
        IEnumerable<Contact> GetContacts(string filePath);
    }
}
