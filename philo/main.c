/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:36:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/11/13 16:39:34 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(int argc, char *argv[ ])
{
	t_params	params;

	set_philos(&params, argc, argv);
	dinner(&params);
	free(params.forks);
	return (0);
}