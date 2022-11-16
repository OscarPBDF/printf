#include "ft_printf.h"
#include <stdio.h>

int	main()
{	
	char c;
	char *s;
	//void *p;
	int	d;
	int	u;
	//int	x;
	//int	X;
	
	c = 'a';
	s = "abc";
	d = -42;
	u = -42;

	//int total;
	printf("%d\n", printf("%p ", -2147483648));
	printf("%d\n", ft_printf("%p ", -2147483648));
	//total = suma(4, 2, 1, 1, 1);
	//printf("%d----", total);
}