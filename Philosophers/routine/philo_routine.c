/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:19:11 by msuter            #+#    #+#             */
/*   Updated: 2026/06/05 00:49:24 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*unlock_my_fork(t_philo *philo, int nb)
{
	if (nb == 1)
	{
		pthread_mutex_unlock(&philo->gen->protect_p);
		pthread_mutex_unlock(&philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->gen->protect_p);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
	return (NULL);
}

int	verif_prog(t_philo *philo)
{
	pthread_mutex_lock(&philo->gen->protect_p);
		if (philo->gen->p_running == 1)
		{
			pthread_mutex_unlock(&philo->gen->protect_p);
			return (1);
		}
		pthread_mutex_unlock(&philo->gen->protect_p);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (verif_prog(philo) == 1)
			return (NULL);
		eat(philo);
		if (verif_prog(philo) == 1)
			return (NULL);
		my_sleep(philo);
		if (verif_prog(philo) == 1)
			return (NULL);
		think(philo);
	}
}