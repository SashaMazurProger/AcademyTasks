using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{
    class RoleServiceMsSql : IRoleService
    {
        private string strCon = StaticValues.ConnectionStringDB;

            //"Data Source=10.7.0.5;" +
            //"Initial Catalog=TestInrerface;" +
            //"User ID=test;" +
            //"Password=123456qwerty";
        public Role Add(Role role)
        {
            Role newRole = null;
            string query = "Insert into Roles ([Name]) " +
                string.Format("Values('{0}'); ",role.Name);
            using (SqlConnection connection = new SqlConnection(strCon))
            {
                // Create the Command and Parameter objects.
                SqlCommand command = new SqlCommand(query, connection);
                try
                {
                    connection.Open();
                    int res = command.ExecuteNonQuery();
                    command.CommandText = "SELECT SCOPE_IDENTITY() AS InsertedRoleId;";
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        if(reader.Read())
                        {
                            int id=int.Parse(reader["InsertedRoleId"].ToString());
                            newRole = new Role
                            {
                                Id = id,
                                Name = role.Name
                            };
                        }
                    }
                    
                }
                catch { }
            }
            return newRole;
        }

        public Role GetRoleByName(string name)
        {
            Role role=null;


            string query = "Select r.Id, r.Name From Roles as r " +
                string.Format("WHERE  r.Name = '{0}'",name);
            using (SqlConnection connection = new SqlConnection(strCon))
            {
                // Create the Command and Parameter objects.
                SqlCommand command = new SqlCommand(query, connection);
                try
                {
                    connection.Open();
                    using (SqlDataReader reader = command.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            role = new Role
                            {
                                Id = int.Parse(reader["Id"].ToString()),
                                Name = reader["Name"].ToString()
                            };
                        }
                    }

                }
                catch { }
            }



            return role;
        }

        public void Remove(int id)
        {
            string querySearch = "select * from Roles where " + "Id=" + id;
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
                                com.CommandText = "delete Roles where Id=" + id;
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

        public Role[] Roles()
        {
            List<Role> roles = new List<Role>();
            string query = "select * from Roles";
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
                                
                                    Role role = new Role
                                    {
                                        Id = reader.GetInt32(0),
                                        Name = reader.GetString(1)
                                    };
                                    try
                                    {
                                        role.Description = reader.GetString(2);
                                    }
                                    catch
                                    {
                                       role.Description=string.Empty;
                                    }
                                    roles.Add(role);
                                
                            }
                        }
                    }
                }
                catch (Exception)
                {
                    throw;
                }
            }
            return roles.ToArray();
        }
    }
}
