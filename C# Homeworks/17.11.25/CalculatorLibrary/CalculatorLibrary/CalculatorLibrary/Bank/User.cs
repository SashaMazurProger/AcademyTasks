using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public decimal Money
        {
            get
            {
                return Money;
            }
            set
            {
                if (value >= 0)
                {
                    Money = value;
                }
            }
        }
        public void Info()
        {
            Console.WriteLine("\nName:{0}\nMoney:{1}",Name,Money);
        }
    }
}
