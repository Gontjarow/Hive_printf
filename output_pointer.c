#include "ft_printf.h"

void	output_pointer(void *arg, t_data *flag)
{
	printf("\n{output_pointer: '%p', w%d p%d}\n", arg, flag->width, flag->precision);
}
