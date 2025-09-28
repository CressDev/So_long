/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isascii.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:02:06 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 15:48:14 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*
ft_isascii comprueba si el caracter está dentro del codigo ascii
retorna 1 en caso true, 0 en caso false
*/
