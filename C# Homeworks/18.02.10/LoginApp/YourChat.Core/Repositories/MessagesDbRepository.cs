using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace YourChat.Core.Repositories
{
    public class MessagesDbRepository:IRepository<Message>
    {
        private ChatContext _context;

        public MessagesDbRepository(ChatContext context)
        {
            _context = context;
        }

        public List<Message> GetAll()
        {
            return _context.Messages.ToList();
        }

        public bool Create(Message item)
        {
            throw new NotImplementedException();
        }

        public void Delete(Message item)
        {
            throw new NotImplementedException();
        }

        public void Update(Message item)
        {
            throw new NotImplementedException();
        }
    }
}
