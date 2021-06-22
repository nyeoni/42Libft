/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:35:06 by nkim              #+#    #+#             */
/*   Updated: 2021/06/22 23:23:31 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	if (!str)
		return (0);
	if (!(tmp = malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len && start < ft_strlen(str))
	{
		tmp[i] = str[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
