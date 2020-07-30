/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:51:48 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/30 15:18:16 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	output_unsigned(unsigned long long arg, t_data *flag)
{
	char *str;

	str = ft_itoa_base(arg, 10);
	// printf("{%s}\n", str);

	// if (flag->bit & FLAG_JUSTIFY_LEFT)
	// 	justify_left(arg, str, flag);
	// else
	// 	justify_right(arg, str, flag);

	free(str);
}
