#include<bits/stdc++.h>
using namespace std;
struct Node{
    vector<vector<int>>arr;
    int cost;
    string path;

    Node(vector<vector<int>> a, int c, string p)
    {
        arr = a;
        cost = c;
        path = p;
    }
};

struct Compare{
    bool operator()(Node a, Node b)
    {
        return a.cost > b.cost;
    }
};

void displayNode(priority_queue<Node, vector<Node>, Compare> pq){
    while(!pq.empty()){
        Node a = pq.top();
        cout << a.cost <<  "  " <<  a.path <<endl;
        pq.pop();
    }
}

int reduction(vector<vector<int>> arr, int n)
{
    int total_cost = 0;
    for (int i = 0; i < n; i++)
    {
        int min_val = arr[i][0];
        for (int j = 1; j < n; j++)
        {
            min_val = min(min_val, arr[i][j]);
        }
        total_cost += min_val;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] -= min_val;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int min_val = arr[0][i];
        for (int j = 1; j < n; j++)
        {
            min_val = min(min_val, arr[j][i]);
        }
        total_cost += min_val;
        for (int j = 0; j < n; j++)
        {
            arr[j][i] -= min_val;
        }
    }
    return total_cost;
}

int main()
{
    priority_queue<int>pqueue; //Max heap is the default type of priority queue in C++
    pqueue.push(10);
    pqueue.push(20);
    pqueue.push(30);
    pqueue.push(40);
    cout << "Top Element = " << pqueue.top() << endl;
    while(!pqueue.empty()){
        cout << pqueue.top() << " ";
        pqueue.pop();
    }
    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(10);
    minPQ.push(20);
    minPQ.push(30);
    minPQ.push(40);
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;

    //-----Create Priority Queue of custom data type-------
    Node data1({{1, 2, 3}, {4, 5, 6}, {7,8,9}}, 100, "Path1");
    Node data2({{5, 6, 10}, {7, 8, 11}, {10,12, 15} }, 50, "Path2");
    Node data3({{9, 10, 12}, {11, 12, 15}, {12,15,20}}, 70, "Path3");
    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push(data1);
    pq.push(data2);
    pq.push(data3);
    displayNode(pq);
    priority_queue<Node, vector<Node>, Compare> pq1;
    data1.cost = reduction(data1.arr, data1.arr[0].size());
    data2.cost = reduction(data2.arr, data2.arr[0].size());
    data3.cost = reduction(data3.arr, data3.arr[0].size());
    pq1.push(data1);
    pq1.push(data2);
    pq1.push(data3);
    pq = pq1;
    cout << ":::::::::::::::::::::" << endl;
    displayNode(pq);


    return 0;
}

