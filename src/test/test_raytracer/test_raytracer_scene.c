/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_raytracer_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:18:56 by achappui          #+#    #+#             */
/*   Updated: 2024/08/21 12:54:11 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_raytracer.h"

int	test_raytracer_scene(void)
{
	t_intersection		*hitting;
	t_list				*intersections_list;
	unsigned int		x;
	unsigned int		y;
	void				*mlx_ptr;
	void				*mlx_win;
	t_image				img;
	t_vec3				color;
	//t_vec4				pt;
	t_computation		c;
	t_ray				r;
    t_scene             scene;

	// mlx
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "TEST_PHONG");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


	// scene
    scene = scene_default();

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
			intersect_scene(r, scene, &intersections_list);
			hitting = hit(intersections_list);
			if (hitting)
			{
				//pt = position(r, hitting->t);
				c = prepare_computation(*hitting, r, *scene.light_point);
				//c.normalv = normal_at(hitting->object, pt);
				//c.eyev = vec4_inv(r.v_direction);
				color = lighting(c, *scene.light_point, light_ambient(1, color_rgb_f(1, 1, 1)), hitting->object.material);
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
