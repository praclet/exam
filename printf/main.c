int ft_printf(const char *fmt,...);

int main(void) {
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


}
