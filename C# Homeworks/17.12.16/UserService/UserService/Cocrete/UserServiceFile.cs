using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    public class UserServiceFile : IUserService
    {

        private static string pathToFile = StaticValues.UsersFilePath;
        private List<User> allUsers=new List<User>();
        public UserServiceFile()
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
                        writer.Write(obj.Email);
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
                        user.Email = reader.ReadString();
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
        public User Add(User user)
        {
            List<User> roles = allUsers.OrderBy(r => r.Id).ToList();

            if (roles.Any())
            {
                user.Id = roles.Last().Id + 1;
            }
            else
            {
                user.Id = 1;
            }
            allUsers.Add(user);
            SaveToFile();
            return user;
        }

        public int Count()
        {
           return allUsers.Count;
        }

        public User[] FindUsers(UserSearch search)
        {
            return allUsers.Where(c => c.Email == search.Email&&
                c.Hobby==search.Hobby&&
                c.Age==search.Age).ToArray();
        }

        public void Remove(int id)
        {
            User found = allUsers.First(c => c.Id == id);
            if (found != null)
            {
                allUsers.Remove(found);
                SaveToFile();
            }
        }

        public User[] Users()
        {
            return allUsers.ToArray();
        }
    }
}
