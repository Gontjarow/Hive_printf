/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:52:28 by ngontjar          #+#    #+#             */
/*   Updated: 2020/08/05 22:50:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Precision: The number of digits to appear after the decimal-point.
** Note: The default precision is 6. If precision is 0, no digits
**       nor the decimal-point will be printed.
**
** Flag: #
** Summary: The decimal-point is always printed, even if no digits follow it.
**
** Flag: -
** Summary: Left-justification.
**
** Flag: +
** Summary: The sign is always printed.
**
** Flag: (space)
** Summary: If the first wide character of a signed conversion is not a sign,
**          or if a signed conversion results in no wide characters,
**          a space is prefixed to the result.
** Note: If the space and + flags both appear, the space flag is ignored.
**
** Flag: 0
** Summary: Leading zeros (following any indication of sign or base) are used
**          to pad to the field width rather than performing space padding,
**          except when converting an infinity or NaN.
** Note: If the 0 and - flags both appear, the 0 flag is ignored.
*/

static long double	g_round[] =
{
	0.5L,
	0.05000000000000000278L,
	0.005000000000000000104L,
	0.0005000000000000000104L,
	5.00000000000000024e-05L,
	5.000000000000000409e-06L,
	5.000000000000000833e-07L,
	5.000000000000000435e-08L,
	5.000000000000000105e-09L,
	5.000000000000000311e-10L,
	5.000000000000000182e-11L,
	5.000000000000000505e-12L,
	5.000000000000000909e-13L,
	5.000000000000000152e-14L,
	5.000000000000000783e-15L,
	5.000000000000000389e-16L,
	5.000000000000000512e-17L,
	5.000000000000000358e-18L,
	5.000000000000000358e-19L,
	5.000000000000000478e-20L
};

#include "ft_printf.h"

static void	init(size_t *len, int *w, int *e, t_data *flag)
{
	if (!(*e) && flag->precision == -1)
	{
		flag->p = *len + 1 + 6;
	}
	else if (!(*e) && flag->precision != 0)
	{
		flag->p = *len + 1 + flag->precision;
	}
	else
	{
		flag->p = *len + !!(flag->bit & FLAG_PREFIX);
	}
	if (flag->width > (int)flag->p)
	{
		*w = flag->width - (int)flag->p;
	}
	else
	{
		*w = 0;
	}
}

static void	init_zeros(int *z, int *w, int *e, t_data *flag)
{
	if (!(*e) && flag->precision > (int)flag->p)
	{
		*z = flag->precision - (int)flag->p;
	}
	else
	{
		*z = 0;
	}
	if (*z > 0)
	{
		*w -= *z;
	}
	if (!(*e) && (flag->bit & FLAG_LEADING_ZERO) && (*w > 0))
	{
		*z += *w;
		*w = 0;
	}
}

static void	write_sign(const long double *arg, const char **str, t_data *flag)
{
	if (flag->bit & FLAG_FORCE_SIGN && *arg >= 0)
		flag->written += ft_putstr("+");
	else if (flag->bit & FLAG_PAD_SIGN && *arg >= 0)
		flag->written += ft_putstr(" ");
	else if (*arg < 0)
		flag->written += ft_putstrn((*str)++, 1);
}

static void	justify_left(long double arg, const char *str, int e, t_data *flag)
{
	int		w;
	size_t	len;

	len = ft_strlen(str);
	init(&len, &w, &e, flag);
	w -= (arg >= 0 && flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN));
	write_sign(&arg, &str, flag);
	flag->written += ft_putstrn(str, len - (arg < 0));
	arg = (arg < 0) ? -arg : arg;
	flag->p -= len;
	if (flag->p)
	{
		flag->written += ft_putstr(".");
		while (--flag->p)
		{
			arg *= 10;
			arg += 0.5 * (flag->p == 1);
			flag->written += ft_putchar('0' + (unsigned char)arg);
			arg -= (long int)arg;
		}
	}
	else if (flag->bit & FLAG_PREFIX)
		flag->written += ft_putstr(".");
	width_padder(w, ' ', flag);
}

static void	justify_right(long double arg, const char *str, int e, t_data *flag)
{
	int		w;
	int		z;
	size_t	len;

	len = ft_strlen(str);
	init(&len, &w, &e, flag);
	w -= (arg >= 0 && flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN));
	init_zeros(&z, &w, &e, flag);
	width_padder(w, ' ', flag);
	write_sign(&arg, &str, flag);
	width_padder(z, '0', flag);
	flag->written += ft_putstrn(str, len - (arg < 0));
	arg = (arg < 0) ? -arg : arg;
	flag->p -= len;
	if (flag->p || flag->bit & FLAG_PREFIX)
		flag->written += ft_putstr(".");
	if (flag->p)
	{
		// arg += (flag->p <= 16) * g_round[flag->p];
		// printf("{%Lf, %d}\n", (flag->p <= 16) * g_round[flag->p], flag->p <= 16);
		while (--flag->p)
		{
			arg *= 10; // ! ROUNDING ERRORS AAAAAAA
			arg += 0.5 * (flag->p == 1);
			flag->written += ft_putchar('0' + (long int)arg);
			arg -= (long int)arg;
		}
	}
}

static char				*check_invalid(long double floating)
{
	if (floating != floating)
		return (ft_strdup("nan"));
	else if (floating == INFINITY)
		return (ft_strdup("inf"));
	else if (floating == -INFINITY)
		return (ft_strdup("-inf"));
	else
		return (NULL);
}

void	output_double(long double arg, t_data *flag)
{
	char *str;
	char error;

	error = FALSE;
	str = check_invalid(arg);
	if (str == NULL)
		str = ft_ftoa(arg, 0);
	else
		error = TRUE;
	arg -= (long int)arg;
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, error, flag);
	else
		justify_right(arg, str, error, flag);
	free(str);
}
