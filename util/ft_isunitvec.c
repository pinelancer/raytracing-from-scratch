/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isunitvec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:21:10 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:01:41 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftx.h"

int	ft_isunitvec(t_vec vec)
{
	if ((pow(vec.i, 2) + pow(vec.j, 2) + pow(vec.k, 2)) != 1)
		return (0);
	return (1);
}
