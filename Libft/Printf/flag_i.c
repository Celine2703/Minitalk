/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:56:53 by cmartin-          #+#    #+#             */
/*   Updated: 2022/05/18 15:56:55 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(va_list args)
{
	unsigned long int	adress;

	adress = (unsigned long int)va_arg(args, void *);
	if (!adress)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putnbr_base(adress, "0123456789abcdef", 16, 1);
	return (ft_nbr_size_u(adress, 16) + 2);
}

int	ft_print_di(va_list args)
{
	int	decimal;

	decimal = va_arg(args, int);
	ft_putnbr_base(decimal, "0123456789", 10, 0);
	return (ft_nbr_size(decimal, 10));
}

int	ft_print_u(va_list args)
{
	unsigned int	decimal;

	decimal = va_arg(args, int);
	ft_putnbr_base(decimal, "0123456789", 10, 1);
	return (ft_nbr_size_u(decimal, 10));
}

int	ft_print_x(va_list args)
{
	unsigned int	hexadecimal;

	hexadecimal = va_arg(args, int);
	ft_putnbr_base(hexadecimal, "0123456789abcdef", 16, 1);
	return (ft_nbr_size_u(hexadecimal, 16));
}

int	ft_print_xx(va_list args)
{
	unsigned int	hexadecimal;

	hexadecimal = va_arg(args, int);
	ft_putnbr_base(hexadecimal, "0123456789ABCDEF", 16, 1);
	return (ft_nbr_size_u(hexadecimal, 16));
}
