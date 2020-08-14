/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:07:10 by ngontjar          #+#    #+#             */
/*   Updated: 2020/08/13 21:37:53 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
				write(1, &c, 1);
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

void			width_padder(int w, const char c, t_data *flag)
{
	while (w > 0)
	{
		write(1, &c, 1);
		++flag->written;
		--w;
	}
}

char			*ft_utoa(unsigned long long number)
{
	char				string[20 + 1];
	unsigned int		length;

	if (number == 0)
		return (ft_strdup("0"));
	ft_memset(string, 0, 21);
	length = ft_numlen_ull(number);
	while (length--)
	{
		if (number)
			string[length] = '0' + (number % 10);
		number /= 10;
	}
	return (ft_strdup(string));
}

char			*ft_utoa_base(unsigned long long number, int base)
{
	char				string[64 + 1];
	unsigned int		mod;
	unsigned int		i;

	if (base < 2 || base > 36)
		return (NULL);
	if (number == 0)
		return (ft_strdup("0"));
	if (base == 10)
		return (ft_utoa(number));
	ft_memset(string, 0, 65);
	i = 0;
	while (number)
	{
		mod = number % base;
		string[i++] = (mod > 9 ? 'A' + (mod - 10) : '0' + mod);
		number /= base;
	}
	string[i] = '\0';
	ft_strrev(string);
	return (ft_strdup(string));
}
