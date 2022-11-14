/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:46:55 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/14 10:38:18 by operez-d         ###   ########.fr       */
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

static int	ft_intmincase(int n, void *str)
{
	char	*nstr;
	int		i;
	char	*auxstr;

	nstr = str;
	if (n == -2147483648)
	{
		i = -1;
		auxstr = "-2147483648";
		while (++i < 12)
			nstr[i] = auxstr[i];
		return (1);
	}
	else if (n == 0)
	{
		nstr[0] = '0';
		nstr[1] = 0;
		return (1);
	}
	return (0);
}

char	*ft_print_unbr(int n)
{
	char	*str;
	int		size;

	if (n < 0)
		n = -n;
	size = ft_nbrsize(n);
	str = malloc(size + 1 * sizeof(char));
	if (!(str))
		return (0);
	if (ft_intmincase(n, str) == 1)
		return (str);
	str[size--] = '\0';
	while (n > 0)
	{
		str[size--] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
