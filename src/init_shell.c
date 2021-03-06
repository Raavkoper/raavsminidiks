/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_shell.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 11:34:32 by rkoper        #+#    #+#                 */
/*   Updated: 2022/06/03 14:46:50 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	welcome(void)
{
	printf("%s%s\n", YELLOW, "                                                \
,--.        ,--.   ,--.,--.,--.           ");
	printf("%s%s\n", GREEN, "--.--. ,--,--. ,--,--.,--.  ,--.,---. ,--,--,--.`\
--\',--,--, `--\' ,-|  |`--\'|  |,-.  ,---. ");
	printf("%s%s\n", BLUE, "  .--\'\' ,-.  |\' ,-.  | \\  `\'  /(  .-\' |     \
   |,--.|      \\,--.\' .-. |,--.|     / (  .-\' ");
	printf("%s%s\n", RED, "  |   \\ \'-\'  |\\ \'-\'  |  \\    / .-\'  `)|  | \
 |  ||  ||  ||  ||  |\\ `-\' ||  ||  \\  \\ .-\'  `)");
	printf("%s%s%s\n", YELLOW, "--\'    `--`--\' `--`--\'   `--\'  `----\' `--\
`--`--\'`--\'`--\'\'--\'`--\' `---\' `--\'`--\'`--\'`----\' ", NC);
}

char	*init_shell(void)
{
	char	*line;

	line = (char *)readline("\033[1m\033[32mminishell$>\x1B[0m ");
	add_history(line);
	return (line);
}

void	run_shell(t_data *data)
{
	char	*line;

	welcome();
	while (1)
	{
		line = init_shell();
		if (line && line[0])
		{
			free_lexer(&data->lexer);
			free_redirections(&data->parser);
			free_parser(&data->parser);
			lexer(data, line);
			//print_lexer(data->lexer);
			error_check(&data->lexer);
			parser(data);
			print_parser(data->parser);
			redirections(data);
			//print_redirections(data->parser->red);
			shell_pipex(data);
			// executor(data);
		}
		free(line);
		//system("leaks minishell");
	}
}
