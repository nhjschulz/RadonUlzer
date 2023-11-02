/* MIT License
 *
 * Copyright (c) 2023 Andreas Merkle <web@blue-andi.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
 * @brief  IMU implementation of the simulation
 * @author Juliane Kerpe <juliane.kerpe@web.de>
 *
 * @addtogroup HALSim
 *
 * @{
 */
#ifndef IMU_H
#define IMU_H

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include "IIMU.h"

#include "SimTime.h"
#include <webots/Accelerometer.hpp>
#include <webots/Gyro.hpp>
#include <webots/Compass.hpp>

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/** The IMU adapter. */
class IMU : public IIMU
{
public:
    /**
     * Constructs the IMU adapter.
     *
     * @param[in] simTime       Simulation time
     * @param[in] accelerometer The accelerometer
     * @param[in] gyro          The gyro
     * @param[in] compass       The compass
     */
    IMU(const SimTime& simTime, webots::Accelerometer* accelerometer, webots::Gyro* gyro, webots::Compass* compass) :
        IIMU(),
        m_simTime(simTime),
        m_accelerometer(accelerometer),
        m_gyro(gyro),
        m_magnetometer(compass)
    {
    }

    /**
     * Destroys the interface.
     */
    ~IMU()
    {
    }

    /**
     * Initializes the inertial sensors and detects their type.
     *
     * @return True if the sensor type was detected succesfully; false otherwise.
     */
    bool init();

    /**
     * Enables all of the inertial sensors with a default configuration.
     */
    void enableDefault()
    {
    }

    /**
     * 	Configures the sensors with settings optimized for turn sensing.
     */
    void configureForTurnSensing()
    {
    }

    /**
     * Takes a reading from the accelerometer and makes the measurements available in a.
     */
    void readAccelerometer();

    /**
     * Takes a reading from the gyro and makes the measurements available in g.
     */
    void readGyro();

    /**
     * Takes a reading from the magnetometer and makes the measurements available in m.
     */
    void readMagnetometer();

    /**
     * Indicates whether the accelerometer has new measurement data ready.
     *
     * @return True if there is new accelerometer data available; false otherwise.
     */
    bool accelerometerDataReady()
    {
        return true;
    }

    /**
     * Indicates whether the gyro  has new measurement data ready.
     *
     * @return True if there is new gyro data available; false otherwise.
     */
    bool gyroDataReady()
    {
        return true;
    }

    /**
     * Indicates whether the magnetometer  has new measurement data ready.
     *
     * @return True if there is new magnetometer data available; false otherwise.
     */
    bool magnetometerDataReady()
    {
        return true;
    }

    /**
     * Get last raw Accelerometer values as a IMUData struct containing values in x, y and z.
     *
     * @param[in] accelerationValues  Pointer to IMUData struct.
     */
    void getAccelerationValues(IMUData* accelerationValues);

    /**
     * Get last raw Gyroscope values as a IMUData struct containing values in x, y and z.
     *
     * @param[in] turnRates  Pointer to IMUData struct.
     */
    void getTurnRates(IMUData* turnRates);

    /**
     * Get last raw Magnetometer values as a IMUData struct containing values in x, y and z.
     *
     * @param[in] magnetometerValues  Pointer to IMUData struct.
     */
    void getMagnetometerValues(IMUData* magnetometerValues);

    /**
     * Calibrate the IMU.
     */
    void calibrate();

private:
    IMUData m_accelerationValues = {0, 0, 0};
    IMUData m_gyroValues = {0, 0, 0};
    IMUData m_magnetometerValues = {0, 0, 0};

private:
    const SimTime&         m_simTime;          /** Simulation time. */
    webots::Accelerometer* m_accelerometer;    /** The accelerometer of Webots. */
    webots::Gyro*          m_gyro;             /** The gyro of Webots. */
    webots::Compass*       m_magnetometer;     /** The magnetometer of Webots. */
};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif /* IMU_H */
/** @} */
