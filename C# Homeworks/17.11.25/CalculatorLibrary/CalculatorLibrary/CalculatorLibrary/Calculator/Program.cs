using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("5.75+2.25={0}",CalculatorLibrary.Calculator.Add(5.75m,2.25m));
        }
    }
}
