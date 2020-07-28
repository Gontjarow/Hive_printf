#include "ft_printf.h"

static void justify_left(long long arg, const char *str, t_data *flag)
{
	// printf("\n");
	int		w;
	int		z;
	int		len;

	len = (flag->precision == 0 && arg == 0) ? 0 : (int)ft_strlen(str);
	// printf("len = %ld\n", len);

	if (flag->precision == -1 || flag->precision < len)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > (size_t)len)
		flag->p = len;

	// flag->p is always the length of the actual content before any padding.
	// printf("flag->p = %ld, len = %d\n", flag->p, len);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("{init w = %d}\n", w);

	if (flag->precision > len)
		z = flag->precision - len;
	else
		z = 0;
	// printf("{init z = %d}\n", z);


	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);
	if (z > 0)
		w -= z;
	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);

	// printf("{leading zero %-3d|p%-3lu|w%-3d|len%-3d|z%-3d}\n", !!(flag->bit & FLAG_LEADING_ZERO), flag->p, w, len, z);
	// if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0) && (w >= len + z))

	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += putstrn_case(str, flag->p, -1 * (flag->type == 'x'));

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(long long arg, const char *str, t_data *flag)
{
	// printf("\n");
	int		w;
	int		z;
	int		len;

	len = (flag->precision == 0 && arg == 0) ? 0 : (int)ft_strlen(str);
	// printf("len = %ld\n", len);

	if (flag->precision == -1 || flag->precision < len)
		flag->p = len;
	else
		flag->p = flag->precision;
	// printf("flag->p = %ld\n", flag->p);

	if (flag->p > (size_t)len)
		flag->p = len;

	// flag->p is always the length of the actual content before any padding.
	// printf("flag->p = %ld, len = %d\n", flag->p, len);

	if ((size_t)flag->width > flag->p)
		w = (size_t)flag->width - flag->p;
	else
		w = 0;
	// printf("{init w = %d}\n", w);

	if (flag->precision > len)
		z = flag->precision - len;
	else
		z = 0;
	// printf("{init z = %d}\n", z);


	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);
	if (z > 0)
		w -= z;
	// printf("{p %-3lu|w %-3d|z %-3d|len %-3d}\n", flag->p, w, z, len);


	// printf("{leading zero %-3d|p%-3lu|w%-3d|len%-3d|z%-3d}\n", !!(flag->bit & FLAG_LEADING_ZERO), flag->p, w, len, z);
	// if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0) && (w >= len + z))

	// printf("{bit %d}\n", flag->bit);
	if (flag->bit & FLAG_LEADING_ZERO && ~flag->precision)
		flag->bit &= ~FLAG_LEADING_ZERO;
	// printf("{bit %d}\n", flag->bit);

	// {leading zero: 1, p8 w2 len8, z0}
	if ((flag->bit & FLAG_LEADING_ZERO) && (w > 0))
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

	while (z > 0)
	{
		write(1, "0", 1);
		// ft_putstr(FG_GREEN "0" TX_NORMAL);
		++flag->written;
		--z;
	}

	flag->written += putstrn_case(str, flag->p, -1 * (flag->type == 'x'));
}

// Undefined flags: +, ' '
// Applicable flags: -, 0, #
// Precision: Minimum amount of digits, leading zeroes if necessary.
// If value is zero and precision is exactly zero, print nothing.
void	output_uint(unsigned long long arg, t_data *flag)
{
	// printf("\n{output_uint: '%llu', w%d p%d}\n", arg, flag->width, flag->precision);
	char *str;

	str = ft_itoa_base(arg, 16);
	// printf("{%s}\n", str);

	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, str, flag);
	else
		justify_right(arg, str, flag);

	free(str);
}
