/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:28:11 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/11 11:28:57 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_charhex(int hex)
{
	if(hex == 10)
		return('A');
	else if(hex == 11)
		return('B');
	else if(hex == 12)
		return('C');
	else if(hex == 13)
		return('D');
	else if(hex == 14)
		return('E');
	else if(hex == 15)
		return('F');
	return (hex + '0');
}

static int	ft_sizehex(int dec)
{
	int	size;

	while(dec/16 > 0)
	{
		size++;
		dec /= 16;
	}
	if(dec%16 != 0)
		size++;
	return(size);
}

char	*ft_tohex(int dec, char format)
{
	char	*hex;
	int		size;
	int		i;

	size = ft_sizehex(dec);
	hex = malloc((size + 1) * sizeof(char)); /////
	hex[size--] = '\0';						///////////
	while(dec/16 > 0)
	{
		hex[size] = ft_charhex(dec%16);
		size--;
		dec /= 16;
	}
	hex[size--] =  ft_charhex(dec%16);
	i = 0;
	if(format == 'x')
		while(hex[i])
		{
			ft_tolower(hex[i])
			i++;
		}
	return (hex);
}
