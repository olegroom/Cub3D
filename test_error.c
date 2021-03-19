#include "wolf3d.h"

int	main(void)
{
	FILE *fl;
	int n;
	int err;
	char s[100];
	fl = fopen("fil.txt", "w");
	for (int i = 0; i < 100; i++)
		printf("Error #%d: %s\n", i, strerror(i));
	fclose(fl);
	return (0);
}