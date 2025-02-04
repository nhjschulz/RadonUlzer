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
 * @brief  Buzzer realization
 * @author Andreas Merkle <web@blue-andi.de>
 *
 * @addtogroup HALSim
 *
 * @{
 */

#ifndef BUZZER_H
#define BUZZER_H

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "IBuzzer.h"

#include <webots/Speaker.hpp>

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/** This class provides access to the robot simulation buzzer. */
class Buzzer : public IBuzzer
{
public:
    /**
     * Constructs the buzzer.
     */
    Buzzer(webots::Speaker* speaker);

    /**
     * Destroys the buzzer.
     */
    ~Buzzer()
    {
    }

    /**
     * Plays the specified frequency for the specified duration.
     *
     * This function plays the note in the background while your program continues
     * to execute. If you call another buzzer function while the note is playing,
     * the new function call will overwrite the previous and take control of the
     * buzzer.
     *
     * @warning @a frequency &times; @a duration / 1000 must be no greater than
     * 0xFFFF (65535). This means you can't use a duration of 65535 ms for
     * frequencies greater than 1 kHz. For example, the maximum duration you can
     * use for a frequency of 10 kHz is 6553 ms. If you use a duration longer than
     * this, you will produce an integer overflow that can result in unexpected
     * behavior.
     *
     * @param[in] freq        Frequency to play in 0.1 Hz.
     * @param[in] duration    Duration of the note in milliseconds.
     * @param[in] volume      Volume of the note (0-15).
     */
    void playFrequency(uint16_t freq, uint16_t duration, uint8_t volume) final;

    /**
     * Plays a melody sequence out of RAM.
     *
     * @param[in] sequence Melody sequence in RAM
     */
    void playMelody(const char* sequence) final;

    /**
     * Plays a melody sequence out of program space.
     *
     * @param[in] sequence Melody sequence in program space
     */
    void playMelodyPGM(const char* sequence) final;

    /**
     * Checks whether a note, frequency, or sequence is being played.
     *
     * @return if the buzzer is current playing a note, frequency, or sequence it will
     * return true otherwise false.
     */
    bool isPlaying() final;

private:
    /** Max. size of a full path. */
    static const size_t MAX_PATH_SIZE = 1024;

    /** Sound file with 440 Hz signal. */
    static const char* WAV_FILE_440_HZ;

    /** Sound file with 4 kHz signal. */
    static const char* WAV_FILE_4_KHZ;

    /** Sound file with 10 kHz signal. */
    static const char* WAV_FILE_10_KHZ;

    webots::Speaker* m_speaker;             /**< The robot simulated speaker. */
    char             m_path[MAX_PATH_SIZE]; /**< Absolute path of working directory. */
    size_t           m_pathLen;             /**< Length of the absolute path. */

    /* Default constructor not allowed. */
    Buzzer();
};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif /* BUZZER_H */
/** @} */
