// Win32ProjectHome.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Win32ProjectHome.h"
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int count_lbutton = 0; // Количество кликов левой кнопкой мыши
int count_rbutton = 0; // Количество кликов правой кнопкой мыши
int cout_mbutton = 0; // Количество кликов средней кнопки мыши
char info[4096]; // Полная информация о кликах

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine,
	int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	//1.Определение класса окна
	wcl.cbSize = sizeof(wcl);//размер структуры WNDCLASSEX
							 //перерисовать все окно, если изменен размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;//стиль класса окна
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;//дескриптор данного приложения
						  //загрузка стандартной иконки
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	//загрузка стандартного курсора
	wcl.hCursor = LoadCursor(NULL, IDC_HAND);
	//заполнение окна белым цветом
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;//имя класса окна
	wcl.hIconSm = NULL;//отсутствие маленькой иконки
					   //Регистрация имя окна
	if (!RegisterClassEx(&wcl))
		return 0;//при неудачной регистрации выход
				 //Создание окна
				 //создается окно и переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,
		szClassWindow,//имя класса
		TEXT("Каркас приложение Windows"),//
		WS_OVERLAPPEDWINDOW,//
		200,
		200,
		500,
		500,
		NULL,
		NULL,
		hInst,
		NULL);
	//
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_LBUTTONDOWN:
		count_lbutton++; // Добовляем +1 
		MessageBox(0, TEXT("Нажата левая кнопка мыши"), TEXT("WM_LBUTTON"), MB_OK | MB_ICONINFORMATION);
		sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton); // пишем полную информацию в info
		SetWindowText(hWnd, (LPCWSTR)info); // изменяем заголовок окна на нашу информацию

		break;
	case WM_RBUTTONDOWN:
		count_rbutton++;
		MessageBox(0, TEXT("нажата правая кнопка мыши"), TEXT("WM_RBUTTON"), MB_OK | MB_ICONINFORMATION);
		sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
		SetWindowText(hWnd, (LPCWSTR)info);
		break;
	case WM_MBUTTONDOWN:
		cout_mbutton++;
		MessageBox(0, TEXT("Нажата средняя кнопка мыши"), TEXT("WM_MBUTTON"), MB_OK | MB_ICONINFORMATION);
		sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
		SetWindowText(hWnd, (LPCWSTR)info);
		break;
	case WM_DESTROY:
		sprintf(info, "lbutton: %d rbutton: %d mbutton: %d", count_lbutton, count_rbutton, cout_mbutton);
		MessageBox(0, (LPCWSTR)info, (LPCWSTR)"LOG", 0); // после завершение выведем msg о всех кликах
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}