/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/23 00:15:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/time.h>
# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define DELAY 1000

typedef unsigned long long int	t_microsec;

typedef struct s_params
{
	int				number_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	bool			death;
	int				number_times_philo_eat;
	long long int	start;
	pthread_mutex_t	dead;
	pthread_mutex_t	*forks;
}				t_params;

typedef struct s_philo
{
	int				name;
	int				meals_eaten;
	int64_t			t_last_meal;
	bool			is_satisfied;
	int				left;
	int				right;
	struct s_params	*params;
	pthread_t		thread;
}				t_philo;

void		set_philos(t_params *p, int argc, char *argv[ ]);
void		dinner(t_params *p);
t_microsec	get_time(void);
int			delta_time(t_microsec init, t_microsec now);
void		sleeep_ms(int time);
bool		sleeping(t_philo *p);
bool		eating(t_philo *p);
bool		philo_eats(t_philo *p);
void		init_phi(t_philo *phi, t_params *p, int i);
void		*monitor(void *arg);
#endif
