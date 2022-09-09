/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molich <molich@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/09/09 17:43:26 by molich           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
    sigset_t    set;
    if (argc != 3)
        return (0);
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);
    kill(atoi(argv[1]), 1);
}

sigghandler int signum
if signum == SIGUSR1
    char +=1

chqr *=2;