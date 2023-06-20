/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acunha <acunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:57:01 by acunha            #+#    #+#             */
/*   Updated: 2022/12/09 15:44:52 by acunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_handleformat(va_list args, const char format);
int		ft_printpercent(void);
int		ft_printptr(uintptr_t ptr);
int		ft_prthex(unsigned int num, const char format);
int		ft_prtnbr(int i);
int		ft_prtunsg(unsigned int nbr);
void	ft_putchar(char c);
int		ft_putstr(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);

#endif
