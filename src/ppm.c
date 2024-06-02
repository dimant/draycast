#include <stdbool.h>

#include "ppm.h"

static int pixels_on_line = 0;

void ppm_write_header(FILE* file, int width, int height) {
	fprintf(file, "P3\n");
	fprintf(file, "%d %d\n", width, height);
	fprintf(file, "255\n");
	pixels_on_line = 0;
}

void ppm_reset_line() {
	pixels_on_line = 0;
}

void ppm_write_pixel (FILE* file, color c) {
	int ir = (int)(((num)255.999) * c.x);
	int ig = (int)(((num)255.999) * c.y);
	int ib = (int)(((num)255.999) * c.z);

	if (pixels_on_line < 4)
	{
		if (pixels_on_line > 0)
		{
			fprintf(file, " ");
		}

		fflush(stdout);

		fprintf(file, "%d %d %d", ir, ig, ib);
		pixels_on_line++;
	}
	else
	{
		fprintf(file, "\n");
		fprintf(file, "%d %d %d", ir, ig, ib);
		pixels_on_line = 1;
	}
}

void ppm_write_footer(FILE* file) {
	fprintf(file, "\n");
}

void ppm_write_canvas(FILE* file, canvas *c) {
	ppm_write_header(file, c->width, c->height);

	for (int j = 0; j < c->height; j++) {
		for (int i = 0; i < c->width; i++) {
			ppm_write_pixel(file, c->pixels[j * c->width + i]);
		}
	}

	ppm_write_footer(file);

	fflush(file);
}

