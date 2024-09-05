//Домашнее задание №10
//Задача 3. Изменить расширение
//В файле .txt записан полный адрес файла (возможно, без расширения).
//Необходимо изменить его расширение на ".html" и записать результат в файл .txt.
//Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
//Данные на выходе: Исходная строка с измененным расширением.
//Пример №1
//Данные на входе: /DOC.TXT/qqq
//Данные на выходе: /DOC.TXT/qqq.html
//Пример №2
//Данные на входе: /DOC.TXT/qqq.com
//Данные на выходе: /DOC.TXT/qqq.html

#include <stdio.h>
#include <string.h>
#define SIZE 1000

void input(char *strIn)
{
FILE *in;
 in = fopen("input.txt", "r");
 while(fscanf(in, "%[^\n]", strIn) == 1);
 fclose(in);
}

void extension(char *strExt, char *buffer, char *_extenstr)
{
  for(int i = strlen(strExt) - 1; i >= 0;i--)
  {
	if(strExt[i] == '/')
	 {
	 strcpy(buffer, strExt);
	 strcat(buffer,_extenstr);
	 break;
	 }
	else if(strExt[i] == '.')
		{
		char newbuffer[SIZE-1];
			for(int j = 0; j < i; j++)
			{
			newbuffer[j] = strExt[j];
			}
		strcpy(buffer, newbuffer);
		strcat(buffer, _extenstr);
		break;
		}
  }
}
void output(char *strOut)
{
 FILE *out;
 out = fopen("output.txt", "w");
 fprintf(out, "%s", strOut);
 fclose(out);
}

int main(int argc, char **argv)
{
 char str[SIZE], strFinal[SIZE];
 input(str);
 char *extenstr=".html";
 extension(str, strFinal, extenstr);
 output(strFinal);
 return 0;
}
