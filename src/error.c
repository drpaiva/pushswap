/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramos-p <dramos-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:05:44 by dramos-p          #+#    #+#             */
/*   Updated: 2022/04/04 17:07:50 by dramos-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

void	msg_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	ft_isdigit_oper(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	if (c == 45 || c == 43)
		return (2048);
	return (0);
}

int	ft_check_value(char *str)
{
	int	i;
	int	x;

	if ((str[0] == 45 || str[0] == 43) && !str[1])
		msg_error();
	x = 0;
	if ((str[0] == 45 || str[0] == 43))
		x = 1;
	i = 0;
	while (str[i])
	{
		if (x == 1 && i > 0 && str[i] == 45)
			msg_error();
		if (x == 1 && i > 0 && str[i] == 43)
			msg_error();
		if (!ft_isdigit_oper(str[i]))
			msg_error();
		i++;
	}
	return (0);
}

void	ft_isduplicate(int argc, char **argv)
{
	int	i;
	int	x;

	i = 1;
	while (argv[i] || i < argc)
	{
		x = 1;
		while (argv[x])
		{
			if (ft_strcmp(argv[i], argv[x]) == 0 && i != x)
				msg_error();
			x++;
		}
		ft_check_value(argv[i]);
		i++;
	}
}
