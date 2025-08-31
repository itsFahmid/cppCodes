#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Declare a Map
    map<int, int>map1;
    map<int, string>map2;
    map<int, string>map3 = {{10, "abc"},{20, "def"},{30, "bbb"}};

    //Insert values in a map
    map1[1] = 2;
    map1[5] = 4;
    map1[3] = 3;
    map1[4] = 6;
    map1.insert({2, 10});

    //Modify value
    map1[3] = 7;
    map1.insert({2, 11});
    map1.at(4) = 8; //Throws out of range if key is not present in the map

    //Capacity of a map
    cout << "Is the map empty? " << map1.empty() << endl; //returns a flag to check if the map is empty or not
    cout << "Size of map1 = " << map1.size() << endl;
    cout << "Size of map2 = " << map2.size() << endl;
    cout << "Maximum size of the map = " << map1.max_size() << endl;


    //Insert values in map 2
    map2.insert({10, "abc"});
    map2.insert({20, "def"});

    //Declare Iterators
    map<int, int>::iterator it;
    cout << "Printing Map1 with iterator: " << endl;
    for(it = map1.begin(); it!= map1.end(); it++)
    {
        cout << it->first << "   " << (*it).second << endl;
    }
    cout << endl;
    cout << "Printing Map2 with iterator: " << endl;
    for(auto itr = map2.begin(); itr!= map2.end(); itr++){
        cout << itr->first << " " << (*itr).second << endl;
    }
    cout << endl;

    //Use for each loop
    //here m is a reference, not a copy
    cout << "Using for each loop to print Map2:" << endl;
    for(auto& m: map2){
        cout << m.first << endl;
    }

    //Suppose we want to print the elements backwards
    map<int, int>::reverse_iterator rit;
    cout << "Printing Map1 in reverse: " << endl;
    for(rit = map1.rbegin(); rit!= map1.rend(); rit++){
        cout << rit->first << "   " << (*rit).second << endl;
    }
    //Difference between begin and cbegin
    auto it_begin = map2.begin();
    cout << it_begin->second << endl;
    it_begin->second = "AAA";
    cout << it_begin->second;

    auto it_cbegin = map2.cbegin();
    //it_cbegin->second = "aaa"; //will throw an error as the iterator is constant

    //Functions
    map<int, string> b1,b2;
    b1[8]= "X";
    b1[7]= "Y";
    b2[5]= "M";
    b2[6]= "N";
    b2[8] = "O";
    b1.swap(b2);
    map<int, string>::iterator it_swap;
    for(it_swap = b1.begin(); it_swap!= b1.end(); it_swap++){
        cout << it_swap->first << "   " << it_swap->second << endl;
    }
    b1.clear(); //clearing b1
    cout << "Size of b1 becomes = " << b1.size() << endl;

    //Find and Erase
    auto it2 = b2.find(8); //we need to give the key here
    if(it2 == b2.end()){
        cout << "Value not found" << endl;
    }
    else{
        cout << "Value = " << it2->second << endl;
    }
    if(it2 == b2.end()){
        cout << "Value can not be erased" << endl;
    }
    else{
        b2.erase(it2);
    }
    b2.erase(prev(b2.end())); //remove the last element of the b2 map

    for(auto it = b2.begin(); it!= b2.end(); it++){
        cout << it->first << "   " << (*it).second << endl;
    }
    //count function
    cout << "Is 4 in map1? = " << map1.count(4) << endl;

    //Multimap allows multiple elements with same key
    multimap<int, string> myMap;
    myMap.insert({4, "apple"});
    myMap.insert({2, "banana"});
    myMap.insert({3, "cherry"});
    myMap.insert({3, "citrus"});
    myMap.insert({5, "date"});
    int key = 3;
    auto range = myMap.equal_range(key);
    // Print the elements in the range
    cout << "Elements with key " << key << " are:" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << "Key: " << it->first << ", Value: " << it->second << endl;
    }

  map<char,int> mymap;
  map<char,int>::iterator itlow,itup;
  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  itlow=mymap.lower_bound ('b');
  itup=mymap.upper_bound ('d');

  mymap.erase(itlow,itup);
  for(auto it=mymap.begin(); it!=mymap.end(); ++it){
    cout << it->first << " => " << it->second << '\n';
  }

  //REVIEW UNORDERED_MAP TOO, ALSO TRY TO FIGURE OUT THE DIFFERENCE BETWEEN MAP AND UNORDERED_MAP
}

