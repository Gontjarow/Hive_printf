#include "ft_printf.h"

static long double		g_round[] =
{
	0.5,

	0.05,
	0.005,
	0.0005,
	0.00005,
	0.000005,
	0.0000005,
	0.00000005,
	0.000000005,
	0.0000000005,
	0.00000000005,

	0.000000000005,
	0.0000000000005,
	0.00000000000005,
	0.000000000000005,
	0.0000000000000005,
	0.00000000000000005,
	0.000000000000000005,
	0.0000000000000000005,
	0.00000000000000000005,
	0.000000000000000000005,
};

static unsigned char	ft_numlen_ul(unsigned long number)
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

static void				write_integer(char *buffer, unsigned long integer,
									unsigned char sign, unsigned char *i)
{
	unsigned char length;

	length = ft_numlen_ul(integer);
	while (length--)
	{
		buffer[sign + length] = '0' + (integer % 10);
		integer /= 10;
		++(*i);
	}
}

static void				write_fractional(char *buffer, long double floating,
								unsigned char precision, unsigned char *i)
{
	if (precision)
	{
		buffer[(*i)++] = '.';
		while (precision--)
		{
			floating *= 10;
			buffer[(*i)++] = '0' + (int)floating;
			floating -= (int)floating;
		}
	}
}

static char				*check_invalid(long double floating)
{
	if (floating != floating)
		return (ft_strdup("nan"));
	else if (floating == INFINITY)
		return (ft_strdup("inf"));
	else if (floating == -INFINITY)
		return (ft_strdup("-inf"));
	else
		return (NULL);
}

/*
** Accurate up to 18 decimals with printf.
*/

char					*ft_ftoa(long double floating, unsigned char precision)
{
	// printf("ftoa got %Lf\n", floating);
	char			buffer[128];
	unsigned char	i;
	unsigned long	integer;
	unsigned char	sign;
	char			*error;

	if ((error = check_invalid(floating)))
		return (error);
	i = 0;
	precision = (precision > 20) ? 20 : precision;
	if ((sign = signbit(floating)))
	{
		floating = -floating;
		buffer[i++] = '-';
	}
	floating += g_round[precision];
	integer = (unsigned long)floating;
	floating -= integer;
	write_integer(buffer, integer, sign, &i);
	write_fractional(buffer, floating, precision, &i);
	buffer[i++] = '\0';
	return (ft_strdup(buffer));
}
