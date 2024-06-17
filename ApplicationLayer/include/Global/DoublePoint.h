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

class DoublePoint3
{
public:
    DoublePoint3()
        : _x(0)
        , _y(0)
        , _z(0)
    {
    }

    DoublePoint3(const DoublePoint3& p)
    {
        _x = p.x();
        _y = p.y();
        _z = p.z();
    }

    DoublePoint3(double xpos, double ypos, double zpos)
        : _x(xpos)
        , _y(ypos)
        , _z(zpos)
    {
    }

    inline double x() const { return _x; }
    inline double y() const { return _y; }
    inline double z() const { return _z; }

    inline void setX(double x)
    {
        _x = x;
    }

    inline void setY(double y)
    {
        _y = y;
    }

    inline void setZ(double z)
    {
        _z = z;
    }

private:
    double _x;
    double _y;
    double _z;
};