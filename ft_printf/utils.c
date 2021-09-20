/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:40:28 by nkim              #+#    #+#             */
/*   Updated: 2021/09/20 19:41:00 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putunnbr(unsigned int nbr) {
  char tmp;

  if (nbr < 10)
    tmp = '0' + nbr;
  else {
    ft_putunnbr(nbr / 10);
    tmp = '0' + (nbr % 10);
  }
  write(1, &tmp, 1);
}

void ft_putunnbr_hex(unsigned long long nbr, char *base) {
  char tmp;

  if (nbr < 0x10)
    tmp = base[nbr];
  else {
    ft_putunnbr_hex(nbr / 0x10, base);
    tmp = base[nbr % 0x10];
  }
  write(1, &tmp, 1);
}