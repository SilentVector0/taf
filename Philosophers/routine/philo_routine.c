/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:19:11 by msuter            #+#    #+#             */
/*   Updated: 2026/06/08 12:51:24 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_fork_order(t_philo *philo, pthread_mutex_t **first,
			pthread_mutex_t **second)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

void	*unlock_my_fork(t_philo *philo, int nb, int prot)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	get_fork_order(philo, &first, &second);
	if (prot == 1)
		pthread_mutex_unlock(&philo->gen->protect_p);
	if (nb == 1)
		pthread_mutex_unlock(first);
	else
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
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
	t_philo	*philo;

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
