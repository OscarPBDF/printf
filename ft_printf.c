/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:27:13 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/15 16:33:39 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int	ft_formats(va_list args, char const conver)
{
	if(conver == 'c')
		return(ft_print_char(va_arg(args, int)));
		
	else if(conver == 's')
		return(ft_print_string(va_arg(args, char *)));
	
	else if(conver == 'p')
		return(ft_print_pointer(va_arg(args, unsigned long *)));
	
	else if(conver == 'd' || conver == 'i')
		return(ft_print_nbr(va_arg(args, int)));
	
	else if(conver == 'u')
		return(ft_print_unbr(va_arg(args, int)));	
	
	else if(conver == 'X')
		return(ft_tohex(va_arg(args, int), "0123456789ABCDEF"));
		
	else if(conver == 'x')
		return(ft_tohex(va_arg(args, int), "0123456789abcdef"));
		
	else if(conver == '%')
		write(1, "%%", 1);
	return (0);
}

int	ft_printf(char const *conver, ...)
{
	int i;
	int	len;
	va_list args;
	
	va_start(args, conver);
	i = 0;
	len = 0;
	while(conver[i])
	{
		if(conver[i++] == '%')
		{
			len += ft_formats(args, conver[i]);
		}
		else
		{
			len++;
			write(1, &conver[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}

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
	//printf("%c", c);
	printf("\n%d", ft_printf("%s", s));
	//total = suma(4, 2, 1, 1, 1);
	//printf("%d----", total);
}