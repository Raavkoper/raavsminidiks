/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cdiks <cdiks@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 13:22:09 by rkoper        #+#    #+#                 */
/*   Updated: 2022/05/09 13:43:17 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	find_command(t_data *data, char *command, char **cmd_table)
{
	if (!ft_strncmp(command, "env", 3))
		ft_env(data->env);
	else if (!ft_strncmp(command, "exit", 4))
		ft_exit();
	else if (!ft_strncmp(command, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(command, "cd", 2))
		ft_cd(cmd_table);
}

void	ft_env(char **env)
{
	while (*env)
	{
		printf("%s\n", *env);
		env++;	
	}
}

void	ft_exit(void)
{
	printf("%scome back soon :)%s\n", BLUE, NC);
	exit(0);
}

void	ft_pwd(void)
{
	char	pwd[256];

	printf("%s\n", getcwd(pwd, sizeof(pwd)));
}

void	ft_cd(char **cmd_table)
{
	cmd_table++;
	if (!*cmd_table)
		return find_home_dir();
	if (chdir(*cmd_table))
	{
		printf("path not found\n");
		exit(1);
	}
}

void	find_home_dir(void)
{
	char	pwd[256];
	char	*path;
	char	*new_path;
	int		i;
	int		s_count;


	s_count = 0;
	i = 0;
	path = getcwd(pwd, sizeof(pwd));
	while (path[i])
	{
		if (s_count == 2 && (iswhitespace(path[i]) || path[i] == '/'))
		{
			i++;
			break ;
		}
		if (path[i] == '/')
			s_count++;
		i++;
	}
	new_path = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(new_path, path, i);
	if (chdir(new_path))
		printf("error near cd\n");
}

