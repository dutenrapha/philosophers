/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/13 16:42:50 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	grab_fork(t_philo *p, int c)
{
	pthread_mutex_lock(&p->params->forks[c]);
	printf("%d has taken a fork\n", p->name);
}

static void	down_fork(t_philo *p,int c1, int c2)
{
	pthread_mutex_unlock(&p->params->forks[c1]);
	pthread_mutex_unlock(&p->params->forks[c2]);
}

static void *philosopher (void *arg)
{
	t_philo	*p;
	p = (t_philo *)arg;
	while(1)
	{
		if (p->params->number_times_philo_eat != -1)
			if (p->meals_eaten == p->params->number_times_philo_eat)
			{
				break;
			}
		pthread_mutex_lock(&p->params->waiter);
		pthread_mutex_lock(&p->params->print);
		grab_fork(p, p->left);
		grab_fork(p, p->right);
		pthread_mutex_unlock(&p->params->waiter);
		printf("%d is eating\n", p->name);
		p->meals_eaten++;
		usleep(p->params->time_to_eat);
		down_fork(p, p->right, p->left);
		printf ("%d is sleeping\n", p->name);
		printf ("%d is thinking\n", p->name);
		pthread_mutex_unlock(&p->params->print);
		usleep(p->params->time_to_sleep);

	}
	return (NULL);
}

void	dinner(t_params *p)
{
	int	i;
	t_philo *phi;


	phi = (t_philo *)malloc(sizeof(t_philo) * p->number_of_philo);
	i = 0;
	while (i < p->number_of_philo)
	{
		phi[i].name = i;
		phi[i].meals_eaten = 0;
		phi[i].left = i;
		phi[i].right = (i + 1) % p->number_of_philo;
		phi[i].params = p;
		i++;
	}
	i = 0;
	while (i < p->number_of_philo)
	{
		pthread_create(&phi[i].thread, NULL, philosopher, (void *)&phi[i]);
		i++;
	}
	i = 0;
	while (i < p->number_of_philo)
	{
		pthread_join(phi[i].thread, NULL);
		i++;
	}
	free(phi);
}
