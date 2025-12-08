/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:47:42 by joho              #+#    #+#             */
/*   Updated: 2025/12/08 23:07:56 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed, window closed\n", keysym);
		destroy_free(mlx);
		exit(1);
	}
	return (0);
}

int	close_window(t_mlx *mlx)
{
	destroy_free(mlx);
	exit(1);
	return (0);
}
