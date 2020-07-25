#include "ft_printf.h"

int			output_str(char *arg, t_data *flag)
{
	printf("\n{output_str: '%s', w%d p%d}\n", arg, flag->width, flag->precision);
}
