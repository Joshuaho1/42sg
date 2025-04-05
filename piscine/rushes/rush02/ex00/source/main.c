/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:51:58 by joho              #+#    #+#             */
/*   Updated: 2025/04/06 01:05:30 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int	error(void)
{
	ft_error("Error\n");
	return (1);
}

static int	dict_error(void)
{
	ft_error("Dict Error\n");
	return (1);
}

static int	run(char *dict_path, char *input)
{
	t_dict			dict;
	t_nbr_buffer	*nbr;
	int				valid_dict;
	int				valid_nbr;
	char			*str;

	str = read_file(dict_path);
	dict = new_dict();
	valid_dict = dict_parse(&dict, str);
	if (valid_dict == -1)
		return (dict_error());
	nbr = new_nbr_buffer();
	valid_nbr = nbr_chunk(nbr, &dict, input);
	if (valid_nbr == -1)
		return (dict_error());
	print_nbr_buffer(nbr);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = check_args(argc, argv, DEFAULT_DICT);
	if (i == 0)
		return (error());
	else if (i == -1)
		return (dict_error());
	if (argc == 2)
	{
		run(DEFAULT_DICT, argv[1]);
	}
	else if (argc == 3)
	{
		run(argv[1], argv[2]);
	}
	return (0);
}
