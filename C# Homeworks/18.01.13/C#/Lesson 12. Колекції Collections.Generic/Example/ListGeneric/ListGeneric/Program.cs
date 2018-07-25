using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListGeneric
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> listInt = new List<int>()
            {
                2,2,3,4,22,2,2,6,9,0
            };
            listInt.Add(4);
            listInt.Add(4);
            Console.WriteLine("Наш список:\n");
            showList(listInt);
            Console.WriteLine("Який елемент видалити?");
            int del;
            del = int.Parse(Console.ReadLine());
            //listInt.Remove(del);
            int n = listInt.Count;
            try
            {
                for (int i = 0; i < n;)
                {
                    if (del == listInt[i])
                    {
                        listInt.Remove(del);
                        n--;
                        continue;
                    }
                    i++;
                }
            }
            catch
            {
                Console.WriteLine("Ми хотіли видалити і виникли проблеми");
            }
            Console.WriteLine("Список після видалення:\n");
            showList(listInt);
        }
        static void showList(List<int> list)
        {
            foreach (int item in list)
            {
                Console.Write("{0} ", item);
            }
            Console.WriteLine();
        }
    }
}
