/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:46:21 by ngontjar          #+#    #+#             */
/*   Updated: 2020/08/10 13:36:02 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(int *len, int *w, long long *arg, t_data *flag)
{
	if (flag->precision == -1 || flag->precision < *len - (*arg < 0))
	{
		flag->p = *len;
	}
	else
	{
		flag->p = flag->precision;
	}
	if (flag->p > (size_t)*len)
	{
		flag->p = *len;
	}
	if ((size_t)flag->width > flag->p)
	{
		*w = (size_t)flag->width - flag->p;
	}
	else
	{
		*w = 0;
	}
}

static void	init_zeros(int *len, int *z, long long *arg, t_data *flag)
{
	if (flag->precision > *len - (*arg < 0))
	{
		*z = flag->precision - *len + (*arg < 0);
	}
	else
	{
		*z = 0;
	}
}

static void	justify_left(long long arg, const char *str, t_data *flag)
{
	int		w;
	int		z;
	int		len;

	len = (flag->precision == 0 && arg == 0) ? 0 : (int)ft_strlen(str);
	init(&len, &w, &arg, flag);
	w -= (arg >= 0 && flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN));
	init_zeros(&len, &z, &arg, flag);
	w = (z > 0) ? w - z : w;
	if (flag->bit & FLAG_FORCE_SIGN && arg >= 0)
		flag->written += ft_putstr("+");
	else if (flag->bit & FLAG_PAD_SIGN && arg >= 0)
		flag->written += ft_putstr(" ");
	else if (arg < 0)
		flag->written += ft_putstrn(str++, 1);
	width_padder(z, '0', flag);
	flag->written += ft_putstrn(str, flag->p - (arg < 0));
	width_padder(w, ' ', flag);
}

static void	justify_right(long long arg, const char *str, t_data *flag)
{
	int		w;
	int		z;
	int		len;

	len = (flag->precision == 0 && arg == 0) ? 0 : (int)ft_strlen(str);
	init(&len, &w, &arg, flag);
	w -= (arg >= 0 && flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN));
	init_zeros(&len, &z, &arg, flag);
	w = (z > 0) ? w - z : w;
	if (flag->bit & FLAG_LEADING_ZERO && ~flag->precision)
		flag->bit &= ~FLAG_LEADING_ZERO;
	if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0))
	{
		z += w;
		w = 0;
	}
	width_padder(w, ' ', flag);
	if (flag->bit & FLAG_FORCE_SIGN && arg >= 0)
		flag->written += ft_putstr("+");
	else if (flag->bit & FLAG_PAD_SIGN && arg >= 0)
		flag->written += ft_putstr(" ");
	else if (arg < 0)
		flag->written += ft_putstrn(str++, 1);
	width_padder(z, '0', flag);
	flag->written += ft_putstrn(str, flag->p - (arg < 0));
}

/*
** todo: clean up
** Undefined flags: #
** Applicable flags: -, +, ' ', 0
** Precision: Minimum amount of digits, leading zeroes if necessary.
** If value is zero and precision is exactly zero, print nothing.
*/

void		output_int(long long arg, t_data *flag)
{
	char *str;

	str = ft_itoa(arg);
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);
	free(str);
}
