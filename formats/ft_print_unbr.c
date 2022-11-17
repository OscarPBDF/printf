/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:46:55 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/17 12:42:54 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_nbrsize(unsigned int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_printnbr(unsigned int n)
{
	n += '0';
	write(1, &n, 1);
}

int	ft_print_unbr(unsigned int nb)
{
	int	len;

	if (nb < 0)
		nb = -nb;
	len = ft_nbrsize(nb);
	if (nb == 2147483648)
	{
		write(1, "2147483648", 10);
		return (10);
	}
	if (nb < 10)
		ft_printnbr(nb);
	if (nb >= 10)
	{
		ft_print_unbr(nb / 10);
		ft_print_unbr(nb % 10);
	}
	return (len);
}
