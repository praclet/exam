#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int g_w;
int g_p;
char g_s;
va_list ap;


int strlen(const char *s)
{
	int res=0;

	while (*s)
	{
		s++;
		res++;
	}
	return res;
}

int nblen(int nb, int len_base)
{
	int res=0;

	do {
		res++;
	}
	while (nb/=len_base);
	return res;
}

void parse(const char **s)
{
	char *fmt=*s;

	g_s=0;
	g_w=g_p=-1;
	if (*fmt && *fmt >= '0' && *fmt <= '9')
		g_w=0;
	while (*fmt && *fmt >= '0' && *fmt <= '9')
	{
		g_w=10*g_w + *fmt-'0';
		fmt++;
	}
	if (*fmt && *fmt='.')
	{
		g_p=0;
		while (*fmt && *fmt >= '0' && *fmt <= '9')
		{
			g_p=10*g_p + *fmt-'0';
			fmt++;
		}
	}
	if (*fmt=='s' || *fmt=='d' || *fmt=='x')
	{
		g_s=*fmt;
		fmt++;
	}
	*s=fmt;
}


int print_nb(va_list ap, const char* base)
{
	int nb=va_arg(ap,int);
	int len_base=strlen(base);
	int len=nblen(nb,len_base);
	int res=0;

	;

	return res;
}



int ft_printf(const char fmt*,...)
{
	int res=0;

	va_start(ap,fmt);
	
	while (*fmt)
	{
		if (*fmt=='%')
		{
			fmt++;
			parse(&fmt);
			switch(g_s)
			{
				case 'x': res+=print_nb(ap,"0123456789abcdef");break;
				case 'd': res+=print_nb(ap,"0123456789");break;
				case 's': res+=print_s(ap);break;
			}

		}
		else
		{
			write(1,fmt,1);
			fmt++;
			res++;
		}
	}

	va_end(ap);
	return res;
}
