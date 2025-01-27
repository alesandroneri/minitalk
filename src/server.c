/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:32 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/27 19:31:16 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)context;
	(void)info;
	if (signum == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (ac > 1)
	{
		ft_putendl_fd("Error invalid number of arguments.", 2);
		return (EXIT_ERROR);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putendl_fd("Error sigaction failed.", 2);
		return (EXIT_ERROR);
	}
	ft_printf("--- SERVER ON: \n");
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		;
	return (EXIT_SUCCESS);
}
