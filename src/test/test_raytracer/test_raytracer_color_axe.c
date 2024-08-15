/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer_color_axe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:18:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/15 11:42:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	test_raytracer_color_axe(void)
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
	t_light_point		light;
	t_vec3				color;
	t_vec4				pt;
	t_shading			shading;
	t_ray				r;

	// mlx
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "TEST_PHONG");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// objct
	my_object = sphere();
	//my_object = plane();
	// my_object = cylinder();
	// my_object.material = material();
	my_object.material.color = color_rgb_f(1, 0.2, 1);

	// transformation
	//set_transform(&my_object, mat4_scaling(.1, .1, .1));
	//add_transform(&my_object, mat4_rotation_z(M_PI/8));
	//add_transform(&my_object, mat4_translation(.15, 0, 1));

	// light
	light = light_point(point(-10, 10, -10), color_rgb_f(2, 2, 2));

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
				pt = position(r, hitting->t);
				shading.normalv = normal_at(hitting->object, pt);
				shading.eyev = vec4_inv(r.v_direction);
				color = lighting(hitting->object.material, light, pt, shading);

				// Conversion de la position du point en couleur RGB en fonction des axes
				float red = fabsf(pt.data[X]); 
				float green = fabsf(pt.data[Y]);
				float blue = fabsf(pt.data[Z]);
				red = fminf(1.0f, red);
				green = fminf(1.0f, green);
				blue = fminf(1.0f, blue);
				color = color_rgb_f(red, green, blue);

				write_pixel(&img, x, y, color);
				//printf("Hit at (%u, %u): color = (%f, %f, %f)\n", x, y, color.data[R], color.data[G], color.data[B]);
			}
			else
			{
				write_pixel(&img, x, y, vec3(0, 0, 0));
				//printf("No hit at (%u, %u)\n", x, y);
			}
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
