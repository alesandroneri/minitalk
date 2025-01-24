/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:35 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/24 15:26:44 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, unsigned char signal)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (signal & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	int		bit;
	int		i;
	char	*msg;

	if (ac != 3)
	{
		ft_putendl_fd("Error invalid number of inputs.", 2);
		return (EXIT_ERROR);
	}
	if ((ac == 3 && !av[1][0]) || (ac == 3 && !av[2][0]))
	{
		ft_putendl_fd("Error invalid pid or invalid message.", 2);
		return (EXIT_ERROR);
	}
	i = -1;
	while (av[1][++i] != '\0')
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_putendl_fd("Error invalid pid.", 2);
			return (EXIT_ERROR);
		}
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid < 0 || !server_pid)
	{
		ft_putendl_fd("Error invalid pid.", 2);
		return (EXIT_ERROR);
	}
	msg = av[2];
	bit = 7;
	i = -1;
	while (av[2][++i] != '\0')
		send_signal(server_pid, msg[i]);
	return (EXIT_SUCCESS);
}
