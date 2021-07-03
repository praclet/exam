#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct {
	int width;
	int height;
	char * board;
}	g_board;

struct {
	float x0;
	float y0;
	float x1;
	float y1;
} g_rectangle;

void free_board()
{
	free(g_board.board);
	g_board.board = NULL;
}

void print_error(char *msg)
{
	if (msg && *msg)
	{
		int i=0;

		while(msg[i])
			i++;
		write(1,msg,i);
		write(1,"\n",1);
	}
	free_board();
}

void print_arg_error()
{
	print_error("Error: arguments");
}

void print_file_error()
{
	print_error("Error: Operation file corrupted");
}

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

int is_on_border(float x, float y)
{
	return 
		(((g_rectangle.x0 <= x && x < g_rectangle.x0 + 1) || (g_rectangle.x1 <= x && x < g_rectangle.x1 + 1))
			&& g_rectangle.y0 <= y && y <= g_rectangle.y1)
		||
		(((g_rectangle.y0 <= y && y < g_rectangle.y0 + 1) || (g_rectangle.y1 <= y && y < g_rectangle.y1 + 1))
			&& g_rectangle.x0 <= x && x <= g_rectangle.x1);
}

int is_in_rectangle(float x, float y)
{
	return g_rectangle.x0 <= x && x <= g_rectangle.x1
			&& g_rectangle.y0 <= y && y <= g_rectangle.y1 ;
}

int process_main_line(FILE *operation_file)
{
	int nb_variables;
	char rectangle_type;
	float width;
	float height;
	char brush;
	float x;
	float y;
	char nl_char;

	if (fread(&nl_char, sizeof(char), 1, operation_file)!=1)
	{
		if (nl_char != '\n')
			print_file_error();
		return 0;
	}
	nb_variables=fscanf(operation_file, "%c %f %f %f %f %c",
			&rectangle_type, &g_rectangle.x0, &g_rectangle.y0,
			&width, &height, &brush);
	if (nb_variables == EOF)
		return 0;
	if (nb_variables != 6 || (rectangle_type != 'r' && rectangle_type != 'R') || width <= 0 || height <= 0)
	{
		print_file_error();
		return 0;
	}
	g_rectangle.x1=g_rectangle.x0 + width;
	g_rectangle.y1=g_rectangle.y0 + height;
	for (x=0;x<g_board.width;x++)
		for (y=0;y<g_board.height;y++)
			if ((rectangle_type == 'R' && is_in_rectangle(x,y))
				|| is_on_border(x,y))
				g_board.board[(int)(x+y*g_board.width)]=brush;

	return 1;
}

void print_board(void)
{
	if (!g_board.board)
		return;

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
	g_board.board = NULL;
	if (argc != 2)
	{
		print_arg_error();
		return 1;
	}
	FILE *operation_file=fopen(argv[1],"r");
	if (!operation_file)
	{
		print_file_error();
		fclose(operation_file);
		return 1;
	}
	if (!process_first_line(operation_file))
	{
		print_file_error();
		fclose(operation_file);
		return 1;
	}
	while (process_main_line(operation_file))
		;
	fclose(operation_file);
	print_board();
	free_board();
	return 0;
}
