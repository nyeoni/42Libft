/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 18:31:07 by nkim              #+#    #+#             */
/*   Updated: 2021/05/07 20:33:52 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_sep(char s, char c)
{
    int i;
    i = 0;

    if (s == c)
        return 1;
    return 0;
}
int get_address_cnt(char const *s, char c)
{
    int cnt;
    
    cnt = 0;
    while (*s)
    {
        if (*s == c)
        {
            s++;
            while (*s == )
        }
    }
}

char **ft_split(char const *s, char c)
{
    char **res;
    
}