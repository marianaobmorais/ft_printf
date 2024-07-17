/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:19:25 by mariaoli          #+#    #+#             */
/*   Updated: 2024/05/02 19:42:52 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse_fmt(va_list ap, const char fmt)
{
	int	count;

	count = 0;
	if (fmt == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (fmt == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (fmt == 'd' || fmt == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (fmt == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	if (fmt == 'x' || fmt == 'X')
		count += ft_putxnbr(va_arg(ap, unsigned int), fmt);
	if (fmt == 'p')
		count += ft_putpnbr(va_arg(ap, unsigned long));
	if (fmt == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	const char	*fmt;
	int			res;

	va_start(ap, format);
	fmt = format;
	res = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%' && *(fmt + 1) != '\0')
		{
			fmt++;
			res += ft_parse_fmt(ap, *fmt);
		}
		else
			res += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (res);
}

#include <stdio.h>
#include <limits.h>

int main(void)
{
 	int output_OG;
	int output_FT;
 	ft_printf("INT_MIN--------------------\n");
 	output_OG = printf("OG -> %d\n", INT_MIN);
 	output_FT = ft_printf("FT -> %d\n", INT_MIN);
 	printf("OUTPUT OG = %d\n", output_OG);
 	ft_printf("OUTPUT FT = %d\n", output_FT);
 	return (0);
}
