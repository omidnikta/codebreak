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

#include "appinfo.h"
#include "rules.h"
#include <QSettings>

Rules::Rules()
{
    QSettings settings;
    mPegs = settings.value("Pegs", 4).toInt();
    mColors = settings.value("Colors", 6).toInt();
    mSameColors = settings.value("SameColor", true).toBool();
    mAlgorithm = (Algorithm) settings.value("Algorithm", 0).toInt();
    mMode = (Mode) settings.value("Mode", 1).toInt();
}

Rules::~Rules()
{
    QSettings settings;
    settings.setValue("Pegs", mPegs);
    settings.setValue("Colors", mColors);
    settings.setValue("SameColor", mSameColors);
    settings.setValue("Algorithm", (int) mAlgorithm);
    settings.setValue("Mode", (int) mMode);
}

Mode Rules::mode() const
{
    return mMode;
}

Algorithm Rules::algorithm() const
{
    return mAlgorithm;
}

bool Rules::sameColors() const
{
    return mSameColors;
}

int Rules::colors() const
{
    return mColors;
}

int Rules::pegs() const
{
    return mPegs;
}


