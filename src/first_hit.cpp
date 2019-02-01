#include "first_hit.h"

bool first_hit(
        const Ray &ray,
        const double min_t,
        const std::vector<std::shared_ptr<Object> > &objects,
        int &hit_id,
        double &t,
        Eigen::Vector3d &n) {
    ////////////////////////////////////////////////////////////////////////////
    bool found = false;

    for (int i = 0; i < objects.size(); i++) {

        double t_temp;
        Eigen::Vector3d n_temp;

        bool object_hit = (*(objects[i])).intersect(ray, min_t, t_temp, n_temp);

        if (object_hit && (!found || t_temp < t)) {
            t = t_temp;
            n = n_temp;
            found = true;
            hit_id = i;
        }
    }

    return found;
    ////////////////////////////////////////////////////////////////////////////
}
