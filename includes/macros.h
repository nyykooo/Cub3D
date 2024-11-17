/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:04:32 by ncampbel          #+#    #+#             */
/*   Updated: 2024/11/17 18:07:51 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define ERROR_MSG(nbr, ...) ft_error_msg_construct(nbr, __VA_ARGS__)
# define ERROR_PRINT(msg, status) ft_put_error_msg(msg, status)
# define ERROR_AC "Error: Invalid number of arguments\n"

#endif