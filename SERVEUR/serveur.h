/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:17 by molich            #+#    #+#             */
/*   Updated: 2022/10/15 18:39:37 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../Libft/libft.h"

static char	g_c;

void	ft_init(struct sigaction *sig);
void	handler(int signum);

#endif