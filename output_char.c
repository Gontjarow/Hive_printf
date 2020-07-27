/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 11:37:43 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/27 08:31:55 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_left(unsigned char arg, t_data *flag)
{
	int w;

	write(1, &arg, 1);
	++flag->written;
	w = flag->width - 1;
	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(unsigned char arg, t_data *flag)
{
	int w;

	w = flag->width - 1;
	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
	write(1, &arg, 1);
	++flag->written;
}

// Undefined flags: #, 0, ' ', +
// Applicable flags: -
// Precision: Ignored
void	output_char(unsigned char arg, t_data *flag)
{
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, flag);
	else
		justify_right(arg, flag);
}
