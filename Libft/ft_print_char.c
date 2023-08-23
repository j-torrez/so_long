/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnbosco <johnbosco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:31:14 by johnbosco         #+#    #+#             */
/*   Updated: 2023/06/14 17:05:20 by johnbosco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The reason for returning 1 in this case is to indicate 
the number of characters written successfully Dd.*/

#include	"ft_printf.h"

int	ft_putchar(char c)
{	
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
