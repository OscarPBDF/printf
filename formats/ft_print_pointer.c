/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:19:18 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/17 14:20:17 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_sizehex(unsigned long dec)
{
	int	size;

	size = 0;
	while ((dec / 16) > 0)
	{
		size++;
		dec /= 16;
	}
	if ((dec % 16) != 0)
		size++;
	return (size);
}

static int	ft_tolonghex(unsigned long dec, char *base)
{
	int	size;

	if (dec < 16)
		write(1, &base[dec], 1);
	else
	{
		ft_tolonghex((dec / 16), base);
		ft_tolonghex((dec % 16), base);
	}
	size = ft_sizehex(dec);
	return (size);
}

int	ft_print_pointer(unsigned long *ptr)
{
	int	size;

	size = write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		size++;
	}
	else
	{
		size += ft_tolonghex((unsigned long)ptr, "0123456789abcdef");
	}
	return (size);
}
