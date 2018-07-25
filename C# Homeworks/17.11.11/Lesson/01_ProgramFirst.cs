
namespace Example_01
{
    using System;

    class Program
    {
        static void Main()//string[] args)
        {
            Console.Title = "Our first C# program. Перша програма."; // public static class Console
     
            Console.BackgroundColor = ConsoleColor.Gray; // ConsoleColor(7)
            Console.ForegroundColor = ConsoleColor.DarkBlue;
            Console.Clear();
          
            // Console.CursorLeft = 40;// x
           // Console.CursorTop = 2;// y
            Console.SetCursorPosition(40, 2);
           // System.Int32
            int i = 12345;// stack
            int a = 'a'; // неявне перетворення типу можливе без втрати точності
            Console.WriteLine("i = " + i/*.ToString()*/ + "\ta = " + a );

            float f = 2.9f;
            decimal d = 45.67890m;
            
             
            Console.WriteLine("\nf = {0}\td= {1}", f, d);// статичний метод класу Console, не потрібен обєкт для виклику, виклик через імя класу

            char symbol = 'A';
           // symbol.
            Console.WriteLine("\n{{ test }} symbol = {0}, its code = {1}", symbol, (ushort)symbol);
            Console.WriteLine("\nIsletter(symbol) = {0}", char.IsLetter(symbol));// стат метод класу Char, чи символ є буквою
            Console.WriteLine("IsUpper(symbol) = {0}", Char.IsUpper(symbol));
            Console.WriteLine("IsLower(symbol) = {0}", Char.IsLower(symbol));
            Console.WriteLine("ToLower('Ю') = {0}", Char.ToLower('Ю'));
            Console.WriteLine($"Isdigit('0') : {Char.IsDigit('0')}");// C#6 $"{}"

            for (int j = 0; j < 10; ++j)
                Console.Write($"{j*j, 10}");// ширина поля виводу  =5
            Console.WriteLine();

            int iValue = 0;
            Console.ForegroundColor = ConsoleColor.DarkRed;
            Console.Write("\nEnter integer value : ");
            
            string strInt = Console.ReadLine();// 12.34   12345  'text
           
            iValue = Convert.ToInt32(strInt);
            iValue *= 2;
            Console.WriteLine("iValue*=2; iValue = {0,10}", iValue); // ширина поля виводу  = 10

            double dValue = 0;
            Console.Write("\nEnter double value : ");
            dValue = Double.Parse(Console.ReadLine());
            //float.Parse
            Console.WriteLine("dValue = {0, 10 :N5}", dValue);// ширина поля виводу  = 10, N3 = 5 знаків після коми, N = числовий формат
          
            double sqrtDD = Math.Sqrt(dValue);//Math  - статичний клас, не потрібно створювати екземпляр стат. класу
            Console.WriteLine("sqrt(dValue) = {0:N3}  dValue % 2 = {1}", sqrtDD, dValue % 2);//  N3 = 3 знаки після коми, N = числовий формат
           
            
            Console.ForegroundColor = ConsoleColor.Black;
            Console.WriteLine("\nEnter some number : ");
            string input = Console.ReadLine();
            input = input.Replace( '.', ',');

         

            if (Int32.TryParse(input, out iValue))// out  ref     
            {
                Console.WriteLine("You entered {0}, its square is {1}", iValue, Math.Pow(iValue, 2));
            }
            else if (Double.TryParse(input, out dValue))
            {
                Console.WriteLine("You entered {0}, its square is  {1}", dValue, Math.Pow(dValue, 2));
            }
            else
            {
                Console.WriteLine("You entered string \"{0}\" which was not converted to Int32 or  Double !!!!", input);
            }


            {
                
                var something = 3;// int

                Console.WriteLine("\nvar something = 3; something.Gettype() : {0}", something.GetType());
            }
            //Console.WriteLine("\nsomething.Gettype() : {0}", something.GetType()); // пом компіляції, something за межами обл видимості 

          //  bool bVal = 1;// пом компіляції
            bool bVal = Convert.ToBoolean(-2);
            Console.WriteLine("bvalue = {0}", bVal);
           // Program p = new Program();
          
            //int result = p.Add(11, 22);
        }// Main

       /* static */int Add(int a, int b)
        {
            return a + b;
        }

    } // class Program

}// NS
