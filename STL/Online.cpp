#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int, pair<string, pair<int, double>>>> emp;
    while(1){
        cout << "Please input your choice: ";
        int c;
        cin >> c;
        if(c == 1){
            int ID; string name; int age; double salary;
            cout << "Enter ID, name, age, salary: " << endl;
            cin >> ID >> name >> age >> salary;
            emp.push_back({ID, {name, {age, salary} } } );
        }
        else if(c == 2){
            cout << "Please input your employee ID: ";
            int x;
            cin >> x;
            for(auto it : emp){
                if(it.first == x){
                    cout << "Salary: " << it.second.second.second << endl;
                }
            }
        }
        else if(c == 3){
            sort(emp.begin(), emp.end(), [] (pair<int, pair<string, pair<int, double>>> &a, pair<int, pair<string, pair<int, double>>> &b){return a.second.second.first < b.second.second.first;} );
            cout << "Sorted by age. Press 4 in the choice to print out the result" << endl;
        }
        else if(c == 4){
            for(auto it : emp){
                cout << it.first << " " << it.second.first << " " << it.second.second.first << " " << it.second.second.second << endl;
            }
        }
        else if(c == 5){
            exit(0);
        }
        else{
            cout << "Error. Try again" << endl;
        }
    }
}


/*
Question:
Suppose you want to store the information of some employees of an organization. The information consists of employee ID, Name, age, salary. Now create 3 options for the users:

1. Insert new employee and have it to the existing container.
2. if any employee ID is provided show the salary of that person.
3. sort all existing data according to age.

Implement this scenario using the concept of STL
*/
