/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:46:16 by msuter            #+#    #+#             */
/*   Updated: 2026/06/10 14:57:41 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*case_solo_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	put_message(philo, "has taken a fork");
	while (1)
	{
		pthread_mutex_lock(&philo->gen->protect_p);
		if (philo->gen->p_running == 1)
		{
			pthread_mutex_unlock(&philo->gen->protect_p);
			pthread_mutex_unlock(philo->left_fork);
			break ;
		}
		pthread_mutex_unlock(&philo->gen->protect_p);
		usleep(10);
	}
	return (NULL);
}

void	counter_reset(t_philo *philo)
{
	struct timeval	t;
	long			time;

	pthread_mutex_lock(&philo->gen->protect_p);
	if (gettimeofday(&t, NULL) != 0)
	{
		printf("erreur lors de la recuperation de l'heure\n");
		cleanup(philo->gen, 0);
		exit (1);
	}
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	philo->nb_eat += 1;
	philo->last_meal = time;
	pthread_mutex_unlock(&philo->gen->protect_p);
}

void	*lock_fork(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*last;

	if (philo->right_fork == philo->left_fork)
		return (case_solo_philo(philo));
	if (verif_prog(philo))
		return (NULL);
	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		last = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		last = philo->left_fork;
	}
	pthread_mutex_lock(first);
	if (verif_prog(philo))
		return (NULL);
	put_message(philo, "has taken a fork");
	pthread_mutex_lock(last);
	if (verif_prog(philo))
		return (NULL);
	put_message(philo, "has taken a fork");
	return (NULL);
}

void	*eat(t_philo *philo)
{
	lock_fork(philo);
	if (verif_prog(philo))
		return (NULL);
	put_message(philo, "is eating");
	counter_reset(philo);
	usleep(philo->gen->ti_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}
