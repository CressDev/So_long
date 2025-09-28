/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isprint.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amonteag <amonteag@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:02:17 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/04/21 17:14:37 by amonteag		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

/* 
ft_isprint comprueba si es un caracter printable
retorna 1 en caso true y 0 en caso false
*/