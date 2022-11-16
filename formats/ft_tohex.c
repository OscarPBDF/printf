/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:28:11 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/16 14:54:58 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_sizehex(unsigned int dec)
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

int	ft_tohex(unsigned int dec, char *base)
{
	int		size;

	size = ft_sizehex(dec);
	if (dec < 16)
		write(1, &base[dec], 1);
	if (dec >= 16)
	{
		ft_tohex((dec / 16), base);
		ft_tohex((dec % 16), base);
	}
	return (size);
}
/*
int	main()
{	
	printf("\n%d",ft_tohex(467433320, "0123456789ABCDEF"));
}*/