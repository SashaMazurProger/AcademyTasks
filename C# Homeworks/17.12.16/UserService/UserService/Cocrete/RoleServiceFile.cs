using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace ConsoleAppInterface
{
    class RoleServiceFile : IRoleService
    {
        private List<Role> roles = new List<Role>();

        public RoleServiceFile()
        {
            LoadRoles();
        }
        private void LoadRoles()
        {
            if (!File.Exists(StaticValues.RolesFilePath))
            {
                FileInfo f = new FileInfo(StaticValues.RolesFilePath);
                f.Create();
            }
            XmlDocument xDoc = new XmlDocument();

            xDoc.Load(StaticValues.RolesFilePath);
            XmlElement xRoot = xDoc.DocumentElement;
            
            foreach (XmlElement item in xRoot)
            {
                Role role = new Role();
                role.Id=int.Parse(item.GetAttribute("id"));
                foreach (XmlNode child in item.ChildNodes)
                {
                    if (child.Name == "name")
                    {
                        role.Name = child.InnerText;
                    }
                    else if (child.Name == "description")
                    {
                        role.Description = child.InnerText;
                    }
                }
                roles.Add(role);
            }
            xDoc.Save(StaticValues.RolesFilePath);
        }
        private void SaveRoles()
        {
          
            XmlDocument xDoc = new XmlDocument();

            try
            {
                xDoc.Load(StaticValues.RolesFilePath);
            }
            catch (Exception e)
            {
                if (xDoc.DocumentElement == null)
                {
                    xDoc.CreateElement("roles");
                }
            }
            XmlElement xRoot = xDoc.DocumentElement;
            foreach (var role in roles)
            {
                XmlElement roleElem = xDoc.CreateElement("role");
                XmlAttribute idAttr = xDoc.CreateAttribute("id");
                XmlElement nameElem = xDoc.CreateElement("name");
                XmlElement descElem=xDoc.CreateElement("description");

                XmlText textId = xDoc.CreateTextNode(role.Id.ToString());
                XmlText textName = xDoc.CreateTextNode(role.Name);
                XmlText textDesc = xDoc.CreateTextNode(role.Description);

                idAttr.AppendChild(textId);
                nameElem.AppendChild(textName);
                descElem.AppendChild(textDesc);

                roleElem.Attributes.Append(idAttr);
                roleElem.AppendChild(nameElem);
                roleElem.AppendChild(descElem);

                xRoot.AppendChild(roleElem);
            }
            xDoc.Save(StaticValues.RolesFilePath);
        }
        public Role Add(Role role)
        {
            if (roles.Any())
            {
                role.Id = roles.OrderBy(r => r.Id).ToList().LastOrDefault().Id+1;
            }
            else
            {
                role.Id = 1;
            }
            roles.Add(role);
            SaveRoles();
            return role;
        }

        public Role GetRoleByName(string name)
        {
            return roles.FirstOrDefault(r => r.Name == name);
        }

        public void Remove(int id)
        {
            Role role = roles.First(r => r.Id == id);
            if (role != null)
            {
                roles.Remove(role);
                SaveRoles();
            }
        }

        public Role[] Roles()
        {
            return roles.ToArray();
        }
    }
}
