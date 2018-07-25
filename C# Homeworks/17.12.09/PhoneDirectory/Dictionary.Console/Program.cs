using Directory.Domain;
using Directory.Domain.Abstract;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary.Console
{
    class Program
    {
        static void Main(string[] args)
        {
            IRepository repo=new ContactsRepository();
            ISearchEngine search=new SearchContacts(repo);
            SaveToFile saver = new SaveToFile();
            LoadFromFile loader = new LoadFromFile();
            ContactsController con = new ContactsController(repo,loader,saver,search);
            con.ShowMainMenu();
        }
    }
}
