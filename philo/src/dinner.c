/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/16 03:39:29 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


void	philo_eats(t_philo *p)
{
	if (p->name != p->params->number_of_philo - 1)
	{
		pthread_mutex_lock(&p->params->forks[p->left]);
		p->t_taken_l_fork = time_diff(p->params->start);
		pthread_mutex_lock(&p->params->forks[p->right]);
		p->t_taken_r_fork = time_diff(p->params->start);
	}
	else
	{
		pthread_mutex_lock(&p->params->forks[p->right]);
		p->t_taken_l_fork = time_diff(p->params->start);
		pthread_mutex_lock(&p->params->forks[p->left]);
		p->t_taken_r_fork = time_diff(p->params->start);
	}
	p->meals_eaten++;
	p->t_last_meal = time_diff(p->params->start);
	usleep(p->params->time_to_eat * 1000);
	pthread_mutex_unlock(&p->params->forks[p->left]);
	pthread_mutex_unlock(&p->params->forks[p->right]);
}

static void	sleeping(t_philo *p)
{
	p->t_last_sleep = time_diff(p->params->start);
	usleep(p->params->time_to_sleep * 1000);
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
			philo_eats(p);
			sleeping(p);
			pthread_mutex_lock(&p->params->print);
			printf("%ld %d has taken a fork\n",p->t_taken_l_fork, p->name);
			printf("%ld %d has taken a fork\n",p->t_taken_r_fork, p->name);
			printf("%ld %d is eating\n",p->t_last_meal, p->name);
			printf("%ld %d is sleeping\n",p->t_last_sleep, p->name);
			printf ("%ld %d is thinkink\n",time_diff(p->params->start), p->name);
			pthread_mutex_unlock(&p->params->print);
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
		phi[i].t_taken_l_fork = 0;
		phi[i].t_taken_r_fork = 0;
		phi[i].t_last_meal = 0;
		phi[i].t_last_sleep = 0;
		phi[i].t_died = 0;
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
