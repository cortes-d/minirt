
#include "parser.h"

void	scene_data_to_scene(t_scene_data *scene_data, t_scene *scene)
{
	unsigned int	size;
	unsigned int	i;
	t_list			*current;

	size = ft_lstsize(scene_data->objects);
	scene->objects = gc_add(\
	(t_object **)malloc((size + 1) * sizeof(t_object *)), 1);
	if (scene->objects == NULL)
		exit_error("ERROR: scene_data_to_scene()\n");
	scene->objects[size] = NULL;
	current = scene_data->objects;
	i = 0;
	while (i < size)
	{
		scene->objects[i] = current->content;
		current->content = NULL;
		current = current->next;
		i++;
	}
	scene->camera = scene_data->cameras->content;
	scene_data->cameras->content = NULL;
	scene->light_ambient = scene_data->ambient_lights->content;
	scene_data->ambient_lights->content = NULL;
	scene->light_point = scene_data->lights->content;
	scene_data->lights->content = NULL;
}
