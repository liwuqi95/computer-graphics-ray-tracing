#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////

  Eigen::Vector3d t1 = std::get<1>(corners) - std::get<0>(corners);
  Eigen::Vector3d t2 = std::get<2>(corners) - std::get<0>(corners);

  Eigen::Vector3d v = ray.direction;
  Eigen::Vector3d u = std::get<0>(corners) - ray.origin;



  double a = t1(0), b = t2(0), c = -v(0), d = u(0);
  double l = t1(1), m = t2(1), o = -v(1), k = u(1);
  double p = t1(2), q = t2(2), r = -v(2), s = u(2);


  double D = (a*m*r+b*p*o+c*l*q)-(a*o*q+b*l*r+c*m*p);

  t = ((a*q*k+b*l*s+d*m*p)-(a*m*s+b*p*k+d*l*q))/D;


  if (t >= min_t){


    double alpha = ((b*r*k+c*m*s+d*o*q)-(b*o*s+c*q*k+d*m*r))/D;
    double beta  = ((a*o*s+c*p*k+d*l*r)-(a*r*k+c*l*s+d*o*p))/D;


    if (alpha >= 0 && beta >= 0 && (alpha + beta) <= 1) {

      n = t1.cross(t2).normalized();
      return true;
    }
  }


  return false;
  ////////////////////////////////////////////////////////////////////////////
}


