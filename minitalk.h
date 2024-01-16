/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:31:51 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:47 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "messages.h"
# include <stdio.h>

typedef struct s_mini
{
	char	*s;
	int		waiting;
}		t_minitalk;

/* *** client.c & bonus *** */

void	convert_and_send(int server_pid, char c);
int		str_isdigit(char *s);

/* *** server.c & bonus *** */

void	new_handler(int signal, siginfo_t *siginfo, void *vd);

#endif
