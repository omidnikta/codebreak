/***********************************************************************
 *
 * Copyright (C) 2013 Omid Nikta <omidnikta@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ***********************************************************************/

#ifndef APPINFO_H
#define APPINFO_H
#include <QString>

static const int VER_MAJOR            = 0; /**< Applictation Major Version */
static const int VER_MINOR            = 8; /**< Applictation Minor Version */
static const int VER_BUGFIX           = 5; /**< Applictation Bugfix Version */
static const QString APP_VER = QString("%1.%2.%3") /**< Applictation Version */
        .arg(VER_MAJOR).arg(VER_MINOR).arg(VER_BUGFIX);

static const QString APP_NAME        = "QtMind"; /**< Applictation Name */
static const QString ORG_NAME        = "QtMind"; /**< Applictation Organisation */
static const QString ORG_DOMAIN      = "http://omidnikta.github.io/qtmind"; /**< Organisation Domain */
static const QString AUTHOR_NAME     = "Omid Nikta"; /**< Applictation Author Name */

static const int MIN_COLOR_NUMBER    = 2; /**< The minimum number of colors */
static const int MAX_COLOR_NUMBER    = 10; /**< The maximum number of colors */

static const int MIN_SLOT_NUMBER     = 2; /**< The minimum number of slots */
static const int MAX_SLOT_NUMBER     = 5; /**< The maximum number of slots */

/**
 * @brief The Solving Algorithms enum
 */
enum class Algorithm
{
    MOST_PARTS,
    WORST_CASE,
    EXPECTED_SIZE
};
/**
 * @brief The Game Mode enum
 */
enum class Mode {
    MVH,    //Machine breaks the hidden code
    HVM        //Human breaks the hidden code
};


/**
 * @brief The Indicator enum
 */
enum class Indicator {
    DIGIT = 48,     // begining of digits in unicode
    CHARACTER = 65, // begining of characters in unicode
};
/**
 * @brief The Sound enum
 */
enum class Sound {
    PEG_DROP,
    PEG_DROP_REFUSE,
    BUTTON_PRESS
};
/**
 * @brief The Volume enum
 */
enum class Volume{
    MUTE,
    LOW,
    MEDIUM,
    HIGH
};
#endif // APPINFO_H
