/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayahiao <mayahiao@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:45:17 by mayahiao          #+#    #+#             */
/*   Updated: 2026/03/25 15:56:01 by mayahiao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# ifndef TILE
#  define TILE 64
# endif

/* keep track of player position*/
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

/* struct to handle both connection and window pointers */
typedef struct s_game
{
	void	*ptr;
	void	*window;
	void	*img;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		collected;
}	t_game;

typedef struct s_flood
{
	int	**visited;
	int	rows;
	int	cols;
	int	py;
	int	px;
}	t_flood;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

/*get_next_line */
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *dest, const char *src);
int		ft_strlen(const char *str);
char	*read_buffer(int fd, char *line);
char	*extract_line(char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s1, int start, size_t len);
char	*ft_strdup(const char *s);

/*is_map_accessible*/
void	flood_fill(char **map, t_flood *f, int y, int x);
int		is_reachable(char **map, t_flood *f);

/*is_map_valid*/
void	count_collectibles(t_game *game);
int		count_map_lines(char *file);
int		count_p_c_e(char *file);
int		is_rectangular(char *file);
int		is_surrounded_by_walls(char *file);
int		is_valid(char *file);
int		valid_chars(char *file);

/*map_parsing_drawing*/
void	free_map(char **map, int i);
char	**parse_map(char *file);
void	draw_map(char **map, t_game *game);

/*movement*/
void	find_player(t_game *game);
void	move_player(t_game *game, int dx, int dy);
int		key_presses(int keysym, void *param);

/*window_management*/
int		close_after_x(t_game *game);
void	init_and_open_window(t_game *game);

void cleanup(t_game *game);
#endif
