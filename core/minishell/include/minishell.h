/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:00:00 by joho              #+#    #+#             */
/*   Updated: 2026/02/21 10:00:00 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>

extern int	g_signal;

typedef enum e_token_type
{
	TOK_WORD,
	TOK_PIPE,
	TOK_REDIR_IN,
	TOK_REDIR_OUT,
	TOK_APPEND,
	TOK_HEREDOC,
	TOK_AND,
	TOK_OR,
	TOK_LPAREN,
	TOK_RPAREN
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_redir_type;

typedef struct s_redir
{
	t_redir_type	type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef enum e_node_type
{
	NODE_CMD,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_SUBSHELL
}	t_node_type;

typedef struct s_cmd
{
	char	**argv;
	int		argc;
}	t_cmd;

typedef struct s_ast
{
	t_node_type		type;
	t_cmd			cmd;
	t_redir			*redirs;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_shell
{
	t_env	*env;
	int		exit_status;
}	t_shell;

/* main.c */
void			run_line(char *line, t_shell *sh);

/* signals.c */
void			setup_signals_interactive(void);
void			setup_signals_child(void);
void			setup_signals_heredoc(void);

/* lexer */
t_token			*lexer(char *input);
t_token			*token_new(t_token_type type, char *value);
void			token_add(t_token **lst, t_token *new);
void			token_free(t_token *lst);
int				is_special_char(char c);
int				is_quote(char c);
int				skip_quotes(char *s, int i);
char			*extract_word(char *s, int *i);

/* parser */
t_ast			*parse_tokens(t_token **tok, t_shell *sh);
t_ast			*parse_expression(t_token **tok, t_shell *sh);
t_ast			*parse_pipeline(t_token **tok, t_shell *sh);
t_ast			*parse_command(t_token **tok, t_shell *sh);
t_ast			*parse_simple_cmd(t_token **tok);
int				parse_redir(t_token **tok, t_redir **rds);
t_ast			*ast_new(t_node_type type);
void			ast_free(t_ast *node);
void			redir_add(t_redir **lst, t_redir *new);
void			redir_free(t_redir *lst);
int				is_redir_token(t_token *tok);
int				syntax_error(char *msg, t_shell *sh);

/* expander */
char			**expand_args(char **argv, int argc, t_shell *sh);
char			*expand_string(char *s, t_shell *sh);
char			*expand_quotes(char *s, t_shell *sh);
char			**expand_wildcard(char *pattern);
int				has_wildcard(char *s);

/* executor */
int				execute_ast(t_ast *node, t_shell *sh);
int				execute_cmd(t_ast *node, t_shell *sh);
int				execute_pipe(t_ast *node, t_shell *sh);
int				apply_redirections(t_redir *rds);
int				handle_heredocs(t_ast *node, t_shell *sh);
char			*find_command(char *cmd, t_shell *sh);

/* builtins */
int				is_builtin(char *cmd);
int				run_builtin(char **argv, t_shell *sh);
int				builtin_echo(char **argv);
int				builtin_cd(char **argv, t_shell *sh);
int				builtin_pwd(void);
int				builtin_export(char **argv, t_shell *sh);
int				builtin_unset(char **argv, t_shell *sh);
int				builtin_env(t_shell *sh);
int				builtin_exit(char **argv, t_shell *sh);

/* env */
t_env			*env_init(char **envp);
char			*env_get(t_env *env, char *key);
int				env_set(t_env **env, char *key, char *val);
int				env_unset(t_env **env, char *key);
void			env_free(t_env *env);
char			**env_to_array(t_env *env);
int				env_size(t_env *env);

#endif
