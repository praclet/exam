#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_error(char *msg)
{
	if (msg && *msg)
	{
		int i=0;

		while(msg[i])
			i++;
		write(1,msg,i);
	}
}

void print_arg_error()
{
	print_error("Error: arguments\n");
}

void print_file_error()
{
	print_error("Error: Operation file corrupted\n");
}

struct {
	int width;
	int height;
	char * board;
}	g_board;

int process_first_line(FILE *operation_file)
{
	if (!operation_file)
		return 0;
	char background;
	if (fscanf(operation_file, "%i %i %c", &g_board.width, &g_board.height, &background) != 3)
		return 0;
	if (g_board.width <= 0 || g_board.width > 300 || g_board.height <= 0 || g_board.height > 300)
		return 0;
	g_board.board = malloc ((g_board.width * g_board.height) * sizeof(char));
	if (!g_board.board)
		return 0;
	memset(g_board.board, background, g_board.width * g_board.height);
	return 1;
}

int process_main_line(FILE *operation_file)
{
	(void)operation_file;
	if (fscanf(operation_file, "%i %i %c", &g_board.width, &g_board.height, &background) != 3)
		return 0;
	return 0;
}

void print_board(void)
{
	int i=0;

	while (i<g_board.height)
	{
		write(1,g_board.board+(i*g_board.width),g_board.width);
		write(1,"\n",1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_arg_error();
		return 1;
	}
	FILE *operation_file=fopen(argv[1],"r");
	if (!operation_file)
	{
		print_file_error();
		return 1;
	}
	if (!process_first_line(operation_file))
	{
		print_file_error();
		return 1;
	}
	while (process_main_line(operation_file))
		;
	print_board();
	return 0;
}
