/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:11:52 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/22 00:37:21 by coder            ###   ########.fr       */
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

void	set_philos(t_params *p, int argc, char *argv[ ])
{
	int	i;

	p->number_of_philo = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		p->number_times_philo_eat = ft_atoi(argv[5]);
	else
		p->number_times_philo_eat = -1;
	p->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * p->number_of_philo);
	i = 0;
	while (i < p->number_of_philo)
	{
		pthread_mutex_init(&p->forks[i], NULL);
		i++;
	}
	p->death = false;
	pthread_mutex_init(&p->dead, NULL);
	pthread_mutex_init(&p->print, NULL);
}

__uint64_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * (__uint64_t)1000 + time.tv_usec / (__uint64_t)1000);

}

int64_t	time_diff(int64_t start_time)
{
	return (get_time() - start_time);
}


