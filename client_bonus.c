/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:51:23 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/16 16:30:21 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_minitalk	g_mini = {NULL, 1};

void	convert_and_send(int server_pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		while (g_mini.waiting)
			;
		g_mini.waiting = 1;
		bit++;
	}
}

int	str_isdigit(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

void	signal_handler(int signal)
{
	static size_t	char_sent = 0;

	g_mini.waiting = 0;
	if (signal == SIGUSR2)
	{
		char_sent++;
		if (char_sent == ft_strlen(g_mini.s))
		{
			ft_putstr_fd(NOTIFICATION_R1, 1);
			ft_putendl_fd(NOTIFICATION_R2, 1);
			printf("\nYour message was : [%s]\n", g_mini.s);
			ft_putstr_fd(UNICODE, 1);
		}
	}
}

void	def_sigaction(void)
{
	struct sigaction	sa_action;

	sa_action.sa_handler = &signal_handler;
	sa_action.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa_action, NULL) == -1)
		ft_putendl_fd(SA_USR1_FAIL, 1);
	if (sigaction(SIGUSR2, &sa_action, NULL) == -1)
		ft_putendl_fd(SA_USR2_FAIL, 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	server_pid;

	g_mini.s = av[2];
	i = 0;
	server_pid = ft_atoi(av[1]);
	if (ac == 3 && str_isdigit(av[1]) && server_pid > 1)
	{
		ft_putendl_fd(C_NOTIFICATION, 1);
		def_sigaction();
		while (av[2][i])
		{
			convert_and_send(server_pid, av[2][i]);
			i++;
		}
		convert_and_send(server_pid, 10);
	}
	else
	{
		ft_putendl_fd(C_ERROR, 1);
		ft_putendl_fd(C_ARGS, 1);
		ft_putendl_fd(C_EX_ARGS, 1);
	}
	return (0);
}
