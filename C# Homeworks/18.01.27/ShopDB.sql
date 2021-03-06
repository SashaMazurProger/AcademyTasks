USE [master]
GO
/****** Object:  Database [InternetShopMSashaFilters]    Script Date: 09.02.2018 18:17:14 ******/
CREATE DATABASE [InternetShopMSashaFilters]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'InternetShopMSashaFilters', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\InternetShopMSashaFilters.mdf' , SIZE = 4288KB , MAXSIZE = UNLIMITED, FILEGROWTH = 1024KB )
 LOG ON 
( NAME = N'InternetShopMSashaFilters_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL12.MSSQLSERVER\MSSQL\DATA\InternetShopMSashaFilters_log.ldf' , SIZE = 1344KB , MAXSIZE = 2048GB , FILEGROWTH = 10%)
GO
ALTER DATABASE [InternetShopMSashaFilters] SET COMPATIBILITY_LEVEL = 120
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [InternetShopMSashaFilters].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ARITHABORT OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET  ENABLE_BROKER 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET RECOVERY FULL 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET  MULTI_USER 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [InternetShopMSashaFilters] SET DB_CHAINING OFF 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET TARGET_RECOVERY_TIME = 0 SECONDS 
GO
ALTER DATABASE [InternetShopMSashaFilters] SET DELAYED_DURABILITY = DISABLED 
GO
EXEC sys.sp_db_vardecimal_storage_format N'InternetShopMSashaFilters', N'ON'
GO
USE [InternetShopMSashaFilters]
GO
/****** Object:  UserDefinedTableType [dbo].[BasketProdRecordType]    Script Date: 09.02.2018 18:17:16 ******/
CREATE TYPE [dbo].[BasketProdRecordType] AS TABLE(
	[BasketProdId] [int] NOT NULL,
	[ProductId] [int] NOT NULL,
	[Quantity] [int] NOT NULL,
	[DateCreate] [datetime] NOT NULL
)
GO
/****** Object:  UserDefinedTableType [dbo].[BasketProdType]    Script Date: 09.02.2018 18:17:16 ******/
CREATE TYPE [dbo].[BasketProdType] AS TABLE(
	[UserId] [int] NOT NULL,
	[DateCreate] [datetime] NOT NULL
)
GO
/****** Object:  Table [dbo].[__MigrationHistory]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[__MigrationHistory](
	[MigrationId] [nvarchar](150) NOT NULL,
	[ContextKey] [nvarchar](300) NOT NULL,
	[Model] [varbinary](max) NOT NULL,
	[ProductVersion] [nvarchar](32) NOT NULL,
 CONSTRAINT [PK_dbo.__MigrationHistory] PRIMARY KEY CLUSTERED 
(
	[MigrationId] ASC,
	[ContextKey] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET ANSI_PADDING OFF
GO
/****** Object:  Table [dbo].[BasketProducts]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BasketProducts](
	[UserProfilesId] [int] NOT NULL,
	[DateCreate] [datetime] NOT NULL,
 CONSTRAINT [PK_BasketProducts] PRIMARY KEY CLUSTERED 
(
	[UserProfilesId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[BasketProductsRecords]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BasketProductsRecords](
	[BasketProductId] [int] NOT NULL,
	[ProductId] [int] NOT NULL,
	[DateCreate] [datetime] NOT NULL,
	[Quantity] [int] NOT NULL,
 CONSTRAINT [PK_BasketProductsRecords] PRIMARY KEY CLUSTERED 
(
	[BasketProductId] ASC,
	[ProductId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Categories]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Categories](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](max) NOT NULL,
	[ParentId] [int] NULL,
 CONSTRAINT [PK_dbo.Categories] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[FilterNames]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[FilterNames](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_FilterNames] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Filters]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Filters](
	[FilterNameId] [int] NOT NULL,
	[FilterValueId] [int] NOT NULL,
	[ProductId] [int] NOT NULL,
 CONSTRAINT [PK_Filters] PRIMARY KEY CLUSTERED 
(
	[FilterNameId] ASC,
	[FilterValueId] ASC,
	[ProductId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[FilterValues]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[FilterValues](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_FilterValues] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[ProductCategories]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProductCategories](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[ParentId] [int] NULL,
	[Image] [nvarchar](100) NULL,
 CONSTRAINT [PK_ProductCategories] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Products]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Products](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[CurrentQuantity] [int] NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[IsAvailable] [bit] NOT NULL,
	[Description] [nvarchar](200) NOT NULL,
	[DateCreate] [datetime] NOT NULL,
	[Image] [nvarchar](128) NULL,
	[Price] [money] NOT NULL,
	[ProductCategoryId] [int] NOT NULL,
 CONSTRAINT [PK_Products] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserOrderRecords]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserOrderRecords](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[DateCreate] [datetime] NOT NULL,
	[Quantity] [int] NOT NULL,
	[UserOrderId] [int] NOT NULL,
	[ProductId] [int] NOT NULL,
 CONSTRAINT [PK_UserOrderRecords] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserOrders]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserOrders](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[UserProfileId] [int]NOT NULL,
	[UserOrderStatusId] [int]NOT NULL,
	[DateCreate] [datetime] NULL,
 CONSTRAINT [PK_UserOrders] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserOrderStatuses]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserOrderStatuses](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_UserOrderStatuses] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[UserProfiles]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserProfiles](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Image] [nvarchar](128) NULL,
	[Telephone] [nvarchar](50) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_UserProfiles] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]

GO
/****** Object:  Table [dbo].[Users]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Users](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](max) NOT NULL,
	[Email] [nvarchar](max) NOT NULL,
	[Telephone] [nvarchar](max) NULL,
 CONSTRAINT [PK_dbo.Users] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Index [IX_ParentId]    Script Date: 09.02.2018 18:17:16 ******/
