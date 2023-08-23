/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:40:43 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/05/12 17:02:40 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void *s: a pointer to the block of memory to set, (void --> any data type)
// int c: the value to set each byte to
// size_t n: the number of byte to set to
// Filled the array with the character for each iteration
// return s, because point to the start of memory block that was filled (newstr)

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i++] = c;
	}
	return (s);
}
/*
int main(void)
{
	char s[50] = "Hello World!";
	printf("Before memset(): %s\n", s);

	ft_memset(s, 'z', 5); //fill with z
	printf("After memset(): %s\n", s);

	return 0;
}*/
