/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_front.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:02:45 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/07/04 20:24:20 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
ft_lstadd_front añade el nodo new al inicio de la lista
lo hace adjudicando el primer nodo de la lista al next que apunta new
asi new apuntara next al que era primer nodo, luego se adjudica new 
al puntero inicial de la lista
*/