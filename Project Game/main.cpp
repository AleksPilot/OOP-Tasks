#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <random>
#include <iomanip>
#include <map>

using namespace std;


class number
{
public:
    int digit[4];

    void reset()
    {
        for (int i = 0; i < 4; ++i) {
            digit[i] = 0;
        }
    }

    void generate()
    {
        for (int i = 0; i < 4; ++i) {
            digit[i] = (rand() % 10);
        };
    }

    void print()
    {
        for (int i = 0; i < 4; ++i) {
            cout << digit[i] << " ";
        }
        cout << "\n";
    }

    number convert(int n)
    {
        number result;
        result.reset();
        try {
            if (n < 1000 || n > 9999)
                throw -1;
        }
        catch (int a){
            std::cerr << "\nCaught exception '" << a << "': invalid int for converting" << '\n';
        }
        int i = 3;
        while (n){
            result.digit[i] = n % 10;
            n /= 10;
            i--;
        }
        return result;
    }

    string easy_search(number a, int n, int standing)
    {
        string result = "miss";
        for (int i = 0; i < 4; ++i) {
            if ((n == a.digit[i]) && (standing == i)) {
                result = "bull";
                return result; //NOTE HERE: IF ONE NUMBER IS BOTH "COW" & "BULL" THE BEST RESULT IS DEFINED
            }
            else if (n == a.digit[i])
                result = "cow";
        }
        return result;
    }

private:

};

class numValue{
public:
    map<string,int> value;
    void init() {

        pair<string, int> temp;
        temp.second = 0;
        temp.first = "bull";
        value.insert(temp);
        temp.first = "cow";
        value.insert(temp);
        temp.first = "miss";
        value.insert(temp);
    }
    numValue checkout(number a, number b)
    {
        numValue result;
        result.init();
        std::map<string, int>::iterator it;
        for (int i = 0; i < 4; ++i) {
            result.value.find(a.easy_search(b, a.digit[i], i))->second++;
        }
        return result;
    }
    void print() {
        std::map<string, int>::iterator it;
        cout.width(5);
        for (it=value.begin(); it != value.end(); it++) {
            cout.width(5);
            cout << it->first << ' ';
            cout.width(2);
            cout << it->second << "\n";
        }
    }
};

int main() {
    number a, b;
    a.reset();
    b.reset();
    a.generate();
    a.print();
    numValue temp;
    b = b.convert(1570);
    //b.print();
    temp.init();
    number c;
    cout << c.easy_search(a, 1, 1) << '\n';
    temp = temp.checkout(a, b);
    temp.print();

    return 0;
}
