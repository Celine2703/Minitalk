/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:10:00 by molich            #+#    #+#             */
/*   Updated: 2022/09/11 12:47:24 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return (0);
    kill(atoi(argv[1]), SIGUSR2);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR1);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR1);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR1);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR1);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR2);
    sleep(1);
    kill(atoi(argv[1]), SIGUSR2);
    sleep(1);
}
