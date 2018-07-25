using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    public class UserServiceMsSql : IUserService
    {
        private string strCon = StaticValues.ConnectionStringDB;
            
            //"Data Source=10.7.0.5;" +
            //"Initial Catalog=TestInrerface;" +
            //"User ID=test;" +
            //"Password=123456qwerty";
      
        public User Add(User user)
        {
            User newUser = null;

            string query = "Insert into Users (Email, Hobby, Age, RoleId) " +
                string.Format("Values('{0}', '{1}', {2}, {3});", user.Email, user.Hobby, user.Age, user.RoleId);
            using (SqlConnection connection = new SqlConnection(strCon))
            {
                // Create the Command and Parameter objects.
                SqlCommand command = new SqlCommand(query, connection);
                try
                {
                    connection.Open();
                    //Вставив користувача       
                    int res = command.ExecuteNonQuery();
                    command.CommandText = "SELECT SCOPE_IDENTITY() AS InsertedUserId;";
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            int id = int.Parse(reader["InsertedUserId"].ToString());
                            newUser = new User
                            {
                                Id = id,
                                Email = user.Email,
                                Hobby = user.Hobby,
                                Age = user.Age,
                                RoleId = user.RoleId
                            };
                        }
                    }

                }
                catch { }
            }
            return newUser;
        }

        public int Count()
        {
            int count = 0;
            string query = "select count(*) as CountUsers from Users";
            using (SqlConnection db = new SqlConnection(strCon))
            {

                SqlCommand com = new SqlCommand(query, db);
                try
                {
                    db.Open();
                    using (SqlDataReader reader = com.ExecuteReader())
                    {
                        count = int.Parse(reader["CountUsers"].ToString());
                    }

                }
                catch
                { }
            }
            return count;
        }

        public User[] FindUsers(UserSearch search)
        {
            List<User> users = new List<User>();
            string query = "select * from Users where " +
                string.Format("Users.Email='{0}' or Users.Hobby='{1}' or Users.Age={2}", search.Email, search.Hobby, search.Age);
            using (SqlConnection db = new SqlConnection(strCon))
            {
                SqlCommand com = new SqlCommand(query, db);
                try
                {
                    db.Open();
                    using (SqlDataReader reader = com.ExecuteReader())
                    {

                       if (reader.HasRows)
                        {
                            while (reader.Read())
                            {
                                User user = new User
                                {
                                    Email = reader.GetString(1),
                                    Hobby = reader.GetString(2),
                                    Age = reader.GetInt32(3)
                                };
                                users.Add(user);
                            }
                            reader.NextResult();
                        }
                    }
                }
                catch (Exception)
                {

                    throw;
                }
            }
            return users.ToArray();
        }

        public void Remove(int id)
        {
            string querySearch = "select * from Users where " + "Id=" + id;
            using (SqlConnection db=new SqlConnection(strCon))
            {
                SqlCommand com = new SqlCommand(querySearch, db);
                try
                {
                    com.Connection.Open();
                    using (SqlDataReader reader=com.ExecuteReader())
                    {
                        if(reader.HasRows)
                        {
                            if(id==reader.GetInt32(0))
                            {
                                com.CommandText = "delete Users where Id=" + id;
                                com.ExecuteNonQuery();
                            }
                        }
                    }
                }
                catch (Exception)
                {
                    
                    throw;
                }
            }
        }

        public User[] Users()
        {
            List<User> users = new List<User>();
            string query = "select * from Users";
            using (SqlConnection db=new SqlConnection(strCon))
            {
                SqlCommand com = new SqlCommand(query, db);
                try
                {
                    db.Open();
                    using (SqlDataReader reader=com.ExecuteReader())
                    {
                        if (reader.HasRows)
                        {
                            while (reader.Read())
                            {
                                User user = new User
                                {
                                    Id=reader.GetInt32(0),
                                    Email = reader.GetString(1),
                                    Hobby = reader.GetString(2),
                                    Age = reader.GetInt32(3),
                                    RoleId=reader.GetInt32(4)
                                };
                                users.Add(user);
                            }
                        }
                    }
                }
                catch (Exception)
                {
                    
                    throw;
                }
            }
            return users.ToArray();
        }
    }
}
