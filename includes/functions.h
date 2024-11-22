/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:00:05 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/22 17:46:57 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// ERROR FUNCTIONS
char	*ft_error_msg_construct(int nbr, ...);
int		ft_put_error_msg(char *error_msg, int exit_status);

// PARSE FUNCTIONS
bool	ft_parse_input(char **av, int ac);

#endif