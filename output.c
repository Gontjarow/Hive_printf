/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:31:26 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/20 20:34:58 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	output_str(char *arg, t_flag flag)
{
	int		written = 0;
	char	padder = ' ';
	int		len = ft_strlen(arg);

	printf("\tOutput: str\n");
	if (flag.width > 0)
	{
		if (len >= flag.width)
			flag.width = 0;
		else
			flag.width -= len;
		if (flag.pad & PAD_ZERO)
			padder = '0';
	}
	if (!(flag.pad & PAD_RIGHT))
	{
		while (flag.width > 0)
		{
			putchar(padder);
			++written;
		}
	}
	ft_putstr(arg);
	written += len;
	while (flag.width > 0)
	{
		putchar(padder);
		++written;
	}
	return (written);
}

int	output_int(int arg, t_flag flag)
{
	char	*str = NULL;
	int		written = 0;

	printf("\tOutput: int\n");
	if (flag.type == 'd' || flag.type == 'i')
	{
		str = ft_itoa(arg);
		ft_putstr(str);
		written = ft_strlen(str);
		free(str);
	}
	else if (flag.type == 'c')
	{
		ft_putchar(arg);
		written = 1;
	}
	else
		ft_putstr("{oh no, int}");
	return (written);
}

int	output_uint(unsigned int arg, t_flag flag)
{
	char	*str = NULL;
	int		written = 0;

	// printf("\tOutput: uint\n");
	if (flag.type == 'X' || flag.type == 'x')
		str = ft_itoa_base(arg, 16);
	else if (flag.type == 'u')
		str = ft_itoa(arg);
	else if (flag.type == 'o')
		str = ft_itoa_base(arg, 8);
	else
		ft_putstr("{oh no, uint}");

	ft_putstr(str);
	written = ft_strlen(str);
	free(str);

	return (written);
}
