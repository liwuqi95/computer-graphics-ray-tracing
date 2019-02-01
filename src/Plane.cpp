#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  double q = normal.dot(point);

  if (normal.dot(ray.direction) != 0) {
    t = (q - normal.dot(ray.origin)) / (normal.dot(ray.direction));
    n = normal;

    if (t >= min_t)
      return true;

  }
  return false;
  ////////////////////////////////////////////////////////////////////////////
}

