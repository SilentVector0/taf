/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:29 by msuter            #+#    #+#             */
/*   Updated: 2026/06/05 14:10:41 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main (int argc, char **argv)
{
	t_gen	gen;
	int		i;

	i = 0;
	printf("test1\n");
	verif_and_attrib_gen(argc, argv, &gen);
	while (i < gen.nb_philo)
	{
		printf("test_loop\n");
		if (pthread_create(&gen.philo[i].thread, NULL, philo_routine, &gen.philo[i]) != 0)
		{
			stop_simu(&gen);
			cleanup(&gen, i - 1);
			exit (1);
		}
		i++;
	}
	printf("test_out_loop\n");
	if (pthread_create(&gen.state, NULL, monitor, &gen))
	{
		printf("stopsimu\n");
		stop_simu(&gen);
		cleanup(&gen, i - 1);
		exit (1);
	}
	while (i >= 0)
	{
		i--;
		pthread_join(gen.philo[i].thread, NULL);
		printf("test_sec_loop\n");
	}
	printf("test_out_sec_loop\n");
	pthread_join(gen.state, NULL);
	printf("test2\n");
	cleanup(&gen, i);
	printf("test3\n");
	return (0);
}