CREATE NONCLUSTERED INDEX [IX_ParentId] ON [dbo].[Categories]
(
	[ParentId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
GO
ALTER TABLE [dbo].[BasketProducts]  WITH CHECK ADD  CONSTRAINT [FK_BasketProducts_UserProfiles] FOREIGN KEY([UserProfilesId])
REFERENCES [dbo].[UserProfiles] ([Id])
GO
ALTER TABLE [dbo].[BasketProducts] CHECK CONSTRAINT [FK_BasketProducts_UserProfiles]
GO
ALTER TABLE [dbo].[BasketProductsRecords]  WITH CHECK ADD  CONSTRAINT [FK_BasketProductsRecords_BasketProducts] FOREIGN KEY([BasketProductId])
REFERENCES [dbo].[BasketProducts] ([UserProfilesId])
GO
ALTER TABLE [dbo].[BasketProductsRecords] CHECK CONSTRAINT [FK_BasketProductsRecords_BasketProducts]
GO
ALTER TABLE [dbo].[BasketProductsRecords]  WITH CHECK ADD  CONSTRAINT [FK_BasketProductsRecords_Products] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Products] ([Id])
GO
ALTER TABLE [dbo].[BasketProductsRecords] CHECK CONSTRAINT [FK_BasketProductsRecords_Products]
GO
ALTER TABLE [dbo].[Categories]  WITH CHECK ADD  CONSTRAINT [FK_dbo.Categories_dbo.Categories_ParentId] FOREIGN KEY([ParentId])
REFERENCES [dbo].[Categories] ([Id])
GO
ALTER TABLE [dbo].[Categories] CHECK CONSTRAINT [FK_dbo.Categories_dbo.Categories_ParentId]
GO
ALTER TABLE [dbo].[Filters]  WITH CHECK ADD  CONSTRAINT [FK_Filters_FilterNames] FOREIGN KEY([FilterNameId])
REFERENCES [dbo].[FilterNames] ([Id])
GO
ALTER TABLE [dbo].[Filters] CHECK CONSTRAINT [FK_Filters_FilterNames]
GO
ALTER TABLE [dbo].[Filters]  WITH CHECK ADD  CONSTRAINT [FK_Filters_FilterValues] FOREIGN KEY([FilterValueId])
REFERENCES [dbo].[FilterValues] ([Id])
GO
ALTER TABLE [dbo].[Filters] CHECK CONSTRAINT [FK_Filters_FilterValues]
GO
ALTER TABLE [dbo].[Filters]  WITH CHECK ADD  CONSTRAINT [FK_Filters_Products] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Products] ([Id])
GO
ALTER TABLE [dbo].[Filters] CHECK CONSTRAINT [FK_Filters_Products]
GO
ALTER TABLE [dbo].[ProductCategories]  WITH CHECK ADD  CONSTRAINT [FK_ProductCategories_ProductCategories] FOREIGN KEY([ParentId])
REFERENCES [dbo].[ProductCategories] ([Id])
GO
ALTER TABLE [dbo].[ProductCategories] CHECK CONSTRAINT [FK_ProductCategories_ProductCategories]
GO
ALTER TABLE [dbo].[Products]  WITH CHECK ADD  CONSTRAINT [FK_Products_ProductCategories] FOREIGN KEY([ProductCategoryId])
REFERENCES [dbo].[ProductCategories] ([Id])
GO
ALTER TABLE [dbo].[Products] CHECK CONSTRAINT [FK_Products_ProductCategories]
GO
ALTER TABLE [dbo].[UserOrderRecords]  WITH CHECK ADD  CONSTRAINT [FK_UserOrderRecords_Products] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Products] ([Id])
GO
ALTER TABLE [dbo].[UserOrderRecords] CHECK CONSTRAINT [FK_UserOrderRecords_Products]
GO
ALTER TABLE [dbo].[UserOrderRecords]  WITH CHECK ADD  CONSTRAINT [FK_UserOrderRecords_UserOrders] FOREIGN KEY([UserOrderId])
REFERENCES [dbo].[UserOrders] ([Id])
GO
ALTER TABLE [dbo].[UserOrderRecords] CHECK CONSTRAINT [FK_UserOrderRecords_UserOrders]
GO
ALTER TABLE [dbo].[UserOrders]  WITH CHECK ADD  CONSTRAINT [FK_UserOrders_UserOrderStatuses] FOREIGN KEY([UserOrderStatusId])
REFERENCES [dbo].[UserOrderStatuses] ([Id])
GO
ALTER TABLE [dbo].[UserOrders] CHECK CONSTRAINT [FK_UserOrders_UserOrderStatuses]
GO
/****** Object:  StoredProcedure [dbo].[InsertUserOrder]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create procedure [dbo].[InsertUserOrder]
@baskProd BasketProdRecordType readonly
as
begin
print 'g'
   --declare @basket as BasketProdType = (select from @baskProd where )
   --declare userId int=(select Id from )
end


GO
/****** Object:  StoredProcedure [dbo].[SelectCategoryFilters]    Script Date: 09.02.2018 18:17:16 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE procedure [dbo].[SelectCategoryFilters]
@prodCatId int
as
begin
  select  fn.Name as FilterName,fv.Name as FilterValue,count(*) as CountProducts
  from Filters fil
  join FilterNames fn on fn.Id = fil.FilterNameId
  join FilterValues fv on fv.Id = fil.FilterValueId
  join Products prod on prod.Id = fil.ProductId
  where prod.ProductCategoryId = @prodCatId
  group by fn.Name,fv.Name
end 

GO
USE [master]
GO
ALTER DATABASE [InternetShopMSashaFilters] SET  READ_WRITE 
GO
