/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:31:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/03/06 13:53:01 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			output_str(char *arg, t_data *flag)
{
	printf("output_str got: '%s'\n", arg);
	int		written;
	int		len;

	written = 0;
	len = (arg ? ft_strlen(arg) : 6); // "(null)"
	printf("output_str: len %d wid %d prec %d\n", len, flag->width, flag->precision);
	if (len > flag->precision && flag->precision != -1)
	{
		len -= (len - flag->precision);
		// printf("{prec len = %d}\n", len);
	}
	else if (flag->precision == -1)
	{
		flag->precision = ft_strlen(arg);
	}
	if (flag->width)
	{
		if (len >= flag->width)
			flag->width = 0;
		else
			flag->width -= len;
	}
	if (!(flag->bit & FLAG_JUSTIFY_LEFT))
	{
		while (flag->width > 0)
		{
			write(1, &flag->padder, 1);
			--flag->width;
			++written;
		}
	}
	// printf("{prec - wid = %d}\n", flag->precision - flag->width);
	if (arg)
		ft_putnstr(arg, flag->precision - flag->width);
	else
		ft_putstr("(null)");
	written += len;
	while (flag->width > 0)
	{
		write(1, &flag->padder, 1);
		--flag->width;
		++written;
	}
	return (written);
}

int			output_int(long long arg, t_data *flag)
{
	char	*str;
	int		written;
	int		length;

	str = NULL;
	written = 0;
	// printf("output_int:%lld\n", arg);
	if (flag->type == 'd' || flag->type == 'i')
	{
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
		written = width_padder(length, flag, arg); //? Arg needed for <0 check
		written += zero_padder(length, flag, arg);
		ft_putstr(str);
	}
	else if (flag->type == 'c')
	{
		written = width_padder(1, flag, arg); //? Length is always 1
		write(1, &arg, written = 1);
	}
	else
		ft_putstr("{oh no, int}");
	free(str);
	return (written);
}

int			output_uint(unsigned long long arg, t_data *flag)
{
	char	*str;
	int		length;
	int		written;

	str = NULL;
	written = 0;
	// printf("\noutput_uint:%llu\n", arg);
	if (flag->type == 'X' || flag->type == 'x')
		str = ft_itoa_base(arg, 16);
	else if (flag->type == 'u')
		str = utoa(arg);
	else if (flag->type == 'o')
		str = ft_itoa_base(arg, 8);
	else
		ft_putstr("{oh no, uint}");
	length = ft_strlen(str);
	// printf("\noutput_uint str:'%s'\n", str);
	// printf("\nlength:%d\n", length);
	written = width_padder(length, flag, (flag->type == 'u' ? 1 : arg));
	written += zero_padder(length, flag, (flag->type == 'u' ? 1 : arg));
	;
	if (flag->type == 'x')
		putstr_case(str, -1);
	else if (flag->type == 'X')
		putstr_case(str, 1);
	else
		ft_putstr(str);
	;
	written = ft_strlen(str);
	free(str);
	return (written);
}

int			output_pointer(void *arg, t_data *flag)
{
	char	*str;
	int		length;
	int		written;

	str = NULL;
	length = 0;
	written = 0;
	str = ft_itoa_base((uintptr_t)arg, 16);
	length = ft_strlen(str);
	written = width_padder(length + 2, flag, (uintptr_t)arg);
	ft_putstr("0x");
	written += zero_padder(length + 2, flag, (uintptr_t)arg);
	putstr_case(str, -1);
	return (written);
}

int			output_double(long double arg, t_data *flag)
{
	char	*str;
	int		written;

	// printf("output_double got: %f\n", arg);
	written = 0;
	// printf("output double prec: %d\n", flag->precision);
	if ((str = ft_ftoa(arg, flag->precision == -1 ? 6 : flag->precision)))
	{
		written = ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (written);
}
