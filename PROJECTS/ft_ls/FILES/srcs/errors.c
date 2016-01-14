/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:54:53 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 11:43:33 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* "time" permet de savoir quand est ce qu'on recoit l'erreur.
 * si c'est au debut (lorsqu'on verifie les arguments : 1,
 * ou si c'est pendant le deroulement du programme : 2
*/
void	print_error(char *message, int time)
{
	if (time == 1)
	{
		ft_putstr("ls: ");
		perror(message);
	}
	else if (time == 2 && errno != 2)
	{
		ft_putstr(message);
		ft_putendl(":");
		ft_putstr("ls: ");
		perror(message);
	}
}
