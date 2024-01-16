/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:31:23 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/16 15:48:18 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	new_handler(int signal, siginfo_t *siginfo, void *vd)
{
	static int	bit = 0;
	static int	i = 0;

	(void)siginfo;
	(void)vd;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		if (i == 10)
			ft_putstr_fd(S_CHEV, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putendl_fd(S_WLC, 1);
	printf(S_PID, pid);
	ft_putstr_fd(S_CHEV, 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = new_handler;
	sigemptyset(&sa.sa_mask);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
