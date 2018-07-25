using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YourChat.Core
{
    public interface IRepository<T> where T:class
    {
        List<T> GetAll();
        bool Create(T item);
        void Delete(T item);
        void Update(T item);

    }
}
