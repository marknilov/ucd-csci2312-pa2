#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;

int main() {

    double stuff[3]{1,2,3};
    double moreStuff[3]{4,5,6};
    Clustering::Point p(3, stuff);
    Clustering::Point b(3,moreStuff);
    Clustering::Point c(3, stuff);

    //multiplication works
//    p *= 2;
//    cout << p;
//    p /= 2;
//    cout << p;

    //Addition / subtraction Works
//    p += b;
//    cout << p;
//    p - b;
//    cout << p;
//
    //equality works
//if (p == c){
//    cout << "they are equal! " << endl;
//}
//    else
//{
//    cout << "not equal ";
//}
    //equality works
//    p = b;
//    cout << p;

    //setvalue / getvalue works, need to remember off by 1 error
//    p.setValue(1,6);
//    cout << p.getValue(2);

    // distance works? yes?
//    cout << p.distanceTo(p,b);

    //all 4 comparisons work
//if(p >= b)
//    cout << " p is bigger (its not) " << endl;
//else
//    cout << "b is bigger " << endl;



    return 0;
}