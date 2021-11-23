/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/23 00:25:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	one_phio(t_philo *p)
{
	printf("%d %d has taken a right fork %d\n",
		delta_time(p->params->start, 0), p->name + 1, p->right);
	sleeep_ms(p->params->time_to_die);
	printf("%d %d died\n", delta_time(p->params->start, 0), p->name + 1);
}

int	simulation(t_philo *p)
{
	while (1)
	{
		if (p->params->death)
			return (1);
		if (p->is_satisfied && !p->params->death)
			return (1);
		if (!philo_eats(p) && !p->params->death)
			break ;
		if (!sleeping(p) && !p->params->death)
			break ;
		if (!p->params->death)
		{
			printf("%d %d is thinking\n",
				delta_time(p->params->start, 0), p->name + 1);
		}
	}
	return (0);
}

static void	*philosopher(void *arg)
{
	t_philo		*p;
	pthread_t	death_monitor;

	p = (t_philo *)arg;
	if (p->params->number_of_philo == 1)
	{
		one_phio(p);
		return (NULL);
	}
	if (pthread_create(&death_monitor, NULL, &monitor, p) != 0)
		return ((void *)1);
	if (p->name % 2 == 0)
		sleeep_ms(5);
	pthread_detach(death_monitor);
	if (simulation(p) == 1)
		return ((void *)1);
	return (NULL);
}

void	dinner(t_params *p)
{
	int		i;
	t_philo	*phi;

	phi = (t_philo *)malloc(sizeof(t_philo) * p->number_of_philo);
	i = 0;
	while (i < p->number_of_philo)
	{
		init_phi(&phi[i], p, i);
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
