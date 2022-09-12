/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:07 by molich            #+#    #+#             */
/*   Updated: 2022/09/12 14:46:15 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int main ()
{
    sigset_t    set;
    struct sigaction    sig;
    int nb;
    char    str[100];
    c = 0;
    printf("PID = %u\n\n",getpid());
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sig.sa_handler = handler;
    int cpt = 0;
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
        printf("%c\n", c);
        str[cpt++] = c;
    }
    printf("%s\n", str);
    exit(EXIT_SUCCESS);
}

void    handler(int signum)
{
    if (signum == SIGUSR1)
        c = 2 * c + 0;
    else if (signum == SIGUSR2)
        c = 2 * c + 1;
}

/*char   sent_sig(int signum)
{
    char    c;
    
    c = 0;
    if (signum == SIGUSR1)
        c = 2 * c + 0;
    else if (signum == SIGUSR2)
        c = 2 * c + 1;
    return (c); 
}*/