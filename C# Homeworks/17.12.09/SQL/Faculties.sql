use ITStepUniversity
go
select fac.Name,fac.Description,fac.CreateDate, us.FirstName+' '+us.LastName as Dean
from Faculties as fac
join Users as us on us.Id=fac.DeanId
