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

#include "guess.h"
#include <QDebug>
#include <QSettings>

Guess::Guess()
{
    QSettings settings;
    mAlgorithm = (Algorithm) settings.value("Algorithm", 0).toInt();
}

Guess::~Guess()
{
    QSettings settings;
    settings.setValue("Algorithm", (int) mAlgorithm);
}

void Guess::update(const int& b, const int& w, const int& p)
{
    mBlacks = b;
    mWhites = w;
    mPossibles = p;
}

void Guess::reset(const Algorithm &algorithm, const int& possibles)
{
//    mColors = colors;
//    mPegs = pegs;
    std::fill(mGuess, mGuess + MAX_SLOT_NUMBER, 0);
    std::fill(mCode, mCode + MAX_SLOT_NUMBER, 0);
    mBlacks = 0;
    mWhites = 0;
    mAlgorithm = algorithm;
    mPossibles = possibles;
    mWeight = 0;
}

void Guess::setWeight(const qreal &weight)
{
    mWeight = weight;
}

void Guess::setGuess(const int &pegs, const int &colors, unsigned char* guess)
{
    for(int i = 0; i < pegs; i++)
        mGuess[i] = guess[i];
    COMPARE(mCode, mGuess, colors, pegs, mBlacks, mWhites);
}

void Guess::setCode(const int &pegs, unsigned char* code)
{
    for(int i = 0; i < pegs; i++)
        mCode[i] = code[i];
}
