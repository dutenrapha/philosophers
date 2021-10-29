/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:08:31 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/29 05:15:22 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	*test(void *arg)
{
	printf("Begin test %d\n", *(int *)arg);
	sleep(4);
	printf("End test %d\n", *(int *)arg);
	return NULL;
}

void	dinner(t_params *params)
{
	int			i;

	i = 0;
	while (i < params->number_of_philo)
	{
		pthread_create(&params->lst_philos[i], NULL, test, (void *)&i);
		i++;
	}
	i = 0;
	while (i < params->number_of_philo)
	{
		pthread_join(params->lst_philos[i], NULL);
		i++;
	}
}