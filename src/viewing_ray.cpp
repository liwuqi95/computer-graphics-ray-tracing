#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
    double u = camera.width / width * (double) (2 * j + 1 - width) / 2;
    double v = -camera.height / height * (double) (2 * i + 1 - height) / 2;
    double d = camera.d;

    ray.origin = camera.e;

    ray.direction(0) = u * camera.u(0) + v * camera.v(0) - (d * camera.w(0));
    ray.direction(1) = u * camera.u(1) + v * camera.v(1) - (d * camera.w(1));
    ray.direction(2) = u * camera.u(2) + v * camera.v(2) - (d * camera.w(2));
  ////////////////////////////////////////////////////////////////////////////
}
