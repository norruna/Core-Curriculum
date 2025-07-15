/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:21:34 by mayahiao          #+#    #+#             */
/*   Updated: 2025/07/15 16:47:21 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h> //for printf just testing
#include <X11/keysym.h> //for events


/*****************************/
/*---------------------------*/
/* WINDOW -------- MANAGEMENT*/
/*---------------------------*/
/*****************************/

//struct to handle both connection and window pointers
//more for mlx key hook
typedef struct s_mlx_param
{
	void	*ptr;
	void	*window;
}	t_mlx_param;

int key_presses(int keysym, t_mlx_param *param)
{
	//change printf to ft_printf later
	if (keysym == XK_Escape)
	{
		printf("You pressed the ESC key, exiting ...\n");
		mlx_destroy_window(param->ptr, param->window);
		mlx_destroy_display(param->ptr);
		free(param->ptr);
		exit(0); //to avoid seg faulting at exit
	}
	printf("Thanks for pressing the %d key, nothing happened yet ..\n", keysym);
	return (0);
}

void init_and_open_window(t_mlx_param *param)
{
	param->ptr = mlx_init(); //connect to server
	if (param->ptr == NULL)
		return ; //error since xvar use malloc
	param->window = mlx_new_window(param->ptr, 500, 500, "night_routine");
	if (param->window == NULL)
	{
		mlx_destroy_display(param->ptr); //close window
		free(param->ptr); //close connection
		return ;
	}
	mlx_key_hook(param->window,key_presses,param); //handle key presses
	mlx_loop(param->ptr);
	mlx_destroy_window(param->ptr, param->window);
	mlx_destroy_display(param->ptr); //destroy the display
	free(param->ptr); //free xvar struct
}

int	main(void)
{
	t_mlx_param	param;

	//for window management section
	init_and_open_window(&param);
	return (0);
}
