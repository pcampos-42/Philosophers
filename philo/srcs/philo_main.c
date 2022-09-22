/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:19:10 by pcampos-          #+#    #+#             */
/*   Updated: 2022/09/09 15:21:17 by pcampos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if(ac < 5 || ac > 6)
		return (0);
	while(av[++i])
	{
		while(av[i][++j])
		{
			if(!(av[i][j] >= 48 && av[i][j] <= 57))
				return (0);
		}
		j = -1;
	}
	return (1);
}

int	fill_struct(char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	printf("%d\n", data->n_philos);
	data->die = ft_atoi(av[2]);
	data->eat = ft_atoi(av[3]);
	data->sleep = ft_atoi(av[4]);
	if (av[5])
	{
		data->repeat = ft_atoi(av[5]);
		if (data->repeat < 1)
			return (0);
	}
	else
		data->repeat = 0;
	if (data->n_philos < 1 || data->die < 1 || data->eat < 1 ||
		data->sleep < 1)
		return (0);
	return (1);
}

void	*rotina_de_teste(void *cenas)
{
	t_philos *philos;

	philos = cenas;
	printf("Eu sou o philo numero: %d \n", philos->philo_n);
	return (NULL);
}

int	main(int ac, char **av)
{
	int			i;
	t_data		data;
	t_philos	*philos;

	if(!check_args(ac, av) || !fill_struct(av, &data))
	{
		printf("Erro nos argumentos\n");
		return (0);
	}
	if(!init(data, *philos));
	{
		printf("Erro ao iniciar mutex ou threads\n");
		return (0);
	}
}