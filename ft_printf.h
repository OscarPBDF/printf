/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:21:20 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/14 11:33:33 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

char	*ft_printf(char const *conver, ...);
int		ft_print_char(int c);
void	ft_print_string(char *s);
char	*ft_print_pointer(unsigned long long *ptr);
char	*ft_print_unbr(int n);
char	*ft_tohex(int dec, char conver);

#endif