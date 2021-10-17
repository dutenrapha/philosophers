/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:53:45 by rdutenke          #+#    #+#             */
/*   Updated: 2021/10/17 17:45:15 by rdutenke         ###   ########.fr       */
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

t_fork *ft_lst_new_fork(void)
{
	t_fork *new;

	new = (t_fork *)malloc(sizeof(t_fork));
	if (!new)
		return (NULL);
	if (new)
	{
		new->number = 0;
		new->availability = true;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_fork(t_fork **lst, t_fork *new)
{
	t_fork	*temp;

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