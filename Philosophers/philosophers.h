/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuter <msuter@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:50:34 by msuter            #+#    #+#             */
/*   Updated: 2026/06/08 09:40:16 by msuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_gen	t_gen;
typedef struct s_philo
{
	int				num;
	int				nb_eat;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		thread;
	t_gen			*gen;

}	t_philo;

typedef struct s_gen
{
	long			ti_to_die;
	long			ti_to_sleep;
	long			ti_to_eat;
	int				nb_philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	logs;
	int				p_running;
	t_philo			*philo;
	pthread_t		state;
	pthread_mutex_t	protect_p;
	int				must_eat;

}	t_gen;

long	ft_atoi_c(const char *str);
void	verif_and_attrib_gen(int argc, char **argv, t_gen *gen);
void	cleanup(t_gen *gen, int i);
void	stop_simu(t_gen *gen);
void	put_message(t_philo *philo, char *message);
void	*case_solo_philo(t_philo *philo);
void	*eat(t_philo *philo);
void	*my_sleep(t_philo *philo);
void	*think(t_philo *philo);
int		verif_prog(t_philo *philo);
void	*philo_routine(void *arg);
void	*monitor(void *arg);
void	*unlock_my_fork(t_philo *philo, int nb, int prot);
void	get_time(struct timeval *t);

#endif
