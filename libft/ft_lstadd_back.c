/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_back.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:02:35 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/07/04 20:24:15 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
		ft_lstlast(*lst)->next = new;
}
/*
ft_lstadd_back añade un nodo al final de la lista
mientras el nodo siguiente no sea null sigue iterando
y cuando el  siguiente nodo es null se añade el nodo nuevo el final
*/