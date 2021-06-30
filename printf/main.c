int ft_printf(const char *fmt,...);

#include <limits.h>

int main(void) {
	/*
	int tmp;

	ft_printf("Test |");
	tmp=ft_printf("%10.2s", "toto");
	ft_printf("| %d\n     |",tmp);
	ft_printf("        to");
	ft_printf("|\nTest |");
	tmp=ft_printf("Magic %s is %5d", "number", 42);
	ft_printf("| %d\n     |",tmp);
	ft_printf("Magic number is    42");
	ft_printf("|\nTest |");
	tmp=ft_printf("Hexadecimal for %d is %x", 42, 42);
	ft_printf("| %d\n     |",tmp);
	ft_printf("Hexadecimal for 42 is 2a");
	ft_printf("|\n");

	ft_printf("\n\n\n");
	tmp=ft_printf("%8d",123456);
	ft_printf(" %d\n",tmp);
	tmp=ft_printf("%8x",123456);
	ft_printf(" %d\n",tmp);
*/

	ft_printf("%d\n",UINT_MAX);
	ft_printf("%d\n",INT_MAX);
	ft_printf("%d\n",INT_MIN);

}
