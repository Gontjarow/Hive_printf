#include "ft_printf.h"

void	putstr_case(const char *str, int mode)
{
	int		i;
	char	c;

	if (mode == 0)
		ft_putstr(str);
	else
	{
		if (str == NULL)
			return ;
		i = 0;
		while (str[i])
		{
			if (mode < 0)
				c = ft_tolower(str[i]);
			else
				c = ft_toupper(str[i]);
			write(1, &c, 1);
			++i;
		}
	}
}

int		width_padder(int length, t_data *flag, long long arg)
{
	// printf("width_padder: {length:%d, width:%d, arg:%lld}\n", length, flag->width, arg);
	if (flag->width > 0)
	{
		// printf("has width\n");
		if (flag->precision > 0 && flag->precision < flag->width
			&& flag->type != 'c')
		{
			// printf("Has precision but less than width {%d -= ", flag->width);
			flag->width -= flag->precision + (arg < 0);
			// printf("%d + %d = %d}\n", flag->precision, (arg < 0), flag->width);
		}
		else if (flag->precision >= flag->width
			&& flag->type != 'c')
		{
			flag->width = 0;
			// printf("Has precision greater than width\n");
		}
		else if (length < flag->width)
		{
			// printf("precision {%d}\n", flag->precision);
			// printf("Has width greater than length {%d -= ", flag->width);
			flag->width -= length + (arg < 0);
			// printf("%d + %d = %d}\n", length, (arg < 0), flag->width);
		}
		else if (length >= flag->width)
		{
			flag->width = 0;
		}
	}
	if (~flag->bit & FLAG_JUSTIFY_LEFT)
	{
		while (flag->width > 0)
		{
			write(1, (flag->bit & FLAG_PAD_ZERO ? "0" : " "), 1); //! 'u'
			++flag->written;
			--flag->width;
		}
	}
	return (0);
}

int		zero_padder(int length, t_data *flag, long long arg)
{
	if (flag->type == 'd' || flag->type == 'i')
	{
		write(1, "-", (arg < 0)); // changed // todo: test!
		flag->written += (arg < 0);
	}
	if (flag->precision > 0)
	{
		// printf("TEST %d < %d\n", length, flag->precision);
		if (length < flag->precision)
			flag->precision -= length;
		else
			flag->precision = 0;
	}
	while (flag->precision > 0)
	{
		write(1, "0", 1);
		++flag->written;
		--flag->precision;
	}
	return (0);
}

void	ft_putnstr(char *str, int bytes)
{
	char	buffer[129];
	int		i;
	int		c;

	// printf("putnstr: {'%s', %d}\n", str, bytes);
	if (!str || bytes <= 0)
		return ;
	i = 0;
	while (bytes && str[i])
	{
		c = 0;
		while (bytes && c < 128 && str[i])
		{
			buffer[c++] = str[i];
			--bytes;
			++i;
		}
		buffer[i] = '\0';
		write(1, buffer, i);
		// bytes -= i;
	}
}
