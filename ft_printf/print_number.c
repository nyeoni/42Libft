/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:39:33 by nkim              #+#    #+#             */
/*   Updated: 2021/09/20 19:41:18 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_decimal(int arg) { ft_putnbr_fd(arg, 1); }

void print_un_decimal(unsigned int arg) {
  int un;

  un = arg;
  if (un < 0)
    un = arg | 0x7fffffff;

  ft_putunnbr(un);
}

void print_un_hex(unsigned long long arg, char type) {
  char *base;

  if (type == 'X')
    base = "0123456789ABCDEF";
  else
    base = "0123456789abcdef";
  ft_putunnbr_hex(arg, base);
}

void print_pointer(unsigned long long arg) {
  char *base;

  base = "0123456789abcdef";
  write(1, "0x", 2);
  ft_putunnbr_hex(arg, base);
}