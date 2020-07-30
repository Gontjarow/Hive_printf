/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <niko.gontjarow@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:57:36 by ngontjar          #+#    #+#             */
/*   Updated: 2020/07/30 14:56:14 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <math.h>

# define SPECIFIER_HH	1
# define SPECIFIER_H	2
# define SPECIFIER_L	3
# define SPECIFIER_LL	4

# define FLAG_JUSTIFY_LEFT	0b1
# define FLAG_FORCE_SIGN	0b10
# define FLAG_PAD_SIGN		0b100
# define FLAG_PREFIX		0b1000
# define FLAG_LEADING_ZERO	0b10000

# define TX_NORMAL  "\x1B[0m"
# define FG_BLACK   "\x1B[30m"
# define FG_RED     "\x1B[31m"
# define FG_GREEN   "\x1B[32m"
# define FG_YELLOW  "\x1B[33m"
# define FG_BLUE    "\x1B[34m"
# define FG_MAGENTA "\x1B[35m"
# define FG_CYAN    "\x1B[36m"
# define FG_WHITE   "\x1B[37m"

typedef struct	s_data
{
	va_list	ap;
	int		bit;
	int		width;
	int		precision;
	int		specifier;
	char	padder;
	char	type;
	size_t	written;
	size_t	p;
}				t_data;

int				ft_printf(const char *format, ...);
char			parse_format(const char *format, t_data *flag);

// s
void			output_str(char *arg, t_data *flag);

// di c
void			output_int(long long arg, t_data *flag);
void			output_char(unsigned char arg, t_data *flag);

// Xx u o
void			output_uint(unsigned long long arg, t_data *flag);
void			output_unsigned(unsigned long long arg, t_data *flag);
void			output_octal(unsigned long long arg, t_data *flag);

// p
void			output_pointer(void *arg, t_data *flag);

// f
void			output_double(long double arg, t_data *flag);

size_t			putstr_case(const char *str, int mode);
size_t			putstrn_case(const char *str, size_t n, int mode);

char			*strany(const char *string, char *specifiers);
char			*strany_skip(const char *string, char *specifiers);
char			*strchr_skip(const char *string, char specifier);
char			*utoa(unsigned long long num);

size_t			ft_abs(ssize_t val);


typedef union	u_double
{
	double d;
	unsigned long ul;
}				t_double;

typedef union	u_float
{
	float f;
	unsigned int u;
}				t_float;

int			float_to_binary(float f);
int			double_to_binary(double d);

#endif
