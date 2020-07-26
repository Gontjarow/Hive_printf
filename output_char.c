/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 11:37:43 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/26 11:55:10 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void justify_left(unsigned char arg, t_data *flag)
{
	//
}

static void justify_right(unsigned char arg, t_data *flag)
{
	//
}

// Undefined flags: #, 0, ' ', +
// Applicable flags: -
// Precision: Ignored
void	output_str(unsigned char arg, t_data *flag)
{
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, flag);
	else
		justify_right(arg, flag);
}
