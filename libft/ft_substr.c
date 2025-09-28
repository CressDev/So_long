/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_substr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:08:56 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 14:08:59 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		subs = ft_calloc(1, sizeof(char));
		return (subs);
	}
	if (len > (len_s - start))
		len = len_s - start;
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

/*
ft_substr reserva y crea una substr obtenida de s a partir de start
con la comprobacion de que len no sea mayor que len_s - start
*/