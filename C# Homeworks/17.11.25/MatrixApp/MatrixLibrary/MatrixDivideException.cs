using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MatrixLibrary
{
    public class MatrixDivideException:Exception
    {
        public override string Message
        {
            get
            {
                return "Digit can't be zero";
            }
        }
    }
}
