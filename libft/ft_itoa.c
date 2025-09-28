/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:02:25 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 15:49:32 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	get_len_num(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_str;
	long	num;

	num = n;
	len_str = get_len_num(n);
	str = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	str[len_str] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num != 0)
	{
		str[len_str - 1] = (num % 10) + '0';
		num = num / 10;
		len_str --;
	}
	return (str);
}

/*
 ft_itoa convierte integer a ascii
se divide en dos funciones, el get_len que es estatico 
el len del numero dividiendo entre diez hasta llegar a cero
la funcion principal hace reserva de memoria como rellena al reves
lo primero que se rellena es el caracter nulo luego las posiciones descienden
mientras num != 0 se rellena del 123 primero el '3' luego el '2' etc;
str[len_str - 1] = (num % 10) + '0'; extrae el último dígito
num = num / 10; elimina el último dígito
len--; recorre una posición hacia atrás
*/
