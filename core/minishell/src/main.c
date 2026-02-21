/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_ast(t_ast *ast, t_shell *sh)
{
	int	ret;

	if (!ast)
		return (1);
	if (handle_heredocs(ast, sh))
	{
		ast_free(ast);
		return (1);
	}
	ret = execute_ast(ast, sh);
	sh->exit_status = ret;
	ast_free(ast);
	return (0);
}

void	run_line(char *line, t_shell *sh)
{
	t_token	*tokens;
	t_ast	*ast;

	tokens = lexer(line);
	if (!tokens)
		return ;
	ast = parse_tokens(&tokens, sh);
	token_free(tokens);
	if (!ast)
		return ;
	process_ast(ast, sh);
}

static void	shell_loop(t_shell *sh)
{
	char	*line;

	while (1)
	{
		setup_signals_interactive();
		g_signal = 0;
		line = readline("minishell$ ");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			break ;
		}
		if (g_signal == SIGINT)
			sh->exit_status = 130;
		if (*line)
		{
			add_history(line);
			run_line(line, sh);
		}
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;

	(void)argc;
	(void)argv;
	sh.env = env_init(envp);
	sh.exit_status = 0;
	shell_loop(&sh);
	env_free(sh.env);
	rl_clear_history();
	return (sh.exit_status);
}
