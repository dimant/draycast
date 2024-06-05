#ifndef PPM_H
#define PPM_H

#include "output_stream.h"

#include "canvas.h"

class PPM
{
private:
    int pixels_on_line = 0;

public:
    void write_header(OutputStream &str, const int &width, const int &height);

    void write_pixel(OutputStream &str, const Tuple &c);

    void write_footer(OutputStream &str);

    void write_canvas(OutputStream &std, const Canvas &c);
};

#endif