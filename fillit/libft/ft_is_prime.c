/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:24:34 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 19:28:22 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(unsigned int a)
{
	unsigned int		i;

	if (a <= 2)
		return (1);
	i = 2;
	while (i < a)
	{
		if (a % i == 0)
			return (0);
		i++;
	}
	return (1);
}
