/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 11:01:24 by dtedgui           #+#    #+#             */
/*   Updated: 2016/01/14 12:12:24 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_owner(struct stat infos)
{
	struct passwd	*owner_infos;

	if (!(owner_infos = getpwuid(infos.st_uid)))
	{
		ft_putendl("pb get_owner()"); // DELETE
		exit(0);
	}
	return (owner_infos->pw_name);
}

static char		*get_group(struct stat infos)
{
	struct group	*group_infos;

	if (!(group_infos = getgrgid(infos.st_gid)))
	{
		ft_putendl("pb getgrgid"); // DELETE
		exit(0);
	}
	return (group_infos->gr_name);
}

// REFORMATER LA DATE
static char		*get_date(struct stat infos)
{
	char	*time;
	char	**time_table;

	time = ft_strdup(ctime(&(infos.st_mtimespec.tv_sec)));
	time_table = ft_strsplit(time, ' ');
//	ft_putstr_array(time_table, '*');
	time = ft_strtrim(time);
	return (time);
}

char			file_type(mode_t file_mode)
{
	if (S_ISDIR(file_mode))
		return ('d');
	else if (S_ISFIFO(file_mode))
		return ('p');
	else if (S_ISCHR(file_mode))
		return ('c');
	else if (S_ISBLK(file_mode))
		return ('b');
	else if (S_ISREG(file_mode))
		return ('-');
	else if (S_ISLNK(file_mode))
		return ('l');
	else if (S_ISSOCK(file_mode))
		return ('s');
	else
		return ('O');
}

char			*file_permissions(mode_t file_mode)
{
	char	*perms;

	perms = ft_strnew(10);
	(file_mode & S_IRUSR) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWUSR) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXUSR) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	(file_mode & S_IRGRP) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWGRP) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXGRP) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	(file_mode & S_IROTH) ? ft_strcat(perms, "r") : ft_strcat(perms, "-");
	(file_mode & S_IWOTH) ? ft_strcat(perms, "w") : ft_strcat(perms, "-");
	(file_mode & S_IXOTH) ? ft_strcat(perms, "x") : ft_strcat(perms, "-");
	return (perms);
}

t_files			*get_file_info(char *file_name)
{
	struct stat		buf;
	t_files	*file;

	if (!(file = (t_files *)ft_memalloc(sizeof(t_files))))
		return (NULL);
	if (stat(file_name, &buf) == -1)
		return (NULL);
	file->name = ft_strdup(file_name);
	file->type = file_type(buf.st_mode);
	file->permissions = file_permissions(buf.st_mode);
	file->links = buf.st_nlink;
	file->owner = get_owner(buf);
	file->group = get_group(buf);
	file->size = buf.st_size;
	file->date = get_date(buf);
	file->timestamp = buf.st_mtimespec.tv_sec;
	file->next = NULL;
	return (file);
}
