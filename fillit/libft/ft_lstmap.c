/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarguer <jmarguer@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:53:28 by jmarguer          #+#    #+#             */
/*   Updated: 2019/05/20 20:31:40 by jmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list		*new;

	if (list != NULL && f != NULL)
	{
		new = f(list);
		if (new != NULL && list->next != NULL)
			new->next = ft_lstmap(list->next, f);
		return (new);
	}
	return (NULL);
}
