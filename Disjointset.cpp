#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i < n + 1; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int x,int y){
        int u = findParent(x);
        int v = findParent(y);
        if(rank[u]> rank[v]){
            parent[v] = u;
        }
        else if(rank[v]>rank[u]){
            parent[u]=v;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    void unionBySize(int x, int y){
        int u = findParent(x);
        int v = findParent(y);
        if(size[u]>size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
};

int32_t main(){
    // First Step is to initialise a Disjoint set of size n
    int n = 5;
    DisjointSet ds(5);
    // Let's add nodes
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(1, 4);
    // check if 1 and 5 are connected together
    if(ds.findParent(1)==ds.findParent(5)){
        cout << "Connected" << endl;
    }
    else
        cout << "Not Connected" << endl;
    // check after adding an edge here
    ds.unionByRank(2,5);
    if(ds.findParent(1)==ds.findParent(5)){
        cout << "Connected" << endl;
    }
    else
        cout << "Not Connected" << endl;

    // You can similarly use unionBySize here you can also get the size of the component in o(1) time
}