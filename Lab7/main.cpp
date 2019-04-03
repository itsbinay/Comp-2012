#include <iostream>
#include <cstdlib>

std::ostream& operator<<(std::ostream& os, std::pair<int, double> value) {
    os << "(" << value.first << " " << value.second << ")";
    return os;
}

std::pair<int, double>& operator++(std::pair<int, double>& value) {
    ++value.first;
    ++value.second;
    return value;
}

const std::pair<int, double> operator++(std::pair<int, double>& value, int) {
    value.first++;
    value.second++;
    return value;
}

#include "myvector.h"

using namespace std;

int main() {

    myvector<int> vec;
    cout << "Create an empty vector of int." << endl;
    cout << vec << endl << endl;

    cout << "Push values into the vector." << endl;
    for (int i=0; i<5; i++) {
        vec.push_back(i);
        cout << "push_back " << i << ": " << vec << endl;
    }
    cout << endl << "Pop values from the vector." << endl;
    for (int i=0; i<3; i++)
        cout << "pop_back " << vec.pop_back() << ": " << vec << endl;
    cout << endl;

    cout << "Calculate vector * 5." << endl;
    myvector<int> mult_1 = vec * 5;
    cout << mult_1 << endl << endl;

    cout << "Calculate 5 * vector." << endl;
    myvector<int> mult_2 = 5 * vec;
    cout << mult_2 << endl << endl;

    cout << "Test whether the above 2 vectors are identical." << endl;
    cout << ((mult_1==mult_2) ? "True" : "False") << endl << endl;

    cout << "Test whether the calculation result and the original vector are identical." << endl;
    cout << ((mult_1==vec) ? "True" : "False") << endl << endl;

    cout << "Pre-increment twice." << endl;
    ++++vec;
    cout << vec << endl << endl;

    cout << "Post-increment." << endl;
    vec++;
    cout << vec << endl << endl;

    cout << "Print the elements by indexing." << endl;
    for (int i=0; i<vec.get_size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl << "Modify the first element to 0." << endl;
    vec[0] = 0;
    cout << vec << endl << endl;

    cout << "Create an empty vector of pair." << endl;
    myvector< pair<int, double> > vec2;
    cout << vec2 << endl << endl;

    cout << "Push values into the vector." << endl;
    for (int i=0; i<5; i++) {
        pair<int, double> new_v{i, (.5 + i)};
        vec2.push_back(new_v);
        cout << "push_back " << new_v << ": " << vec2 << endl;
    }
    cout << endl << "Pop values from the vector." << endl;
    for (int i=0; i<3; i++)
        cout << "pop_back " << vec2.pop_back() << ": " << vec2 << endl;
    cout << endl;

    cout << "Pre-increment twice." << endl;
    ++++vec2;
    cout << vec2 << endl;

    return 0;
}