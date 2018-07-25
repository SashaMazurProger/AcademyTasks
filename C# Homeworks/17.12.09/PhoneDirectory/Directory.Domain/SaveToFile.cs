using Directory.Domain.Abstract;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain
{
    public class SaveToFile:ISaveContacts
    {
        public bool Save(IEnumerable<Contact> contacts,string pathToFile)
        {
            if (contacts == null || !contacts.Any())
                return false;
            try
            {
                using (BinaryWriter writer = new BinaryWriter(File.Open(pathToFile, FileMode.OpenOrCreate)))
                {
                    foreach (var obj in contacts)
                    {
                        if (obj.FirstName == null)
                            obj.FirstName = "";
                        if (obj.LastName == null)
                            obj.LastName = "";
                        if (obj.Telephone == null)
                            obj.Telephone = "";
                        if (obj.Address == null)
                            obj.Address = "";

                        writer.Write(obj.Id);
                        writer.Write(obj.FirstName);
                        writer.Write(obj.LastName);
                        writer.Write(obj.Telephone);
                        writer.Write(obj.Address);
                    }
                }
                return true;
            }
            catch (Exception e)
            {
                throw e;
            }
        }
    }
}
