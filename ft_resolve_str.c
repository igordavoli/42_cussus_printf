/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idavoli- <idavoli-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:36:29 by idavoli-          #+#    #+#             */
/*   Updated: 2021/10/16 20:02:10 by idavoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_flgs(int str_len, t_flags flags)
{
	int i;

	// printf("\n1aaaaa %d %s\n", flags.f_space, str);
	i = 0;
	if (flags.f_space)
	{
		while (flags.f_space - i++ - str_len)
			ft_putchar_fd(' ', 1);
	}
}

int	ft_resolve_str(char *str, t_flags flags)
{
	int str_len;
	int	len;

	str_len = ft_strlen(str);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if(flags.f_space > str_len)
	{
		len = flags.f_space;
		ft_handle_flgs(str_len, flags);
	}
	else
		len = str_len;
	ft_putstr_fd(str, 1);
	return (len);
}