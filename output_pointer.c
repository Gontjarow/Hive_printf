/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 07:48:21 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/31 18:33:52 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_left(const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	int		z;
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
	// printf("{w = %d}\n", w);

	if (flag->precision > (int)len)
		z = flag->precision - len;
	else
		z = 0;
	// printf("{init z = %d}\n", z);

	if (z > 0)
		w -= z;
	// printf("{w = %d}\n", w);

	flag->written += ft_putstrn("0x", prefix);

	// printf("{z = %d}\n", z);
	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += putstr_case(str, -1);

	while (w - prefix > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	int		z;
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

	if (flag->precision > (int)len)
		z = flag->precision - len;
	else
		z = 0;
	// printf("{init z = %d}\n", z);

	if (z > 0)
		w -= z;

	while (w - prefix > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}

	flag->written += ft_putstrn("0x", prefix);

	// printf("{z = %d}\n", z);
	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += putstr_case(str, -1);
}

// Undefined flags: #, 0, ' ', +
// Applicable flags: -
// Precision: Minimum amount of digits.
// Leading zeroes (after prefix) if necessary.
// Note: School Mac prints 0x0 for null instead of (nil) or (null).
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
		justify_left(str, flag);
	else
		justify_right(str, flag);
	free(str);
}
