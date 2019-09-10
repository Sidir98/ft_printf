/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouabda <ibouabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 12:50:22 by ibouabda          #+#    #+#             */
/*   Updated: 2019/09/09 14:18:35 by ibouabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list *initialize_lst() //initialise les differents maillons/reperes
{
	t_list *m;

	m = ft_lstnewc(&ft_itoa, 'd');
	ft_lstaddend(&m, ft_lstnewc(&ft_itoa, 'i'));
	ft_lstaddend(&m, ft_lstnewc(&o, 'o'));
	ft_lstaddend(&m, ft_lstnewc(&u, 'u'));
	ft_lstaddend(&m, ft_lstnewc(&x, 'x'));
	ft_lstaddend(&m, ft_lstnewc(&X, 'X'));
	ft_lstaddend(&m, ft_lstnewc(&c, 'c'));
	ft_lstaddend(&m, ft_lstnewc(NULL, 's'));
	ft_lstaddend(&m, ft_lstnewc(&f, 'f'));
	ft_lstaddend(&m, ft_lstnewc(&p, 'p'));
	ft_lstaddend(&m, ft_lstnewc(NULL, '%'));
	return (m);
}

pf_spe *ft_pf_spenew()
{
	pf_spe *vars;

	if (!(vars = (pf_spe *)malloc(sizeof(pf_spe))))
	{
		ft_putendl("ft_pf_spenew malloc error");
		exit(EXIT_FAILURE);
	}
	vars->nbl = 0;
	vars->nbp = 0;
	vars->precs = 6;
	vars->flag = 0;
	vars->convert = NULL;
	vars->arg = 0;
	return(vars);
}

char *spe_search(va_list args, t_list *m, char *str, pf_spe *vars) // va chercher dans tous les maillons le bon repere
{
	while ((int)(m->content_size) != str[0] && m->next)
		m = m->next;
	if ((int)(m->content_size) == str[0])
	{
		if ((int)m->content_size == 'f')
			return (((char *(*)(double, int))m->content)(va_arg(args, double), vars->precs));
		else if ((int)m->content_size == 'p')
			return (((char *(*)(void *))m->content)(va_arg(args, void *)));
		else if ((int)m->content_size == 's')
			return (ft_strdup(va_arg(args, char *)));
		else if ((int)m->content_size == '%')
			return ("%");
		else
			return ((((char *(*)(int))m->content)(va_arg(args, int))));
	}
	return (NULL);
}

void spe_input(pf_spe *vars, char **str) //fixe la largeur de champs ou le nombre de chiffres
{
	if (ft_strchr("#0-+", **str)) // utiliser ft_prstr2chr avec arg
	{
		vars->flag = **str;
		*str += 1;
	}
	if (**str > '0' && **str <= '9') //largeur de champs
	{
		vars->nbl = ft_atoi(*str);
		*str += ft_countnumbers(vars->nbl);
	}
	if (**str == '.') //nombres de chiffres
	{
		*str = *str + 1;
		vars->nbp = ft_atoi(*str);
		*str += ft_countnumbers(vars->nbp);
		vars->precs = vars->nbp;
	}
	if (ft_strnstrdup(*str,"l", 1, &vars->convert)
	|| ft_strnstrdup(*str,"ll", 2, &vars->convert)
	|| ft_strnstrdup(*str ,"h", 1, &vars->convert)
	|| ft_strnstrdup(*str ,"hh", 2, &vars->convert)
	|| ft_strnstrdup(*str ,"L", 1, &vars->convert))
		*str += ft_strlen(vars->convert);
}
void modify_toprint(char **str, pf_spe *vars, char **toprint) //modifie selon la largeur de champs et le nombre de chiffres
{
	char *todel;
	char *todel2;

	if (vars->nbp > 0 && vars->nbp < (int)ft_strlen(*toprint) && **str == 's')
		*toprint[vars->nbp] = '\0';
	if (ft_strchr("diouxX", **str)
	&& vars->nbp > 0 && vars->nbp > (int)ft_strlen(*toprint))
	{
		todel = *toprint;
		todel2 = ft_strchar(vars->nbp - ft_strlen(todel), '0');
		*toprint = ft_strjoin(todel2, todel);
		ft_strdel(&todel);
		ft_strdel(&todel2);
	}
	if (0 < (vars->nbl - (int)ft_strlen(*toprint)))
	{
		todel = *toprint;
		todel2 = ft_strchar(vars->nbl - ft_strlen(todel), ' ');
		*toprint = ft_strjoin(todel2, todel);
		ft_strdel(&todel);
		ft_strdel(&todel2);
	}
}

int spe_out(va_list args, t_list *m, char *str) //s'occupe du cas %...
{
	char	*toprint;
	char	*arg;
	pf_spe *vars;

	vars = ft_pf_spenew();
	if (ft_prstr2chr(str, "%cspdiouxXf") >= 0)
		arg = ft_strsub(str, 0, ft_prstr2chr(str, "%cspdiouxXf"));
	else
		ft_putendl("Bad argument");
	spe_input(vars, &str);
	if (!(toprint = spe_search(args, m, str, vars)))
	{
		ft_putendl("Bad argument");
		exit(0);
	}
	modify_toprint(&str, vars, &toprint);
	ft_putstr(toprint);
	vars->nbp = ft_strlen(toprint);
	ft_strdel(&toprint);
	return (vars->nbp);
}

t_list *initialize(int *i, int *k, int *count, char *str) // lance l'initialisation de la liste
{
	*i = 0;
	*count = 0;
	*k = 0;
	if (str == NULL)
	{
		ft_putstr("Error no arguments\n");
		exit(0);
	}
	else
		return (initialize_lst());
}

int ft_printf(char *str, ...)
{
	va_list args;
	t_list *m;
	int i;
	int k;
	int count;

	m = initialize(&i, &k, &count, str);
	va_start(args, str);
	while (str[i + k])
	{
		if (str[i + k] == '%')
		{
			i--;
			k += 2;
			count += spe_out(args, m, str + i + k);
			while (!ft_strchr("%cspdiouxXf", str[i + k]))
				k++;
		}
		else
			ft_putchar(str[i + k]);
		i++;
	}
	va_end(args);
	ft_lstdelm(&m);
	return (i + count);
}

int main(int argc, char **argv)
{
	(void)argc;
	char *str;
	int i;
	int k;

	str = "test : ";
	str = ft_strjoin(str, argv[1]); //leaks
	str = ft_strjoin(str, "\n");
	i = ft_printf("test : %f\n", (double)5);
	k = printf("test : %f\n", (double)5);
	//i = ft_printf(str, ft_atoi(argv[2]));
	//k = printf(str, ft_atoi(argv[2]));
	//k = printf("test : %15.5xlol\n", 15635);
	printf("My equal to %i\n", i);
	printf("Official equal to %i\n", k);
	return (0);
}