/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 11:19:11 by msuter            #+#    #+#             */
/*   Updated: 2026/06/01 15:39:28 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *eat(t_philo *philo)
{
	if (philo->right_fork == philo->left_fork)
	{
		
	}
	pthread_mutex_lock(&philo->left_fork);
	put_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->gen->protect_p);
	if (philo->gen->p_running == 1)
	{
		pthread_mutex_unlock(&philo->gen->protect_p);
		pthread_mutex_unlock(&philo->left_fork);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->gen->protect_p);
	pthread_mutex_lock(&philo->right_fork);
	put_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->gen->protect_p);
	if (philo->gen->p_running == 1)
	{
		pthread_mutex_unlock(&philo->gen->protect_p);
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->gen->protect_p);
	put_message(philo, "is eating");
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
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
			return (NULL);
		pthread_mutex_unlock(&philo->gen->protect_p);
		
	}
}