/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:32 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/24 15:27:35 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// SIUSR1 = 1
// SIGUSR2 = 0

void deal_signal(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("Signal received: SIGUSR1\n");
    else
        ft_printf("Signal received: SIGUSR2\n");
}
void signal_handler(int signum)
{
    char c;
    int bit;

    bit = 0;
    if (signum == SIGUSR1)
        c |= ((1 >> bit) == 1);
    else
        c &= ((1 >> bit) == 0);
    ++bit;
    if (bit == 8)
    {
        bit = 0;
        if (c == '\0')
            ft_putchar_fd('\n', 1);
    }
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_putendl_fd("Error invalid number of inputs.", 2);
		return (EXIT_ERROR);
	}
    ft_printf("---------- SERVER ON ...\n");
	ft_printf("Server PID: %d\n", getpid());

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
	while (1)
		pause();
    ft_printf("---------------SERVER OFF------------\n");
	return (EXIT_SUCCESS);
}