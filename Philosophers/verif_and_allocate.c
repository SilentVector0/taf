/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_and_allocate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:51:34 by msuter            #+#    #+#             */
/*   Updated: 2026/06/02 11:02:26 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	error(char *message)
{
	printf("%s", message);
	exit(1);
}

static void	allocate_fork(t_gen	*gen)
{
	int	i;

	i = 0;
	gen->fork = malloc(sizeof(pthread_mutex_t) * gen->nb_philo);
	if (!gen->fork)
		error("erreur lors de l'allocation de mon tableau fork\n");
	while (i < gen->nb_philo)
	{
		if (pthread_mutex_init(&gen->fork[i], NULL) != 0)
		{
			printf("erreur lors de la creation lors du mutex %d\n", i);
			i--;
			while (i >= 0)
			{
				pthread_mutex_destroy(&gen->fork[i]);
				i--;
			}
			free(gen->fork);
			exit (1);
		}
		i++;
	}
}

static void	allocate_philo(t_gen	*gen)
{
	struct timeval	t;
	int	i;

	i = 0;
	if (gettimeofday(&t, NULL) != 0)
		error("erreur lors de la recuperation de l'heure\n");
	gen->philo = malloc(sizeof(t_philo) * gen->nb_philo);
	if (!gen->philo)
		error("erreur lors de l'allocation de mon tableau philo\n");
	while (i < gen->nb_philo)
	{
		gen->philo[i].nb_eat = 0;
		gen->philo[i].num = i;
		gen->philo[i].last_meal = (t.tv_sec * 1000) + (t.tv_usec / 1000);
		gen->philo[i].left_fork = &gen->fork[i];
		if (i == gen->nb_philo -1)
			gen->philo[i].right_fork = &gen->fork[0];
		else
			gen->philo[i].right_fork = &gen->fork[i + 1];
		gen->philo[i].gen = gen;
		i++;
	}
}

void	verif_and_attrib_gen(int	argc, char **argv, t_gen *gen)
{
	if (!(argc >= 5 && argc <= 6))
	{
		printf("les arguments requis sont:\n nb_philo\n\
			temp_avant_mort\n temps_avant_manger\n\
			temps_avant_dormir\n nb_de_fois_a_manger\n");
		exit(1);
	}
	gen->p_running = 0;
	gen->nb_philo = ft_atoi_c(argv[1]);
	gen->ti_to_die = ft_atoi_c(argv[2]);
	gen->ti_to_eat = ft_atoi_c(argv[3]);
	gen->ti_to_sleep = ft_atoi_c(argv[4]);
	if (argv[5] == NULL)
		gen->must_eat = -1;
	else
		gen->must_eat = ft_atoi_c(argv[5]);
	allocate_fork(gen);
	allocate_philo(gen);
}
