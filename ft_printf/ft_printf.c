/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:21:06 by nkim              #+#    #+#             */
/*   Updated: 2021/09/20 19:41:40 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void print_format(va_list ap, const char *format) {
  if (*format == 'c')
    print_c(va_arg(ap, int));
  else if (*format == 's')
    print_s(va_arg(ap, char *));
  else if (*format == 'd' || *format == 'i')
    print_decimal(va_arg(ap, int));
  else if (*format == 'u')
    print_un_decimal(va_arg(ap, int));
  else if (*format == 'p')
    print_pointer(va_arg(ap, unsigned long));
  else if (*format == 'X' || *format == 'x')
    print_un_hex(va_arg(ap, unsigned long), *format);
  else if (*format == '%')
    write(1, "%", 1);
  else
    return;
}

int ft_printf(const char *string, ...) {
  va_list ap;
  int i;

  va_start(ap, string);
  i = 0;
  while (string[i]) {
    if (string[i] == '%')
      print_format(ap, &(string[++i]));
    else
      write(1, &(string[i]), 1);
    i++;
  }
  return (int)ft_strlen(string);
}

int main(void) {
  int a;
  /**
   * c type tester
   **/
  printf("%c\n", 'a');
  ft_printf("%c\n", 'a');

  printf("%c\n", 0);
  ft_printf("%c\n", 0);

  /**
   * string type tester
   **/
  printf("hello %s\n", "abcd");
  ft_printf("hello %s\n", "abcd");

  printf("%s\n", 0);
  ft_printf("%s\n", 0);

  /**
   * number type tester
   **/
  printf("%d\n", 123);
  ft_printf("%d\n", 123);

  printf("%i\n", 123);
  ft_printf("%i\n", 123);

  printf("%u\n", -1);
  ft_printf("%u\n", -1);

  printf("%u\n", 123);
  ft_printf("%u\n", 123);

  printf("%u\n", -123);
  ft_printf("%u\n", -123);

  /**
   * pointer type tester
   */
  printf("%p\n", &a);
  ft_printf("%p\n", &a);

  /**
   * hex type tester
   **/
  printf("%x\n", 'a');
  ft_printf("%x\n", 'a');

  printf("%X\n", a);
  ft_printf("%X\n", a);

  /**
   * % type tester
   * */
  printf("%%\n");
  ft_printf("%%\n");
}