/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:37:20 by dtolmaco          #+#    #+#             */
/*   Updated: 2024/01/04 09:28:36 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result > 2147483647 || result < -2147483648 || ft_strlen(str) > 11) \
	&& ft_strcmp(str, "-2147483648") != 0)
		return (0);
	return (result * sign);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
    (void)argc;
    printf("%d\n", ft_atoi(argv[1]));
    printf("%d\n", atoi(argv[1]));
}*/