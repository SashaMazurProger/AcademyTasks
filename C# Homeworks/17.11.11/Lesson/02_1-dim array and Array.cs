using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq; // для використання методів  розширення(extension) Average(), Count(), ... для масивів
using System.Text;

namespace _02_arrays
{
    class Program
    {
        static void Main(string[] args)
        {


            //int valInt = 0;
            //double valDbl = -1.0 / valInt;
            //Console.WriteLine($"{valDbl}");
            //Console.WriteLine($"{ double.IsPositiveInfinity(valDbl)}");
            //Console.WriteLine($"{sizeof(long)}, {sizeof(int)}");
            //return;
            Console.WriteLine(" __________ ValueType ___________\n");

            int a = 5;
            int b = 7;
            Console.WriteLine(" a = {0}   b = {1}", a, b);
            a = b;
            Console.WriteLine(" a = {0}   b = {1}", a, b);
            a = 11;
            Console.WriteLine(" a = {0}   b = {1}", a, b);


            Console.WriteLine("\n__________ ReferenceType ___________\n");

            int size = 6;
            int[] c = new int[size]; //масив - reference type
            int[] d = new int[size];
            for (int i = 0; i < size; ++i)
            {
                c[i] = i + 1;
                d[i] = i * 5;
            }
            ShowArr("c : ", c);
            ShowArr("d : ", d);

            c = d; // с  посилається на d
            ShowArr("After c = d;\n c : ", c);
            ShowArr("d : ", d);

            c[5] = 1000;
            ShowArr("After c[5] = 1000;\n c : ", c);
            ShowArr("d : ", d);

            Console.WriteLine("\n__________ class Array methods ___________\n");// System.Array - абстрактний,  базовий клас для масивів
            c = new int[] { 9, -8, 7, -6, 5, -4, 3, -2, 1, 10 };
            Array.Sort(c); // для впорядкування масиву використали статичний метод класу Array
          // Array.Sort(c, Cmp); // впорядкування за спаданням, Cmp - ми визначили стат метод для порівняння двох цілих
                                //Array.Sort(c, (x, y) => y - x); //за спаданням, використали лямбду

            ShowArr("After c = new int[] {9, -8, ...} and sorting\n c : ", c);
            Console.WriteLine("\n BinarySearch(c, -4) : " + Array.BinarySearch(c, -4)); // бінарний пошук елемента у масиві, повертає індекс входження(або  <0 )

            Array.Copy(d, 2, c, 4, 3);// копія 3-х елементів масиву d, починаючи з 2-го у масив с, починаючи з 4-го
            ShowArr("\n Array.Copy( d, 2, c, 4, 3 ) -- ", c);

            d.CopyTo(c, 2); // копія d у масив  c, починаючи з позиції 2(destination index)
            ShowArr("\n d.CopyTo( c, 2 )            -- ", c);
            //[] (int x)-> bool
            int elem = Array.Find(c,  (int x) => { return x % 3 == 0; }); // лямбда для пошуку кратних 3
            Console.WriteLine(" First element in  array c which divisible on 3: {0}", elem);

            int[] neg = Array.FindAll(c, x => x < 0);// результат - масив з відємних елементів
            ShowArr("\n Negative elements from c: ", neg);

            int[] odd = Array.FindAll(c, NotPair);
            ShowArr("\n Odd elements from c: ", odd);

            //---------------------------------------------розглянути самостійно------------
            Array.Reverse(c); // реверс елементів масиву
            ShowArr("Reverse of c : ", c);

            int summa = 0;
            Array.ForEach(c, x => summa += x); //захопили змінну summa
            Console.WriteLine("\n Summa of array c is " + summa);

            Console.WriteLine(" Summa(by c.Sum()) of array c is " + c.Sum()); // сума елементів обчислена за допомогою методу розширення Sum()
            Console.WriteLine("\n Average of array c is " + c.Average());
            Console.WriteLine("\n Maximum of array c is " + c.Max());

            Console.WriteLine("\n Count of  > 0 in array c is " + c.Count(x => x > 0));// кількість додатних елементів
            Console.WriteLine(" Array c contains 15 ?  " + c.Contains(15)); // чи містить 15
            try
            {
                Console.WriteLine(" First divisible 5 is ");
                Console.WriteLine(c.First(x => x % 5 ==0)); // c.Last(...)

                Console.WriteLine(" First  > 12345 is ");
                Console.WriteLine(c.First(x => x > 12345)); 
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.WriteLine(" IndexOf(c, 10) is " + Array.IndexOf(c, 10));
            
            Console.WriteLine("\n______________Paralell arrays(key, value)___________________\n");
            string[] words = { "ten", "two", "one", "zero", "seven" };
            int[] nums = { 10, 2, 1, 0, 7 };
            Array.Sort(nums, words); // сортування паралельних  масивів, nums = масив з ключами
            for (int i = 0; i < words.Length; ++i)
            {
                Console.WriteLine("num :{0,4}, words : {1}", nums[i], words[i]);
            }


            object cloneWords = words.Clone();// поверхнева копія масиву рядків
            string[] w = null; ;
            w = (string[])cloneWords; // явне приведення  типів: object --> string[]


            for (int i = 0; i < w.Length; ++i)
                Console.WriteLine("clone : " + w[i]);

            Console.WriteLine("\nAfter Array.Resize(ref w, 2);");
            Array.Resize(ref w, 2);
            for (int i = 0; i < w.Length; ++i)
                Console.WriteLine("clone : " + w[i]);

            //IEnumerable<int> res = c.Intersect(d);
            //Console.Write("\n Intersection of c and d :");
            //foreach (int r in res)
            //    Console.Write(r + "\t");

            //int[] arrRes = res.ToArray<int>();
            //ShowArr("\n arrRes: ", arrRes);
            Console.ReadKey();
        }

        static int Cmp(int x, int y)// 0 ==     >0    x > y    <0     X<y
        {
            return y - x;
        }

        static bool NotPair(int x)
        {
            return x % 2 != 0;
        }


        public static void ShowArr(string prompt, int[] arr)
        {
            Console.Write(" {0}: ", prompt);
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(" {0,2}", arr[i]);
            }
            Console.WriteLine("\n");
        }

    }
}
