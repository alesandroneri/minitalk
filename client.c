/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneri-da <aneri-da@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:31:35 by aneri-da          #+#    #+#             */
/*   Updated: 2025/01/23 14:29:17 by aneri-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_bits(unsigned char octet)
{
    int bit;

    bit = 7;
    while (bit-- >= 0)
    {
        if (octet & (1 << bit))
            ft_putchar_fd('1', 1);
        else
            ft_putchar_fd('0', 1);
    }
}
int main(void)
{
    print_bits(1);
    return (0);
}

// int main(int ac, char **av)
// {
//     if (ac != 3)
//     {
//         ft_putendl_fd("Error invalid input.", 2);
//         return (EXIT_ERROR);
//     }
//     int server_pid;
//     int bit;
//     char *msg;

//     server_pid = ft_atoi(av[1]);
//     msg = av[2];
//     bit = 0;
//     while (++bit <= 8)
//     {

//     }
//     return (EXIT_SUCCESS);
// }