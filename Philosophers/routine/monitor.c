/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 00:01:26 by msuter            #+#    #+#             */
/*   Updated: 2026/06/18 13:46:13 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_eating(t_gen *gen)
{
	int	i;

	i = 0;
	if (gen->must_eat == -1)
		return (1);
	while (i != gen->nb_philo)
	{
		if (gen->must_eat && gen->philo[i].nb_eat >= gen->must_eat)
			i++;
		else
			return (1);
	}
	return (0);
}

static void	put_death(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->gen->logs);
	printf("%ld %d died\n", time - philo->gen->start_time, philo->num);
	pthread_mutex_unlock(&philo->gen->logs);
}

void	gestion_p_run(t_gen *gen, long time, int i)
{
	int	dead;

	dead = 0;
	pthread_mutex_lock(&gen->protect_p);
	if (gen->p_running == 0
		&& time - gen->philo[i].last_meal > gen->ti_to_die)
	{
		gen->p_running = 1;
		dead = 1;
	}
	if (all_eating(gen) == 0)
		gen->p_running = 1;
	pthread_mutex_unlock(&gen->protect_p);
	if (dead == 1)
		put_death(&gen->philo[i], time);
}

void	*monitor(void *arg)
{
	struct timeval	t;
	long			time;
	t_gen			*gen;
	int				i;

	gen = arg;
	while (1)
	{
		i = 0;
		while (i != gen->nb_philo)
		{
			if (verif_prog(&gen->philo[i]) == 1)
				return (NULL);
			get_time(&t, gen);
			time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
			gestion_p_run(gen, time, i);
			i++;
		}
		usleep(1000);
	}
}
