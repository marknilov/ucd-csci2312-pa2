//
// Created by mark on 9/20/2015.
//

#include <cmath>
#include "Point.h"
namespace Clustering {
    Point::Point(int x) {
        dim = x;
    }

    Point::Point(int x, double *myArray) {
        dim = x;
        values = new double[sizeof(myArray)];
        std::copy(myArray, myArray + dim, values);
    }

    Point::~Point() {
        delete[]values;
    }

    Point::Point(const Point &point) {
        dim = point.dim;
        for(int i = 0; i < point.dim; i++) {
            values[i] = point.values[i];
        }
    }

    Point &Point::operator=(const Point &point) {
        if (this == &point)
            return *this;

        dim = point.dim;
        values = point.values;

        return *this;
    }

    void Point::setValue(int x, double d) {
        values[x] = d;
    }

    double Point::getValue(int x) const {
        return values[x];
    }

//uses cmath
    double Point::distanceTo(const Point &point1, const Point &point2) const {
        double sum = 0;
        double distance;
        for (int i = 0; i < point1.getDims(); i++) {
            sum += pow(point1.getValue(i) - point2.getValue(i), 2);
        }
        distance = sqrt(sum);
        return distance;
    }

    Point &Point::operator*=(double d) {
        Point result = *this;
        for (int i = 0; i < dim; i++) {
             result.values[i] *= d;
        }
        return result;
    }

    const Point Point::operator*(double d) const {
        Point result = *this;
        for (int i = 0; i < result.dim; i++) {
            result.values[i] *= d;
        }
        return result;
    }

    std::ostream &operator<<(std::ostream &ostream, const Point &point)
    {
        int i = 0;
        ostream << "Dim: " << point.dim << " value: ";
        while(i < 3)
        {
            ostream << point.values[i] << " ";
            i++;
        }
        return ostream;
    }


    Point &Point::operator/=(double d)
    {
        Point result = *this;
        for (int i = 0; i < result.dim; i++) {
            result.values[i] /= d;
        }
        return result;
    }

    const Point Point::operator/(double d) const
    {
        if(d == 0) {
            return *this;
        }
            Point result = *this;
        for (int i = 0; i < result.dim; i++) {
            result.values[i] /= d;
        }
        return result;
    }

    Point &operator+=(Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] += point1.values[i];
        }
        return point;
    }

    const Point operator+(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] += point1.values[i];
        }
        return point;
    }

    Point &operator-=(Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] -= point1.values[i];
        }
        return point;
    }

    const Point operator-(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] -= point1.values[i];
        }
        return point;
    }

    bool operator==(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] != point1.values[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] != point1.values[i])
                return true;
        }
        return false;
    }

    bool operator<(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] < point1.values[i])
                return true;
        }
        return false;
    }

    bool operator>(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] > point1.values[i])
                return true;
        }
        return false;
    }

    bool operator<=(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] <= point1.values[i])
                return true;
        }
        return false;
    }

    bool operator>=(const Point &point, const Point &point1)
    {
        for(int i = 0; i < point.dim; i++)
        {
            if(point.values[i] >= point1.values[i])
                return true;
        }
        return false;
    }
/*
    std::istream &operator>>(std::istream &istream, Point &point)
    {
       istream >> point.dim;
        return istream;
    } */
}