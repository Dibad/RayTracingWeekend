#include "metal.h"

Metal::Metal(const Vec3& a, float f)
    : albedo(a)
{
    if (f < 1)
        fuzz = f;
    else
        fuzz = 1;
}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const
{
    Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}