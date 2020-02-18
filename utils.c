/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 21:07:10 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/18 21:44:11 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int unsigned_str_num(char *str)
{
	unsigned int	number;
	while (ft_isdigit(*str))
	{
		number *= 10;
		number += (*str - '0');
		++str;
	}
}
