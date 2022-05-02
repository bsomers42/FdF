/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:42:37 by bsomers       #+#    #+#                 */
/*   Updated: 2022/04/22 14:10:26 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void    if_error(char *str)
{
    ft_putstr_fd("\033[0;\e[1mError:\e[0m", 2);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}