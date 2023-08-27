/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:20:30 by owatanab          #+#    #+#             */
/*   Updated: 2023/08/15 00:31:45 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list*));
	if (a == NULL)
		return (NULL);
	a -> content = content;
	a -> next = NULL;
	return (a);
}