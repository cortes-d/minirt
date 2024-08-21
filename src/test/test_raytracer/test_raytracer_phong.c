/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer_phong.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:18:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 12:54:42 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	test_raytracer_phong(void)
{
	t_object			my_object;
	//t_intersection_pair	intersection_pair;
	//t_intersection		*intersec1;
	//t_intersection		*intersec2;
	t_intersection		*hitting;
	t_list				*intersections_list;
	unsigned int		x;
	unsigned int		y;
	void				*mlx_ptr;
	void				*mlx_win;
	t_image				img;
	t_light_point		my_light_point;
	t_light_ambient		my_light_ambient;
	t_vec3				color;
	t_ray				r;

	// mlx
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "TEST_PHONG");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// object
	my_object = sphere_default();
	//my_object = plane();
	// my_object = cylinder_default();
	my_object.material = material_default();
	my_object.material.color = color_rgb_f(1, 0.2, 1);
	// my_object.u_object.cylinder.maximum = 0.5;
	// my_object.u_object.cylinder.minimum = -0.5;
	// transformation
	//set_transform(&my_object, mat4_scaling(.1, .1, .1));
	//add_transform(&my_object, mat4_rotation_z(M_PI/8));
	//add_transform(&my_object, mat4_translation(.15, 0, 1));

	// add_transform(&my_object, mat4_scaling(0.25, 1, 0.25)); // Scale the cylinder
	// add_transform(&my_object, mat4_rotation_x(M_PI / 4)); // Rotate around the X-axis
	// add_transform(&my_object, mat4_rotation_y(M_PI / 6)); // Rotate around the Y-axis
	// add_transform(&my_object, mat4_translation(0.5, 0, 1)); // Translate to a new position*/
	// light
	my_light_point = light_point(point(-20, 10, -10), 1, color_rgb_f(1, 1, 1));
	my_light_ambient = light_ambient(1, color_rgb_f(1, 1, 1));
	// intersections
	intersections_list = NULL;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r = test_ray_for_pixel(x, y);
			r.v_direction = vec4_normalize(r.v_direction); // Normalize the ray direction
			intersect(r, my_object, &intersections_list);
			hitting = hit(intersections_list);
			if (hitting)
			{
				color = lighting(prepare_computation(*hitting, r, my_light_point), my_light_point, my_light_ambient, hitting->object.material);
				write_pixel(&img, x, y, color);
				//printf("Hit at (%u, %u): color = (%f, %f, %f)\n", x, y, color.data[R], color.data[G], color.data[B]);
			}
			else
			{
				write_pixel(&img, x, y, vec3(0, 0, 0));
				//printf("No hit at (%u, %u)\n", x, y);
			}
			ft_lstclear_plus(&intersections_list, &gc_free, &gc_free);
			intersections_list = NULL;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
