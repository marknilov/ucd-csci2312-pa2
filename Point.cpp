//
// Created by mark on 9/20/2015.
//

#include <cmath>
#include "Point.h"
namespace Clustering {
    // constructor
    Point::Point(int x) {
        dim = x;
    }
    //2nd constructor with dimensions
    Point::Point(int x, double *myArray) {
        dim = x;
        values = new double[sizeof(myArray)];
        std::copy(myArray, myArray + dim, values);
    }
    //destructor, deletes dimensions
    Point::~Point() {
        delete[]values;
    }
    // overloaded copy constructor
    Point::Point(const Point &point) {
        dim = point.dim;
        for(int i = 0; i < point.dim; i++) {
            values[i] = point.values[i];
        }
    }
    // overloaded assignment operator
    Point &Point::operator=(const Point &point) {
        if (this == &point)
            return *this;
        else {
            dim = point.dim;
            for(int i = 0; i < dim; i++) {
                values[i] = point.values[i];
            }
        }
        return *this;
    }
    // setvalues to individual values of x
    void Point::setValue(int x, double d) {
        values[x] = d;
    }
    //gets values
    double Point::getValue(int x) const {
        return values[x];
    }

//uses cmath, calculates distance between 2 points, should be same dimension
    double Point::distanceTo(const Point &point1, const Point &point2) const {
        double sum = 0;
        double distance;
        for (int i = 0; i < point1.getDims(); i++) {
            sum += pow(point1.getValue(i) - point2.getValue(i), 2);
        }
        distance = sqrt(sum);
        return distance;
    }
//overloaded multiplication
    Point &Point::operator*=(double d)
    {
        for (int i = 0; i < dim; i++) {
             values[i] *= d;
        }
        return *this;
    }

    const Point Point::operator*(double d) const {
        Point temp(0);
        for (int i = 0; i < dim; i++) {
            values[i] *= d;
        }
        return temp;
    }
    //overloaded output opperator
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

    //overloaded division, does not work
    Point &Point::operator/=(double d)
    {
        for (int i = 0; i < dim; i++)
        {
            values[i] /= d;
        }
        return *this;
    }

    const Point Point::operator/(double d) const
    {
        Point temp(0);
        if(d != 0)
        {
            for (int i = 0; i < dim; i++)
            {
                values[i] /= d;
            }

        }
        return temp;
    }
    //overloaded addition
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
        Point temp(0);
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] += point1.values[i];
        }
        return temp;
    }
    //overloaded subtraction
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
        Point temp(0);
        for(int i = 0; i < point.dim; i++)
        {
            point.values[i] -= point1.values[i];
        }
        return temp;
    }
    //overloaded equality
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
    //overlaoded comparisons, basically they are all the same
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
    //not sure how this works or why I needed it, so commented out for now
/*
    std::istream &operator>>(std::istream &istream, Point &point)
    {
       istream >> point.dim;
        return istream;
    } */
}