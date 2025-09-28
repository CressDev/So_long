/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putchar_fd.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/21 14:06:16 by amonteag		  #+#	#+#			 */
/*   Updated: 2025/06/24 19:58:42 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

/*
ft_putchar_fd escribirá en fd el caracter c
fd o file descriptor es el destino donde se escrbira c
*/