/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:00:46 by cmartin-          #+#    #+#             */
/*   Updated: 2022/10/15 18:40:52 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		ft_flag(int i, const char *str, va_list args);
int		ft_print_c(va_list args);
int		ft_print_s(va_list args);
int		ft_print_p(va_list args);
int		ft_print_di(va_list args);
int		ft_print_u(va_list args);
int		ft_print_x(va_list args);
int		ft_print_xx(va_list args);
int		ft_nbr_size_u(long unsigned int nb, long unsigned int taille);
int		ft_nbr_size(long int nb, long int taille);
void	ft_putnbr_base(long int nbr, char *base, int taille, int u);

#endif
