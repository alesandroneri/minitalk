/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:36:22 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/27 19:31:20 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

int	check_arguments(int ac, char **av)
{
	char	*pid;

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
	pid = av[1];
	while (*av[1])
	{
		if (!ft_isdigit(*av[1]))
		{
			ft_putendl_fd("Error invalid pid.", 2);
			return (EXIT_ERROR);
		}
		av[1]++;
	}
	return (ft_atoi(pid));
}

void	send_signal(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("Error sending SIGUSR1", 2);
				exit(EXIT_ERROR);
			}
			usleep(500);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("Error sending SIGUSR2", 2);
				exit(EXIT_ERROR);
			}
			usleep(500);
		}
		bit--;
		usleep(1500);
	}
}

int	main(int ac, char **av)
{
	int		server_pid;
	char	*msg;
	int		i;

	server_pid = check_arguments(ac, av);
	if (server_pid <= 0)
		return (EXIT_ERROR);
	msg = av[2];
	i = -1;
	while (msg[++i] != '\0')
		send_signal(server_pid, msg[i]);
	send_signal(server_pid, '\0');
	return (EXIT_SUCCESS);
}
