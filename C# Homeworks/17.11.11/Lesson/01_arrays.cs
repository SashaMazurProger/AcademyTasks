using System;


namespace Arrays_01
{
    class Program
    {
        static void Main()
        {
           
			const int size = 7;
            //int array[size]

            int[] arr= null;		// оголосили змінну, яка може містити посилання на масив (містить null)
            
            arr = new int[ size ];// arr-----> [][][][]
            for( int i = 0 ; i < size - 2 ; i++ )
			{
				arr[i] = i * i;
			}
			for( int i = 0 ; i < size ; i++ )
			{
				Console.Write(" {0,5}", arr[i] );
			}
			Console.WriteLine("\n");

			//int [] arr2 = new int[ size ]{ 11, 22, 33, 44, 55, 66, 77 };
			int [] arr2 =  { 11, 22, 33, 44, 55, 66 ,77, 88, 99, 111  }; // new int [] можна опустити, бо видно якого типу масив і на скільки елементів потрібно створити
			
			
			for( int i = 0 ; i < arr2.Length ; i++ )
			{
				Console.Write("{0,4}", ++arr2[i] );
			}
			Console.WriteLine("\n");
           // var  iii = 12344.6f;
            foreach (var elem in arr2) // foreach не дозволяє змінювати елементи, тільки читати
                Console.Write($"{elem,4}");

            Random random = new Random();// DateTime.Now.Millisecond); //створили екземпляр класу Random, розпочинаємо роботу з вип числами
            for (int i = 0; i < size; ++i)
            {
                arr[i] = random.Next(-10, 10); //генерація чергового цілого числа з [-10..10), 10 - не включаючи
                 
            }
          //  Program program = new Arrays_01.Program();
            //program.
             //Program.
                PrintArr("Random array(-10..10)", arr);

            double []dArray = new double[size];
            for (int i = 0; i < size; ++i)
            {
                dArray[i] = -7 + random.NextDouble() * 14000; //генерація чергового дробового числа з [-7..7)
            }
            PrintArr("Random double array(-7..7)", dArray);


                Console.WriteLine("\n\n\n");
        }// Main()
        
        static void PrintArr(string prompt, int[] arr) 
        {
            Console.WriteLine("\n\nArray {0} : ", prompt); 
            foreach (int elem in arr)
                Console.Write("{0,4}", elem);
            Console.WriteLine("\n");
        }
        static void PrintArr(string prompt, double[] arr)
        {
            arr[0] = 3;
            Console.WriteLine("\n\nArray {0} : ", prompt);
            foreach (var elem in arr)
                Console.WriteLine("|{0,-10:N2}|", elem);
            Console.WriteLine("\n");
        }
    }
}
