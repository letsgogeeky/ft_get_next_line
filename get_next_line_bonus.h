/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:27:54 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/09 15:57:49 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

int		ft_strlen(char *c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, int len);
char	*ft_calloc(unsigned int count, unsigned int size);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

#endif