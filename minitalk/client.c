/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:00:34 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/25 04:21:45 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int arc, char **arv)
{
	int		i;
	int		b;
	pid_t	pid;

	if (arc != 3)
		return (0);
	i = 0;
	pid = ft_atoi(arv[1]);
	while (arv[2][i])
	{
		b = 31;
		while (b >= 0)
		{
			usleep(500);
			if (((arv[2][i] >> b) & 1) == 1)
				kill(pid, SIGUSR2);
			else if (((arv[2][i] >> b) & 1) == 0)
				kill(pid, SIGUSR1);
			b--;
		}
		i++;
	}
	ft_printf("%d", pid);
}
