#include "raytracer.h"
#include "libft.h"
#include "libla.h"
#include "mlx.h"
#include "graphic.h"

#include <math.h>

# define WIDTH			500
# define HEIGHT			500
# define HALF_WIDTH		250
# define HALF_HEIGHT	250
# define PIXEL_SIZE		1.25 / 250
# define CANVA_Z_POS	5

t_ray	ray_for_pixel_test(unsigned int px, unsigned int py)
{
	t_vec4	origin;
	float	world_x;
	float	world_y;

	world_x = PIXEL_SIZE * HALF_WIDTH - (px + 0.5) * PIXEL_SIZE;
	world_y = PIXEL_SIZE * HALF_HEIGHT - (py + 0.5) * PIXEL_SIZE;
	origin = point(world_x, world_y, CANVA_Z_POS);
	return (ray(origin, vector(0, 0, -1)));
}

int	main(void)
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

	// sphere
	my_sphere = sphere();
	my_sphere.material = material();
	my_sphere.material.color = color_rgb_f(1, 0.2, 1);

	// transformation
	
	set_transform(&my_sphere, mat4_scaling(.4, .8, 1));
	add_transform(&my_sphere, mat4_rotation_z(M_PI/8));
	add_transform(&my_sphere, mat4_translation(.15, 0, 1));

	// light
	light = light_point(point(-10, 10, -10), color_rgb_f(1, 1, 1));

	// intersections
	intersections_list = NULL;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			r = ray_for_pixel_test(x, y);
			r.v_direction = vec4_normalize(r.v_direction); // Normalize the ray direction
			intersection_pair = intersect(r, my_sphere);
			if (intersection_pair.count == 1 || intersection_pair.count == 2)
			{
				intersec1 = (t_intersection *)malloc(sizeof(t_intersection));
				intersec2 = (t_intersection *)malloc(sizeof(t_intersection));
				if (intersec1 == NULL || intersec2 == NULL)
				{
					printf("Memory allocation error\n");
					return (1);
				}
				*intersec1 = intersection(intersection_pair.t[0], my_sphere);
				*intersec2 = intersection(intersection_pair.t[1], my_sphere);
				intersections(&intersections_list, intersec1);
				intersections(&intersections_list, intersec2);
			}
			hitting = hit(intersections_list);
			if (hitting)
			{
				pt = position(r, hitting->t);
				shading.normalv = normal_at(hitting->object, pt);
				shading.eyev = vec4_inv(r.v_direction);
				color = lighting(hitting->object.material, light, pt, shading);
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