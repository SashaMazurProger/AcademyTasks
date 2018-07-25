using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExampleSP
{
    public class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
    }
    public class EmployeeManager
    {
        private string _cs;
        public EmployeeManager(string con)
        {
            _cs = con;
        }
        public void DeleteById(int id)
        {
            using (SqlConnection con = new SqlConnection(_cs))
            {
                //У команді вказуємо назву нашої процедури
                SqlCommand cmd = new SqlCommand("delEmployeeById", con);
                //Тип команди вклик процедуры
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter paramTVP = new SqlParameter()
                {
                    ParameterName = "@EmployeeId",
                    Value = id
                };
                cmd.Parameters.Add(paramTVP);

                con.Open();
                cmd.ExecuteNonQuery();
            }
        }
        public void UpdateEmployee(Employee emp)
        {
            if (emp == null)
            { 
                return;
            }
            using (SqlConnection con = new SqlConnection(_cs))
            {
                //У команді вказуємо назву нашої процедури
                SqlCommand cmd = new SqlCommand("updEmployee", con);
                //Тип команди вклик процедуры
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter paramId = new SqlParameter()
                {
                    ParameterName = "@id",
                    Value = emp.Id
                };

                SqlParameter paramName = new SqlParameter()
                {
                    ParameterName = "@name",
                    Value = emp.Name
                };

                cmd.Parameters.Add(paramId);
                cmd.Parameters.Add(paramName);

                con.Open();
                cmd.ExecuteNonQuery();
            }
        }
        public List<Employee> FindEmployies(int id,string name,string gender)
        {
            List<Employee> found= new List<Employee>();
            if (name == null&&gender==null)
            {
                return null;
            }
            
            using (SqlConnection con = new SqlConnection(_cs))
            {
                string query = string.Format(" SELECT * from dbo.searchEmployies({0},'{1}','{2}')", id, name, gender);

                SqlCommand cmd = new SqlCommand(query, con);

                con.Open();

                SqlDataReader reader = cmd.ExecuteReader();

                if(reader.HasRows)
                {
                    while (reader.Read())
                    {
                        int empId = reader.GetInt32(0);
                        string empName = reader.GetString(1);
                        string empGender = reader.GetString(2);

                        found.Add(new Employee { Id = empId, Name = empName, Gender = empGender });
                    }
                }
                return found;
            }
        }
        public void UpdateFewEmployies(List<Employee> emp)
        {
            if (emp == null)
            { 
                return;
            }
            DataTable dt = new DataTable();
            dt.Columns.Add("Id");
            dt.Columns.Add("Name");
            dt.Columns.Add("Gender");

            foreach (var item in emp)
            {
                dt.Rows.Add(item.Id, item.Name,item.Gender);
            }

            using (SqlConnection con = new SqlConnection(_cs))
            {
                //У команді вказуємо назву нашої процедури
                SqlCommand cmd = new SqlCommand("updAllEmployies", con);
                //Тип команди вклик процедуры
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter paramEmp = new SqlParameter()
                {
                    ParameterName = "@employies",
                    Value = dt
                };

                cmd.Parameters.Add(paramEmp);

                con.Open();
                cmd.ExecuteNonQuery();
            }
        }
       
        public void AddRange(List<Employee> list)
        {
            DataTable dt = new DataTable();
            dt.Columns.Add("Name");
            dt.Columns.Add("Gender");
            foreach (Employee item in list)
            {
                dt.Rows.Add( item.Name, item.Gender);
            }


            using (SqlConnection con = new SqlConnection(_cs))
            {
                //У команді вказуємо назву нашої процедури
                SqlCommand cmd = new SqlCommand("spInsertEmployees", con);
                //Тип команди вклик процедуры
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter paramTVP = new SqlParameter()
                {
                    ParameterName = "@InputEmploees",
                    Value = dt
                };
                cmd.Parameters.Add(paramTVP);

                con.Open();
                cmd.ExecuteNonQuery();
                //con.Close();
            }

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Employee> list = new List<Employee>()
            {
                new Employee{Name="Vanya",Gender="Male"},
                new Employee{Name="Vova",Gender="Male"},
                new Employee{Name="Tanya",Gender="Female"}
            };

            //EmployeeManager manager = 
            //    new EmployeeManager("Data Source=.;Initial Catalog=ExampleTableType;Integrated Security=True");

            ////manager.AddRange(list);
            ////Console.WriteLine("\nAdded");

            //manager.DeleteById(4);
            //Console.WriteLine("\nDeleted with id=4");

            //manager.UpdateFewEmployies(new List<Employee> { new Employee{Id = 1, Name = "Sasha" },new Employee{Id=2,Name="Max"}});
            //Console.WriteLine("\nUpdated employies with id=1 and 2");

            //Console.WriteLine("\nSearch employies (Name = 'Vova')");
            //List<Employee> e = manager.FindEmployies(0, "Vova", " ");

            //Console.WriteLine("\nFound "+e.Count+" employies");
            //e.ForEach(a => Console.WriteLine("Id:"+a.Id + "  " + a.Name + "  " + a.Gender));

            Stack<Employee> stack = new Stack<Employee>();
            stack.Push(list[0]);
            stack.Push(list[1]);

            Console.WriteLine(stack.Peek().Name);

            Console.WriteLine(stack.Pop().Name);

            Console.WriteLine(stack.Pop().Name);
        }
    }
}
