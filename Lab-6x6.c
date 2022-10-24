#include "stdio.h"
#include <locale.h>
/*char symbol = 'a';
	while (symbol < 'z'+1)
	{
		printf("Symbol %c = %d \n", symbol, symbol);
		symbol += 1;
	}
	symbol = 'A';
	while (symbol < 'Z' + 1)
	{
		printf("Symbol %c = %d \n", symbol, symbol);
		symbol += 1;
	}
	symbol = 'а';
	while (symbol < 'я' + 1)
	{
		printf("Symbol %c = %d \n", symbol, symbol);
		symbol += 1;
	}
	symbol = 'А';
	while (symbol < 'Я' + 1)
	{
		printf("Symbol %c = %d \n", symbol, symbol);
		symbol += 1;
	}*/
	/*for (int y = 0; y < 6; y++)
		{
			for (int x = 0; x < 6; x++)
			{
				printf("%c", newArea[y][x]);
			}
			if (y < 5)
			{
				printf("\n");
			}
		}*/
char Area[6][6] = {
		'#','#', '#', '*', '*', '#',
		'*','#', '#', '#', '#', '#',
		'#','#', '*', '*', '#', '#',
		'#','*', '#', '#', '#', '#',
		'#','*', '#', '*', '#', '#',
		'#','#', '#', '*', '#', '#',
};
int main(void) {
	setlocale(LC_ALL, "Rus");
	
	enum States {
		f = 'f',
		b = 'b',
		r = 'r',
		l = 'l',
	};

	char newArea[6][6];
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			newArea[y][x] = Area[y][x];
		}
	}

	int ycord = 5;
	int xcord = 0;
	newArea[ycord][xcord] = '@';
	for (int y = 0; y<6;y++)
	{
		for (int x = 0; x<6; x++) 
		{
			printf("%c",newArea[y][x]);
		}
		if (y < 6)
		{
			printf("\n");
		}
		
	}
	char command;
	while (newArea[0][5] != '@')
	{
		command = getch("%c");
		switch (command)
		{
		case f:
			
			ycord -= 1;
			if (ycord > 5 || ycord < 0 || xcord>5 || xcord < 0)
			{
				ycord += 1;
				break;
			}
			if (Area[ycord][xcord] == '*')
			{
				ycord += 1;
				break;
			}
			system("cls");
			printf("f \n");
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{ 
					if(x == xcord && y == ycord)
						newArea[ycord][xcord] = '@';
					else
						newArea[y][x] = Area[y][x];
				}
			}
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					printf("%c", newArea[y][x]);
				}
				if (y < 5)
				{
					printf("\n");
				}

			}
			printf("\n");
			break;
		case b:
			ycord += 1;
			if (ycord>5 || ycord<0 || xcord>5 || xcord<0)
			{
				ycord -= 1;
				break;
			}
			
			if (Area[ycord][xcord] == '*')
			{
				ycord -= 1;
				break;
			}
			system("cls");
			printf("b \n");
			
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					if (x == xcord && y == ycord)
						newArea[ycord][xcord] = '@';
					else
					newArea[y][x] = Area[y][x];
				}
			}
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					printf("%c", newArea[y][x]);
				}
				if (y < 5)
				{
					printf("\n");
				}

			}
			printf("\n");
			break;
		case l:
			xcord -= 1;
			if (ycord > 5 || ycord < 0 || xcord>5 || xcord < 0)
			{
				xcord += 1;
				break;
			}
			if (Area[ycord][xcord] == '*')
			{
				xcord += 1;
				break;
			}
			system("cls");
			printf("l \n");
			
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					if (x == xcord && y == ycord)
						newArea[ycord][xcord] = '@';
					else
					newArea[y][x] = Area[y][x];
				}
			}
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					printf("%c", newArea[y][x]);
				}
				if (y < 5)
				{
					printf("\n");
				}

			}
			printf("\n");
			break;
		case r:
			xcord += 1;
			if (ycord > 5 || ycord < 0 || xcord>5 || xcord < 0)
			{
				xcord -= 1;
				break;
			}
			if (Area[ycord][xcord] == '*')
			{
				xcord -= 1;
				break;
			}
			system("cls");
			printf("r \n");
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					if (x == xcord && y == ycord)
						newArea[ycord][xcord] = '@';
					else
					newArea[y][x] = Area[y][x];
				}
			}
			for (int y = 0; y < 6; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					printf("%c", newArea[y][x]);
				}
				if (y < 5)
				{
					printf("\n");
				}

			}
			printf("\n");
			break;
		};
	}
	printf("Поздравляю, Вы победили!");
}
