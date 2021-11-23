/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:34:23 by coder             #+#    #+#             */
/*   Updated: 2021/11/23 01:08:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_string_number(char *string)
{
	if (*string == '-')
		string++;
	while (*string)
		if (!ft_isdigit(*string++))
			return (false);
	return (true);
}

int	is_integer(int number)
{
	if (number > INT_MAX)
		return (false);
	if (number < INT_MIN)
		return (false);
	return (true);
}
