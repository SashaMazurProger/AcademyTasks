using Bogus;
using Companies.Domain;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Companies.ConsoleApp
{
    public class AddRandomData
    {
        public IEnumerable<Hobby> GenerateHobbies( int count)
        {
            List<Hobby> data=new List<Hobby>();
            var gen = new Faker<Hobby>()
            .RuleFor(h => h.Name, f => f.Commerce.Department())
            .RuleFor(h=>h.Description,f=>f.Lorem.Word())
            .FinishWith((f, h) => data.Add(h))
            .Generate(count);

            return data;
        }
        public IEnumerable<Company> GenerateCompanies(int count)
        {
            List<Company> data = new List<Company>();
            var gen = new Faker<Company>()
            .RuleFor(h => h.Name, f => f.Company.CompanyName())
            .FinishWith((f, h) => data.Add(h))
            .Generate(count);

            return data;
        }
        public IEnumerable<User> GenerateUsers(int count)
        {
            List<User> data = new List<User>();
            var gen = new Faker<User>()
            .RuleFor(h => h.FullName, f => f.Person.FullName)
            .RuleFor(h=>h.BirthDate,f=>f.Person.DateOfBirth)
            .FinishWith((f, h) => data.Add(h))
            .Generate(count);

            return data;
        }
    }
}
