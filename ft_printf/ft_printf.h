/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:26:48 by nkim              #+#    #+#             */
/*   Updated: 2021/09/20 19:41:11 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

void ft_putunnbr(unsigned int nbr);
void ft_putunnbr_hex(unsigned long long nbr, char *base);
void print_c(int arg);
void print_s(char *arg);
void print_decimal(int arg);
void print_un_decimal(unsigned int arg);
void print_pointer(unsigned long long arg);
void print_un_hex(unsigned long long arg, char type);

#endif