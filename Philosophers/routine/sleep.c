/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:21:30 by msuter            #+#    #+#             */
/*   Updated: 2026/06/03 00:02:45 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*sleep(t_philo *philo)
{
	struct	timeval	t;
	long	current_time;
	long	end_sleep;

	put_message(philo, "is sleeping");
	if (gettimeofday(&t, NULL) != 0)
	{
		printf("erreur lors de la recuperation de l'heure\n");
		exit (1);
	}
	end_sleep = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	end_sleep += philo->gen->ti_to_sleep;
	while (1)
	{
		pthread_mutex_lock(&philo->gen->protect_p);
		if (gettimeofday(&t, NULL) != 0)
		{
			printf("erreur lors de la recuperation de l'heure\n");
			pthread_mutex_unlock(&philo->gen->protect_p);
			exit (1);
		}
		current_time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
		if (philo->gen->p_running == 1 || current_time >= end_sleep)
		{
			pthread_mutex_unlock(&philo->gen->protect_p);
			break ;
		}
		pthread_mutex_unlock(&philo->gen->protect_p);
		usleep(1000);
	}
	return (NULL);
}