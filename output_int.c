#include "ft_printf.h"

void	output_int(long long arg, t_data *flag)
{
	printf("\n{output_int: '%lld', w%d p%d}\n", arg, flag->width, flag->precision);
}
