#include "ft_printf.h"

static void justify_left(char *arg, t_data *flag)
{
	// printf("\n");

	int		w;
	size_t	len;

	len = ft_strlen(arg);
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

	flag->written += ft_putstrn(arg, flag->p);

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}
}

static void justify_right(char *arg, t_data *flag)
{
	// printf("\n");

	int		w;
	size_t	len;

	len = ft_strlen(arg);
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

	while (w > 0)
	{
		write(1, " ", 1);
		++flag->written;
		--w;
	}

	flag->written += ft_putstrn(arg, flag->p);
}

// Undefined flags: #, 0, ' ', +
// Applicable flags: -
// Precision: maximum amount of characters
void	output_str(char *arg, t_data *flag)
{
	if (flag->bit & FLAG_JUSTIFY_LEFT)
		justify_left(arg, flag);
	else
		justify_right(arg, flag);
}
