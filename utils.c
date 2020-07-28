/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:07:10 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/28 21:16:22 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	unsigned_str_num(char *str)
{
	unsigned int	number;

	while (ft_isspace(*str))
		++str;
	while (*str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		number *= 10;
		number += (*str - '0');
		++str;
	}
	return (number);
}

size_t			putstr_case(const char *str, int mode)
{
	size_t	i;
	size_t	length;
	char	c;

	if (mode == 0)
		return (ft_putstr(str));
	else
	{
		if (str)
		{
			length = ft_strlen(str);
			i = 0;
			while (str[i])
			{
				c = (mode < 0) ? ft_tolower(str[i]) : ft_toupper(str[i]);
				ft_putstr(FG_YELLOW);
				write(1, &c, 1);
				ft_putstr(TX_NORMAL);
				++i;
			}
		}
		else
			return (putstr_case("(null)", mode));
	}
	return (length);
}

size_t			putstrn_case(const char *str, size_t n, int mode)
{
	size_t	i;
	char	c;

	i = 0;
	if (str)
	{
		while (str[i] && i < n)
		{
			c = (mode < 0) ? ft_tolower(str[i]) : ft_toupper(str[i]);
			write(1, &c, 1);
			++i;
		}
	}
	else
		return (putstr_case("(null)", mode));
	return (i);
}
