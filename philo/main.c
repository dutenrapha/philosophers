/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:36:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/22 23:38:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int argc, char *argv[ ])
{
	t_params	params;

	set_philos(&params, argc, argv);
	params.start = get_time();
	dinner(&params);
	free(params.forks);
	return (0);
}
