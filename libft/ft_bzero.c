/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_bzero.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:01:31 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 16:42:14 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
}

/*
 ft_bzero rellena n posiciones a 0 desde el inicio de el string hasta n
la diferencia con putstr por ejemplo es que rellena la celda de memoria
la cual es convertida a puntero tipo char para poder iterar sobre cada byte
*/