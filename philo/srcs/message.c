/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcid-gon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:17:43 by jcid-gon          #+#    #+#             */
/*   Updated: 2022/01/12 13:59:13 by jcid-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <unistd.h>

void	ft_print_message(t_philos *philos)
{
	if (philos->base->stop == 0)
	{
		pthread_mutex_lock(&philos->base->writing);
		if (philos->base->stop == 1)
			return ;
		ft_putnbr(ft_get_time() - philos->base->time);
		write(1, " ", 1);
		ft_putnbr(philos->pos + 1);
		if (philos->state == 0)
			ft_putstr(" is thinking\n");
		else if (philos->state == 1)
			ft_putstr(" has taken a fork\n");
		else if (philos->state == 2)
			ft_putstr (" is eating\n");
		else if (philos->state == 3)
			ft_putstr(" is sleeping\n");
		else if (philos->state == 4)
		{
			ft_putstr(" died\n");
			philos->base->stop = 1;
			return ;
		}
		pthread_mutex_unlock(&philos->base->writing);
	}
}
