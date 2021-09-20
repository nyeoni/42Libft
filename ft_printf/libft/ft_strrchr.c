/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:25:51 by nkim              #+#    #+#             */
/*   Updated: 2021/06/19 19:15:08 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int	size;
	int	i;

	size = ft_strlen(src);
	if (c == 0)
		return (char *)&src[size];
	i = 0;
	while (i < size)
	{
		if (src[size - i - 1] == (char)c)
			return (char *)&src[size - i - 1];
		i++;
	}
	return (0);
}
