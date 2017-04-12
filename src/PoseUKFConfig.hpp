#ifndef _UWV_KALMAN_FILTERS_POSE_UKF_CONFIG_HPP
#define _UWV_KALMAN_FILTERS_POSE_UKF_CONFIG_HPP

#include <base/Eigen.hpp>

namespace uwv_kalman_filters
{

struct InertialNoiseParameters
{
    /*  Random walk ((m/s^s)/sqrt(Hz) for accelerometers or (rad/s)/sqrt(Hz) for gyros) */
    base::Vector3d randomwalk;

    /*  Bias offset in static regimen (initial bias value) */
    base::Vector3d bias_offset;

    /* Bias instability (m/s^2 for accelerometers or rad/s for gyros) */
    base::Vector3d bias_instability;

    /* Tau value to limit the bias gain in seconds */
    double bias_tau;
};

struct DynamicModelNoiseParameters
{
    /* Standard deviation of linear body effort measurements (N/sqrt(Hz)) */
    base::Vector3d body_efforts_std;

    /* Liniar damping parameter instability (kg/s)
     * The instability is mapped to the x, yx, xy, y, xψ, yψ components of
     * the damping matrix. ψ is the rotation around the z-axis.
     */
    base::Vector6d lin_damping_instability;

    /* Quadratic damping parameter instability (kg/m)
     * The instability is mapped to the x, yx, xy, y, xψ, yψ components of
     * the damping matrix. ψ is the rotation around the z-axis.
     */
    base::Vector6d quad_damping_instability;

    /* Tau value to limit the bias gain in seconds */
    double lin_damping_tau;

    /* Tau value to limit the bias gain in seconds */
    double quad_damping_tau;
};

struct LocationConfiguration
{
    /* Latitude in radians */
    double latitude;

    /* Longitude in radians */
    double longitude;

    /* Altitude in meters */
    double altitude;
};

struct PoseUKFConfig
{
    /* Inerial noise parameters for acceleration */
    InertialNoiseParameters acceleration;

    /** Inerial noise parameters for acceleration */
    InertialNoiseParameters rotation_rate;

    /** Noise parameter for the dynamic motion model */
    DynamicModelNoiseParameters model_noise_parameters;

    /* Latitude and Longitude of operational area */
    LocationConfiguration location;
};

}

#endif