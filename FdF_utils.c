/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FdF_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bsomers <bsomers@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/22 10:42:37 by bsomers       #+#    #+#                 */
/*   Updated: 2022/06/09 17:35:27 by bsomers       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void    if_error(char *str)
{
    ft_putstr_fd("\033[0;\e[1mFdF Error: \e[0m", 2);
    ft_putstr_fd(str, 2);
    exit(EXIT_FAILURE);
}