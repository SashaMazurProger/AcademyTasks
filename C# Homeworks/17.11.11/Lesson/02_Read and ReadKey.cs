using System;

namespace _02_first
{
    class Program
    {
        static void Main(string[] args)
        {
            //Console.Rea

            char symbol;
            int numA = 0, others = 0;
            const int newLine = 13; // 13 = return caret, 10 = newline

            Console.WriteLine("Input text. We will count letters a, A and others.");
            symbol =(char) Console.Read();
            while (symbol != newLine) //(int)ConsoleKey.Enter)
            {
                switch (symbol)
                {
                    case 'a' :
                    case 'A':
                        ++numA;
                        break;
                    default:
                        ++others;
                        break;
                }
                symbol = (char)Console.Read();
                
            }
            Console.WriteLine("Number of 'a' and 'A' : {0}, other symbols : {1}", numA, others);
            Console.ReadLine();
            Console.ReadLine();

            /////////////////////////
           // Console.Clear();
            Console.WriteLine("Test Console.ReadKey()\nPress  a or then control Z, press Escape for exit");
            ConsoleKeyInfo info = Console.ReadKey(); 
	        while (info.Key != ConsoleKey.Escape)
	        {
                if (info.Modifiers == (ConsoleModifiers)0)
                {
                    if (info.KeyChar == 'a')
                    {
                        Console.WriteLine("\tYou pressed small latin a");
                    }
                    else if (info.KeyChar == 'A')
                    {
                        Console.WriteLine("\tYou pressed Big latin a");
                    }
                    else if (info.KeyChar == 'я')
                    {
                        Console.WriteLine("\tYou pressed small cyrylic я");

                    }
                    else if (info.KeyChar == 'Я')
                    {
                        Console.WriteLine("\tYou pressed big cyrylic Я");

                    }
                    if (info.Key == ConsoleKey.A)
                    {
                        Console.WriteLine("\tYou pressed  key with A in any keyboard shift");
                    }

                    else if (info.Key == ConsoleKey.UpArrow)
                    {
                        Console.WriteLine("\tYou pressed UpArrow");

                    }
                    else if (info.Key == ConsoleKey.Enter)
                    {
                        Console.WriteLine("\tYou pressed Enter");

                    }
                    else
                    {
                        Console.WriteLine("\tYou pressed some  key without modifier");

                    }
                }
                else if (info.Key == ConsoleKey.Z && info.Modifiers == ConsoleModifiers.Control)
                {
                    Console.WriteLine("\tYou pressed control Z");
                }
                else if (info.Key == ConsoleKey.A && info.Modifiers == ConsoleModifiers.Alt)
                {
                    Console.WriteLine("\tYou pressed Alt- A");
                }
                else
                {
                    Console.WriteLine("\tYou pressed other key with modifier");

                }
                info = Console.ReadKey();

	        }
            Console.WriteLine("\tYou pressed escape!");

            System.Threading.Thread.Sleep(1000);// sleep = 1000 miliseconds 
            // Environment.Exit(0); // close application 
        }
    }
}