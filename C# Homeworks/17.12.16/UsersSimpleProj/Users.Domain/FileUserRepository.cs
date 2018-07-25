using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Users.Domain.Abstract;
using Users.Domain.Entities;

namespace Users.Domain
{
    public class FileUserRepository:IUserRepository
    {
        private static string pathToFile = StaticValues.UsersFilePath;
        private List<User> allUsers;
        public FileUserRepository()
        {
            SetListUsers();
        }
        private void SaveToFile()
        {
            if (allUsers == null || !allUsers.Any())
                return;
            try
            {
                using (BinaryWriter writer = new BinaryWriter(File.Open(pathToFile, FileMode.OpenOrCreate)))
                {
                    foreach (var obj in allUsers)
                    {
                        writer.Write(obj.Id);
                        writer.Write(obj.Name);
                        writer.Write(obj.Hobby);
                        writer.Write(obj.Age);
                        writer.Write(obj.RoleId);
                    }
                }
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        private void SetListUsers()
        {
            if (!File.Exists(pathToFile))
                return;

            List<User> users = new List<User>();
            try
            {
                using (BinaryReader reader = new BinaryReader(File.Open(pathToFile, FileMode.Open)))
                {
                    while (reader.PeekChar() > -1)
                    {
                        User user = new User();
                        user.Id = reader.ReadInt32();
                        user.Name = reader.ReadString();
                        user.Hobby = reader.ReadString();
                        user.Age = reader.ReadInt32();
                        user.RoleId = reader.ReadInt32();
                        users.Add(user);
                    }
                }
                allUsers= users;
            }
            catch (Exception e)
            {
                throw e;
            }
        }
        public IEnumerable<User> GetListUsers()
        {
            return allUsers;
        }

        public User GetUser(int id)
        {
            return allUsers.First(c => c.Id == id);
        }

        public void Create(User user)
        {
            allUsers.Add(user);
            SaveToFile();
        }

        public void Update(User user)
        {
            User found = allUsers.First(c => c.Id == user.Id);
            if (found != null)
            {
                found = user;
                SaveToFile();
            }
        }

        public void Delete(User user)
        {
            User found = allUsers.First(c => c.Id == user.Id);
            if (found != null)
            {
                allUsers.Remove(found);
                SaveToFile();
             }
        }
    }
}
