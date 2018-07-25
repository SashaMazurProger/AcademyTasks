using Directory.Domain;
using Directory.Domain.Abstract;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary.Console
{
    public class SearchContacts:ISearchEngine
    {
        IRepository repository;
        public SearchContacts(IRepository repository)
        {
            this.repository = repository;
        }


        public IEnumerable<Contact> FindAll(params string[] parameters)
        {
            List<Contact> found=new List<Contact>();
            if (repository != null)
            {
                List<Contact> contacts = repository.GetListContacts().ToList();

                if (contacts.Any())
                {
                    foreach (var param in parameters)
                    {
                        try
                        {
                            var foundByParam = from i in contacts
                                               where i.FirstName.Contains(param) || i.LastName.Contains(param) ||
                                               i.Telephone.Contains(param) || i.Address.Contains(param)
                                               orderby i.FirstName
                                               select i;

                            foreach (var item in foundByParam)
                            {
                                if (!found.Contains(item))
                                    found.Add(item);
                            }
                        }
                        catch (Exception e)
                        {
                            throw e;
                        }
                    }
                }
            }
            return found;
        }
    }
}
