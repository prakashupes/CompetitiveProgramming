#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input("geeks\tfor\tgeeks");
    vector<string> result;
    boost::split(result, input, boost::is_any_of("\t"));

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}
