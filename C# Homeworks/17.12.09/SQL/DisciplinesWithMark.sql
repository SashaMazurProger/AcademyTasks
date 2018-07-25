use ITStepUniversity


go
select Users.FirstName+' '+Users.LastName as Teacher, Disciplines.Name as DisciplineWithMark
from DisciplineOrders as discOrd
join TeachersDisciplines as teachDisc on discOrd.TeachersDisciplineId=teachDisc.Id  
join Disciplines on Disciplines.Id=teachDisc.DisciplineId
join Users on teachDisc.TeacherId=Users.Id 
where discOrd.Mark>0

