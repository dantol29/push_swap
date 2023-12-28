/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:10:57 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/11/16 14:23:13 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(int *a, int *b, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (1);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
    printf("%d", ft_memcmp("hella", "hellb", 4));
}*/