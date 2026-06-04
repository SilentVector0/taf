/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/05/29 11:19:27 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
	t_gen	gen;
	int		i;

	i = 0;
	verif_and_attrib_gen(argc, argv, &gen);
	while (i < gen.nb_philo)
	{
		if (pthread_create(&gen.philo[i].thread, NULL, philo_routine, &gen.philo[i]) != 0)
		{
			stop_simu(&gen);
			cleanup(&gen, i - 1);
			exit (1);
		}
		i++;
	}
	if (pthread_create(&gen.state, NULL, verif_philo, &gen))
	{
		stop_simu(&gen);
		cleanup(&gen, i - 1);
		exit (1);
	}
	while (i >= 0)
	{
		i--;
		pthread_join(gen.philo[i].thread, NULL);
	}
	pthread_join(gen.state, NULL);
	cleanup(&gen, i);
	return (0);
}
