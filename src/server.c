/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:32 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/26 16:07:40 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// SIUSR1 = 1
// SIGUSR2 = 0

// void deal_signal(int signum)
// {
//     if (signum == SIGUSR1)
//         ft_printf("Signal received: SIGUSR1\n");
//     else
//         ft_printf("Signal received: SIGUSR2\n");
// }
#include "../includes/minitalk.h"

void signal_handler(int signum, siginfo_t *info, void *context)
{
    static char c = 0;
    static int bit = 0;
    //static pid_t server;
    
    //server = info->si_pid;
    (void)context;
    if (signum == SIGUSR1)
        c |= (1 << (7 - bit));
    else
        c &= ~(1 << (7 - bit));
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
        {
            ft_putchar_fd('\n', 1);
            kill(info->si_pid, SIGUSR1);
        }
        else
            ft_putchar_fd(c, 1);
        c = 0;
        bit = 0;
    }
}

// void set_signal(int sig, void *dealer, int now)
// {
//     struct sigaction sa;

//     if(now == 1)
//     {
//         sa.sa_flags = SA_SIGINFO;
//         sa.sa_sigaction = signal_handler;
//     }
//     else
//         sa.sa_handler = signal_handler;
//     sigemptyset(&sa.sa_mask);
//     sigaddset(&sa.sa_mask, SIGUSR1);
//     sigaddset(&sa.sa_mask, SIGUSR2);
//     if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
//     {
//         ft_putendl_fd("Error signal failed.", 2);
//         exit(EXIT_ERROR);
//     }


// }

int	main(int ac, char **av)
{
    // struct sigaction sa = {0};

    // (void)av;
    // sa.sa_flags = SA_SIGINFO;
    // sa.sa_handler = signal_handler;
    // sigemptyset(&sa.sa_mask);
	if (ac != 1)
	{
		ft_putendl_fd("Error invalid number of inputs.", 2);
		return (EXIT_ERROR);
	}
    // if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
    // {
    //     ft_putendl_fd("Error signal failed.", 2);
    //     return(EXIT_ERROR);
    // }
    ft_printf("---------- SERVER ON ...\n");
	ft_printf("Server PID: %d\n", getpid());
    set_signal(SIGUSR1, signal_handler, 1);
    set_signal(SIGUSR2, signal_handler, 1);

	while (1)
		pause();
    ft_printf("---------------SERVER OFF------------\n");
	return (EXIT_SUCCESS);
}