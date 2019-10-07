#include <iostream>
using namespace std;

#define EVEN 0
#define ODD 1
int main()
{
    int i = 3;
    switch (i & 1)
    {
        case EVEN: cout << "Even";
                break;
        case ODD: cout << "Odd";
                break;
        default: cout << "Default";
    }
    return 0;
}
