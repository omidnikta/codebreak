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

#ifndef PEG_H
#define PEG_H

#include "appinfo.h"
#include <QGraphicsObject>

class QGestureEvent;
class QGraphicsDropShadowEffect;
class QTapGesture;

/**
 * @brief The Peg class represent a peg on the board
 */
class Peg : public QGraphicsObject
{
    Q_OBJECT

public:
    /**
    * @brief The State enum represent different states of the peg
    */
    enum class State {
        INITIAL,    //    Right source pegs
        VISIBLE,
        INVISIBLE,
        UNDERNEATH,    //    Pegs under Initial right pegs
        PLAIN        //    Just circle is visible
    };
    explicit Peg(const QPointF& _position, const int& _color,
                 QGraphicsItem* parent = 0);

    /**
    * @brief setColor set the color of the peg
    * @param color the color
    */
    void setColor(const int& color);

    /**
    * @brief getColor get the color of the peg
    * @return the color of the peg
    */
    int getColor() const {return mColor;}

    /**
    * @brief setMovable set the peg movable or not
    * @param b the movability
    */
    void setMovable(bool b);

    /**
    * @brief isMovable check if the peg is movable
    * @return true if the peg is movable, false otherwise
    */
    bool isMovable() const { return mMovable; }

    /**
    * @brief setState set the state of the peg
    * @param _state the peg state
    */
    void setState(const State& _state);

    /**
    * @brief getState get the peg state
    * @return the peg state
    */
    State getState() const {return mState;}
    /**
     * @brief getShowColors get show colors property
     * @return true if show colors is enabled, false otherwise
     */
    static bool getShowColors();
    /**
     * @brief setShowColors set show colors property
     * @param value the new show colors property to set
     */
    static void setShowColors(bool value);
    /**
     * @brief getShowIndicators get show indicators property
     * @return the show indicators property
     */
    static bool getShowIndicators();
    /**
     * @brief setShowIndicators set the show indicators property
     * @param value the new show indicatros property to set
     */
    static void setShowIndicators(bool value);
    /**
     * @brief getIndicatorIndex get the indicator index
     * @return the indicator index
     */
    static int getIndicatorIndex();
    /**
     * @brief getIndicator get the indicator type
     * @return the indicator type
     */
    static Indicator getIndicator();
    /**
     * @brief setIndicator set the indicator
     * @param value the indicator to set
     */
    static void setIndicator(const Indicator& value);

public slots:
    void onResetIndicators();

signals:
    /**
     * @brief mouseReleaseSignal
     */
    void mouseReleaseSignal(Peg*);
    /**
    * @brief mouseDoubleClickSignal
    */
    void mouseDoubleClickSignal(Peg*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*,
               QWidget*);
    QRectF boundingRect() const;
    bool event(QEvent* event);
    bool gestureEvent( QGestureEvent* event );
    void tapGestureTriggered(QTapGesture* gesture );

private:
    static const QColor sPegColors[MAX_COLOR_NUMBER][2]; /**< TODO */
    static const QFont sFont; /**< TODO */
    static QFont setFont();
    static Indicator sIndicator;
    static bool sShowColors;
    static bool sShowIndicators;

    QPointF mPosition; /**< TODO */
    QGraphicsDropShadowEffect* mPressedEffect; /**< TODO */
    QGraphicsEllipseItem* mCircle; /**< TODO */

    State mState; /**< TODO */
    int mColor; /**< TODO */
    bool mMovable; /**< TODO */
};

#endif // PEG_H
