/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:19:18 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/15 15:33:50 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_sizehex(unsigned int dec)
{
	int	size;

	size = 0;
	while(dec/16 > 0)
	{
		size++;
		dec /= 16;
	}
	if(dec%16 != 0)
		size++;
	return(size);
}

static int	ft_tolonghex(unsigned long dec, char *base)
{
	int		size;

	size = ft_sizehex(dec);
	if(dec < 16)
		write(1, &base[dec], 1); 
	if(dec > 16)
	{
		ft_tolonghex(dec/16, base);
		ft_tolonghex(dec%16, base);
	}
	return (size);
}

int	ft_print_pointer(unsigned long *ptr)
{
	int	size;
	
	size = 0;
	size += write(1, "0x", 2);
	if(!ptr)
		write(1, "0", 1);
	else
	{
		size += ft_tolonghex((unsigned long)ptr, "0123456789abcdef");
	}
	return (size);	
}

/*int main()
{
	unsigned long	c;

	c = 1;
	printf("%p\n", &c);
	ft_print_pointer(&c);
}*/