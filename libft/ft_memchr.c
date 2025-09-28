/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memchr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:05:19 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 16:05:47 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		val;
	size_t				i;

	i = 0;
	str = (const void *)s;
	val = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == val)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

/* ft_memchr encuentra la primera ocurrencia de c en s
al trabajar con la memoria se castean a unsigned char 
se retorna un casteo a void * de str[i]
*/