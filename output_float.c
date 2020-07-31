#include "ft_printf.h"

static void justify_left(long double arg, const char *str, t_data *flag)
{
	(void)arg; (void)str; (void)flag;
}

static void justify_right(long double arg, const char *str, t_data *flag)
{
	int w;
	int z;
	size_t len;

	len = ft_strlen(str);
	// printf("len %ld\n", len);

	if (flag->precision == -1)
		flag->p = len + 1 + 6;
	else if (flag->precision != 0)
		flag->p = len + 1 + flag->precision;
	else
		flag->p = len;

	if (flag->width > (int)flag->p)
		w = flag->width - (int)flag->p;
	else
		w = 0;

	if (flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN))
	{
		--w;
	}

	if (flag->precision > flag->p)
		z = flag->precision - flag->p; // ? negative-sign should be ignored for this.
	else
		z = 0;
	// printf("{pre%d, w%d, p%d, len%lu, z%d}\n", flag->precision, w, flag->p, len, z);
	// real: |0.000000|
	if (z > 0)
		w -= z;

	if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0))
	{
		z += w;
		w = 0;
	}
	// printf("{z %d}\n", z);

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}

	if (flag->bit & FLAG_FORCE_SIGN && arg >= 0)
		flag->written += ft_putstr("+");
	else if (flag->bit & FLAG_PAD_SIGN && arg >= 0)
		flag->written += ft_putstr(" ");
	else if (arg < 0)
		flag->written += ft_putstrn(str++, 1);

	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	// Note: Negative sign has already been printed.
	// Todo: Find a more elegant solution?
	flag->written += ft_putstrn(str, len - (arg < 0)); // ? Integer part
	flag->p -= len;
	if (flag->p)
	{
		flag->written += ft_putstr(".");
		while (--flag->p)
		{
			arg *= 10;
			flag->written += ft_putchar('0' + (unsigned char)arg);
			// printf("{%hhu}\n", (unsigned char)arg);
			arg -= (long int)arg;
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

// Undefined flags:
// Applicable flags: -, +, ' ', #, 0
// Precision: The amount of digits following the decimal point.
// If precision == 0, no decimal point is printed.
// The default precision is 6.

void	output_double(long double arg, t_data *flag)
{
	// printf("\n{output_double: '%Lf', w%d p%d}\n", arg, flag->width, flag->precision);
	char *str;

	str = check_invalid(arg);
	if (str == NULL)
		str = ft_itoa((long int)arg);

	if (arg < 0)
	{
		arg *= -1;
		// printf("{negative}\n");
	}
	arg -= (long int)arg; // ? Remove the integer part already...
	// printf("|%Lf|\n", arg);
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);

	free(str);
}
