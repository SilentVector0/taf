/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:23 by msuter            #+#    #+#             */
/*   Updated: 2026/06/18 14:22:23 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	put_message(t_philo *philo, char *message)
{
	struct timeval	t;
	long			time;

	pthread_mutex_lock(&philo->gen->logs);
	if (philo->gen->dead_printed == 1)
	{
		pthread_mutex_unlock(&philo->gen->logs);
		return ;
	}
	if (gettimeofday(&t, NULL) != 0)
	{
		printf("error: failed to get the current time\n");
		cleanup(philo->gen, 0);
		exit (1);
	}
	time = ((t.tv_sec * 1000) + (t.tv_usec / 1000)) - philo->gen->start_time;
	printf("%ld %d %s\n", time, philo->num, message);
	pthread_mutex_unlock(&philo->gen->logs);
}

void	stop_simu(t_gen *gen)
{
	pthread_mutex_lock(&gen->protect_p);
	gen->p_running = 1;
	pthread_mutex_unlock(&gen->protect_p);
}

void	cleanup(t_gen *gen, int i)
{
	i = 0;
	while (i < gen->nb_philo)
	{
		pthread_mutex_destroy(&gen->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&gen->protect_p);
	pthread_mutex_destroy(&gen->logs);
}

static void	verif(const char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '-' || str[*i] == '0')
		{
			printf("please enter a positive number\n");
			exit (1);
		}
		(*i)++;
		if (str[*i] == '\0')
		{
			printf ("please enter a valid number\n");
			exit (1);
		}
	}
}

long	ft_atoi_c(const char *str)
{
	int		i;
	long	total;

	i = 0;
	total = 0;
	verif (str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		printf("error in an argument, please try again\n");
		exit(1);
	}
	if (total < 2147483647)
		return (total);
	printf ("please enter a smaller number, the limit is 2147483647\n");
	exit (1);
}
