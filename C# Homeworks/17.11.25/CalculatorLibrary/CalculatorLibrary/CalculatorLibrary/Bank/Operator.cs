using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    public class Operator
    {
        private IUserRepository repository;
        public int OperatorId { get; set; }
        public Operator(IUserRepository userRepository)
        {
            repository = userRepository;
        }
        public void AddModey()
        {
            Console.Write("Input id of user:");
            int id = int.Parse(Console.ReadLine());
            User user = repository.GetUser(id);

            if (user == null)
                return;

            Console.Write("Input money(UAH):");
            decimal money = decimal.Parse(Console.ReadLine());
            user.Money = CalculatorLibrary.Calculator.Add(user.Money, money);
        }
        public void UserInfo()
        {
            Console.Write("Input id of user:");
            int id = int.Parse(Console.ReadLine());
            User user = repository.GetUser(id);

            if (user == null)
                return;

            user.Info();
        }
    }
}
