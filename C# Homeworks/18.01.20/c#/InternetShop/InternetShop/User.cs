using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InternetShop
{
    public class User
    {
        public int Id { get; set; }

        public string Name { get;private set; }

        public string Image { get;private set; }

        public string Telephone { get;private set; }

        public bool IsBasketProducts { get; set; }
        public User(string name,string image,string tel)
        {
            this.Name = name;
            this.Telephone = tel;
            this.Image = image;
            IsBasketProducts = false;
        }
        public User(int id,string name, string image, string tel)
        {
            this.Id = id;
            this.Name = name;
            this.Telephone = tel;
            this.Image = image;
            IsBasketProducts = false;
        }
    }
}
