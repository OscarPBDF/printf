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
#include "../libft/libft.h"

/*static int	ft_charhex(int hex)
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
}*/

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
//Termminar de reestructurar la funcion 
int	ft_tohex(int dec, char *base)
{
	int		size;
	int		i;
	int		alphanum;

	size = ft_sizehex(dec);
	while(dec > 16)
	{
		alphanum = dec%16;
		write(1, &base[alphanum], 1);
		dec /= 16;
	}
	alphanum = dec%16;
	write(1, &base[alphanum], 1); //Lo muestra al reves
	i = 0;
	return (size);
}

int	main()
{	
	ft_tohex(123, "0123456789ABCDEF");

}