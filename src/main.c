/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:35:48 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/10 16:46:03 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv[])
{
	t_data	data;
	
	if (validate_argc(argc) || validate_file(argv[1]))
		return (EXIT_FAILURE);
	
	parse_description(argv[1], &data);
	//setup_mlx; test-assignment
	data.win.width = 1920;
	data.win.height = 1080;
	data.mlx_ptr = mlx_init();
	data.win.ptr = mlx_new_window(data.mlx_ptr, data.win.width, data.win.height, "m!n!RT");
	mlx_img_init(data.mlx_ptr, &data.win, &data.img);

	//setup ray; test assignment
	data.cam.ray.dir = (t_vec){0, 0, -1};
	data.cam.ray.origin = (t_vec){0, 0, 1};
	data.cam.ray.up = (t_vec){0, 1, 0};
	data.cam.ray.focal_len = 1.f;
	data.cam.ray.fov = 120.f;

	init_cam(&data.cam, data.win.width, data.win.height);
	//break point; lldb check
	mlx_put_image_to_window(data.mlx_ptr, data.win.ptr, data.img.ptr, data.win.width, data.win.height);
	listen_event(&data);
	return (0);
}
