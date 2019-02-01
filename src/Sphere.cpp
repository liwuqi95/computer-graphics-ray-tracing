#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  Eigen::Vector3d t_e = ray.origin - center;

  double a = ray.direction.dot(ray.direction);
  double b = 2 * t_e.dot(ray.direction);
  double c = t_e.dot(t_e) - radius * radius;

  double dt = b * b - 4 * a * c;

  if (dt >= 0) {

    dt = sqrt(dt);

    t = dt == 0 ? -b / (2 * a) : ((-b - dt) / (2 * a));
    n = ((t * ray.direction + ray.origin) - center) / radius;

    if (t >= min_t)
      return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}

