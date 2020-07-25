#include "ft_printf.h"

int			output_pointer(void *arg, t_data *flag)
{
	printf("\n{output_pointer: '%lld', w%d p%d}\n", arg, flag->width, flag->precision);

}
