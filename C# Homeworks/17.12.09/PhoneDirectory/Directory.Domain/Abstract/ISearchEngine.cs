using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Directory.Domain.Abstract
{
    public interface ISearchEngine
    {
        IEnumerable<Contact> FindAll( params string[] parameters);
    }
}
