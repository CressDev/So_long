/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:07:48 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/06/23 18:23:54 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}
/*
int	main(void)
{
	char	origen[] = "La norminette";
	char	destino[15];
	size_t	cantidad = 15;

	printf("%p\n", destino);
	ft_strlcpy(destino, origen, cantidad);
	printf("%p\n", destino);
	printf("%s", destino);
	return (0);
}
*/
/* 
ft_strlcpy copia en el destino el size asignado para src
dejando sitio para caracter nulo, por eso es < y no <= en el while
*/