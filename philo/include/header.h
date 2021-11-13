/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/13 05:04:27 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# define THINKING 0
# define EATING 1
# define SLEEPING 2

typedef struct	s_params
{
	int	number_of_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	number_times_philo_eat;
	int	*states;
	pthread_mutex_t print;
	pthread_mutex_t *forks;
}				t_params;

typedef struct	s_philo
{
	int				name;
	int				meals_eaten;
	int				right;
	int				left;
	struct s_params	*params;
	pthread_t		thread;
}				t_philo;

void	set_philos(t_params *p, int argc, char *argv[ ]);
void	dinner(t_params *p);
#endif
