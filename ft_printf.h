/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operez-d <operez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:21:20 by operez-d          #+#    #+#             */
/*   Updated: 2022/11/14 14:38:13 by operez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

char	*ft_printf(char const *conver, ...);
int		ft_print_char(int c);
int		ft_print_string(char *s);
int		*ft_print_pointer(unsigned long long *ptr);
int		*ft_print_unbr(int n);
int		*ft_tohex(int dec, char conver);

#endif