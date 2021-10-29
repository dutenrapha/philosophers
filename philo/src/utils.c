/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:11:52 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/29 05:14:18 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static	int	ft_return(int sinal)
{
	if (sinal == 1)
	{
		return (-1);
	}
	else
	{
		return (0);
	}
}

static int	ft_atoi(const char *nptr)
{
	int			i;
	int			sinal;
	long int	unidade;

	i = 0;
	sinal = 1;
	unidade = 0;
	while (*(nptr + i) == ' ' || *(nptr + i) == '\n'
		|| *(nptr + i) == '\t' || *(nptr + i) == '\v'
		|| *(nptr + i) == '\f' || *(nptr + i) == '\r')
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sinal = -1;
		i += 1;
	}
	while (*(nptr + i) >= 48 && *(nptr + i) <= 57)
	{
		unidade = unidade * 10 + *(nptr + i) - 48;
		if (unidade > 2147483648)
			return (ft_return(sinal));
		i++;
	}
	return (unidade * sinal);
}

void	set_philos(t_params *params, int argc, char *argv[ ])
{
	params->number_of_philo = ft_atoi(argv[1]);
	params->time_to_eat = ft_atoi(argv[2]);
	params->time_to_sleep = ft_atoi(argv[3]);
	params->time_to_die = ft_atoi(argv[4]);
	params->number_forks = params->number_of_philo;
	if (argc == 6)
		params->number_times_philo_eat = ft_atoi(argv[5]);
	else
		params->number_times_philo_eat = -1;
	params->lst_philos = (pthread_t *)malloc(sizeof(pthread_t) * params->number_of_philo);

}