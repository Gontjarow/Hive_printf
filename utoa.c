/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:54:54 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/20 13:16:06 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned char	ft_numlen_ull(unsigned long long number)
{
	unsigned char length;

	if (number == 0)
		return (1);
	length = 0;
	while (number)
	{
		++length;
		number /= 10;
	}
	return (length);
}

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
