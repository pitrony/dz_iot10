//Домашнее задание №10
//Задача 1. Пары соседних символов
//В файле .txt записаны символы. Необходимо разработать функцию, которая
//меняет местами пары соседних символов не обращая внимание на символы
//пробел. Если количество символов нечетно (пробелы не считаем), то
//последний символ не меняем. Результат записать в файл .txt.

#include <stdio.h>
#include <string.h>
const int line_size = 1000;
void change_symbols(int size, char *line)
{
 int i = 0, j;
 char temp;
 while (i < size)
	{
		while (line[i] == ' ')
		i++;
	j = i + 1;
			while (line[j] == ' ')
			j++;
	if (j >= size) 
	break;
 
	temp = line[i];
	line[i] = line[j];
	line[j] = temp;
	i = j + 1;
	}
}

int main(void)
{
char * input_fn = "input.txt";
char * output_fn = "output.txt";
char line[line_size];
FILE *fp;
 fp = fopen(input_fn, "r");
 fscanf(fp, "%[^\n]", line);
 fclose(fp);
 change_symbols(strlen(line),line);

 fp = fopen(output_fn, "w");
 fprintf(fp, "%s", line);
 fclose(fp);

 return 0;
}
