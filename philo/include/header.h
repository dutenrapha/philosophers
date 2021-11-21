/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/21 18:39:32 by rdutenke         ###   ########.fr       */
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

typedef struct	s_params
{
	int				number_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	bool			death;
	int				number_times_philo_eat;
	long long int	start;
	pthread_mutex_t print;
	pthread_mutex_t *forks;
}				t_params;

typedef struct	s_philo
{
	int				name;
	int				meals_eaten;
	int64_t			t_taken_l_fork;
	int64_t			t_taken_r_fork;
	int64_t			t_last_meal;
	int64_t			t_meal;
	int64_t			t_sleep;
	int64_t			t_died;
	bool			is_satisfied;
	int				left;
	int				right;
	struct s_params	*params;
	pthread_t		thread;
}				t_philo;

void		set_philos(t_params *p, int argc, char *argv[ ]);
void		dinner(t_params *p);
__uint64_t	get_time(void);
int64_t	time_diff(int64_t start_time);
#endif
