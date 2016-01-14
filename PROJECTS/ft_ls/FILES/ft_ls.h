/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:02:29 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 10:35:46 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h> // le laisser pour perror()

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h> // pour errno
# include <time.h>

# include <string.h> // strerror

typedef struct	s_files
{
	char				type;
	char				*permissions;
	int					links;
	char				*owner;
	char				*group;
	int					size;
	char				*date;
	int					timestamp;
	char				*name;
	char				*parent_dir;
	struct s_files		*next;
}				t_files;

typedef struct	s_ls_args
{
	char		*authorized_options;
	char		*options;
	t_files		*dirs;
}				t_ls_args;

void			check_arguments(int ac, char **av, t_ls_args *ls_args);
int				browse_directories(t_ls_args *args);
int				read_directory(t_files *current_dir, t_ls_args *args, t_files **head_list, int head);
t_files			*get_file_info(char *file_name);

//void			print_dir_long(t_files *head, char *name);
//void			print_dir_short(t_files *head, char *name);
void			print_files(t_files *head, char *name, t_ls_args *args);

void			print_error(char *message, int time);
int				is_option(char *argm, t_ls_args *ls_args);

#endif
