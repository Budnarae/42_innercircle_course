/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:33:57 by chansjeo          #+#    #+#             */
/*   Updated: 2024/04/17 17:30:00 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_hex(unsigned int hex)
{
	unsigned char	hex_char;

	hex_char = (unsigned char)hex;
	if (hex_char == 10)
		write(1, "a", 1);
	else if (hex_char == 11)
		write(1, "b", 1);
	else if (hex_char == 12)
		write(1, "c", 1);
	else if (hex_char == 13)
		write(1, "d", 1);
	else if (hex_char == 14)
		write(1, "e", 1);
	else if (hex_char == 15)
		write(1, "f", 1);
	else
	{
		hex_char += 48;
		write(1, &hex_char, 1);
	}
}

void	long_to_hex(unsigned long addr, unsigned int recursive_count)
{
	int	mod;

	if (addr > 16)
		long_to_hex(addr / 16, recursive_count - 1);
	else
	{
		while (recursive_count != 0)
		{
			write(1, "0", 1);
			--recursive_count;
		}
		put_hex(addr);
	}
	if (addr > 16)
	{
		mod = addr % 16;
		put_hex(mod);
	}
}

void	ft_print_char_hex(unsigned char *str, unsigned int size)
{
	unsigned int	hex_div;
	unsigned int	hex_mod;

	while (size--)
	{
		if (*str != '\0')
		{
			hex_div = (unsigned int)(*str / 16);
			hex_mod = (unsigned int)(*str % 16);
			put_hex(hex_div);
			put_hex(hex_mod);
			if ((size % 2) == 0)
				write(1, " ", 1);
		}
		else
		{
			write(1, "00", 2);
			if ((size % 2) == 0)
				write(1, " ", 1);
		}
		++str;
	}
}

void	ft_str_print_char(unsigned char *str, unsigned int size)
{
	write(1, " ", 1);
	while (size--)
	{
		if (!(*str >= 32 && *str <= 126))
			write(1, ".", 1);
		else
			write(1, str, 1);
		++str;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*str;
	unsigned long	hex_addr;

	str = (unsigned char *)addr;
	hex_addr = (unsigned long)addr;
	while (size != 0)
	{
		long_to_hex(hex_addr, 15);
		write(1, ": ", 2);
		ft_print_char_hex(str, 16);
		ft_str_print_char(str, 16);
		write(1, "\n", 1);
		if (size < 16)
			break ;
		else
		{
			hex_addr += 16;
			size -= 16;
			str += 16;
		}
	}
	return (addr);
}
