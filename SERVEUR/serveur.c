/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:07 by molich            #+#    #+#             */
/*   Updated: 2022/09/12 18:37:49 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "../Libft/libft.h"

void    ft_init(sigset_t *set, struct sigaction *sig)
{
    sigemptyset(set);
    sig ->sa_handler = handler;
    sig ->sa_flags = 0;
    sig ->sa_mask = *set;
}

void    handler(int signum)
{
    if (signum == SIGUSR1)
        c = 2 * c + 0;
    else if (signum == SIGUSR2)
        c = 2 * c + 1;
    //printf("coucou\n\n");
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

int main ()
{
    sigset_t    set;
    struct sigaction    sig;
    char    *str;
    char    *temp;
    int nb;
    printf("PID = %u\n",getpid());
    ft_init(&set, &sig);
    while (1)
    {
        str = NULL;
        c = 1;
        while (c)
        {
            c = 0;
            nb = 8;
            while (nb--)
            {
                sigaction(SIGUSR1, &sig, NULL);
                sigaction(SIGUSR2, &sig, NULL);
                pause();
            }
            temp = ft_strjoin_char(str, c);
            free(str);
            str = NULL;
            str = temp;
        }
        printf("%s\n", str);
        if (!ft_strncmp(str, "EXIT", 5))
        {
            free(str);
            exit(EXIT_SUCCESS);
        }
        free(str);
        str = NULL;
    }
}

//ctrl C