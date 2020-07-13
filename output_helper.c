#include "ft_printf.h"

void	putstr_case(const char *str, int mode)
{
	int		i;
	char	c;

	if (mode == 0)
		ft_putstr(str);
	else
	{
		if (str != NULL)
		{
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
}

int		width_padder(int length, t_data *flag, long long arg)
{
	int		written;

	// printf("length:%d, width:%d, arg:%lld\n", length, flag->width, arg);
	written = 0;
	if (flag->width > 0)
	{
		if (flag->precision > 0 && flag->precision < flag->width
			&& flag->type != 'c')
		{
			flag->width -= flag->precision + (arg < 0);
			// printf("Has precision but less than width\n");
		}
		else if (flag->precision >= flag->width
			&& flag->type != 'c')
		{
			flag->width = 0;
			// printf("Has precision greater than width\n");
		}
		else if (length < flag->width - 1)
		{
			flag->width -= length + (arg < 0);
			// printf("Has width greater than length\n");
			// printf("length (%d) < flag->width (%d)\n", length, flag->width - 1);
		}
		else if (length >= flag->width)
		{
			flag->width = 0;
		}
	}
	if (!(flag->bit & FLAG_JUSTIFY_LEFT))
	{
		while (flag->width > 0)
		{
			write(1, (flag->bit & FLAG_PAD_ZERO ? "0" : " "), 1); //! 'u'
			--flag->width;
			++written;
		}
	}
	return (written);
}

int		zero_padder(int length, t_data *flag, long long arg)
{
	int		written;

	if (flag->type == 'd' || flag->type == 'i')
	{
		// ft_putstr(arg < 0 ? "@" : "");
		write(1, (arg < 0 ? "-" : ""), written = (arg < 0));
	}
	if (flag->precision > 0)
	{
		if (length < flag->precision)
			flag->precision -= length;
		else
			flag->precision = 0;
	}
	while (flag->precision > 0)
	{
		write(1, "0", 1);
		--flag->precision;
		++written;
	}
	return (written);
}

void	ft_putnstr(char *str, int bytes)
{
	char	buffer[129];
	int		i;
	int		c;

	if (!str || bytes <= 0)
		return ;
	i = 0;
	while (bytes && str[i])
	{
		c = 0;
		while (c < 128 && str[i])
		{
			buffer[c] = str[i];
			++i;
		}
		buffer[i] = '\0';
		write(1, buffer, i);
		bytes -= i;
	}
}
