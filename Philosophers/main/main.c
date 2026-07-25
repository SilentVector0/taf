/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/06/18 14:22:53 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_my_t(void)
{
	struct timeval	t;
	long			time;

	if (gettimeofday(&t, NULL) != 0)
	{
		printf("error: failed to get the current time\n");
		exit (1);
	}
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

void	creation_thread(t_gen *gen, int *i)
{
	gen->start_time = get_my_t();
	while (*i < gen->nb_philo)
	{
		if (pthread_create(&gen->philo[*i].thread,
				NULL, philo_routine, &gen->philo[*i]) != 0)
		{
			stop_simu(gen);
			cleanup(gen, *i - 1);
			exit (1);
		}
		(*i)++;
	}
	if (pthread_create(&gen->state, NULL, monitor, gen))
	{
		stop_simu(gen);
		cleanup(gen, *i - 1);
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_gen	gen;
	int		i;

	i = 0;
	verif_and_attrib_gen(argc, argv, &gen);
	creation_thread(&gen, &i);
	while (i > 0)
	{
		i--;
		pthread_join(gen.philo[i].thread, NULL);
	}
	pthread_join(gen.state, NULL);
	cleanup(&gen, i);
	return (0);
}
