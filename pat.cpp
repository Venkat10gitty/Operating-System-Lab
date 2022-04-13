#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > v;

    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            temp.push_back(x); 
        }
        v.push_back(temp);
    }

    return 0;
}