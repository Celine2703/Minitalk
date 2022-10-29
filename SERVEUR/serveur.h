/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartin- <cmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:17 by molich            #+#    #+#             */
/*   Updated: 2022/10/29 14:34:06 by cmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../Libft/libft.h"

static char	g_c;

void	ft_init(void);
void	handler(int signum, siginfo_t *info, void *ucontext);
char	*ft_strjoin_char(char const *s1, char s2);

#endif