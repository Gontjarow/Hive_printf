/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:54:29 by ngontjar          #+#    #+#             */
/*   Updated: 2020/02/25 20:18:34 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	try_parsing(const char *format, t_flag *flag);

int			ft_printf(const char *format, ...)
{
	t_flag	flag;
	char	bytes;

	flag = (t_flag){{{0}}, 0, 0, 0, 0};
	va_start(flag.ap, format);
	while (*format)
	{
		//printf("\treading str: %c\n", *format);
		if (*format == '%')
		{
			////printf("\tTry parsing...\n");
			bytes = 1;
			flag.pad = 0;
			flag.width = 0;
			flag.precision = 0;
			flag.type = 0;
			bytes += try_parsing(format, &flag);
			format += bytes;
			//printf("\tskipping to %c after parse.\n", *format);
			continue ;
		}
		write(1, format, 1);
		++format;
	}
	va_end(flag.ap);
	return (0);
}

static char	try_parsing(const char *format, t_flag *flag)
{
	char	parsed;
	int		written;

	if (0 == (parsed = parse_format(++format, flag)))
	{
		//printf("\tparse_format said NO!\n");
		return (0);
	}

	// printf("\tLet's see what it is...\n");
	if (flag->type == 's')
		written = output_str(va_arg(flag->ap, char *), flag);
	else if (strcany("dci", flag->type))
		written = output_int(va_arg(flag->ap, int), flag);
	else if (strcany("Xxuo", flag->type))
		written = output_uint(va_arg(flag->ap, unsigned int), flag);

	//printf("\tParsed: %d\n", parsed);
	return (parsed);
}

int			main(int argc, char **argv)
{
	(void)argc; (void)argv;

	ft_putendl("wrong flags");
	printf("|%5.d|\n", 0);
	ft_printf("|%5.d|\n", 0);
	ft_putendl("");

	// ft_putendl("asterisk");
	// printf("real> %%*s 15 		|%*s|\n", 15, "hello world");
	// ft_printf("mine> %%*s 15 		|%*s|\n", 15, "hello world");
	// ft_putendl("");

	// printf("real> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_printf("mine> %%-*s 15 	|%-*s|\n", 15, "hello world");
	// ft_putendl("");

	// printf("real> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_printf("mine> %%*s -15 	|%*s|\n", -15, "hello world");
	// ft_putendl("");

	// printf("real> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_printf("mine> %%-*s -15 	|%-*s|\n", -15, "hello world");
	// ft_putendl("");

	// printf("real> |%s %% %s|\n", "hello", "world");
	// ft_printf("mine> |%s %% %s|\n", "hello", "world");
	// ft_putendl("");

	// ft_putendl("regular string");
	// printf("real> |%s, and good night|\n", "hello world");
	// ft_printf("mine> |%s, and good night|\n", "hello world");
	// ft_putendl("");

	// ft_putendl("null string");
	// printf("real> |%s, and good night|\n", NULL);
	// ft_printf("mine> |%s, and good night|\n", NULL);
	// ft_putendl("");

	// ft_putendl("width positive");
	// printf("real> |%15s, and good night|\n", "hello world");
	// ft_printf("mine> |%15s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%15s, and good night|\n", NULL);
	// ft_printf("mine> |%15s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("real> |%1s, and good night|\n", "hello world");
	// ft_printf("mine> |%1s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%1s, and good night|\n", NULL);
	// ft_printf("mine> |%1s, and good night|\n", NULL);
	// ft_putendl("");

	// ft_putendl("width negative");
	// printf("real> |%-15s, and good night|\n", "hello world");
	// ft_printf("mine> |%-15s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%-15s, and good night|\n", NULL);
	// ft_printf("mine> |%-15s, and good night|\n", NULL);
	// ft_putendl("");

	// printf("real> |%-1s, and good night|\n", "hello world");
	// ft_printf("mine> |%-1s, and good night|\n", "hello world");
	// ft_putendl("");

	// printf("real> |%-1s, and good night|\n", NULL);
	// ft_printf("mine> |%-1s, and good night|\n", NULL);
	// ft_putendl("");
}
