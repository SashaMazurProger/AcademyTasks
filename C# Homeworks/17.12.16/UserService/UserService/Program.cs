using Bogus;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleAppInterface
{

    class Program
    {
        static void Main(string[] args)
        {
            
            IRoleService roleService;
            IUserService userService;
            SimpleInterface(out userService, out roleService);
            IUserManager userManager = new UserManager(roleService, userService);

            Console.WriteLine("\nGenerate random users? 1-yes");
            int op = int.Parse(Console.ReadKey().KeyChar.ToString());
            if (op == 1)
            {
                DateTime start = DateTime.Now;
                Console.WriteLine("\nGenerate and save users");
                GenerateData(100000, userManager);
                TimeSpan time = DateTime.Now - start;
                Console.WriteLine("\nSuccesful: " + time.Hours.ToString() + "m " + time.Seconds.ToString() + "s");
            }
            Console.ReadKey();
            while (true)
            {
                Console.WriteLine("***ALL USERS***");
                Role[] roles=roleService.Roles();
                foreach (var item in userManager.Users())
                {
                    try
                    {
                        Console.WriteLine("\n----------------------");
                        Console.WriteLine("\nId:{0} \nEmail:{1} \nHobby:{2} \nAge:{3} \nRole:{4}", item.Id,
                            item.Email, item.Hobby, item.Age, roles.First(r => r.Id == item.RoleId).Name);
                        Console.WriteLine("\n----------------------");
                    }
                    catch (Exception e)
                    {
                        Console.WriteLine("\nError:"+e.Message);
                    }
                }
                User newUser = new User();
                Console.WriteLine("Add new User:");
                Console.Write("Email: ");
                newUser.Email = Console.ReadLine();
                Console.Write("Hobby: ");
                newUser.Hobby = Console.ReadLine();
                Console.Write("Age: ");
                newUser.Age = int.Parse(Console.ReadLine());
                Console.Write("Role in system: ");
                string role = Console.ReadLine();

                var userAdd = userManager.Add(newUser, role);
                Console.WriteLine("User add successed id {0}", userAdd.Id);
            }

            Console.ReadKey();

        }
        static void SimpleInterface(out IUserService userService,out IRoleService roleService)
        {
            
            Console.WriteLine("З чим ви хочете працювати:");
            Console.WriteLine("1. Файлова система");
            Console.WriteLine("2. База даних MsSqlSever");
            Console.Write("->_");
            int action;
            action = int.Parse(Console.ReadLine());
            if (action == 1)
            {
                userService = new UserServiceFile();
                roleService = new RoleServiceFile();
                return;
            }

                userService = new UserServiceMsSql();
                roleService = new RoleServiceMsSql();
            
        }
        private static void GenerateData(int count,IUserManager manager)
        {
            List<User> users = new Faker<User>()
            .RuleFor(u => u.Id, f => f.UniqueIndex)
            .RuleFor(u => u.Email, f => f.Internet.Email())
            .RuleFor(u => u.Hobby, f => f.Commerce.Department())
            .RuleFor(u => u.Age, f => f.Random.Int(1, 100))
            .Generate(count);

            foreach (var item in users)
            {
                Console.Write("\nUser:" + item.Id);
                manager.Add(item, "user");

            }
        }
    }
}
