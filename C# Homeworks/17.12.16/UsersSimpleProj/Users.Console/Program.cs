using Bogus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Users.Domain.Entities;
namespace Users.Console
{
    class Program
    {
        static void Main(string[] args)
        {
            var Roles = new Faker<Role>()
            .RuleFor(bp => bp.Id, f => f.IndexFaker)
            .RuleFor(r => r.Name, f => f.Commerce.Department()).Generate(100);

            foreach (var item in Roles)
            {
                System.Console.WriteLine("\nId{0}  Name:{1}", item.Id, item.Name);
            }
            System.Console.ReadKey();
            //System.Console.WriteLine("\nId{0}  Name:{1}", r.Id, r.Name));
        }
    }
}
