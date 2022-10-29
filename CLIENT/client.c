/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/10/29 14:49:06 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_init(struct sigaction *sig)
{
	sig ->sa_flags = SA_SIGINFO;
	sigemptyset(&(sig ->sa_mask));
	sig ->sa_sigaction = handler ;
	sigaction(SIGUSR1, sig, NULL);
	sigaction(SIGUSR2, sig, NULL);
}

void	handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)sig;
	(void)siginfo;
	usleep(150);
}

void	send_nbr(int pid, int nb, int cpt)
{
	if (cpt == 8)
		return ;
	else if (nb % 2 == 0)
	{
		send_nbr(pid, nb / 2, ++cpt);
		kill(pid, SIGUSR1);
	}
	else if (nb % 2 == 1)
	{
		send_nbr(pid, nb / 2, ++cpt);
		kill(pid, SIGUSR2);
	}
	pause();
}

int	main(int argc, char **argv)
{
	int					i;
	char				*verif;
	long int			pid;
	struct sigaction	sig;

	ft_init(&sig);
	i = 0;
	if (argc != 3)
		return (0);
	verif = ft_itoa(ft_atoi(argv[1]));
	if (ft_strncmp(verif, argv[1], strlen(argv[1])) != 0)
		return (free(verif), 0);
	free(verif);
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
