/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:17 by molich            #+#    #+#             */
/*   Updated: 2022/10/29 14:43:37 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <limits.h>
# include "../Libft/libft.h"

void	handler(int sig, siginfo_t *siginfo, void *context);
void	send_nbr(int pid, int nb, int cpt);

#endif