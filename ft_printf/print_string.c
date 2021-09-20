/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:48:31 by nkim              #+#    #+#             */
/*   Updated: 2021/09/18 16:26:17 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_c(int arg) {
  char c;

  c = (char)arg;
  ft_putchar_fd(c, 1);
}

void print_s(char *arg) {
  if (!arg)
    ft_putstr_fd("(null)", 1);
  else
    ft_putstr_fd(arg, 1);
}