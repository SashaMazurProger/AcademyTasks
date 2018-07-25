using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain.Abstract
{
    public interface IRepository
    {
        void SetContacts(IEnumerable<Contact> contacts);
        IEnumerable<Contact> GetListContacts();
        Contact GetContact(int id);
        void Create(Contact contact);
        void Update(Contact contact);
        void Delete(Contact contact);
    }
}
