/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/09/12 10:49:45 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    send_nbr(int pib, int nb, int cpt)
{
    if (cpt == 8)
        return ;
    else if (nb % 2 == 0)
    {
        send_nbr(pib, nb / 2, ++cpt);
        usleep(130);
        kill(pib, SIGUSR1);
    }
    else if (nb % 2 == 1)
    {
        send_nbr(pib, nb / 2, ++cpt);
        usleep(130);
        kill(pib, SIGUSR2);
    }
}

int main(int argc, char **argv)
{
    int i;
    int nb;

    i = 0;
    if (argc != 3)
        return (0);
    while (argv[2][i])
    {
        send_nbr(atoi(argv[1]), (int)(argv[2][i]), 0);
        i++;
    }
}
