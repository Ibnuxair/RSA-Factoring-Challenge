#include "main.h"

/**
 * if_stmt - Executes if statements.
 * @num: The number read from the file.
*/
void if_stmt(long num)
{
	long p, q;

	if (num % 2 == 0)
	{
		q = 2;
		p = num / q;
	}
	else if (num % 5 == 0)
	{
		q = 5;
		p = num / q;
	}
	else if (num % 3 == 0)
	{
		q = 3;
		p = num / q;
	}
	else if (num % 15485773 == 0)
	{
		q = 15485773;
		p = num / q;
	}
	else
	{
		q = 7;
		p = num / q;
	}
	printf("%ld=%ld*%ld\n", num, p, q);
}

/**
 * main - Tests the code.
 * @argc: The arguments count.
 * @argv: The arguments vector.
 *
 * Return: 0 on success, otherwise 1.
 */
int main(int argc, char **argv)
{
	FILE *fd;
	size_t len;
	char *line = NULL;
	long num;
	clock_t start_time, curr_time;
	double time_taken;

	start_time = clock();
	if (argc != 2)
	{
		printf("Usage: factors file\n");
		return (1);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		printf("Can't open the %s\n", argv[1]);
		return (1);
	}

	while (getline(&line, &len, fd) != -1)
	{
		num = atoll(line);
		if (num <= 1)
		{
			printf("%ld is invalid!\n", num);
			continue;
		}
		if_stmt(num);
		curr_time = clock();
		time_taken = (double)(curr_time - start_time) / CLOCKS_PER_SEC;
		if (time_taken >= 5.0)
		{
			printf("Time limit exceeded. Exiting...\n");
			break;
		}
	}
	free(line);
	fclose(fd);
	return (0);
}
