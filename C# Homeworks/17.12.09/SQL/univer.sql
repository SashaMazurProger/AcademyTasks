
/****** Object:  Database [ITStepUniversity]    Script Date: 09.12.2017 13:20:54 ******/

USE [ITStepUniversity]
GO
/****** Object:  User [test]    Script Date: 09.12.2017 13:20:54 ******/
/****** Object:  Table [dbo].[DisciplineOrders]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DisciplineOrders](
	[Id] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[TeachersDisciplineId] [int] NOT NULL,
	[Descripiton] [nvarchar](50) NULL,
	[Published] [bit] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
	[Mark] [float] NOT NULL,
	[Modified] [datetime] NULL,
	[StudentId] [int] NOT NULL,
 CONSTRAINT [PK_DisciplineOrders] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Disciplines]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Disciplines](
	[Id] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](200) NULL,
	[Published] [bit] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
	[Modified] [datetime] NULL,
 CONSTRAINT [PK_Disciplines] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Roles]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Roles](
	[Id] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Roles] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[RoleUsers]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[RoleUsers](
	[UserId] [int] NOT NULL,
	[RoleId] [int] NOT NULL,
 CONSTRAINT [PK_RoleUsers] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC,
	[RoleId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Students]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Students](
	[Id] [int] NOT NULL,
	[CreateDate] [datetime] NULL,
	[Published] [bit] NULL,
	[StudentGroupId] [int] NULL,
	[TelephoneId] [int] NULL,
 CONSTRAINT [PK_Students] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Teachers]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Teachers](
	[UserId] [int] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
	[Published] [bit] NOT NULL,
	[TelephoneId] [int] NULL,
 CONSTRAINT [PK_Teachers] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[TeachersDisciplines]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TeachersDisciplines](
	[Id] [int] NOT NULL,
	[TeacherId] [int] NOT NULL,
	[DisciplineId] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](200) NULL,
	[Published] [bit] NOT NULL,
	[CreateDate] [datetime] NOT NULL,
	[Modified] [datetime] NULL,
 CONSTRAINT [PK_TeachersDisciplines] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Telephones]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Telephones](
	[Id] [int] NOT NULL,
	[Number] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Telephones] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserDetails]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserDetails](
	[UserId] [int] NOT NULL,
	[IsConfirmed] [bit] NOT NULL,
	[CreateDateTime] [datetime] NOT NULL,
	[Image] [nvarchar](150) NULL,
	[MiniImage] [nvarchar](150) NULL,
	[MicroImage] [nvarchar](150) NULL,
	[ImageExtension] [nvarchar](50) NULL,
	[Description] [nvarchar](200) NULL,
 CONSTRAINT [PK_UserDetails] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Users]    Script Date: 09.12.2017 13:20:54 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[Id] [int] NOT NULL,
	[Email] [nvarchar](150) NOT NULL,
	[Password] [nvarchar](250) NOT NULL,
	[PasswordSalt] [nvarchar](250) NOT NULL,
	[FirstName] [nvarchar](150) NOT NULL,
	[LastName] [nvarchar](150) NOT NULL,
 CONSTRAINT [PK_Users] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
ALTER TABLE [dbo].[DisciplineOrders]  WITH CHECK ADD  CONSTRAINT [FK_DisciplineOrders_Students] FOREIGN KEY([StudentId])
REFERENCES [dbo].[Students] ([Id])
GO
ALTER TABLE [dbo].[DisciplineOrders] CHECK CONSTRAINT [FK_DisciplineOrders_Students]
GO
ALTER TABLE [dbo].[DisciplineOrders]  WITH CHECK ADD  CONSTRAINT [FK_DisciplineOrders_TeachersDisciplines] FOREIGN KEY([TeachersDisciplineId])
REFERENCES [dbo].[TeachersDisciplines] ([Id])
GO
ALTER TABLE [dbo].[DisciplineOrders] CHECK CONSTRAINT [FK_DisciplineOrders_TeachersDisciplines]
GO
ALTER TABLE [dbo].[RoleUsers]  WITH CHECK ADD  CONSTRAINT [FK_RoleUsers_Roles] FOREIGN KEY([RoleId])
REFERENCES [dbo].[Roles] ([Id])
GO
ALTER TABLE [dbo].[RoleUsers] CHECK CONSTRAINT [FK_RoleUsers_Roles]
GO
ALTER TABLE [dbo].[RoleUsers]  WITH CHECK ADD  CONSTRAINT [FK_RoleUsers_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[RoleUsers] CHECK CONSTRAINT [FK_RoleUsers_Users]
GO
ALTER TABLE [dbo].[Students]  WITH CHECK ADD  CONSTRAINT [FK_Students_Telephones] FOREIGN KEY([TelephoneId])
REFERENCES [dbo].[Telephones] ([Id])
GO
ALTER TABLE [dbo].[Students] CHECK CONSTRAINT [FK_Students_Telephones]
GO
ALTER TABLE [dbo].[Teachers]  WITH CHECK ADD  CONSTRAINT [FK_Teachers_Telephones] FOREIGN KEY([TelephoneId])
REFERENCES [dbo].[Telephones] ([Id])
GO
ALTER TABLE [dbo].[Teachers] CHECK CONSTRAINT [FK_Teachers_Telephones]
GO
ALTER TABLE [dbo].[Teachers]  WITH CHECK ADD  CONSTRAINT [FK_Teachers_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[Teachers] CHECK CONSTRAINT [FK_Teachers_Users]
GO
ALTER TABLE [dbo].[TeachersDisciplines]  WITH CHECK ADD  CONSTRAINT [FK_TeachersDisciplines_Disciplines] FOREIGN KEY([DisciplineId])
REFERENCES [dbo].[Disciplines] ([Id])
GO
ALTER TABLE [dbo].[TeachersDisciplines] CHECK CONSTRAINT [FK_TeachersDisciplines_Disciplines]
GO
ALTER TABLE [dbo].[TeachersDisciplines]  WITH CHECK ADD  CONSTRAINT [FK_TeachersDisciplines_Teachers] FOREIGN KEY([TeacherId])
REFERENCES [dbo].[Teachers] ([UserId])
GO
ALTER TABLE [dbo].[TeachersDisciplines] CHECK CONSTRAINT [FK_TeachersDisciplines_Teachers]
GO
ALTER TABLE [dbo].[UserDetails]  WITH CHECK ADD  CONSTRAINT [FK_UserDetails_Users] FOREIGN KEY([UserId])
REFERENCES [dbo].[Users] ([Id])
GO
ALTER TABLE [dbo].[UserDetails] CHECK CONSTRAINT [FK_UserDetails_Users]
GO
USE [master]
GO
ALTER DATABASE [ITStepUniversity] SET  READ_WRITE 
GO
