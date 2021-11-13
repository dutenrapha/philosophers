/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/13 05:45:04 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	grab_chopstick(t_philo *p, int c)
{
	pthread_mutex_lock(&p->params->forks[c]);
}

static void	down_chopsticks(t_philo *p,int c1, int c2)
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

		if (p->name != 0)
			printf ("%d is thinking\n", p->name);
		pthread_mutex_lock(&p->params->print);
		if (p->name == p->params->number_of_philo - 1)
		{
			grab_chopstick(p, p->right);
			grab_chopstick(p, p->left);
		}
		else
		{
			grab_chopstick(p, p->left);
			grab_chopstick(p, p->right);
		}
		printf("%d has taken a fork\n", p->name);
		printf("%d has taken a fork\n", p->name);
		printf("%d is eating\n", p->name);
		pthread_mutex_unlock(&p->params->print);
		sleep(8);
		//usleep(p->params->time_to_eat);
		down_chopsticks(p, p->right, p->left);
		printf ("%d is sleeping\n", p->name);
		sleep(2);
		//usleep(p->params->time_to_sleep);

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
