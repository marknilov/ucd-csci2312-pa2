#include <iostream>
#include "Point.h"
using namespace std;

int main() {

    double stuff[3]{1,2,3};
    Clustering::Point p(3, stuff);

    cout << p;

    return 0;
}