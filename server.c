/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:32 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/23 13:40:22 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//SIUSR1 = 1
//SIGUSR2 = 0


int main(int ac, char **av)
{
    if (ac != 1)
    {
        ft_putendl_fd("Error invalid input.", 2);
        return(EXIT_ERROR)
    }
    ft_printf("Server PID: %d\n", getpid());
    while(1)
        pause();

    return (EXIT_SUCCESS);
}