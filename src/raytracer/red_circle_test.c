/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_circle_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:33:05 by achappui          #+#    #+#             */
/*   Updated: 2024/08/06 17:16:14 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include "libft.h"
#include "libla.h"
#include "mlx.h"
#include "graphic.h"

# define WIDTH			500
# define HEIGHT			500
# define HALF_WIDTH		250
# define HALF_HEIGHT	250
# define PIXEL_SIZE		1.25 / 250
# define CANVA_Z_POS	5


t_ray	ray_for_pixel_test(unsigned int px, unsigned int py)
{
	t_vec4	pixel;
	t_vec4	origin;
	t_vec4	direction;
	float	world_x;
	float	world_y;

	world_x = HALF_WIDTH - (px + 0.5) * PIXEL_SIZE;
	world_y = HALF_HEIGHT - (py + 0.5) * PIXEL_SIZE;
	pixel = point(world_x, world_y, CANVA_Z_POS);
	origin = point(0, 0, 0);
	direction = vec4_normalize(vec4_sub(pixel, origin));
	return (ray(origin, direction));
}

int	main()
{
	t_object			my_sphere;
	t_intersection_pair	intersection_pair;
	t_intersection		*intersec;
	t_list				*intersections_list;
	unsigned int		x;
	unsigned int		y;
	void				*mlx_ptr;
	void				*mlx_win;
	t_image				img;				

	intersections_list = NULL;
	my_sphere = sphere();
	my_sphere.material.color = vec3(255, 0, 0);
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "RED_CIRCLE_TEST");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	// write_pixel(&img, 10, 10, vec3(255, 0, 0));
	// write_pixel(&img, 11, 10, vec3(255, 0, 0));
	// write_pixel(&img, 10, 11, vec3(255, 0, 0));
	// write_pixel(&img, 11, 11, vec3(255, 0, 0));
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			vec4_print(ray_for_pixel_test(x, y).p_origin);
			vec4_print(ray_for_pixel_test(x, y).v_direction);
			intersection_pair = intersect(ray_for_pixel_test(x, y), my_sphere);
			intersec = (t_intersection *)malloc(sizeof(t_intersection));
			if (intersec == NULL)
				return (printf("ERROR\n"));
			*intersec = intersection(intersection_pair.t[0], my_sphere);
			intersections(&intersections_list, intersec);
			if (intersection_pair.t[0] != intersection_pair.t[1])
			{
				intersec = (t_intersection *)malloc(sizeof(t_intersection));
				if (intersec == NULL)
					return (printf("ERROR\n"));
				*intersec = intersection(intersection_pair.t[1], my_sphere);
				intersections(&intersections_list, intersec);
			}
			intersec = NULL;
			intersec = hit(intersections_list);
			if (intersec)
			{
				//printf("GORRIGLE\n");
				write_pixel(&img, x, y, intersec->object.material.color);
			}
			else
			{
				printf("GORRIGLE\n");
				write_pixel(&img, x, y, vec3(0, 0, 0));
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