/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:57:35 by cmartin-          #+#    #+#             */
/*   Updated: 2022/02/10 22:00:57 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_size_u(long unsigned int nb, long unsigned int taille)
{
	int	cpt;

	cpt = 1;
	while (nb / taille)
	{
		nb = nb / taille;
		cpt++;
	}
	return (cpt);
}

int	ft_nbr_size(long int nb, long int taille)
{
	int	cpt;

	cpt = 1;
	if (nb < 0)
		cpt++;
	while (nb / taille)
	{
		nb = nb / taille;
		cpt++;
	}
	return (cpt);
}

static void	ft_putnbr_u(unsigned long int nb,
		char *base, unsigned long int taille)
{
	if (nb > taille - 1)
	{
		ft_putnbr_u(nb / taille, base, taille);
		nb = nb % taille;
	}
	write(1, (&base[nb]), 1);
}

static void	ft_putnbr(long int nb, char *base, long int taille)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	ft_putnbr_u(nb, base, taille);
}

void	ft_putnbr_base(long int nbr, char *base, int taille, int u)
{
	long int	nb;

	if (u == 1)
	{
		nb = (unsigned long int)nbr;
		ft_putnbr_u(nb, base, taille);
	}	
	else
	{
		nb = nbr;
		ft_putnbr(nb, base, taille);
	}
}
