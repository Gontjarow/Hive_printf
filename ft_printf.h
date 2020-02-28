/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/28 23:30:24 by ngontjar         ###   ########.fr       */
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

typedef struct	s_data
{
	va_list	ap;
	int		width;
	int		precision;
	int		pad;
	char	padder;
	char	type;
	size_t	written;
}				t_data;

int				ft_printf(const char *format, ...);
char			parse_format(const char * format, t_data *flag);
int				output_str(char *arg, t_data *flag);
int				output_int(int arg, t_data *flag);
int				output_uint(unsigned int arg, t_data *flag);

char			*strany(const char *string, char *specifiers);
char			*stranyskip(const char *string, char *specifiers);
char			*strchr_skip(const char *string, char specifier);
char			*utoa(unsigned int num);


#endif
