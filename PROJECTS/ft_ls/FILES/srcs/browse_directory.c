/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:58:46 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 10:34:52 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			add_directory_to_list(t_files *target, char *new)
{
	t_files	*new_dir;

	new_dir = (t_files *)ft_memalloc(sizeof(t_files));
	new_dir->name = ft_strdup(new);
	new_dir->next = target->next;
	target->next = new_dir;
}

int		read_directory(t_files *current_dir, t_ls_args *args, t_files **head_list, int head)
{
	DIR				*dirp;
	struct dirent	*dir_entry;
	char			*full_name;
	t_files			*current_file;
	t_files			*tmp;

	if (!(dirp = opendir(current_dir->name)))
		return (0);
	while ((dir_entry = readdir(dirp)))
	{
		if (!ft_strchr(args->options, 'a') && dir_entry->d_name[0] == '.')
			continue ;
		full_name = ft_strjoin("/", dir_entry->d_name);
		full_name = ft_strjoin(current_dir->name, full_name);
		tmp = get_file_info(full_name);
		tmp->name = ft_strdup(dir_entry->d_name);
		if (ft_strchr(args->options, 'R'))
		{
			if (tmp->type == 'd' && ft_strcmp(tmp->name, ".") && ft_strcmp(tmp->name, ".."))
				add_directory_to_list(current_dir, full_name);
		}
		if (head)
		{
			*head_list = tmp;
			current_file = *head_list;
			head = 0;
		}
		else
		{
			current_file->next = tmp;
			current_file = current_file->next;
		}
	}
	closedir(dirp);
	return (1);
}

int				browse_directories(t_ls_args *args)
{
	t_files		*current_dir;
	t_files			*files_list;

	current_dir = args->dirs;
	while (current_dir)
	{
		files_list = NULL;
		if (read_directory(current_dir, args, &files_list, 1))
			print_files(files_list, current_dir->name, args);
		else
			print_error(current_dir->name, 2);
		current_dir = current_dir->next;
		if (current_dir)
			ft_putchar('\n');
	}
	return (1);
}
