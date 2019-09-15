/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 11:39:20 by dberger           #+#    #+#             */
/*   Updated: 2019/09/15 14:17:05 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_double(char **argv, int k)
{
	int		i;
	int		j;

	i = 1;
	j = i + 1;
	if (k == 2)
		return (1);
	while (i < k - 1)
	{
		if (!ft_strcmp(argv[i], argv[j]))
			return (0);
		else
			j++;
		if (j == k && i < k)
		{
			i++;
			j = i + 1;
		}
	}
	return (1);
}

int		ft_min_max(int neg, int j, char *argv)
{
	if ((neg == 0 && j == 10))
		if (ft_strcmp(argv, "2147483647") > 0)
			return (0);
	if ((neg == -1 && j == 11))
		if (ft_strcmp(argv, "-2147483648") > 0)
			return (0);
	return (1);
}

/*
** Checks if the arguments are only numbers, not twice the same,
** Not bigger than an INT
*/

int		ft_check_arg(char **argv)
{
	int		j;
	int		i;
	int		neg;

	i = 1;
	while (argv[i])
	{
		j = 0;
		neg = 0;
		if ((argv[i][j] == '-' && (neg = -1) == -1 && argv[i][j + 1])
			|| (argv[i][j] == '+' && argv[i][j + 1]))
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9'
				|| (neg == 0 && j > 9) || (neg == -1 && j > 10))
				return (0);
			j++;
		}
		if (!(ft_min_max(neg, j, argv[i])))
			return (0);
		i++;
	}
	return (!(ft_check_double(argv, i)) ? 0 : 1);
}
