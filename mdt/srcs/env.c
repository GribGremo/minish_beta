/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grib <grib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:27:21 by sylabbe           #+#    #+#             */
/*   Updated: 2024/05/12 19:00:00 by grib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int exit_error(t_data *data, char *str);


// A ajouter : quand on appel la fcontion export -> ajouter une nouvelle variable dans t_env dans l'ordre
void	alpha_order(t_env *env)
{
	t_env *tmp;
	int len;
	char *str_temp;
	
	tmp = env;
	str_temp = NULL;
	len = 0;
	while (tmp->next != NULL)
	{
		if (ft_strlen(tmp->var) >= ft_strlen(tmp->next->var) )
			len = ft_strlen(tmp->var);
		else
			len = ft_strlen(tmp->next->var);
		if (ft_strncmp(tmp->var, tmp->next->var, len) > 0)
		{
			str_temp = ft_strdup(tmp->next->var);
			free(tmp->next->var);
			tmp->next->var = ft_strdup(tmp->var);
			free(tmp->var);
			tmp->var = ft_strdup(str_temp);
			free(str_temp);
			tmp = env;
		}
		else
			tmp = tmp->next;
	}
}
int add_qmark_env(t_data *data)
{
	t_env *node;
	
	add_env_node(data);
	node = ft_lstlast_env(data->env);
	node->var = malloc(2 * sizeof(char));//
	node->var[0] = '?';
	node->var[1] = '\0';
	node->value = malloc(2 * sizeof(char));//
	node->value[0]= '0';
	node->value[1]= '\0';
	node->origin = -1;
	return (0);
}

int get_env(t_data *data, char **envp)
{
	int i;
	t_env *node;
	char egual[2];

	egual[0] = '=';
	egual[1] = '\0';
	i = 0;
	while(envp[i] != NULL)
	{
		add_env_node(data);
		node = ft_lstlast_env(data->env);
		node->var =ft_substr_a(data->lst_alloc, envp[i], 0, found_char(envp[i], egual));
		node->value = ft_substr_a(data->lst_alloc, envp[i], found_char(envp[i], egual) + 1, ft_strlen(envp[i]));
		node->origin = 1;
		i++;
	}
	add_qmark_env(data);
	return (0);
}

// int sort_env(t_data *data)
// {
// 	t_env *node;

// 	node = data->env;
// 	while(node != NULL);
// 	{
// 		if()
// 	}
// }

// int add_var_env()
// {
	
// }

int	add_env_node(t_data *data)
{
	t_env	*node;

	if (data->env == NULL)
	{
		data->env = ft_lstnew_env(data->lst_alloc);
		if (data->env == NULL)
			exit_error(data, "Memory allocation issue");
	}
	else
	{
		node = ft_lstnew_env(data->lst_alloc);
		if (node == NULL)
			exit_error(data, "Memory allocation issue");
		ft_lstadd_back_env(&(data->env), node);
	}
	return (0);
}
int	found_char(const char *string, char *searchedChar)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (string[i] != '\0')
	{
		j = 0;
		while (searchedChar[j] != '\0')
		{
			if (string[i] == searchedChar[j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int exit_error(t_data *data, char *str)
{
	(void)data;
	(void)str;
	return (1);
}

t_env *get_env_var(t_data *data, char *str)
{
	t_env *node;

	node = data->env;
	while(node != NULL)
	{
		if (!strcmp(node->var, str))
			return (node);
		node = node->next;
	}
	return (NULL);
}