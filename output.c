/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:31:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/20 20:10:45 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			output_str(char *arg, t_data *flag)
{
	// printf("output_str got: '%s'\n", arg);
	int		len;

	len = (arg ? ft_strlen(arg) : 6); // "(null)"
	// printf("output_str: {len %d wid %d prec %d}\n", len, flag->width, flag->precision);
	if (flag->precision != -1 && len > flag->precision)
	{
		// printf("precision given && len > precision\n");
		len -= (len - flag->precision);
	}
	else if (flag->precision == -1)
	{
		// printf("precision default\n");
		flag->precision = ft_strlen(arg);
	}
	// printf("len adjust 1 {%d}\n", len);
	if (flag->width)
	{
		if (len >= flag->width)
		{
			// printf("len >= flag->width\n");
			flag->width = 0;
		}
		else
		{
			// printf("len < width\n");
			flag->width -= len;
		}
	}
	// printf("len adjust 2 {%d, width %d}\n", len, flag->width);
	if (~flag->bit & FLAG_JUSTIFY_LEFT) // changed //? pad left if not justified
	{
		while (flag->width > 0)
		{
			write(1, &flag->padder, 1);
			++flag->written;
			--flag->width;
		}
	}
	// printf("{len %d wid %d prec %d}\n", len, flag->width, flag->precision);
	// printf("{'%s' prec - wid = %d}\n", arg, flag->precision - flag->width);
	if (arg)
		ft_putnstr(arg, flag->precision);
	else
		ft_putstr("(null)");
	flag->written += len;
	while (flag->width > 0) //? maybe use width_padder
	{
		write(1, &flag->padder, 1);
		++flag->written;
		--flag->width;
	}
	return (0);
}

/*
** Int output:
** Always full output, even if precision is low.
*/

int			output_int(long long arg, t_data *flag)
{
	char	*str;
	int		length;

	str = NULL;
	// printf("output_int:%lld\n", arg);
	if ((flag->type == 'd' || flag->type == 'i'))
	{
		if (arg == 0 && flag->precision == 0)
			return (0);
		if (flag->specifier == SPECIFIER_HH)
			str = ft_itoa((char)arg < 0 ? (char)-arg : (char)arg);
		else if (flag->specifier == SPECIFIER_H)
			str = ft_itoa((short)arg < 0 ? (short)-arg : (short)arg);
		else if (flag->specifier == SPECIFIER_L
			|| flag->specifier == SPECIFIER_LL)
			str = ft_itoa(arg < 0 ? -arg : arg);
		else
			str = ft_itoa((int)arg < 0 ? (int)-arg : (int)arg);
		length = ft_strlen(str);
		flag->precision = (length > flag->precision ? length : flag->precision);
		// printf("{w%d p%d}\n", flag->width, flag->precision);
		width_padder(length, flag, arg); //? Arg needed for <0 check
		zero_padder(length, flag, arg);
		ft_putstr(str);
		flag->written += length;
	}
	else if (flag->type == 'c')
	{
		width_padder(1, flag, arg); //? Length is always 1
		write(1, &arg, 1);
		++flag->written;
	}
	else
		ft_putstr("{oh no, int}");
	free(str);
	return (0);
}

int			output_uint(unsigned long long arg, t_data *flag)
{
	char	*str;
	int		length;

	str = NULL;
	// printf("\noutput_uint: {%c %llu, w%d p%d}\n", flag->type, arg, flag->width, flag->precision);
	// if (arg == 0 && flag->precision == 0)
	// 	return (0);
	if (flag->type == 'X' || flag->type == 'x')
		str = ft_itoa_base(arg, 16);
	else if (flag->type == 'u')
		str = utoa(arg);
	else if (flag->type == 'o')
		str = ft_itoa_base(arg, 8);
	else
		ft_putstr("{oh no, uint}");
	length = ft_strlen(str);
	// printf("output_uint {'%s'}\n", str);
	// printf("\nlength:%d\n", length);

	width_padder(length, flag, (flag->type == 'u' ? 1 : arg));

	if (flag->bit & FLAG_PREFIX)
	{
		if (flag->type == 'o' && arg)
		{
			ft_putstr("0");
			// ft_putstr("<o>");
		}
		else if ((flag->type == 'x' || flag->type == 'X') && arg)
		{
			ft_putstr("0x");
			// ft_putstr("<x>");
		}
	}

	if (flag->precision == 0 && arg == 0)
	{
		if (flag->bit & FLAG_PREFIX && flag->type == 'o')
			ft_putstr(FG_RED "0" TX_NORMAL); // todo: remove color
		return (0);
	}
	zero_padder(length, flag, (flag->type == 'u' ? 1 : arg));

	if (flag->type == 'x')
		putstr_case(str, -1);
	else if (flag->type == 'X')
		putstr_case(str, 1);
	else
		ft_putstr(str);
	flag->written += length;
	free(str);
	return (0);
}

/*
** Pointer output:
** Always outputs whole pointer, even if precision is low.
*/

int			output_pointer(void *arg, t_data *flag)
{
	char	*str;
	int		length;

	str = NULL;
	length = 0;
	str = ft_itoa_base((uintptr_t)arg, 16);
	length = 2 + ft_strlen(str);
	flag->precision = (length > flag->precision ? length : flag->precision);
	width_padder(length, flag, 0);
	ft_putstr("0x");
	zero_padder(length, flag, 0);
	putstr_case(str, -1);
	flag->written += length;
	return (0);
}

int			output_double(long double arg, t_data *flag)
{
	char	*str;

	// printf("output_double got: %f\n", arg);
	// printf("output double prec: %d\n", flag->precision);
	if ((str = ft_ftoa(arg, flag->precision == -1 ? 6 : flag->precision)))
	{
		// ft_putstr("ftoa out:"); ft_putendl(str);
		flag->written += ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (0);
}
