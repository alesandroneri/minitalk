/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:36:22 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/26 15:05:47 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void send_signal(int pid, unsigned char c)
{
    int bit;

    bit = 7;
    while (bit >= 0)
    {
        if (c & (1 << bit))
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                ft_putendl_fd("Error sending SIGUSR1", 2);
                return(EXIT_ERROR);
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                ft_putendl_fd("Error sending SIGUSR2", 2);
                return(EXIT_ERROR);
            }
        }
        bit--;
        usleep(100); // Garantir que o servidor tenha tempo de processar o sinal
    }
}

int main(int ac, char **av)
{
    int server_pid;
    char *msg;

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
	//i = -1;
	//while (av[1][++i] != '\0')
    while (*av[1]++ != '\0')
	{
		//if (!ft_isdigit(av[1][i]))
        if (!ft_isdigit(*av[1]))
		{
			ft_putendl_fd("Error invalid server PID.", 2);
			return (EXIT_ERROR);
		}
	}
    server_pid = ft_atoi(av[1]);
    if (server_pid <= 0)
    {
        ft_putendl_fd("Error invalid server PID.\n", 2);
        return (EXIT_FAILURE);
    }
    msg = av[2];
    while (*msg)
    {
        send_signal(server_pid, *msg++);
        //msg++;
    }
    send_signal(server_pid, '\0');
    return (EXIT_SUCCESS);
}
