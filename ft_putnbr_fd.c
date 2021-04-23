/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: treo <treo@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:06:25 by treo              #+#    #+#             */
/*   Updated: 2021/04/23 18:13:17 by treo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	num_d;
	int	num_m;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n >= 20)
	{
		num_d = n / 10;
		num_m = n % 10;
		ft_putnbr_fd(num_d, fd);
		ft_putnbr_fd(num_m, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
