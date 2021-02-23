#include "wolf3d.h"

int	main(void)
{
	void *mlx;
	void *img;
	void *win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 600, 600, "test");
	char *relative_path = "./wood.xpm";
	int width;
	int height;
	img = mlx_xpm_file_to_image(mlx, relative_path, &width, &height);
	int i = 0;
	int j = 0;
	while (i < 64)
	{
		i++;
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}