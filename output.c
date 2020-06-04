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

static void putstr_case(const char *str, int mode)
{
	int		i;
	char	c;

	if (mode == 0)
		ft_putstr(str);
	else
	{
		if (str != NULL)
		{
			i = 0;
			while (str[i])
			{
				if (mode < 0)
					c = ft_tolower(str[i]);
				else
					c = ft_toupper(str[i]);
				write(1, &c, 1);
				++i;
			}
		}
	}
}

static int	width_padder(int length, t_data *flag, int arg)
{
	int		written;

	written = 0;
	if (flag->width > 0)
	{
		if (flag->precision > 0 && flag->precision < flag->width
			&& flag->type != 'c')
		{
			flag->width -= flag->precision + (arg < 0);
			// printf("Has precision but less than width\n");
		}
		else if (flag->precision >= flag->width
			&& flag->type != 'c')
		{
			flag->width = 0;
			// printf("Has precision greater than width\n");
		}
		else if (length < flag->width - 1)
		{
			flag->width -= length + (arg < 0);
			// printf("Account for the '-' sign with integer output\n");
		}
	}
	if (!(flag->bit & FLAG_JUSTIFY_LEFT))
	{
		while (flag->width > 0)
		{
			write(1, (flag->bit & FLAG_PAD_ZERO ? "0" : " "), 1);
			--flag->width;
			++written;
		}
	}
	return (written);
}

static int zero_padder(int length, t_data *flag, int arg)
{
	int		written;

	if (flag->type == 'd' || flag->type == 'i')
		write(1, (arg < 0 ? "-" : ""), written = (arg < 0));
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

int			output_str(char *arg, t_data *flag)
{
	int		written = 0;
	int		len = (arg ? ft_strlen(arg) : 6);

	if (flag->width > 0)
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
	ft_putstr((arg ? arg : "(null)"));
	written += len;
	while (flag->width > 0)
	{
		write(1, &flag->padder, 1);
		--flag->width;
		++written;
	}
	return (written);
}

int			output_int(int arg, t_data *flag)
{
	char	*str = NULL;
	int		written = 0;
	int		length;

	if (flag->type == 'd' || flag->type == 'i')
	{
		if (arg < 0)
			str = ft_itoa(-arg); //? str is always unsigned
		else
			str = ft_itoa(arg);
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

int			output_uint(unsigned int arg, t_data *flag)
{
	char	*str = NULL;
	int		length;
	int		written = 0;

	if (flag->type == 'X' || flag->type == 'x')
		str = ft_itoa_base(arg, 16);
	else if (flag->type == 'u')
		str = utoa(arg);
	else if (flag->type == 'o')
		str = ft_itoa_base(arg, 8);
	else
		ft_putstr("{oh no, uint}");
	length = ft_strlen(str);
	written = width_padder(length, flag, arg);
	written += zero_padder(length, flag, (flag->type == 'u' ? 1 : arg));

	if (flag->type == 'x')
		putstr_case(str, -1);
	else if (flag->type == 'X')
		putstr_case(str, 1);
	else
		ft_putstr(str);

	written = ft_strlen(str);
	free(str);
	return (written);
}

int			output_pointer(void *arg, t_data *flag)
{
	flag->type = 'x';
	return (output_uint((uintptr_t)arg, flag));
}