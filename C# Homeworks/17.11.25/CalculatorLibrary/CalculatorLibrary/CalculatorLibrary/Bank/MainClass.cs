using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class MainClass
    {
        static void Main(string[] args)
        {
            IUserRepository repository = new LocalBankRepository();
            Operator oper = new Operator(repository);

            oper.UserInfo();
            oper.AddModey();
            oper.UserInfo();

        }
    }
}
