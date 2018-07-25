using System;
using System.Collections;
using System.Collections.Generic;


namespace Example
{
    class Test
    {

    }
    class MyEnumerator : IEnumerator
    {
        public int[] list;
        private int current;
        public MyEnumerator()
        {
            current = -1;
        }
        public object Current
        {
            get
            {
                return list[current];
            }
        }

        public bool MoveNext()
        {
            if (current < list.Length - 1)
            {
                current++;
                return true;
            }
            else
            {
                this.Reset();
                return false;
            }
        }

        public void Reset()
        {
            current = -1;
        }
    }
    class MyArray : IEnumerable
    {
        //Array[] array;
        MyEnumerator myEnumerator;
        public MyArray()
        {
            myEnumerator = new MyEnumerator();
            myEnumerator.list = new int[5];
            Random a = new Random();
            for (int i = 0; i < myEnumerator.list.Length; i++)
                myEnumerator.list[i] = a.Next(1, 10);
            //mass = new int[5];
            //Random a = new Random();
            //for (int i = 0; i < mass.Length; i++)
            //    mass[i] = a.Next(1, 10);
        }
        public IEnumerator GetEnumerator()
        {
            return myEnumerator;
        }
        public override string ToString()
        {
            return "Hello! My name is MyArray";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] mas = new int[] { 23, 23, 23, 2, 2, 6 };
            Console.WriteLine("--------Array-----------");
            foreach(int item in mas)
            {
                Console.Write("{0} ",item);
            }
            Console.WriteLine();
            ArrayList arrayList = new ArrayList();
            arrayList.AddRange(mas);
            arrayList.Add(12);
            Console.WriteLine("-----------ArrayList------------------");
            foreach (int item in arrayList)
            {
                Console.Write("{0} ", item);
            }
            Console.WriteLine();
            Console.WriteLine("-----------MyArray------------------");
            MyArray myArray = new MyArray();
            Console.WriteLine(myArray);
            foreach(var item in myArray)
                Console.Write("{0} ",item);
            Console.WriteLine();
            Console.WriteLine("-----------MyArray------------------");
            foreach (var item in myArray)
                Console.Write("{0} ", item);
            Console.WriteLine();

            //Test test = new Test();
            //Console.WriteLine("-----------MyArray------------------");
            //foreach (var item in test)
            //    Console.Write("{0} ", item);
            //Console.WriteLine();
        }
    }
}
