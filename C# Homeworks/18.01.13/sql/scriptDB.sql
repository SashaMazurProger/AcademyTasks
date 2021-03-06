USE [ExampleTableType]
GO
/****** Object:  UserDefinedTableType [dbo].[EmpTableType]    Script Date: 20.01.2018 0:05:35 ******/
CREATE TYPE [dbo].[EmpTableType] AS TABLE(
	[Id] [int] NOT NULL IDENTITY (1,1),
	[Name] [nvarchar](50) NULL,
	[Gender] [nvarchar](10) NULL,
	PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (IGNORE_DUP_KEY = OFF)
)
GO
/****** Object:  Table [dbo].[Employees]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Employees](
	[Id] [int] NOT NULL IDENTITY (1,1),
	[Name] [nvarchar](50) NULL,
	[Gender] [nvarchar](10) NULL,
PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  UserDefinedFunction [dbo].[searchEmployies]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE function [dbo].[searchEmployies](@id int, @name nvarchar(50),@gender nvarchar(20))
returns table
as 
return (select * from Employees 
        where Id = @id or Name = @name or Gender = @gender)


GO
/****** Object:  StoredProcedure [dbo].[delEmployeeById]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create procedure [dbo].[delEmployeeById]
@EmployeeId int
as
delete from Employees
  where Id = @EmployeeId
GO
/****** Object:  StoredProcedure [dbo].[findEmployies]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create proc [dbo].[findEmployies]
@id int, @name nvarchar(50),@gender nvarchar(20)
as
begin
  select * from Employees 
  where Id = @id or 
  upper(Name) like upper('%'+@name+'%') or 
  upper(Gender) like upper('%'+@gender+'%')
end
GO
/****** Object:  StoredProcedure [dbo].[spInsertEmployees]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[spInsertEmployees]
@InputEmploees EmpTableType READONLY
AS
BEGIN
    INSERT INTO Employees
    SELECT * FROM @InputEmploees
END


GO
/****** Object:  StoredProcedure [dbo].[updAllEmployies]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE procedure [dbo].[updAllEmployies]
@employies EmpTableType readonly
as
begin
  declare @count int=(select count(*) from @employies)

  if (@count)>0
  begin
	  DECLARE EmpCursor CURSOR READ_ONLY  
  		FOR  select Id, Name from @employies; 
  	  
  	  Declare @empId int  
  	  Declare @empName nvarchar(50)  
    
  	  Open EmpCursor;
  	  FETCH NEXT from EmpCursor INTO @empId, @empName;
  	  WHILE @@FETCH_STATUS = 0   
   	  BEGIN  
  	        update Employees
			set Name = @empName
			where Id = @empId

            FETCH NEXT from EmpCursor INTO @empId, @empName; 
  	  END  
  	  CLOSE EmpCursor;
  	  DEALLOCATE EmpCursor;
  end
  else
  print 'Empty parameter' 
end
GO
/****** Object:  StoredProcedure [dbo].[updEmployee]    Script Date: 20.01.2018 0:05:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create procedure [dbo].[updEmployee]
@id int,@name nvarchar(50)
as 
begin
 update Employees
 set Name = @name
 where Id = @id
end
GO
