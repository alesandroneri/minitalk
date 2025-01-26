/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:35 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/26 15:37:33 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void send_signal(int pid, unsigned char c)
{
    int bit = 7;

    // Envia os bits do caractere, um por um
    while (bit >= 0)
    {
        if (c & (1 << bit)) // Se o bit atual é 1, envia SIGUSR1
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                perror("Error sending SIGUSR1");
                exit(EXIT_FAILURE);
            }
        }
        else // Caso contrário, envia SIGUSR2
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                perror("Error sending SIGUSR2");
                exit(EXIT_FAILURE);
            }
        }
        bit--;
        usleep(100); // Pequeno delay para evitar perda de sinais
    }
}

int	main(int ac, char **av)
{
	int		server_pid;
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
		if (!ft_isdigit(av[1][i]))
		{
			ft_putendl_fd("Error invalid pid.", 2);
			return (EXIT_ERROR);
		}
	server_pid = ft_atoi(av[1]);
	if (server_pid < 0 || !server_pid)
	{
		ft_putendl_fd("Error invalid pid.", 2);
		return (EXIT_ERROR);
	}
	msg = av[2];
	while (*msg)
    {
        send_signal(server_pid, *msg); // Envia cada caractere da mensagem
        msg++;
    }
	send_signal(server_pid, '\0');
	return (EXIT_SUCCESS);
}
