#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

bool raycolor(
        const Ray &ray,
        const double min_t,
        const std::vector<std::shared_ptr<Object> > &objects,
        const std::vector<std::shared_ptr<Light> > &lights,
        const int num_recursive_calls,
        Eigen::Vector3d &rgb) {
    ////////////////////////////////////////////////////////////////////////////



    int hit_id;
    double t;
    Eigen::Vector3d n;
    if (!first_hit(ray, min_t, objects, hit_id, t, n))
        return false;


    Eigen::Vector3d color = blinn_phong_shading(ray, hit_id, t, n, objects, lights);

    if (num_recursive_calls < 5) {
        Ray ray_reflect;
        ray_reflect.origin = ray.origin + ray.direction * t;
        ray_reflect.direction = reflect(ray.direction.normalized(), n);

        Eigen::Vector3d color_reflect;
        if (raycolor(ray_reflect, 0.00001, objects, lights,
                     num_recursive_calls + 1, color_reflect))
            color += (objects[hit_id]->material->km.array() * color_reflect.array()).matrix();
    }

    rgb = color;

    return true;

    ////////////////////////////////////////////////////////////////////////////
}
