#pragma once

class DoublePoint
{
public:
    DoublePoint()
        : _x(0)
        , _y(0)
    {

    }

    DoublePoint(const DoublePoint& p)
    {
        _x = p.x();
        _y = p.y();
    }

    DoublePoint(double xpos, double ypos)
        : _x(xpos)
        , _y(ypos)
    {

    }

    inline double x() const { return _x; }
    inline double y() const { return _y; }

    inline void setX(double x)
    {
        _x = x;
    }

    inline void setY(double y)
    {
        _y = y;
    }

private:
    double _x;
    double _y;
};