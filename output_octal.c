/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:51:20 by ngontjar          #+#    #+#             */
/*   Updated: 2020/08/03 20:42:35 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_left(long long arg, const char *str, t_data *flag)
{
	// printf("\n");
	// printf("{bit=%d}\n", flag->bit);
	int		w;
	int		z;
	size_t	len;
	int		prefix;

	prefix = !!(flag->bit & FLAG_PREFIX);
	len = (flag->precision == 0 && arg == 0) ? 0 : ft_strlen(str);
	// len += prefix;

	// printf("len = %ld\n", len);

	if (flag->precision == -1 || flag->precision < len)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > len)
		flag->p = len;

	// flag->p is always the length of the actual content before any padding.
	// printf("flag->p = %ld, len = %d\n", flag->p, len);

	if (flag->width > flag->p)
		w = flag->width - flag->p - prefix;
	else
		w = 0;
	// printf("{init w = %d}\n", w);

	if (flag->precision > (int)len)
		z = flag->precision - len - prefix;
	else
		z = 0;
	// printf("{init z = %d}\n", z);


	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);
	if (z > 0)
		w -= z;
	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);

	// printf("{leading zero %-3d|p%-3lu|w%-3d|len%-3d|z%-3d}\n", !!(flag->bit & FLAG_LEADING_ZERO), flag->p, w, len, z);
	// if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0) && (w >= len + z))

	if (prefix)
		flag->written += ft_putstr("0");
	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += ft_putstrn(str, flag->p);

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(long long arg, const char *str, t_data *flag)
{
	// printf("\n");
	// printf("{bit=%d}\n", flag->bit);
	int		w;
	int		z;
	size_t	len;
	int		prefix;

	prefix = !!(flag->bit & FLAG_PREFIX);
	len = (flag->precision == 0 && arg == 0) ? 0 : ft_strlen(str);
	// len += prefix;

	// printf("len = %ld\n", len);

	if (flag->precision == -1 || flag->precision < len)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->precision = %d, flag->p = %ld\n", flag->precision, flag->p);

	if (flag->p > len)
		flag->p = len;

	// flag->p is always the length of the actual content before any padding.
	// printf("flag->p = %ld, len = %d\n", flag->p, len);

	// printf("{f->p%d, f->w%d w%d, p%d, len%lu, z%d}\n", flag->precision, flag->width, w, flag->p, len, z);
	if (flag->width > (int)flag->p)
	{
		w = flag->width - (int)flag->p - prefix;
		// printf("%d - %d - %d = %d\n", flag->width, (int)flag->p, prefix, w);
	}
	else
		w = 0;
	// printf("{init w = %d}\n", w);

	if (flag->precision > (int)len)
		z = flag->precision - len - prefix;
	else
		z = 0;
	// printf("{init z = %d}\n", z);


	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);
	if (z > 0)
		w -= z;
	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);


	// printf("{leading zero %-3d|p%-3lu|w%-3d|len%-3d|z%-3d}\n", !!(flag->bit & FLAG_LEADING_ZERO), flag->p, w, len, z);
	// if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0) && (w >= len + z))

	// printf("{bit %d}\n", flag->bit);
	if (flag->bit & FLAG_LEADING_ZERO && ~flag->precision)
		flag->bit &= ~FLAG_LEADING_ZERO;
	// printf("{bit %d}\n", flag->bit);

	if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0))
	{
		z += w;
		w = 0;
	}

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}

	if (prefix)
		flag->written += ft_putstr("0");
	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += ft_putstrn(str, flag->p);
}

// Undefined flags: +, ' '
// Applicable flags: -, 0, #
// Precision: Minimum amount of digits, leading zeroes if necessary.
// If value is zero and precision is exactly zero, print nothing.
void	output_octal(unsigned long long arg, t_data *flag)
{
	char *str;

	str = ft_itoa_base(arg, 8);
	// printf("{%s}\n", str);

	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);

	free(str);
}
