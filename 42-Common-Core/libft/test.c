/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neleon <neleon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:43:17 by neleon            #+#    #+#             */
/*   Updated: 2023/12/01 18:02:36 by neleon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new;
    t_list *first;

    first = NULL;
    if (!lst || !f || !del)
        return (NULL);
    while (lst)
    {
        new = ft_lstnew((*f)(lst->content));
        if (!new)
            ft_lstclear(&new, (*del));
        if (!first)
            first =
    }
    return (new);
}
