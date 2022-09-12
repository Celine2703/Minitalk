/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:58:07 by molich            #+#    #+#             */
/*   Updated: 2022/09/12 10:51:26 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int main ()
{
    sigset_t    set;
    struct sigaction    sig;
    c = 0;
    printf("PID = %u\n\n",getpid());
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    sig.sa_handler = handler;
    int cpt = 50;
    while (cpt --)
    {
        c = 0;
        int nb = 8;
        while (nb)
        {
            sigaction(SIGUSR1, &sig, NULL);
            sigaction(SIGUSR2, &sig, NULL);
            pause();
            nb --;
        }
        printf("%c", c);
    }
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