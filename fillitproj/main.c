/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:43:11 by jmarguer          #+#    #+#             */
/*   Updated: 2019/08/20 17:54:51 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_list(t_piece *list)
{
	t_piece		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int		main(int argc, char **argv)
{
	t_piece		*piecelist;

	if (argc == 2)
	{
		if ((piecelist = readinput(argv[1])) == NULL)
		{
			ft_putstr("error\n");
			return (1);
		}
		solve(piecelist);
		free_list(piecelist);
	}
	else
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putstr(" [pieces.fillit]\n");
	}
	return (0);
}
