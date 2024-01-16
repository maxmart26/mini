/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:30:21 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/16 15:31:10 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(200);
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

int	main(int ac, char **av)
{
	int	i;
	int	server_pid;

	i = 0;
	server_pid = ft_atoi(av[1]);
	if (ac == 3 && str_isdigit(av[1]) && server_pid > 1)
	{
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
