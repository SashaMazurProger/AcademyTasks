use ITStepUniversity


go

select gr.Name as NameGroup,Disciplines.Name as Discipline,AVG(DisciplineOrders.Mark) as Mark
from StudentGroups as gr
left join Students on Students.StudentGroupId=gr.Id
left join DisciplineOrders on DisciplineOrders.StudentId=Students.Id
join TeachersDisciplines on DisciplineOrders.TeachersDisciplineId=TeachersDisciplines.Id
left join Disciplines on Disciplines.Id=TeachersDisciplines.DisciplineId 

go



