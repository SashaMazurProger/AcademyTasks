using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace MatrixLibrary
{
    public class Matrix
    {
        private static Random random = new Random();
        public float[,] array;
        public Matrix(int colums, int raws)
        {
            array = new float[raws, colums];
        }
        public void SetRandomValues()
        {
            for (int r = 0; r < array.GetLength(0); ++r)
            {
                for (int c = 0; c < array.GetLength(1); ++c)
                {
                    array[r, c] = random.Next(0, 5);
                }
            }
        }
        public static Matrix operator +(Matrix a, Matrix b)
        {
            int col = a.array.GetLength(1), raws = a.array.GetLength(0);

            if (raws != b.array.GetLength(0))
                return null;
            else if (col != b.array.GetLength(1))
                return null;

            Matrix matrix = new Matrix(a.array.GetLength(0),
                a.array.GetLength(1));

            for (int r = 0; r < raws; ++r)
            {
                for (int c = 0; c < col; ++c)
                {
                    matrix.array[r, c] = a.array[r, c] + b.array[r, c];
                }
            }
            return matrix;
        }
        public static Matrix operator -(Matrix a, Matrix b)
        {
            int colA = a.array.GetLength(1), rawsA = a.array.GetLength(0);
            int colB = b.array.GetLength(1), rawsB = b.array.GetLength(0);
            if ((rawsA != rawsB))
                return null;
            else if ((colA != colB))
                return null;

            Matrix newMatrix = new Matrix(colA, rawsA);
            float[,] arrayA = a.array;
            float[,] arrayB = b.array;

            for (int i = 0; i < rawsA; i++)
            {
                for (int e = 0; e < colA; e++)
                {
                    newMatrix.array[i, e] = arrayA[i, e] - arrayB[i, e];
                }
            }
            return newMatrix;
        }
        public static Matrix operator /(Matrix matrix, int d)
        {
            if (d == 0)
                throw new MatrixDivideException();

            int col=matrix.array.GetLength(1),raws= matrix.array.GetLength(0);
            Matrix newMatrix = new Matrix(col,raws);
            for (int i = 0; i < raws; i++)
            {
                for (int e = 0; e < col; e++)
                {
                    newMatrix.array[i, e] = matrix.array[i, e] / d;
                }
            }
            return newMatrix;
        }
        public static bool operator true(Matrix a)
        {
            foreach (var item in a.array)
            {
                if (item < 0)
                    return false;
            }
            return true;
        }
        public static bool operator false(Matrix a)
        {
            foreach (var item in a.array)
            {
                if (item < 0)
                    return true;
            }
            return false;
        }
        public override string ToString()
        {
            StringBuilder str=new StringBuilder();
            for (int r = 0; r < array.GetLength(0); ++r)
            {
                for (int c = 0; c < array.GetLength(1); ++c)
                {
                    str.Append(array[r, c]+" ");
                }
                str.Append("\n");
            }
            return str.ToString();
        }
        public void Show()
        {
            Console.WriteLine("=============");
            for (int i = 0; i < this.array.GetLength(0); i++)
            {
                for (int e = 0; e < this.array.GetLength(1); e++)
                {
                    Console.Write(this.array[i,e]+" ");
                }
                Console.WriteLine();
            }
            Console.WriteLine("=============");
        }
    }
}
