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

void    ft_init(sigset_t *set, struct sigaction *sig)
{
    sigemptyset(set);
    sigaddset(set, SIGUSR1);
    sigaddset(set, SIGUSR1);
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
}

int main ()
{
    sigset_t    set;
    struct sigaction    sig;
    char    str[10000];
    int nb;
    int cpt;
    printf("PID = %u\n\n",getpid());
    ft_init(&set, &sig);
    c = 0;
    nb = 8;
    while (nb--)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
    printf("%i\n\n", (unsigned char)c);
    //str = malloc(sizeof(char) * ((unsigned char)c + 1));
    cpt = 0;
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
        str[cpt++] = c;
    }
    printf("%s\n", str);
    //free(str);
    exit(EXIT_SUCCESS);
}
