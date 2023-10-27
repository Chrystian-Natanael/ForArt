#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_print_header(void)
{
	printf("************************************\n");
	printf("*                                  *\n");
	printf("*   Welcome to the guessing game   *\n");
	printf("*                                  *\n");
	printf("************************************\n");
}

void	ft_won(int p)
{
	printf("\nCongratulations you won!!\n");
	printf("You scored %d points", p);
	printf("Thanks for playing ^_^\n");
}

int	ft_lose(int points, int shot, int s_num)
{
	printf("Oh no, you made a mistake... Try again: \n");
	if (shot > s_num)
		printf("Your shot was greater than the secret number\n");
	else
		printf("Your guess was less than the secret number\n");
	if (shot > s_num)
		points -= ((shot - s_num) / 2);
	else
		points -= ((s_num - shot) / 2);
	return (points);
}

int	main(void)
{
	int	secret_number;
	int	shot;
	int	lifes;
	int	points;
	int segundos = time(0);

	srand(segundos);
	secret_number = rand();
	secret_number %= 100;
	lifes = 10;
	points = 1000;
	ft_print_header();
	while (lifes--)
	{
		printf("\nWhat's your guess?\n");
		scanf("%d", &shot);
		if (shot < 0)
		{
			printf("You can't guess negative numbers\n");
			lifes++;
			continue ;
		}
		if (shot == secret_number)
		{
			ft_won(points);
			return (0);
		}
		else
			points = ft_lose(points, shot, secret_number);
	}
	printf("Your lives are over, game over...\n");
	printf("Thanks for playing ^_^\n");
	return (0);
}
