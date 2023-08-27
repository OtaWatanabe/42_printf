/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otawatanabe <otawatanabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:46:00 by otawatanabe       #+#    #+#             */
/*   Updated: 2023/08/15 00:37:46 by otawatanabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *next;

    if (lst == NULL)
        return ;
    while (*lst)
    {
        next = (*lst) -> next;
        ft_lstdelone(*lst, del);
        *lst = next;
    }
    *lst = NULL;
}