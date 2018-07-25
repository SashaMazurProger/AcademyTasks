using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternetShop
{
    public class UserManager
    {
        private string _con;

        private User curUser;

        public UserManager(string con)
        {
            this._con = con;
        }
        public void AddUser(User user)
        {
            if (user == null)
            {
                return;
            }

            string query = string.Format("insert into UserProfiles(Name,Image,Telephone) values('{0}','{1}','{2}')",
                user.Name, user.Image, user.Telephone);

            using (SqlConnection con = new SqlConnection(_con))
            {

                SqlCommand com = new SqlCommand(query, con);

                con.Open();

                com.ExecuteNonQuery();

                string queryId = "SELECT SCOPE_IDENTITY()";

                com = new SqlCommand(queryId, con);

                int id = (int)(decimal)com.ExecuteScalar();

                user.Id = id;

                curUser = user;

                Console.WriteLine("\nUser with id="+id+" was added");
            }
        }
        public void AddBasketProduct()
        {
            if (curUser == null)
            {
                return;
            }

            string query = string.Format("insert into BasketProducts(UserProfilesId, DateCreate) values({0}, GETDATE())",
                curUser.Id);

            using (SqlConnection con = new SqlConnection(_con))
            {

                SqlCommand com = new SqlCommand(query, con);

                con.Open();

                com.ExecuteNonQuery();

                curUser.IsBasketProducts = true;

            }
        }
        public List<Product> GetAllProducts()
        {
            List<Product> prods = new List<Product>();

            using (SqlConnection con = new SqlConnection(_con))
            {
                string query = " SELECT Id, Name, Price, Description from Products";

                SqlCommand cmd = new SqlCommand(query, con);

                con.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if (reader.HasRows)
                {
                    while (reader.Read())
                    {
                        int Id = (int)reader["Id"];
                        string Name = (string)reader["Name"];
                        decimal Price = (decimal)reader["Price"];
                        string desc = (string)reader["Description"];

                        prods.Add(new Product(Id, Name, Price, desc));
                    }
                }
                return prods;
            }
        }
        public void AddProductToUserBasket(Product prod, int quantity)
        {
            if (curUser == null || !curUser.IsBasketProducts)
            {
                return;
            }

            string query = string.Format("insert into BasketProductsRecords(ProductId,BasketProductId,Quantity,DateCreate)" +
                "values({0},{1},{2},GETDATE())",
                prod.Id, curUser.Id, quantity);

            using (SqlConnection con = new SqlConnection(_con))
            {

                SqlCommand com = new SqlCommand(query, con);

                con.Open();

                com.ExecuteNonQuery();

              
            }

        }
        public void FinishTheOrder()
        {
            using (SqlConnection con=new SqlConnection(_con))
            {
                SqlCommand com = new SqlCommand("InsertUserOrder", con);

                com.CommandType=CommandType.StoredProcedure;

                SqlParameter basketParam=new SqlParameter
                {
                   ParameterName="@userId",
                   Value=curUser.Id
                };

                com.Parameters.Add(basketParam);

                con.Open();

                com.ExecuteNonQuery();

                Console.WriteLine("\nOrder confirm");
            }
        }
    }
}
