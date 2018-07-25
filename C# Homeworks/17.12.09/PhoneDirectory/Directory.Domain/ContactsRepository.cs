using Directory.Domain.Abstract;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain
{
    public class ContactsRepository:IRepository
    {
        private List<Contact> contacts = new List<Contact>() ;

        public void SetContacts(IEnumerable<Contact> contacts)
        {
            this.contacts = contacts.ToList();
        }
        
        public IEnumerable<Contact> GetListContacts()
        {
            return contacts;
        }

        public Contact GetContact(int id)
        {
            return contacts.First(c => c.Id == id);
        }

        public void Create(Contact contact)
        {
            contacts.Add(contact);
        }

        public void Update(Contact contact)
        {
            Contact found = contacts.First(c => c.Id == contact.Id);
            if (found != null)
                found = contact;
        }

        public void Delete(Contact contact)
        {
            contacts.Remove(contact);
        }
        
    }
}
