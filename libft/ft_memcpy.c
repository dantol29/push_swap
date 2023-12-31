/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:05:59 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/14 10:47:58 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcpy(int *dest, int *src, size_t n)
{
	size_t				i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char src[50] = "https://www.tutorialspoint.com";
    char dest[50] = "Heloooo!!";
    printf("Before memcpy dest = %s\n", dest);
    memcpy(dest, src, strlen(src) + 1);
    printf("After memcpy dest = %s\n", dest);
}*/