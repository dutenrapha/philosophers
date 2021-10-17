/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:39:03 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/17 16:59:26 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_params
{
	int	number_of_philo;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_die;
	int	number_times_philo_eat;
}						t_params;

typedef struct s_philo
{
	int				name;
	int				status;
	pthread_t		philosopher;
	struct s_philo	*next;
}						t_philo;


void	set_philos(t_params *parmas, int argc, char *argv[ ]);
t_philo *ft_lst_new_philo(void);
void	ft_lstadd_back_philo(t_philo **lst, t_philo *new);
#endif