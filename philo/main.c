/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:36:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/17 17:03:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int argc, char *argv[ ])
{
	t_params	params;
	t_philo		*f1;
	t_philo		f2;

	set_philos(&params, argc, argv);
	printf("number_of_philo: %d\ntime_to_eat: %d\ntime_to_sleep: %d\ntime_to_die: %d\nnumber_times_philo_eat: %d\n",
	params.number_of_philo,
	params.time_to_eat,
	params.time_to_sleep,
	params.time_to_die,
	params.number_times_philo_eat);

	f1 = ft_lst_new_philo();
	f2.name = 1;
	f2.status = 2;
	f2.next = NULL;
	ft_lstadd_back_philo(&f1,&f2);

	return (0);
}