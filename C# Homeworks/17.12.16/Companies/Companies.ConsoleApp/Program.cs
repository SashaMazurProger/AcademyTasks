using Companies.Domain;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Companies.ConsoleApp
{
    class Program
    {
        static string conString = "data source=10.7.0.5;initial catalog=CompaniesMazurS;user id=test;password=123456qwerty";
        static void Main(string[] args)
        {
            AddRandomData r=new AddRandomData();
            var h = r.GenerateHobbies(100);
            //InsertHobbies(h);
            var c = r.GenerateCompanies(200);
            InsertCompanies(c);
            List<int> id=new List<int>();
            string query="select Company.Id from Company";
            
            //using(SqlConnection con=new SqlConnection(conString))
            //{
            //    con.Open();
            //   using(SqlCommand com=new SqlCommand(query,con))
            //   {
            //      using(SqlDataReader reader=com.ExecuteReader())
            //      {
            //         //id.Add( reader.GetFieldValue["wef"])
            //      }
                  
            //   }
            //}
            //var u = r.GenerateUsers(300).ToList();

            //Random rand = new Random();
            //foreach (var item in id)
            //{
            //    Console.WriteLine(item);
            //}
            //for (int i = 0; i < u.Count();++i )
            //{
            //    u[i].CompanyId=id.First(it=>it==rand.Next(1,id.Count()-1));
            //    Console.WriteLine("\n Name:{0} CID:{1}", u[i].FullName, u[i].CompanyId);
            //}
            //foreach (var item in u)
            //{
            //    item.CompanyId = id.Single(it => it == rand.Next(1, id.Count() - 1));
            //}
        }
        public static void InsertHobbies(IEnumerable<Hobby> hob)
        {
            using (SqlConnection con = new SqlConnection(conString))
            {
                con.Open();
                foreach (var item in hob)
                {
                    string query = "insert into Hobby(Name,Description) values('" + item.Name + "','" + item.Description + "')";
                   using(SqlCommand com = new SqlCommand(query, con))
                   {
                       com.ExecuteNonQuery();
                   }
               
                }
            }
        }
        public static void InsertCompanies(IEnumerable<Company> hob)
        {
            using (SqlConnection con = new SqlConnection(conString))
            {
                con.Open();
                foreach (var item in hob)
                {
                    string query = "insert into Company(Name,Description) values('" + item.Name + "','" + item.Description + "')";
                    using (SqlCommand com = new SqlCommand(query, con))
                    {
                        com.ExecuteNonQuery();
                    }

                }
            }
        }
        public static void InsertUsers(IEnumerable<User> hob)
        {
            using (SqlConnection con = new SqlConnection(conString))
            {
                con.Open();
                foreach (var item in hob)
                {
                    string query = "insert into User(Name,Description) values('" + item.Name + "','" + item.Description + "')";
                    using (SqlCommand com = new SqlCommand(query, con))
                    {
                        com.ExecuteNonQuery();
                    }

                }
            }
        }
    }
    
}
