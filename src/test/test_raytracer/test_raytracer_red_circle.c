/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer_red_circle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:20:57 by dcortes           #+#    #+#             */
/*   Updated: 2024/08/14 16:21:55 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	test_raytracer_red_circle(void)
{
	t_object			my_sphere;
	t_intersection_pair	intersection_pair;
	t_intersection		*intersec1;
	t_intersection		*intersec2;
	t_intersection		*hitting;
	t_list				*intersections_list;
	unsigned int		x;
	unsigned int		y;
	void				*mlx_ptr;
	void				*mlx_win;
	t_image				img;

	// mlx
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "TEST_RED_CIRCLE");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// sphere
	my_sphere = sphere();
	my_sphere.material = material_from_color(255, 0, 0);

	// intersections
	intersections_list = NULL;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			intersection_pair = intersect(test_ray_for_pixel(x, y), my_sphere);
			if (intersection_pair.count == 1 || intersection_pair.count == 2)
			{
				intersec1 = (t_intersection *)malloc(sizeof(t_intersection));
				intersec2 = (t_intersection *)malloc(sizeof(t_intersection));
				if (intersec1 == NULL)
					return (printf("ERROR\n"));
				if (intersec2 == NULL)
					return (printf("ERROR\n"));
				*intersec1 = intersection(intersection_pair.t[0], my_sphere);
				*intersec2 = intersection(intersection_pair.t[1], my_sphere);
				intersections(&intersections_list, intersec1);
				intersections(&intersections_list, intersec2);
			}
			hitting = NULL;
			hitting = hit(intersections_list);
			if (hitting)
				write_pixel(&img, x, y, hitting->object.material.color);
			else
				write_pixel(&img, x, y, vec3(0, 0, 0));
			ft_lstclear(&intersections_list, &free);
			intersections_list = NULL;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
