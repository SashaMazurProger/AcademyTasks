using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using YourChat.Core.Models;

namespace YourChat.Core.Helpers
{
    public class MessagesHelper
    {
        private IRepository<Message> _repository;

        public MessagesHelper(IRepository<Message> repository)
        {
            _repository = repository;
        }

        public List<Message> GetMessagesByChatId(int chatId)
        {
            return _repository.GetAll().FindAll(m=>m.)
        }
    }
}
