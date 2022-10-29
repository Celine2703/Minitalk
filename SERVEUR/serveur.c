/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:07 by molich            #+#    #+#             */
/*   Updated: 2022/10/29 14:49:03 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "../Libft/libft.h"

void	ft_init(void)
{
	struct sigaction	sig;

	sigemptyset(&(sig.sa_mask));
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
}

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == SIGUSR1)
		g_c = 2 * g_c + 0;
	else if (signum == SIGUSR2)
		g_c = 2 * g_c + 1;
	usleep(150);
	kill(info->si_pid, SIGUSR1);
}

char	*ft_strjoin_char(char const *s1, char s2)
{
	int		i;
	char	*final;
	int		taille;

	if (!s1)
	{
		final = malloc(sizeof(char) * (1 + 1));
		final[0] = s2;
		final[1] = '\0';
		return (final);
	}
	taille = ft_strlen(s1) + 1;
	final = malloc(sizeof(char) * (taille + 1));
	if (final == 0)
		return (0);
	i = 0;
	while (s1 && s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	final[i++] = s2;
	final[i] = '\0';
	return (final);
}

int	main(void)
{
	char				*str;
	char				*temp;
	int					nb;

	ft_printf("PID = %u\n", getpid());
	ft_init();
	while (1)
	{
		str = NULL;
		g_c = 1;
		while (g_c > 0)
		{
			g_c = 0;
			nb = 8;
			while (nb-- && g_c >= 0)
				pause();
			temp = ft_strjoin_char(str, g_c);
			free(str);
			str = temp;
		}
		if (g_c == -1 || !ft_strncmp(str, "EXIT", 5))
			return (free(str), 0);
		ft_putendl_fd(str, 1);
		free(str);
	}
}
