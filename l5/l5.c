#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "Header.h"

void menu(int task_count)
{
	int i = 1;
	while (i <= task_count)
	{
		printf("%d. Задание %d\n", i, i);
		++i;
	}
	printf("%d. Выход \n", i);
}

void wait_for_click(void)
{
	printf("Нажмите любую кнопку для выхода в меню \n");
	getch();
}

void main(void)
{
	setlocale(LC_ALL, "Rus");
	_Bool close_flag = true;
	while (close_flag)
	{
		char str1[] = "UNISWAP HODL";
		char substr[] = "SWAP";
		char str3[] = " MAX ";

		unsigned int len1 = 0, destlen = 0, index = 0;
		_Bool err;
		char *point , dest[100];

		menu(6);
		switch (getch())
		{
			case '1':
				system("cls");
				len1 = strlen(str1);
				printf("Строка - %s. Длина строки - %d \n", str1, len1);
				wait_for_click();
				break;
			case '2':
				system("cls");
				point = find(str1, substr);
				point == 0 ? printf("Строка - %s. Подстрока - %s. \nПодстрока не входит в строку \n", str1, substr) : printf("Строка - %s. Подстрока - %s. \nАдрес вхождения - %p \n", str1, substr, point);
				wait_for_click();
				break;
			case '3':
				system("cls");
				printf("Строка - %s. Подстрока - %s \n", str1, substr);
				delete(str1, substr);
				printf("Строка после удаления подстроки - %s \n", str1);
				wait_for_click();
				break;
			case '4':
				system("cls");
				destlen = strlen(dest);
				strcpy(dest, destlen, str1);
				printf("Строка - %s. После копирования - %s \n", str1, dest);
				wait_for_click();
				break;
			case '5':
				system("cls");
				destlen = strlen(dest);
				strcat(dest, destlen, str1, str3);
				printf("Строка - %s. Вторая строка - %s. \nРезультат конкатенации - %s \n", str1, str3, dest);
				wait_for_click();
				break;
			case '6':
				system("cls");
				destlen = strlen(dest);
				printf("Введите индекс для вставки ");
				scanf_s("%d", &index);
				err = insert(str1, str3, index, dest, destlen);
				err ? printf("Строка - %s. Вторая строка - %s. \nРезультат вставки - %s \n", str1, str3, dest) : printf("Ошибка \n");
				wait_for_click();
				break;
			case '7':
				close_flag = false;
				break;


		}
	}
}
