/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/18 20:43:46 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define PAD_LEFT	 0b0;
# define PAD_RIGHT	 0b1;
# define PAD_ZERO	0b10

typedef struct	s_flag
{
	char	pad;
	char	width;
	char	precision;
	char	type;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*strany(const char *string, const char *specifiers);
char			*strcany(const char *string, const char specifier);

#endif
