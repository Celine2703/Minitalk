/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celine <celine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:17 by molich            #+#    #+#             */
/*   Updated: 2022/09/11 12:34:08 by celine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H
 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

static char c;

char   sent_sig(int signum);
void    handler(int entier);

#endif