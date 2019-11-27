/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsmienk <lsmienk@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 12:56:58 by lsmienk        #+#    #+#                */
/*   Updated: 2019/03/25 16:43:42 by lsmienk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}