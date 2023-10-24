/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:14:16 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/24 10:50:57 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/*# include <libreriasestandarquevayaausar>*/
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/*el tema de asegurar que haya un buffer*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*ahora las funciones*/
char	*ft_challoc(size_t count);
bool	ft_srchnl(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
