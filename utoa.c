/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:54:54 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/25 03:58:13 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*utoa(unsigned long long number)
{
	char				string[20 + 1];
	unsigned int		length;

	// printf("utoa:%llu\n", number);
	if (number == 0)
		return (ft_strdup("0"));
	ft_memset(string, 0, 21);
	length = ft_numlen_ull(number);
	// printf("utoa numlen:%u\n", length);
	// 18446744073709551615
	while (length--)
	{
		if (number)
			string[length] = '0' + (number % 10);
		number /= 10;
	}
	return (ft_strdup(string));
}
