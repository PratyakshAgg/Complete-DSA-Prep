//sort in increasing order
/*#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int arr[] = {4,2,1};

    sort(arr, arr+3);
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}*/


//sort in decreasing order
/*#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int arr[] = {4,2,1};

    sort(arr, arr+3, greater<int>());
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}
*/

//sort in custom order
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main() {
    
    vector<pair<int, int> > vec = {{10,3}, {20, 1}, {30, 2}};
    
    sort(vec.begin(), vec.end(), sortbysec);
    
    for(int i=0; i<3; i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<"\n";
    }
    
    return 0;
}