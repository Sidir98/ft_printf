/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 20:28:40 by exam              #+#    #+#             */
/*   Updated: 2019/05/23 13:20:03 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_putchar(char c)
{
	write(1, &c, 1);
	return(0);
}

int ft_atoim(char *tab)
{
	int i;
	int nb;
	int m;

	i = 0;
	nb = 0;
	m = 1;
	while (tab[i])
	{
		nb = nb * 10;
		nb += tab[i] - '0';
		i++;
	}
	return (nb);
}
void ft_puthex(int nb,char *base)
{
	if (nb >= 16)
		ft_puthex(nb / 16,base);
	ft_putchar(base[nb % 16]);
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int nb;
		char *base = "0123456789abcdef";
		nb = ft_atoim(argv[1]);
		ft_puthex(nb,base);
	}
	ft_putchar('\n');
}
