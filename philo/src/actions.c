/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:37:03 by coder             #+#    #+#             */
/*   Updated: 2021/11/23 00:17:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	sleeping(t_philo *p)
{
	if (p->params->death == true)
		return (false);
	if (!p->params->death)
		printf("%d %d is sleeping\n",
			delta_time(p->params->start, 0), p->name + 1);
	sleeep_ms(p->params->time_to_sleep);
	return (true);
}

bool	eating(t_philo *p)
{
	if (p->params->death == true)
		return (false);
	p->t_last_meal = get_time();
	p->meals_eaten++;
	if (!p->params->death)
	{
		printf("%d %d is eating the %d meal\n",
			delta_time(p->params->start, 0), p->name + 1, p->meals_eaten);
	}
	sleeep_ms(p->params->time_to_eat);
	return (true);
}

bool	philo_eats(t_philo *p)
{
	bool	result;

	result = true;
	pthread_mutex_lock(&p->params->forks[p->right]);
	if (!p->params->death)
	{
		printf("%d %d has taken a fork\n",
			delta_time(p->params->start, 0), p->name + 1);
	}
	pthread_mutex_lock(&p->params->forks[p->left]);
	if (!p->params->death)
	{
		printf("%d %d has taken a fork\n",
			delta_time(p->params->start, 0), p->name + 1);
	}
	result = eating(p);
	pthread_mutex_unlock(&p->params->forks[p->right]);
	pthread_mutex_unlock(&p->params->forks[p->left]);
	return (result);
}
