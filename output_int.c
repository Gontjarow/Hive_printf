#include "ft_printf.h"

static void justify_left(long long arg, const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	size_t	len;

	len = ft_strlen(str);
	// printf("len = %ld\n", len);

	if (flag->precision == -1)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > len)
		flag->p = len;
	// printf("flag->p = %ld\n", flag->p);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("w = %ld\n", w);

	flag->written += ft_putstrn(str, flag->p);

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

/*
**
** Separator
**
*/

static void justify_right(long long arg, const char *str, t_data *flag)
{
	// printf("\n");

	int		w;
	int		z;
	int		len;

	len = (flag->precision == 0 && arg == 0) ? 0 : (int)ft_strlen(str);
	// printf("len = %ld\n", len);

	if (flag->precision == -1 || flag->precision < len - (arg < 0))
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > len)
		flag->p = len;
	// printf("flag->p = %ld\n", flag->p);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("w = %ld\n", w);

	if (arg >= 0 && flag->bit & (FLAG_FORCE_SIGN | FLAG_PAD_SIGN))
	{
		--w;
	}

	if (flag->precision > len - (arg < 0))
		z = flag->precision - len + (arg < 0); // ? negative-sign should be ignored for this.
	else
		z = 0;
	// printf("{w = %d, pre = %d, len = %lu, z = %d}\n", w, flag->precision, len, z);

	if (z > 0)
		w -= z;

	if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0) && (w >= len + z))
	{
		z += w;
		w = 0;
	}

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
		flag->written += ft_putstrn(str++, 1); // ? Advance the pointer...

	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	// Note: Negative sign has already been printed.
	// Todo: Find a more elegant solution?
	flag->written += ft_putstrn(str, flag->p - (arg < 0));
}

// Undefined flags: #
// Applicable flags: -, +, ' ', 0
// Precision: Minimum amount of digits, leading zeroes if necessary.
// If value is zero and precision is exactly zero, print nothing.
// todo: Separate 'c' from here? It has significant difference to 'd' and 'i'
void	output_int(long long arg, t_data *flag)
{
	// printf("\n{output_int: '%lld', w%d p%d}\n", arg, flag->width, flag->precision);
	char *str;

	if (flag->type == 'c')
	{
		output_char(arg, flag);
		return ;
	}

	str = ft_itoa(arg);

	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);

	free(str);
}
