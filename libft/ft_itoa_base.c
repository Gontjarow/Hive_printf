/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:36:21 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/26 08:22:40 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long number, int base)
{
	char			string[64 + 1];
	long long		num;
	unsigned int	mod;
	unsigned int	i;

	if (base < 2 || base > 36)
		return (NULL);
	if (base == 10)
		return (ft_itoa(number));
	if (number == 0)
		return (ft_strdup("0"));
	i = 0;
	string[i] = '0';
	num = (number < 0) ? -number : number;
	while (num)
	{
		mod = num % base;
		string[i++] = (mod > 9 ? 'A' + (mod - 10) : '0' + mod);
		num /= base;
	}
	string[i] = '\0';
	ft_strrev(string);
	return (ft_strdup(string));
}
