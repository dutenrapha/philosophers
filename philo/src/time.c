/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:43:34 by coder             #+#    #+#             */
/*   Updated: 2021/11/22 23:43:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_microsec	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	delta_time(t_microsec init, t_microsec now)
{
	t_microsec	delta;

	if (now == 0)
		now = get_time();
	delta = now - init;
	return (delta / 1000);
}

void	sleeep_ms(int time)
{
	int	delay_factor;

	delay_factor = 200000000 / (200000 + DELAY);
	usleep(time * delay_factor);
}
