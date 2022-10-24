#ifndef POINT_H_
#define POINT_H_

template<typename T> class Point2
{

    Point2( const T& )
    
    const T& get_x() const
    {
        return x_;
    }

    T& get_x()
    {
        return x_;
    }

    const T& get_y() const
    {
        return y_;
    }

    T& get_y()
    {
        return y_;
    }

private:
    T x_;
    T y_;
};


#endif


