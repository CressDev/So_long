/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calloc.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:01:38 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 16:43:44 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*
 ft_calloc hace reserva de memoria mediante malloc 
ptr = malloc(nmemb * size);
solo que ft_calloc reserva poniendo todos los bytes de la memoria a 0
se calcula que no supera el int_max con, if (nmemb > (size_t)-1 / size)
ya que size_t -1 entre size no puede dar mas de nmemb
*/