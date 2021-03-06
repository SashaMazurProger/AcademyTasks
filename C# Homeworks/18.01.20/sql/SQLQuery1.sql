
/****** Object:  Database [Shop29ps]    Script Date: 20.01.2018 11:13:39 ******/
CREATE DATABASE [Shop29pstest]
Go
USE [Shop29pstest]
GO
/****** Object:  Table [dbo].[BasketProductRecords]    Script Date: 20.01.2018 11:13:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BasketProductRecords](
	[DateCreate] [datetime] NOT NULL,
	[Quantity] [int] NOT NULL,
	[BasketProductId] [int] NOT NULL,
	[ProductId] [int] NOT NULL,
 CONSTRAINT [PK_BasketProductRecords] PRIMARY KEY CLUSTERED 
(
	[BasketProductId] ASC,
	[ProductId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[BasketProducts]    Script Date: 20.01.2018 11:13:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[BasketProducts](
	[Id] [int] NOT NULL,
	[DateCreate] [datetime] NOT NULL,
 CONSTRAINT [PK_BasketProducts] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ProductCategories]    Script Date: 20.01.2018 11:13:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProductCategories](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](250) NOT NULL,
	[Image] [nvarchar](128) NOT NULL,
	[DateCreate] [datetime] NOT NULL,
	[Description] [nvarchar](max) NULL,
	[IsShow] [bit] NOT NULL,
 CONSTRAINT [PK_ProductCategories] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Products]    Script Date: 20.01.2018 11:13:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Products](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](500) NOT NULL,
	[QuantityCurrent] [int] NOT NULL,
	[IsAvailable] [bit] NOT NULL,
	[DateCreate] [datetime] NOT NULL,
	[Description] [nvarchar](max) NULL,
	[ProductCategoryId] [int] NOT NULL,
	[Image] [nvarchar](128) NOT NULL,
	[Price] [real] NOT NULL,
 CONSTRAINT [PK_Products] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]
GO
/****** Object:  Table [dbo].[UserProfiles]    Script Date: 20.01.2018 11:13:40 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserProfiles](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[Image] [nvarchar](128) NULL,
	[Telephone] [nvarchar](20) NOT NULL,
 CONSTRAINT [PK_UserProfiles] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
ALTER TABLE [dbo].[ProductCategories] ADD  CONSTRAINT [DF_ProductCategories_IsShow]  DEFAULT ((0)) FOR [IsShow]
GO
ALTER TABLE [dbo].[Products] ADD  CONSTRAINT [DF_Products_Image]  DEFAULT ('') FOR [Image]
GO
ALTER TABLE [dbo].[Products] ADD  CONSTRAINT [DF_Products_Price]  DEFAULT ((0)) FOR [Price]
GO
ALTER TABLE [dbo].[UserProfiles] ADD  CONSTRAINT [DF_UserProfiles_Telephone]  DEFAULT ('') FOR [Telephone]
GO
ALTER TABLE [dbo].[BasketProductRecords]  WITH CHECK ADD  CONSTRAINT [FK_BasketProductRecords_BasketProducts] FOREIGN KEY([BasketProductId])
REFERENCES [dbo].[BasketProducts] ([Id])
GO
ALTER TABLE [dbo].[BasketProductRecords] CHECK CONSTRAINT [FK_BasketProductRecords_BasketProducts]
GO
ALTER TABLE [dbo].[BasketProductRecords]  WITH CHECK ADD  CONSTRAINT [FK_BasketProductRecords_Products] FOREIGN KEY([ProductId])
REFERENCES [dbo].[Products] ([Id])
GO
ALTER TABLE [dbo].[BasketProductRecords] CHECK CONSTRAINT [FK_BasketProductRecords_Products]
GO
ALTER TABLE [dbo].[BasketProducts]  WITH CHECK ADD  CONSTRAINT [FK_BasketProducts_UserProfiles] FOREIGN KEY([Id])
REFERENCES [dbo].[UserProfiles] ([Id])
GO
ALTER TABLE [dbo].[BasketProducts] CHECK CONSTRAINT [FK_BasketProducts_UserProfiles]
GO
ALTER TABLE [dbo].[Products]  WITH CHECK ADD  CONSTRAINT [FK_Products_ProductCategories] FOREIGN KEY([ProductCategoryId])
REFERENCES [dbo].[ProductCategories] ([Id])
GO
ALTER TABLE [dbo].[Products] CHECK CONSTRAINT [FK_Products_ProductCategories]


