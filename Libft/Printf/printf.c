/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:59:50 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/18 13:59:52 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag(int i, const char *str, va_list args)
{
	if (str[i] == 'c')
		return (ft_print_c(args));
	else if (str[i] == 's')
		return (ft_print_s(args));
	else if (str[i] == 'p')
		return (ft_print_p(args));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_print_di(args));
	else if (str[i] == 'u')
		return (ft_print_u(args));
	else if (str[i] == 'x')
		return (ft_print_x(args));
	else if (str[i] == 'X')
		return (ft_print_xx(args));
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cpt;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else
			cpt += ft_flag(++i, str, args) - 1;
		i++;
		cpt++;
	}
	return (cpt);
}
