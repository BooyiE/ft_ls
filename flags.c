#include "ft_ls.h"

typedef struct my_flags
{
	char a;
	char l;
	char t;
	char R;
	char r;
}		flags;

int main(int argc, char **argv)
{
	int i;
	int j;
	flags	flag;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][j] == '-')
		{
			j++;
			while(argv[i][j])
			{
				if (argv[i][j] == 'a')
					flag.a = 1;
				else if (argv[i][j] == 'l')
					flag.l = 1;
				else if (argv[i][j] == 't')
					flag.t = 1;
				else if (argv[i][j] == 'R')
					flag.R = 1;
				else if (argv[i][j] == 'r')
					flag.r = 1;
				else
					ft_putendl("wrong flag");
				j++;
			}
		}
		i++;
	}

	if (flag.a)
		ft_putendl("a");
	if (flag.l)
		ft_putendl("l");
	if (flag.r)
		ft_putendl("r");
	if (flag.R)
		ft_putendl("R");
	if (flag.t)
		ft_putendl("t");
	return (0);
}
