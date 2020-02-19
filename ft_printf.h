/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/19 20:53:09 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define PAD_DEFAULT	0b00
# define PAD_ZERO		0b10
# define PAD_RIGHT		 0b1

typedef struct	s_flag
{
	unsigned char	width;
	char			precision;
	char			pad;
	char			type;
}				t_flag;

int				ft_printf(const char *format, ...);
char			parse_format(const char * format, t_flag *flag);
int				output_str(char *arg, t_flag flag);
int				output_int(int arg, t_flag flag);
int				output_uint(unsigned int arg, t_flag flag);

char			*strany(const char *string, const char *specifiers);
char			*strcany(const char *string, const char specifier);

#endif
