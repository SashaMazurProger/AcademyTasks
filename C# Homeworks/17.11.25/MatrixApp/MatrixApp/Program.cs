using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MatrixLibrary;

namespace MatrixApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Matrix a = new Matrix(3, 3);
            Matrix b = new Matrix(3, 3);
            a.SetRandomValues();
            b.SetRandomValues();

            Console.WriteLine("Matrix A:");
            a.Show();

            Console.WriteLine("\nMatrix B:");
            b.Show();

            Console.WriteLine("\nOperation A-B");
            (a - b).Show();

            Console.WriteLine("\nOperation A+B");
            (a + b).Show();

            Console.WriteLine("\nOperation A/2");
            (a/2).Show();

            if (a)
                Console.WriteLine("\nMatrix A only have >0 numbers ");
            else
                Console.WriteLine("\nMatrix A only don't have <0 numbers ");

            Console.WriteLine("\n\nMatrix A to string\n");
            Console.WriteLine(a.ToString());

            Console.WriteLine("\nOperation A/0");
            try
            {
                (a / 0).Show();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.ReadKey();
        }
    }
}
