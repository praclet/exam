#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int g_w;
int g_p;
char g_s;
va_list ap;


int ft_strlen(const char *s)
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
	return res+!!(nb<0);
}

void parse(const char **s)
{
	char *fmt=(char *)*s;

	g_s=0;
	g_w=g_p=-1;
	if (*fmt >= '0' && *fmt <= '9')
		g_w=0;
	while (*fmt && *fmt >= '0' && *fmt <= '9')
	{
		g_w=10*g_w + *fmt-'0';
		fmt++;
	}
	if (*fmt=='.')
	{
		g_p=0;
		fmt++;
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

int putstr(char *str)
{
	int len=ft_strlen(str);
	int nb_spaces;
	int i;

	if (g_p>=0 && len>g_p)
		len=g_p;
	nb_spaces=g_w-len;
	if (nb_spaces<0)
		nb_spaces=0;
	for (i=0;i<nb_spaces;i++)
		write(1," ",1);
	write(1,str,len);
	return len + nb_spaces;
}


int print_s(va_list ap)
{
	return putstr(va_arg(ap,char *));
}

int print_nb(va_list ap, const char* base)
{
	int nb=va_arg(ap,int);
	int len_base=ft_strlen(base);
	int len=nblen(nb,len_base);
	int res=0;
	int pos;
	int i;
	char *str=malloc(sizeof(char)*(len+1));

	if (!str)
		return (-1);
	i=len;
	str[i--]=0;
	if(nb<0)
	{
		pos=1;
		str[0]='-';
	}
	else
		pos=0;
	while(i>=pos)
	{
		str[i--]=base[nb%len_base];
		nb/=len_base;
	}
	res=putstr(str);
	free(str);
	return res;
}



int ft_printf(const char *fmt,...)
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
