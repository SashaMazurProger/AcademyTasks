using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using LoginApp.Models;

namespace LoginApp.Abstract
{
    public interface IChatView
    {
        void SetController(ChatController controller);
        void ClearMessageList();
        void AddMessageToList(User user);
        void AddChatToList(Chat chat);
        int GetIdOfSelectedChatInGrid();
        void SetSelectedChatInGrid(User user);

        string FirstName { get; set; }
        string LastName { get; set; }
        string NickName { get; set; }
    }
}
