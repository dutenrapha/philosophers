/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:42:17 by coder             #+#    #+#             */
/*   Updated: 2021/11/23 01:14:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

bool	is_valid_number(char *str_number)
{
	int	number;

	if (!is_string_number(str_number))
	{
		printf("Input is not a number\n");
		return (false);
	}
	number = ft_atoi(str_number);
	if (number < 0 || !is_integer(number))
	{
		printf("Invalid number\n");
		return (false);
	}
	return (true);
}

bool	is_number_of_arguments_correct(int argc)
{
	if (argc == 6 || argc == 5)
		return (true);
	printf("Incorrect number of arguments\n");
	return (false);
}

bool	is_validation_ok(int argc, char *argv[ ])
{
	int	i;

	i = 1;
	if (!is_number_of_arguments_correct(argc))
		return (false);
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		i++;
	}
	return (true);
}
