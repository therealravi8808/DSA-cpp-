#include<bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

// Find square root of a number in log…
int floorSqrt(int n)
{
    int low=1,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        long long val=(mid*mid);
        if(val<=(long long)(n)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}

// Nth Root of a Number using Binary Search
int func(int mid,int n,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}

int  NthRoot(int n, int m) {
  long long low=1,high=m;
  while(low<=high){
    long long mid=(low+high)/2;
    long long  midN=func(mid,n,m);
    if(midN==1) {
      return mid;
    } else if (midN == 0) {
      low + mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// Koko Eating Bananas
int findMax(vector<int> &v){
    int maxi=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}
int calculatetotalhours(vector<int> &v ,int hourly){
    int totalH=0;
    int n=v.size();
    for(int i=0;i<n;i++){
        totalH+=ceil((double)(v[i])/(double)(hourly));
    }
    return totalH;

}
int minimumRateToEatBananas(vector<int> v, int h) {
    int low=1,high=findMax(v);
    while(low<=high){
        int mid=(low+high)/2;
        int totalH= calculatetotalhours(v,mid);
        if(totalH<=h){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
 return low;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

// // Find square root of a number in log…
int n;
cin>>n;
int ans=floorSqrt(n);
cout<<"Square root of a number: "<<ans<<" ";

// Nth Root of a Number using Binary Search
// int n=4,m=27;

// int ans=NthRoot(n,m);
// cout<<"Nth Root of a Number using Binary Search: "<<ans<<" ";

// // Koko Eating Bananas
// vector<int> v={3,4,7,13};
// int h=7;
// // cin>>h;
// int ans=minimumRateToEatBananas(v,h);
// cout<<"Koko Eating Bananas: "<<ans<<" Bananas/Hrs. ";

    return 0;
}