#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>

Eigen::Vector3d blinn_phong_shading(
        const Ray &ray,
        const int &hit_id,
        const double &t,
        const Eigen::Vector3d &n,
        const std::vector<std::shared_ptr<Object> > &objects,
        const std::vector<std::shared_ptr<Light> > &lights) {
    ////////////////////////////////////////////////////////////////////////////

    Eigen::Vector3d color = 0.1 * objects[hit_id]->material->ka;
    Eigen::Vector3d hit_point = ray.origin + ray.direction * t;

    for (int i = 0; i < lights.size(); i++) {

        Eigen::Vector3d direction;
        double max_t;

        lights[i]->direction(hit_point, direction, max_t);


        Ray shadow_ray;
        shadow_ray.origin = hit_point;
        shadow_ray.direction = direction;

        int shadow_hit_id;
        double shadow_t;
        Eigen::Vector3d shadow_n;


        if (!first_hit(shadow_ray, 0.00001, objects, shadow_hit_id, shadow_t, shadow_n) || shadow_t >= max_t) {

            Eigen::Vector3d l = direction.normalized();

            if (n.dot(l) > 0)
                color = color + (objects[hit_id]->material->kd.array() * lights[i]->I.array()).matrix() * n.dot(l);

            Eigen::Vector3d half_vector = ((-ray.direction).normalized() + l).normalized();

            if (n.dot(half_vector) > 0)
                color = color + (objects[hit_id]->material->ks.array() * lights[i]->I.array()).matrix() *
                                pow(n.dot(half_vector), objects[hit_id]->material->phong_exponent);
        }
    }

    return color;
    ////////////////////////////////////////////////////////////////////////////
}
