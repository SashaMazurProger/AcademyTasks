using System;
using System.Collections;
//using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
//using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListExample
{
    class People : IComparable
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public int CompareTo(object obj)
        {
            People people = null;
            if (obj is People)
            {
                people = obj as People;
            }
            if(people!=null)
            {
                return this.Name.CompareTo(people.Name);
            }
            return 0;
        }
        public override string ToString()
        {
            return Name;
        }
    }
    class PeopleSortUp : IComparer<People>
    {
        public int Compare(People x, People y)
        {
            return x.Name.CompareTo(y.Name);
        }
    }
    class PeopleSortDown : IComparer<People>
    {
        public int Compare(People x, People y)
        {
            return -(x.Name.CompareTo(y.Name));
        }
    }
    class MyList<People> : IList<People>
    {
        public People this[int index] { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }

        public int Count => throw new NotImplementedException();

        public bool IsReadOnly => throw new NotImplementedException();

        public void Add(People item)
        {
            throw new NotImplementedException();
        }

        public void Clear()
        {
            throw new NotImplementedException();
        }

        public bool Contains(People item)
        {
            throw new NotImplementedException();
        }

        public void CopyTo(People[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }

        public IEnumerator<People> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public int IndexOf(People item)
        {
            throw new NotImplementedException();
        }

        public void Insert(int index, People item)
        {
            throw new NotImplementedException();
        }

        public bool Remove(People item)
        {
            throw new NotImplementedException();
        }

        public void RemoveAt(int index)
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
    }
    class UserManager
    {
        private MyList<People> _peoples;
        public UserManager()
        {
            _peoples = new MyList<People>();
        }
        public IList<People> GetAllUsers()
        {
            return _peoples;
        }
    }
    //class UserStatus
    //{
    //    public UserStatus()
    //    {
    //        _status = false;
    //    }
    //    private bool _status;

    //    public bool Status
    //    {
    //        get { return _status; }
    //        private set { _status = value; }
    //    }

    //    public bool Susseced { get { return _status; } }
    //}


    class Program
    {
        static void Main(string[] args)
        {
            //Dictionary<int, People> dictionary = new Dictionary<int, People>();
            ObservableCollection<People> collection = 
                new ObservableCollection<People>();
            collection.CollectionChanged += Collection_CollectionChanged;

            collection.Add(new People()
            {
                Id=22,
                Name="Stepan"
            });
            //ArrayList list = new ArrayList();
            //list.Add(new People { Id = 1, Name = "Hello" });
            //list.Add(new UserStatus() { });
            List<People> peoples = new List<People>();
            People p = new People {
                Id=1,
                Name="Slavik"
            };
            People p1 = new People
            {
                Id = 2,
                Name = "Tolik"
            };
            People p2 = new People
            {
                Id = 3,
                Name = "Olga"
            };
            People p3 = new People
            {
                Id = 4,
                Name = "Ivan"
            };
            peoples.Add(p);
            peoples.Add(p1);
            peoples.Add(p2);
            peoples.Add(p3);
            peoples.Sort();
            foreach (var item in peoples)
            {
                Console.WriteLine("item: {0}", item.Name);
            }
            Console.WriteLine();
            peoples.Sort(new PeopleSortDown());
            foreach (var item in peoples)
            {
                Console.WriteLine("item: {0}", item.Name);
            }
            //peoples[3].Name="asdfaf";


        }

        private static void Collection_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
        {
            
            if(e.Action == NotifyCollectionChangedAction.Add)
            {
                Console.WriteLine("Collectio add {0}", e.NewItems[0]);
            }

            
            //throw new NotImplementedException();
        }
    }
}
