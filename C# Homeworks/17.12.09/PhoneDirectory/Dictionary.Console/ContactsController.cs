using Directory.Domain.Abstract;
using System;
using Directory.Domain;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Threading;

namespace Directory.Domain
{
    public class ContactsController
    {
        private IRepository repository;
        private ILoadContacts loader;
        private ISaveContacts saver;
        private ISearchEngine searcher;
        public ContactsController(IRepository repo)
        {
            repository = repo;
        }
        public ContactsController(IRepository repo, ILoadContacts loader, ISaveContacts saver, ISearchEngine searcher)
        {
            repository = repo;
            this.loader = loader;
            this.saver = saver;
            this.searcher = searcher;
        }
        public void ShowAllContacts()
        {
            Contact[] contacts;
            if (repository != null)
            {
                contacts = repository.GetListContacts().ToArray();
            }
            else
                return;

            Console.Write("\n*************Contacts**************");
            if (!contacts.Any())
            {
                Console.Write("\n--Empty--");
                Console.Write("\n*****************************************");
                return;
            }
            for (int i = 0; i <contacts.Length; ++i)
            {
                Console.Write("\n-------------------");
                Console.Write("\nId:{0} \nFirstName:{1} \nLastName:{2}  \nTel.:{3} \nAddress:{4}",
                    contacts[i].Id, contacts[i].FirstName, contacts[i].LastName, contacts[i].Telephone,contacts[i].Address);
                Console.Write("\n-------------------");
            }
            Console.Write("\n*****************************************");

        }
        public void ShowFoundContacts(Contact[] contacts)//функція виводу знайдених контактів
        {
            
            if (!contacts.Any())
            {
                Console.WriteLine("\n--Empty--");

                return;
            }
            for (int i = 0; i < contacts.Length; ++i)
            {
                Console.Write("\n-------------------");
                Console.Write("\nId:{0} \nFirstName:{1} \nLastName:{2}  \nTel.:{3} \nAddress:{4}",
                    contacts[i].Id, contacts[i].FirstName, contacts[i].LastName, contacts[i].Telephone, contacts[i].Address);
                Console.Write("\n-------------------");
            }
        }
        public void ShowMainMenu()
        {
            Console.WriteLine("\n\t\tPhone Directory---MAIN MENU ");
            while (true)
            {
                Console.WriteLine("\n\nCHOOSE OPERATION:");
                Console.WriteLine("\n1-Show All contacts");
                Console.WriteLine("\n2-Add contact");
                Console.WriteLine("\n3-Delete contact");
                Console.WriteLine("\n4-Load contacts from file");
                Console.WriteLine("\n5-Save contacts to file");
                Console.WriteLine("\n6-Search contacts");
                Console.WriteLine("\n7-Exit");
                Console.Write("\n\nNumber of operation: ");
                int operation;
                int.TryParse(Console.ReadLine(),out operation);
                switch (operation)
                {
                    case 1: 
                        ShowAllContacts();
                        break;
                    case 2:
                        AddContact();
                        break;
                    case 3:
                        ShowAllContacts();
                        DeleteContact();
                        break;
                    case 4:
                        Console.Write("\nPath to file:");
                        string path = Console.ReadLine();
                        if (loader != null&&string.Empty!=path)
                        {
                            IEnumerable<Contact> contacts = loader.GetContacts(path);
                            repository.SetContacts(contacts);
                            Console.WriteLine("\nContacts were loaded");
                        }
                        else if (!File.Exists(path))
                        {
                            Console.WriteLine("\nFile not found");
                        }
                        else
                        {
                            Console.WriteLine("\nCan't load contacts");
                        }
                        break;
                    case 5:
                        Console.Write("\nPath to file:");
                        string pathSave = Console.ReadLine();
                        if (saver != null&&string.Empty!=pathSave)
                        {
                            IEnumerable<Contact> contacts = repository.GetListContacts();
                            if (saver.Save(contacts, pathSave))
                            {
                                Console.WriteLine("\nContacts were saved");
                            }
                            else
                            {
                                Console.WriteLine("\nContacts weren't saved");
                            }
                        }
                        else
                        {
                            Console.WriteLine("\nCan't save contacts");
                        }
                        break;
                    case 6:
                        if (searcher != null)
                        {
                            Console.Clear();
                            Console.Write("\n(Press Enter for exit)\n\n");
                            Thread.Sleep(1000);
                            SearchContacts();
                        }
                        break;
                    case 7:
                        Environment.Exit(0);
                        break;
                    default:
                        Console.WriteLine("\nWrong symbol");
                        break;
                }
            }
        }
        public void SearchContacts(string keyWord = null)
        {
            Console.Clear();
            ConsoleKeyInfo keyInfo;
            Contact[] contacts=null;
            
            if (keyWord == null)
            {
                keyWord = string.Empty;
            }
            else //знаходимо та показуємо результат
            {
                Console.Write("Search:" + keyWord);
                try
                {
                    contacts = searcher.FindAll(keyWord).ToArray();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    return;
                }
                ShowFoundContacts(contacts);
                Thread.Sleep(500);
                Console.Clear();
            }
            string key=keyWord;

                Console.Write("Search:" + keyWord);
                keyInfo = Console.ReadKey();
                //читаємо останній введений символ
                switch (keyInfo.Key)
                {
                    case ConsoleKey.Backspace: //стираємо останній символ в стоці пошуку
                        if (key != String.Empty)
                        {
                            key = key.Remove(key.Length - 1);
                        }
                        SearchContacts(key);
                        break;
                    case ConsoleKey.Enter:  //закінчуємо пошук, показуючи результат
                        if (contacts != null)
                            ShowFoundContacts(contacts);
                        else
                        {
                            Console.Clear();
                            return;
                        }
                        Console.ReadKey();
                        Console.Clear();
                        return;
                    default:
                        //додаємо символ до стоки пошуку
                        if (char.IsLetterOrDigit(keyInfo.KeyChar))
                        {
                            key = keyWord + keyInfo.KeyChar.ToString();
                            SearchContacts(key);
                            
                        }
                        break;
                }
                
        }
        
        public void AddContact()
        {

            Console.Write("\nFirst Name:");
            string firstName = Console.ReadLine();
            Console.Write("\nLast Name:");
            string lastName = Console.ReadLine();
            Console.Write("\nTelephone:");
            string tel = Console.ReadLine();
            Console.Write("\nAddresss:");
            string address = Console.ReadLine();

            //шукаэмо id останнього елемента
            int lastId;
            var all=repository.GetListContacts();
            if (all.Any())
            {
                var sort = (from i in all
                            orderby i.Id
                            select i).ToArray();
                lastId = sort[sort.Count() - 1].Id;
            }
            else
            {
                lastId = -1;
            }
                Contact con = new Contact
                {
                    Id = lastId + 1,
                    FirstName = firstName,
                    LastName = lastName,
                    Telephone = tel,
                    Address = address
                };
            
                repository.Create(con);
            

        }
        public void DeleteContact()
        {
            Console.Write("\nInput ID of deleted contact: ");
            int id =int.Parse( Console.ReadLine());
            Contact del=repository.GetContact(id);
            if (del != null)
                repository.Delete(del);
        }
    }
}
