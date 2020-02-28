/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:54:54 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/28 22:49:15 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*utoa(unsigned int num)
{
	char			string[10 + 1];
	unsigned int	number;
	unsigned int	length;

	if (num == 0)
		return (ft_strdup("0"));
	ft_memset(string, 0, 11);
	length = ft_numlen(num);
	number = num;
	while (length--)
	{
		if (number)
			string[length] = '0' + (number % 10);
		number /= 10;
	}
	return (ft_strdup(string));
}
