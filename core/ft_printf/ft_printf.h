/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:38:36 by joho              #+#    #+#             */
/*   Updated: 2025/09/01 23:39:58 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	printchar(int n);
int	printstr(char *str);
int	printp(void *ptr);
int	printnum(long long n, int base, int uppercase, int sign);
int	check_specifier(char spec, va_list ap);
int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

#endif