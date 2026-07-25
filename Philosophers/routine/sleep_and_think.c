/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:21:30 by msuter            #+#    #+#             */
/*   Updated: 2026/07/25 17:03:48 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*think(t_philo *philo)
{
	long	think_time;

	put_message(philo, "is thinking");
	if (philo->gen->nb_philo % 2 == 1)
	{
		think_time = philo->gen->ti_to_eat * 2 - philo->gen->ti_to_sleep;
		if (think_time > 0)
			usleep(think_time * 1000);
	}
	return (NULL);
}

void	get_time(struct timeval *t, t_gen *gen)
{
	if (gettimeofday(t, NULL) != 0)
	{
		printf("error: failed to get the current time\n");
		cleanup(gen, 0);
		exit (1);
	}
}

void	precise_sleep(t_philo *philo, long duration_ms)
{
	struct timeval	t;
	long			current_time;
	long			end_time;

	get_time(&t, philo->gen);
	end_time = (t.tv_sec * 1000) + (t.tv_usec / 1000) + duration_ms;
	while (1)
	{
		get_time(&t, philo->gen);
		current_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
		pthread_mutex_lock(&philo->gen->protect_p);
		if (philo->gen->p_running == 1 || current_time >= end_time)
		{
			pthread_mutex_unlock(&philo->gen->protect_p);
			break ;
		}
		pthread_mutex_unlock(&philo->gen->protect_p);
		if (end_time - current_time > 5)
			usleep(5000);
		else
			usleep(500);
	}
}

void	*my_sleep(t_philo *philo)
{
	put_message(philo, "is sleeping");
	precise_sleep(philo, philo->gen->ti_to_sleep);
	return (NULL);
}
