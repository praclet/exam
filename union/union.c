#include <unistd.h>
int main (int argc, char *argv[])
{
	char tab[256];
	int i;
	char *s;
	if(argc==3)
	{
		for (i=0;i<256;i++)
			tab[i]=0;
		s=argv[1];
		while(*s)
		{
			if(!tab[(int)*s])
			{
				tab[(int)*s]=1;
				write (1,s,1);
			}
			s++;
		}
		s=argv[2];
		while(*s)
		{
			if(!tab[(int)*s])
			{
				tab[(int)*s]=1;
				write (1,s,1);
			}
			s++;
		}
	}
	write(1,"\n",1);
	return (0);
}
