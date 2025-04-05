/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joho <joho@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:29:48 by joho              #+#    #+#             */
/*   Updated: 2025/04/05 20:50:41 by joho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int	check_args(int argc, char **argv, char *default_dict);
int	check_digits(char *str);
int	check_dict_file(char *dict);

#endif