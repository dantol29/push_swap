/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:48:06 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/21 19:01:40 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_memcmp(int *a, int *b, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (a[i] != b[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_atoi(const char *str)
// {
// 	int	result;
// 	int	sign;
// 	int	i;

// 	i = 0;
// 	result = 0;
// 	sign = 1;
// 	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// void	ft_memcpy(int *dest, int *src, size_t n)
// {
// 	size_t				i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// }

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	print_stack(int *stack, int	size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, str + i, 1);
		i++;
	}
}