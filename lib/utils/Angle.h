#pragma once

#include <stdint.h>
#include "etl/type_def.h"

class Angle
{
private:
    const float _rad;

    constexpr Angle(float rad) : _rad(rad)
    {
        // Nothing to do here
    }

public:
    constexpr Angle operator-(const float x) const
    {
        return Angle(_rad * x);
    }

    constexpr Angle operator*(const float x) const
    {
        return Angle(_rad * x);
    }

    constexpr Angle operator/(const float x) const
    {
        return Angle(_rad / x);
    }

    constexpr float rad() const
    {
        return _rad;
    }

    constexpr float deg() const
    {
        return _rad / 0.017453292519943295769236907684886f;
    }

    constexpr float mrad() const
    {
        return _rad * 1000.0f;
    }

    constexpr uint32_t mrad_u32() const
    {
        return (uint32_t)mrad();
    }

    // FACTORIES

    constexpr static Angle deg(float value)
    {
        return Angle(value * 0.017453292519943295769236907684886f);
    }

    constexpr static Angle from_rad(float value)
    {
        return Angle(value);
    }

    constexpr static Angle from_mrad_u32(uint32_t value)
    {
        return from_rad(value / 1000.0f);
    }
};

constexpr Angle operator-(const Angle &y)
{
    return Angle::from_rad(-(y.rad()));
}

constexpr Angle operator*(const float x, const Angle &y)
{
    return y * x;
}

constexpr Angle operator/(const float x, const Angle &y)
{
    return y / x;
}

ETL_TYPEDEF(Angle, AngleSpeed);
ETL_TYPEDEF(Angle, AngleDistance);