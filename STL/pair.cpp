#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Declare and Initialize a Pair
    pair<int, string>pair1;
    pair1 = make_pair(20, "A");
    pair<int, string>pair2(10, "B");
    pair<int, string>pair3 = {30, "C"};

    //suppose we haven't initialized a pair
    pair<int, string>p;
    cout << "Before Initialization = " << p.first << "\t" << p.second << endl; //default initialization, first element is int, so 0, second = ""
    p.first = 10;
    p.second  = "X";
    cout << "After Initialization = " << p.first << "\t" << p.second << endl; //default initialization, first element is int, so 0, second = ""
    //Access Elements
    //we need to access members of pairs using first and second
    cout << "First element = " << pair1.first << " Second Pair = " << pair1.second << endl;

    //Compare between pairs
    //First compares between the first element of each pairs, if one is greater than other then result is based on that
    //initially pair1.first = 20, pair2.first = 10, so pair1 is greater
    if(pair1 > pair2)
    {
        cout << "Pair1 is greater than pair2" << endl;
    }
    else
    {
        cout << "Pair2 is greater than pair1" << endl;

    }
    //Now if first element of both pairs are equal, the result is shown after comparision of second elements of the pairs
    pair1.first = 10;
    pair2.first = 10;
    //2nd element of pair1 = A, 2nd element of pair2 = B
    if(pair1 > pair2)
    {
        cout << "Pair1 is greater than pair2" << endl;
    }
    else
    {
        cout << "Pair2 is greater than pair1" << endl;

    }
    //----Create a vector of pairs and sort them-----------
    vector<pair<int, string>>pair_vector = {pair1, pair2, pair3};
    sort(pair_vector.begin(), pair_vector.end()); //same as compare
    for (auto p : pair_vector)
    {
        cout << p.first << " " << p.second << endl;
    }

    //Nested Pairs
    pair<pair<int, string>, int> nested_pair = make_pair(make_pair(1, "ABC"), 20);
    cout << nested_pair.first.first << "\t";
    cout << nested_pair.first.second << "\t";
    cout << nested_pair.second << endl;

    vector<vector<int>>matrix = {{1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    pair< vector<vector<int>>,int> my_pair = make_pair(matrix, 1000);
    cout << "Second element: " << my_pair.second << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cout << my_pair.first[i][j] << " ";
        }
        cout << endl;
    }
    pair< pair< vector<vector<int> >, int>, string> my_new_pair = make_pair(make_pair(matrix, 1000), "AUST");
    cout << "Second element: " << my_new_pair.second << endl;
    cout << "Second element: " << my_new_pair.first.second << endl;
    for(int i = 0 ; i < 3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << my_new_pair.first.first[i][j] << " ";
        }
        cout << endl;
    }
    vector< pair< pair< vector<vector<int> >, int>, string> > v;
    v.push_back( make_pair(make_pair(matrix, 5000), "AUST") );
    v.push_back( make_pair(make_pair(matrix, 6000), "AUST") );
    cout << v[1].first.second;
    return 0;
}
