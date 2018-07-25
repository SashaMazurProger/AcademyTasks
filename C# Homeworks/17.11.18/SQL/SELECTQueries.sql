use [Chat]
GO
select us.NickName as Nick ,ch.Text as Message, ch.CreateDate as Time
from Users as us,ChatMessage as ch
where ch.FromUser=us.Id and ch.ChatId=2
GO
select ch.Text as Message, us.NickName as FromNick,ch.ToUser as ToNick
from ChatMessage as ch,Users as us
where us.Id=ch.FromUser and ch.ToUser!=0 
GO
--Відображення повідомлення, його автора і для кого воно
select ch.Text as Message, fr.NickName as FromNick,tou.NickName as ToNick
from ChatMessage as ch
join Users as fr
on ch.FromUser=fr.Id
join Users as tou
on ch.ToUser=tou.Id
where ch.ChatId=2
