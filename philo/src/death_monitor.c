/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:05:44 by coder             #+#    #+#             */
/*   Updated: 2021/11/23 01:13:57 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	death_sequece(t_philo *p)
{
	pthread_mutex_lock(&p->params->dead);
	if (!p->params->death)
	{
		p->params->death = true;
		printf("%d %d is died\n",
			delta_time(p->params->start, 0), p->name + 1);
	}
	pthread_mutex_lock(&p->params->dead);
}

static int	satisfied_sequece(t_philo *p)
{
	if (p->meals_eaten == p->params->number_times_philo_eat)
	{
		p->is_satisfied = true;
		return (1);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*p;

	sleeep_ms(5);
	p = (t_philo *)arg;
	while (1)
	{
		if (p->params->death == true)
			return ((void *)1);
		if (p->params->number_times_philo_eat != -1)
		{
			if (satisfied_sequece(p) == 1)
				return ((void *)1);
		}
		if (p->meals_eaten > 0)
		{
			if (delta_time(p->t_last_meal, 0) > p->params->time_to_die
				&& p->params->death == false)
			{
				death_sequece(p);
				return ((void *)1);
			}
		}
	}
	return (NULL);
}
