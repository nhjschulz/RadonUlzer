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
 * @brief  Display realization for the Sensor Fusion App
 * @author Juliane Kerpe <juliane.kerpe@web.de>
 * 
 * @addtogroup HALTarget
 *
 * @{
 */

#ifndef SENSORFUSIONDISPLAY_H
#define SENSORFUSIONDISPLAY_H

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "IDisplay.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/** This class provides access to a dummy driver for the Display of the Sensor Fusion Application.  */
class SensorFusionDisplay : public IDisplay
{
public:
    /**
     * Constructs the display adapter.
     */
    SensorFusionDisplay() : IDisplay()
    {
    }

    /**
     * Destroys the display adapter.
     */
    ~SensorFusionDisplay()
    {
    }

    /**
     * Clear the display and set the cursor to the upper left corner.
     */
    void clear() final
    {
    }

    /**
     * Set the cursor to the given position.
     *
     * @param[in] xCoord x-coordinate, 0 is the most left position.
     * @param[in] yCoord y-coordinate, 0 is the most upper position.
     */
    void gotoXY(uint8_t xCoord, uint8_t yCoord) final
    {
    }

    /**
     * Print the string to the display at the current cursor position.
     *
     * @param[in] str   String
     *
     * @return Printed number of characters
     */
    size_t print(const char str[]) final
    {
        return 0;
    }

    /**
     * Print the unsigned 8-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(uint8_t value) final
    {
        return 0;
    }

    /**
     * Print the unsigned 16-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(uint16_t value) final
    {
        return 0;
    }

    /**
     * Print the unsigned 32-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(uint32_t value) final
    {
        return 0;
    }

    /**
     * Print the signed 8-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(int8_t value) final
    {
        return 0;
    }

    /**
     * Print the signed 16-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(int16_t value) final
    {
        return 0;
    }

    /**
     * Print the signed 32-bit value to the display at the current cursor position.
     *
     * @param[in] value Value
     *
     * @return Printed number of characters
     */
    size_t print(int32_t value) final
    {
        return 0;
    }

private:
};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif /* SENSORFUSIONDISPLAY_H */
/** @} */
