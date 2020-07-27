#include "ft_printf.h"

// todo: Separate 'c' from here? It has significant difference to 'd' and 'i'
void	output_int(long long arg, t_data *flag)
{
	// printf("\n{output_int: '%lld', w%d p%d}\n", arg, flag->width, flag->precision);
	if (flag->type == 'c')
		output_char(arg, flag);
}
