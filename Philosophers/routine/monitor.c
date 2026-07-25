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

void	gestion_p_run(t_gen *gen, long time, int i)
{
	pthread_mutex_lock(&gen->protect_p);
	if (time - gen->philo[i].last_meal > gen->ti_to_die)
	{
		put_message(&gen->philo[i], "died");
		gen->p_running = 1;
	}
	if (all_eating(gen) == 0)
		gen->p_running = 1;
	pthread_mutex_unlock(&gen->protect_p);
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
