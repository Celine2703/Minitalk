/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/10/15 18:25:55 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_nbr(int pid, int nb, int cpt)
{
	if (cpt == 8)
		return ;
	else if (nb % 2 == 0)
	{
		send_nbr(pid, nb / 2, ++cpt);
		usleep(400);
		kill(pid, SIGUSR1);
	}
	else if (nb % 2 == 1)
	{
		send_nbr(pid, nb / 2, ++cpt);
		usleep(400);
		kill(pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int			i;
	char		*verif;
	long int	pid;

	i = 0;
	if (argc != 3)
		return (0);
	verif = ft_itoa(ft_atoi(argv[1]));
	if (ft_strncmp(verif, argv[1], strlen(argv[1])) != 0)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > INT_MAX || kill(pid, 0) == -1)
		return (0);
	while (argv[2][i])
	{
		send_nbr(pid, (int)(argv[2][i]), 0);
		i++;
	}
	send_nbr(pid, (int)(argv[2][i]), 0);
}
