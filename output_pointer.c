/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 07:48:21 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/27 13:22:31 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_left(void *arg, const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	size_t	len;
	int		prefix;

	// prefix = 2 * (arg != NULL);
	prefix = 2;
	len = ft_strlen(str) + prefix;
	// printf("len = %ld\n", len);

	if (flag->precision == -1)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > len)
		flag->p = len;
	// printf("flag->p = %ld\n", flag->p);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("w = %ld\n", w);

	flag->written += ft_putstrn("0x", prefix);
	flag->written += ft_putstr(str);

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(void *arg, const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	size_t	len;
	int		prefix;

	// prefix = 2 * (arg != NULL);
	prefix = 2;
	len = ft_strlen(str);
	// printf("len = %ld\n", len);

	if (flag->precision == -1)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > len)
		flag->p = len;
	// printf("flag->p = %ld\n", flag->p);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("w = %ld\n", w);

	while (w - prefix > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}

	flag->written += ft_putstrn("0x", prefix);
	flag->written += ft_putstr(str);
}

// Undefined flags: #, 0, ' ', +
// Applicable flags: -
// Precision: Undefined
// note: School Mac prints 0x0 for null.
void	output_pointer(void *arg, t_data *flag)
{
	// printf("\n");
	// printf("{output_pointer: '%p', w%d p%d}\n", arg, flag->width, flag->precision);
	char	*str;

	if (arg)
		str = ft_itoa_base((long long)arg, 16);
	else
		// str = ft_strdup("(nil)"); // todo: change to "(null)"
		str = ft_strdup("0");

	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);
	free(str);
}
