/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/14 03:21:11 by rdutenke         ###   ########.fr       */
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

typedef struct	s_params
{
	int	number_of_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	number_times_philo_eat;
	long long int	start;
	pthread_mutex_t print;
	pthread_mutex_t waiter;
	pthread_mutex_t *forks;
}				t_params;

typedef struct	s_philo
{
	int				name;
	int				meals_eaten;
	int64_t			last_meal_time;
	int				right;
	int				left;
	struct s_params	*params;
	pthread_t		thread;
}				t_philo;

void		set_philos(t_params *p, int argc, char *argv[ ]);
void		dinner(t_params *p);
__uint64_t	get_time(void);
#endif
