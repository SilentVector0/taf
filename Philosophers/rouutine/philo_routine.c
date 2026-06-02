/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:19:11 by msuter            #+#    #+#             */
/*   Updated: 2026/06/02 22:47:20 by msuter           ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	if (philo->num % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philo->gen->protect_p);
		if (philo->gen->p_running == 1)
		{
			pthread_mutex_unlock(&philo->gen->protect_p);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->gen->protect_p);
	}
}