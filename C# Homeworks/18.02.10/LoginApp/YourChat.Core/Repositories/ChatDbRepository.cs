using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace YourChat.Core.Repositories
{
    class ChatDbRepository:IRepository<Chat>
    {
        private ChatContext _context;

        public ChatDbRepository(ChatContext context)
        {
            _context = context;
        }

        public List<Chat> GetAll()
        {
            return _context.Chats.ToList();
        }

        public bool Create(Chat item)
        {
            throw new NotImplementedException();
        }

        public void Delete(Chat item)
        {
            throw new NotImplementedException();
        }

        public void Update(Chat item)
        {
            throw new NotImplementedException();
        }
    }
}
