/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:31:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/27 22:28:41 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	width_padder(int length, t_flag *flag, int arg)
{
	int		written;

	written = 0;
	if (flag->width > 0)
	{
		if (flag->precision > 0 && flag->precision < flag->width)
			flag->width -= flag->precision + (arg < 0);
		else if (length < flag->width)
			flag->width -= length + (arg < 0);
		else
			flag->width = 0;
	}
	if ((flag->pad & PAD_RIGHT) == FALSE)
	{
		while (flag->width > 0)
		{
			write(1, &flag->padder, 1);
			--flag->width;
			++written;
		}
	}
	return (written);
}

static int zero_padder(int length, t_flag *flag, int arg)
{
	int		written;

	write(1, "-", written = (arg < 0));
	if (flag->precision > 0)
	{
		if (length < flag->precision)
			flag->precision -= length;
		else
			flag->precision = 0;
	}
	while (flag->precision > 0)
	{
		write(1, "0", 1);
		--flag->precision;
		++written;
	}
	return (written);
}

int			output_str(char *arg, t_flag *flag)
{
	int		written = 0;
	char	padder = ' ';
	int		len = (arg ? ft_strlen(arg) : 6);

	if (flag->width > 0)
	{
		if (len >= flag->width)
			flag->width = 0;
		else
			flag->width -= len;
		if (flag->pad & PAD_ZERO)
			padder = '0';
	}
	if (!(flag->pad & PAD_RIGHT))
	{
		while (flag->width > 0)
		{
			ft_putchar(padder);
			--flag->width;
			++written;
		}
	}
	ft_putstr((arg ? arg : "(null)"));
	written += len;
	while (flag->width > 0)
	{
		ft_putchar(padder);
		--flag->width;
		++written;
	}
	return (written);
}

int			output_int(int arg, t_flag *flag)
{
	char	*str = NULL;
	int		written = 0;
	int		length;

	if (arg < 0)
		str = ft_itoa(-arg);
	else
		str = ft_itoa(arg);
	length = ft_strlen(str);
	if (flag->type == 'd' || flag->type == 'i')
	{
		written = width_padder(length, flag, arg);
		written += zero_padder(length, flag, arg);
		ft_putstr(str);
	}
	else if (flag->type == 'c')
	{
		written = width_padder(1, flag, arg);
		written += zero_padder(1, flag, arg);
		write(1, &arg, written = 1);
	}
	else
		ft_putstr("{oh no, int}");
	free(str);
	return (written);
}

int			output_uint(unsigned int arg, t_flag *flag)
{
	char	*str = NULL;
	int		written = 0;

	// printf("\tOutput: uint\n");
	if (flag->type == 'X' || flag->type == 'x')
		str = ft_itoa_base(arg, 16);
	else if (flag->type == 'u')
		str = ft_itoa(arg);
	else if (flag->type == 'o')
		str = ft_itoa_base(arg, 8);
	else
		ft_putstr("{oh no, uint}");

	ft_putstr(str);
	written = ft_strlen(str);
	free(str);

	return (written);
}
