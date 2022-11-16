/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:46:55 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/16 11:00:03 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_nbrsize(int n)
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

static void	ft_printnbr(int n)
{
	n += '0';
	write(1, &n, 1);
}

int	ft_print_nbr(int nb)
{
	int	len;

	len = ft_nbrsize(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
		ft_printnbr(nb);
	if (nb >= 10)
	{
		ft_print_nbr(nb / 10);
		ft_print_nbr(nb % 10);
	}
	return (len);
}
