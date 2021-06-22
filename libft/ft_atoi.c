/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:36:34 by nkim              #+#    #+#             */
/*   Updated: 2021/06/18 19:32:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ctoi(char c)
{
	int	res;

	res = c - '0';
	return (res);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	is_minus;
	int	i;

	i = 0;
	is_minus = 1;
	while (is_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_minus = -1;
		i++;
	}
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + ctoi(str[i]);
		i++;
	}
	return (is_minus * res);
}
