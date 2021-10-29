/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/29 05:15:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_params
{
	int	number_of_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	number_times_philo_eat;
	int	number_forks;
	pthread_t	*lst_philos;
}						t_params;

void	set_philos(t_params *parmas, int argc, char *argv[ ]);
void	dinner(t_params *params);
#endif