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

#include "pegbox.h"
#include "peg.h"
#include "board.h"
#include "QGraphicsEllipseItem"
#include <QPen>
#include <QLinearGradient>

PegBox::PegBox(const QPoint &position, Board *board, QGraphicsItem *parent):
	EmptyBox(position, parent),
	mPegState(PEG_EMPTY),
	mBoard(board),
	mPeg(0)
{
	QLinearGradient lgrad(2, 2, 35, 35);
	lgrad.setColorAt(0.0, QColor(0, 0, 0, 150));
	lgrad.setColorAt(1.0, QColor(0xff, 0xff, 0xff, 0xa0));

	mCircle = new QGraphicsEllipseItem(2, 2, 35, 35, this);
	mCircle->setPen(QPen(QBrush(lgrad), 2));
	setBoxState();
}
//-----------------------------------------------------------------------------

void PegBox::setPeg(Peg *peg)
{
	mPeg = peg;
	mPeg->setPegBox(this);
	mCircle->setVisible(hasPeg());
}
//-----------------------------------------------------------------------------

void PegBox::setPegState(const PEG_STATE &state)
{
	mPegState = state;
	switch (mPegState) {
	case PEG_INITIAL:
		if (mPeg) mPeg->setVisible(true);
		mCircle->setVisible(true);
		break;
	case PEG_FILLED:
		if (mPeg) mPeg->setVisible(true);
		mCircle->setVisible(true);
		break;
	case PEG_EMPTY:
		if (mPeg) mPeg->setVisible(false);
		mCircle->setVisible(false);
		break;
	default:// PEG_DRAGED
		if (mPeg) mPeg->setVisible(true);
		mCircle->setVisible(false);
		break;
	}
}
//-----------------------------------------------------------------------------

void PegBox::setPegColor(int color_number)
{
	if (hasPeg())
		mPeg->setColor(color_number);
}
//-----------------------------------------------------------------------------

int PegBox::getPegColor()
{
	if (hasPeg()) return mPeg->getColor();
	return -1;
}
//-----------------------------------------------------------------------------

void PegBox::setBoxState(const BOX_STATE &state)
{
	mBoxState = state;

	switch (mBoxState) {
	case BOX_PAST:
		setPegState(PEG_FILLED);
		setEnabled(false);
		if (mPeg) {
			mPeg->setEnabled(false);
			mPeg->setMovable(false);
			mPeg->setVisible(true);
		}
		break;
	case BOX_CURRENT:
		setEnabled(true);
		if (mPeg) {
			mPeg->setEnabled(true);
			mPeg->setMovable(true);
			mPeg->setVisible(true);
		}
		break;
	case BOX_FUTURE:
		setEnabled(false);
		if (mPeg) {
			mPeg->setEnabled(false);
			mPeg->setMovable(false);
			mPeg->setVisible(true);
		}
		break;
	default: //BOX_NONE
		setEnabled(false);
		if (mPeg) {
			mPeg->setVisible(false);
		}
		break;
	}
}
//-----------------------------------------------------------------------------

bool PegBox::isPegVisible()
{
	return mPeg && mPeg->isVisible();
}
//-----------------------------------------------------------------------------

//int PegBox::handlePegMouseRelease(QPoint position)
//{
//	if (sceneBoundingRect().contains(position)) // do nothing if dropped on its own box
//		return 0;
//	else
//		return mBoard->handlePegMouseRelease(position, mPeg->getColor());
//}