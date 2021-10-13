/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:36:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/13 19:33:40 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int argc, char *argv[ ])
{
	t_philo	philos;

	set_philos(&philos, argc, argv);
	printf("number_of_philo: %d\ntime_to_eat: %d\ntime_to_sleep: %d\ntime_to_die: %d\nnumber_times_philo_eat: %d\n",
	philos.number_of_philo,
	philos.time_to_eat,
	philos.time_to_sleep,
	philos.time_to_die,
	philos.number_times_philo_eat);
	ft_test();
	return (0);
}