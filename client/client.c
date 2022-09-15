/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/09/12 18:38:58 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void    send_nbr(int pid, int nb, int cpt)
{
    if (cpt == 8)
        return ;
    else if (nb % 2 == 0)
    {
        send_nbr(pid, nb / 2, ++cpt);
        usleep(200);
        kill(pid, SIGUSR1);
    }
    else if (nb % 2 == 1)
    {
        send_nbr(pid, nb / 2, ++cpt);
        usleep(200);
        kill(pid, SIGUSR2);
    }
}

int main(int argc, char **argv)
{
    int i;
    int nb;

    i = 0;
    if (argc != 3)
        return (0);
    send_nbr(atoi(argv[1]), strlen(argv[2]), 0);
    while (argv[2][i])
    {
        send_nbr(atoi(argv[1]), (int)(argv[2][i]), 0);
        i++;
    }
    send_nbr(atoi(argv[1]), (int)(argv[2][i]), 0);
}
