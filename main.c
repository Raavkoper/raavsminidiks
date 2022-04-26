/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkoper <rkoper@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/26 14:13:34 by rkoper        #+#    #+#                 */
/*   Updated: 2022/04/26 14:39:09 by rkoper        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
		lexer(&data, argv[1]);
	print_lexer(data.lexer);
	return (0);
}