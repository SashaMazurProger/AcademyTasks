using Directory.Domain.Abstract;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain
{
    public class LoadFromFile:ILoadContacts
    {
        public IEnumerable<Contact> GetContacts(string pathToFile)
        {
            if (!File.Exists(pathToFile))
                return null;

            List<Contact> contacts = new List<Contact>();
            try
            {
                using (BinaryReader reader = new BinaryReader(File.Open(pathToFile, FileMode.Open)))
                {
                    while(reader.PeekChar()>-1)
                    {
                        Contact con=new Contact();
                        con.Id=reader.ReadInt32();
                        con.FirstName=reader.ReadString();
                        con.LastName = reader.ReadString();
                        con.Telephone = reader.ReadString();
                        con.Address = reader.ReadString();
                        contacts.Add(con);
                    }
                }
                return contacts;
            }
            catch (Exception e)
            {
                throw e;
            }
        }
    }
}
