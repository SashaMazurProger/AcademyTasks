--Create Database ExampleTableType

--Go
Use ExampleTableType
--Go
--Create Table Employees
--(
--    Id int primary key,
--    Name nvarchar(50),
--    Gender nvarchar(10)
--)
--Go

--CREATE TYPE EmpTableType AS TABLE
--(
--    Id INT PRIMARY KEY,
--    Name NVARCHAR(50),
--    Gender NVARCHAR(10)
--)
--Go

--CREATE PROCEDURE spInsertEmployees
--@InputEmploees EmpTableType READONLY
--AS
--BEGIN
--    INSERT INTO Employees
--    SELECT * FROM @InputEmploees
--END

GO
DECLARE @EmployeeTableType EmpTableType

INSERT INTO @EmployeeTableType VALUES (1, 'Mark', 'Male')
INSERT INTO @EmployeeTableType VALUES (2, 'Mary', 'Female')
INSERT INTO @EmployeeTableType VALUES (3, 'John', 'Male')
INSERT INTO @EmployeeTableType VALUES (4, 'Sara', 'Female')
INSERT INTO @EmployeeTableType VALUES (5, 'Rob', 'Male')

EXECUTE spInsertEmployees @EmployeeTableType

--Drop database ExampleTableType


	