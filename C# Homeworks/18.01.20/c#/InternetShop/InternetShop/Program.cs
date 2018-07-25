using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternetShop
{
    class Program
    {
        static void Main(string[] args)
        {
            string conStr = "Data Source=.;Initial Catalog=InternetShopMSasha;Integrated Security=True";

            UserManager manager = new UserManager(conStr);

            //Add new user
            Console.WriteLine("Name of new user:");
            string n = Console.ReadLine();
            Console.WriteLine("\nImage:");
            string i = Console.ReadLine();
            Console.WriteLine("\nTel:");
            string t = Console.ReadLine();

            User user = new User(n, i, t);

            manager.AddUser(user);

            Console.ReadKey();

            //Add products to user basket
            Console.WriteLine("\n\nAll products");

            List<Product> prods=manager.GetAllProducts();

            prods.ForEach(p => Console.WriteLine("\nId:{0}  Name:{1}  Price:{2} Description:{3}",
                p.Id, p.Name, p.Price, p.Description));

            Console.WriteLine("\nAdd product with Id=2 and quantity=2");

            manager.AddBasketProduct();

            Product chooseProd=(from p in prods
                           where p.Id==2
                           select p).FirstOrDefault();

            if(chooseProd!=null)
            {
                manager.AddProductToUserBasket((Product)chooseProd,2);
            }

            Console.WriteLine("\nFinish order");
            manager.FinishTheOrder();
            Console.ReadKey();
        }
    }
}
