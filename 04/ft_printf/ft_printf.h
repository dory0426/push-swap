/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myazawa <myazawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 20:24:39 by myazawa           #+#    #+#             */
/*   Updated: 2026/08/05 18:55:52 by myazawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putnbr_base(unsigned long n, unsigned long base, int fd);
int		ft_putnbr_base_upper(unsigned int n, unsigned int base, int fd);
int		ft_putstr(char *s, int fd);
int		ft_printf(int fd, const char *format, ...);
int		ft_putchar(char c, int fd);
char	*ft_strcpy(char *dst, const char *src);
int		ft_putnbr(int n, int fd);
int		ft_putnbr_unsigned(unsigned int n, int fd);
int		ft_putpointer(void *ptr, int fd);
#endif
