//Домашнее задание №10
//Задача 2. Удалить пробелы из текста
//В файле .txt необходимо удалить все лишние пробелы (в начале предложения
//и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
//записать в .txt.

#include <stdio.h>
#include <string.h>

void delete_probel(char *f_input, char *f_output)
{
char c;
int count=-1;
FILE *f_in = fopen(f_input, "r");
FILE *f_out = fopen(f_output, "w");

while ((c = fgetc(f_in)) != EOF)
{
	if ((c == ' ') &&(count==0))
		{
		fputc(c, f_out);
		count=1;
		}
		
	if (c != ' ')
    {
	fputc(c, f_out);
	count=0;
	}
}
fclose(f_in);
fclose(f_out);
}

int main()

{
char *f_in ="input.txt";
char *f_out ="output.txt";
delete_probel( f_in, f_out);
return 0;
}
