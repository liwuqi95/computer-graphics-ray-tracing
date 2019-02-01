#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  std::ofstream f(filename);
  bool color_channel = (num_channels == 3);


  f << 'P' << (color_channel ? "3" : "2") << '\n';
  f << width << '\t' << height << '\n';
  f << "255" << '\n';

  for (int i = 0; i < data.size(); i++) {

    f << int(data[i]) << ' ';

    if (i != 0 && i % width == 0)
      f << '\n';

  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
