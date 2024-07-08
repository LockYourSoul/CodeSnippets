#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main(){
    //defining a policy based data structure
    pbds s;
    s.insert(3);
    s.insert(100);
    s.insert(203);
    s.insert(0);
    s.insert(1);
    s.insert(2);
    cout << s.order_of_key(5) << endl;
    cout<<*s.find_by_order(2)<<endl;
    
    //order_of_key(x) returns number of elements strictly less than x in the set ;
    //find_by_order(x) returns the element at xth position
    // you can also use functions that are used in unordered set
    //NOTE: Both of these operations take O(logN) time
    return 0;
}