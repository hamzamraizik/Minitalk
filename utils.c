/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:50:49 by hmraizik          #+#    #+#             */
/*   Updated: 2024/05/26 18:06:25 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	usage(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
	write(2, "\n", 1);
	exit(1);
}

void	put_nbr(long nbr)
{
	unsigned char	res;

	res = 0;
	if (nbr > 9)
		put_nbr(nbr / 10);
	res = (nbr % 10) + '0';
	write(1, &res, 1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;
	int		number;
	long	i;

	sign = 1;
	result = 0;
	number = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = number * 10 + str[i++] - '0';
		if ((result < number && sign == 1) || (-result > number && sign == -1))
			return (-1);
		number = result;
	}
	if (str[i])
		return (-1);
	return (result * sign);
}
