#include "minishell.h"


int	init_lst_alloc(t_data *data)
{
	data->lst_alloc = malloc(sizeof(t_alloc **));
	if (data->lst_alloc != NULL)
	{
		*data->lst_alloc = NULL;
		if (add_alloc(data->lst_alloc, NULL, (void *)data->lst_alloc))
			return (1);
	}
	else
	{
		free(data);// ? PAS BESOIN
		ft_printf("Error : Memory allocation issue\n");
		return (1);
	}
	return (0);
}

int    init_data(char **envp, t_data *data);

int	ft_strcmp(const char *stro, const char *strt);

int    init_data(char **envp, t_data *data)
{
	data->lst_alloc = NULL;
	if(init_lst_alloc(data))
		return (1);
	data->envp = envp;
	data->entry = NULL;
	data->env = NULL;
	data->lst_char = NULL;
	data->lst_word = NULL;
	return (0);
}

int display_prompt(t_data *data)
{
	(void)data;
	char *entry;
	while(1)
	{
		entry = readline("Minishell>");
		if (is_entry_empty(entry))
		{
			add_history(entry);
            data->entry = entry;
            create_lst_char(data);
            check_quote(data); 
            token_char(data);
			expand(data);
			create_lst_word(data);
            print_lst_char(data, 'r');
			print_lst_word(data);
			if (ft_strcmp(entry,"exit") == 0)
			{
				free(entry);
				break;        
			}
		}
		free(entry);
		data->lst_char = NULL;// ! TEMP : IL FAUDRA FREE POTENTIELLEMENT
		data->lst_word = NULL;
	}
	rm_lst_alloc(*data->lst_alloc,"LST_ALLOC CLEARED: END OF PROMPT");
	return (0);
}

int main(int ac, char **av, char **envp)
{
	t_data  data;

	init_data(envp, &data);
	get_env(&data, envp);
	print_env_debug(&data);
	display_prompt(&data);
	(void) av;
	(void) ac;
	(void) envp;
	return (0);
}

int	ft_strcmp(const char *stro, const char *strt)
{
	int	i;

	i = 0;
	//if (stro[i])
	while (stro[i] != '\0' || strt[i] != '\0')
	{
		if (stro[i] != strt[i])
			return ((unsigned char)stro[i] - (unsigned char)strt[i]);
		i++;
	}
	if (stro[i] != strt[i])
		return ((unsigned char)stro[i] - (unsigned char)strt[i]);
	return (0);
}

int is_entry_empty(char *entry)
{
	int i;

	i = 0;
	while (entry[i] != '\0')
	{
		if (entry[i] > 32 && entry[i] < 127)
			return (1);
		i++;
	}
	return (0);
}
