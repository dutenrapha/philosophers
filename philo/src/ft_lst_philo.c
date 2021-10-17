/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:53:45 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/17 16:58:38 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_philo *ft_lst_new_philo(void)
{
	t_philo *new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	if (new)
	{
		new->name = 0;
		new->status = 0;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_philo(t_philo **lst, t_philo *new)
{
	t_philo	*temp;

	temp = *lst;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*lst = new;
}