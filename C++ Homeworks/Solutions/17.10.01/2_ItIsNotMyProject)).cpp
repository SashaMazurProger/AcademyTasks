#include<windows.h>
char *szTitle = "Отгадываем число";
char *szNumQuery = "Вы задумали число от 1 до 100?";
char *szEqualQuery = "Вы задумали %d, правильно?";
char *szGreatQuery = "Задуманное число больше?";
char *szFound = "Было отгадано число %d за %d попыток";
char *szError = "Вы неправильно играете...";
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR IpszCmdLine, int nCmdShow)
{
   int      Number;      //очередное число программы
   int      Min, Max;   //пределы, где ищется число
   int      N;         //количество попыток
   char   sBuf[64];   //буфер для формирования сообщения
   do   //бесконечный цикл
   {
      //ожидаем, когда пользователь загадает число
      //если "нет", то выходим
      if (IDYES == MessageBox(0, szNumQuery, szTitle, MB_YESNO | MB_ICONQUESTION))
      {
         //ищем число, пока или пользователь не подтвердит равенство, или дойдем до равенства min==max, что есть ошибка
         for (N=1,Min=1,Max=100; Max!=Min; N++)
         {
            //для правого края, когда Max=Min+1, Number останется тем же!
            //Чтобы изменить Number, увеличим явно на 1
            if (Number == (Max+Min)>>1)
               Number++;
            else //для всех остальных берем середину
               Number = (Max+Min)>>1;
            //формируем строку с числом
            wsprintf(sBuf, szEqualQuery, Number);
            
            //спрашиваем на равенство
            if (IDYES == MessageBox(0, sBuf, szTitle, MB_YESNO | MB_ICONQUESTION))
            {
               //выводим результат, когда равно
               wsprintf(sBuf, szFound, Number, N);
               MessageBox(0, sBuf, szTitle, MB_OK | MB_ICONEXCLAMATION);
               break;  //на бесконечный цикл, т.е. на запрос следующего числа 
                     //(точнее, за цикл for, причем проверка на равенство Min == Max даст обязательно "ложь")
            }
            else //не равно
            {   //спрашиваем, больше?
               if (IDYES == MessageBox(0, szGreatQuery, szTitle, MB_YESNO | MB_ICONQUESTION))
               {   //левая граница смещается на предложенное число
                  Min = Number;
               }
               else
               {   //правая граница смещается на предложенное число
                  Max = Number;
               }
            }
         }
         //проверим на ошибочную игру...
         if (Min == Max)
         {
            MessageBox(0, szError, szTitle, MB_OK | MB_ICONEXCLAMATION);
         }
      }
      //ответили "нет" - выходим из программы
      else
         break;
   }while (TRUE);
   return (0);
}