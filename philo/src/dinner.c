/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/21 20:32:33 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


static bool	sleeping(t_philo *p)
{
	int64_t	time;

	if(p->params->death == true)
		return (false);
	time = get_time();
	p->t_sleep = time_diff(p->params->start);
	if (!p->params->death)
	{
		pthread_mutex_lock(&p->params->print);
		printf("%ld %d is sleeping\n",p->t_sleep, p->name);
		pthread_mutex_unlock(&p->params->print);
	}
	usleep(p->params->time_to_sleep * 1000);
	return(true);
}

static bool	eating(t_philo *p)
{
	if(p->params->death == true)
		return (false);
	p->t_last_meal = get_time();
	p->meals_eaten++;
	p->t_meal = time_diff(p->params->start);
	if (!p->params->death)
	{
		pthread_mutex_lock(&p->params->print);
		printf("%ld %d is eating the %d meal\n",p->t_meal, p->name,p->meals_eaten);
		pthread_mutex_unlock(&p->params->print);
	}
	usleep(p->params->time_to_eat * 1000);
	return(true);
}

static bool	philo_eats(t_philo *p)
{
	bool	result;

	result = true;
	if (p->name != p->params->number_of_philo - 1)
	{
		pthread_mutex_lock(&p->params->forks[p->left]);
		p->t_taken_l_fork = time_diff(p->params->start);
		if (!p->params->death)
		{
			pthread_mutex_lock(&p->params->print);
			printf("%ld %d has taken a left fork %d\n",p->t_taken_l_fork, p->name, p->left);
			pthread_mutex_unlock(&p->params->print);
		}
		pthread_mutex_lock(&p->params->forks[p->right]);
		p->t_taken_r_fork = time_diff(p->params->start);
		if (!p->params->death)
		{
			pthread_mutex_lock(&p->params->print);
			printf("%ld %d has taken a right fork %d\n",p->t_taken_r_fork, p->name, p->right);
			pthread_mutex_unlock(&p->params->print);
		}
		result = eating(p);
		pthread_mutex_unlock(&p->params->forks[p->left]);
		pthread_mutex_unlock(&p->params->forks[p->right]);
	}
	else
	{
		pthread_mutex_lock(&p->params->forks[p->right]);
		p->t_taken_r_fork = time_diff(p->params->start);
		if (!p->params->death)
		{
			pthread_mutex_lock(&p->params->print);
			printf("%ld %d has taken a right fork %d\n",p->t_taken_r_fork, p->name, p->right);
			pthread_mutex_unlock(&p->params->print);
		}
		pthread_mutex_lock(&p->params->forks[p->left]);
		p->t_taken_l_fork = time_diff(p->params->start);
		if (!p->params->death)
		{
			pthread_mutex_lock(&p->params->print);
			printf("%ld %d has taken a left fork %d\n",p->t_taken_l_fork, p->name, p->left);
			pthread_mutex_unlock(&p->params->print);
		}
		result = eating(p);
		pthread_mutex_unlock(&p->params->forks[p->right]);
		pthread_mutex_unlock(&p->params->forks[p->left]);
	}

	return (result);
}

static void	*monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	usleep(6000);
	while (1)
	{
		if (p->params->death == true)
			return ((void *)1);
		if (p->params->number_times_philo_eat != -1)
		{
			if (p->meals_eaten == p->params->number_times_philo_eat)
			{
				p->is_satisfied=true;
				return ((void *)1);
			}
		}
		if (p->meals_eaten > 0)
		{
			if (time_diff(p->t_last_meal) >  p->params->time_to_die && p->params->death == false)
			{
				pthread_mutex_lock(&p->params->dead);
				p->params->death = true;
				printf ("%ld %d died\n",time_diff(p->params->start), p->name);
				pthread_mutex_unlock(&p->params->dead);
				return ((void *)1);
			}
		}
	}
	return (NULL);
}

static void *philosopher(void *arg)
{
	t_philo	*p;
	p = (t_philo *)arg;


	if (pthread_create(&death_monitor, NULL, &monitor, p) != 0)
		return ((void *)1);
	pthread_detach(death_monitor);
	while(1)
	{
		if (p->params->death)
			return ((void *)1);
		if (p->is_satisfied && !p->params->death)
			return ((void *)1);
		if(!philo_eats(p) && !p->params->death)
			break;
		if(!sleeping(p) && !p->params->death)
			break;
		pthread_mutex_lock(&p->params->print);
		if (!p->params->death)
			printf("%ld %d is thinkink\n",time_diff(p->params->start), p->name);

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
		phi[i].t_last_meal = p->start;
		phi[i].t_meal = 0;
		phi[i].t_sleep = 0;
		phi[i].t_died = 0;
		phi[i].is_satisfied = false;
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
