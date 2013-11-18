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

#ifndef GAME_H
#define GAME_H
#include <QList>
#include <QString>
#include "constants.h"

class Game
{
	/*	The class Game is the engine of the mastermind game. It contains all the solving
	 *	algorithms and auxiliary functions that provide efficient code guess and handling
	 *	response and so on
	 */
public:
	Game(const int& peg_no = 4, const int& color_no = 6, const bool& allow_same_color = true);
	~Game();
	bool done () const;
	QString getGuess();
	QString getGuess(const Algorithm& alg);
	bool setResponse(const int& response);
	void reset(const int& peg_no = 4, const int& color_no = 6, const bool& allow_same_color = true);

private:
	void createTables();
	void deleteTables();
	int compare (const int *codeA, const int *codeB) const;
	QString arrayToString(const int*) const;
	void stringToArray(const QString& str, int* arr) const;
	int computeWeight(int* responses, const Algorithm& alg) const;
	void convertBase(int decimal, const int &base, const int &precision, int* convertedArray);


	int mPegNumber;										//	pegs count, 4
	int mColorNumber;									//	colors count, 6
	bool mAllowSameColor;
	QString mGuess;										//	the guess number, ?
	int mResponse;										//	the black-white response code, [0..14]
	int mResponseSpaceSize;
	int mAllCodesSize;									//	the size of the complete code space, 6^4 = 1296

	int** mAllCodes;									//	all indexes of codes (0...1295)
	QList<int> mPossibleCodes;							//	list of all possibles
	int* mFirstPossibleCodes;							//	Contains the first remaining possibles (in case mAllCodesSize > 10000) or is mAllCodes otherwise
	int mFirstPossibleCodesSize;

};

#endif // GAME_H
