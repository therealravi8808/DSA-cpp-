#include<bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

// Program to generate Pascal’s Triangle
// Type : 1
int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);

    }
    return res;
}

int pascalTriangle(int r ,int c){
    int element=nCr(r,c);
    return element;
}


// Type : 2

int nCr1(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);

    }
    return res;
}

void pascalTriangle1(int n){
    for(int c=1;c<=n; c++){
        cout<<nCr1(n-1,c-1)<<" ";
    }
    cout<<" ";
}


// Type : 3
int nCr2(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);

    }
    return  (int)res;
}

vector<vector<int>> pascalTriangle2(int n) {

    vector<vector<int>> ans;
    for(int row=1;row<=n;row++){
        vector<int> templist;
        for(int col=1;col<=row;col++){
            templist.push_back(nCr2(row-1,col-1));
        }
        ans.push_back(templist);


    }
    return ans;
    }


// Majority Elements(>N/3 times) 
vector<int> majorityElement(vector<int> v) {
	// Better Solution
    
    // vector<int> ls;
	// map<int,int> mpp;
	// int n=v.size();
	// int mini=(int)(n/3)+1;
	// for(int i=0;i<n;i++){
	// 	mpp[v[i]]++;
	// 	if(mpp[v[i]]==mini){
	// 		ls.push_back(v[i]);
	// 	}
	// 	if(ls.size()==2) break;
	// }
	// sort(ls.begin(),ls.end());
	// return ls;

    //Optimal solution
    int cnt1=0,cnt2=0;
int el1=INT_MIN;
int el2=INT_MIN;
for(int i=0;i<v.size();i++){
	if(cnt1==0 && el2!=v[i]){
		cnt1=1;
		el1=v[i];
	}
	else if (cnt2==0 && el1!=v[i]){
		cnt2=1;
		el2=v[i];
	}
	else if (el1==v[i]) cnt1++;
	else if (el2==v[i]) cnt2++;
	else{
		cnt1--;
		cnt2--;
	}
}
vector<int> ls;
cnt1=0,cnt2=0;
for(int i=0;i<v.size();i++){
	if(el1==v[i]) cnt1++;
	if(el2==v[i]) cnt2++;
}
int mini=(int)(v.size()/3)+1;
if(cnt1>=mini) ls.push_back(el1);
if(cnt2>=mini) ls.push_back(el2);
sort(ls.begin(),ls.end());
return ls;
}


// 3 Sum Problem
// Better Solution
vector<vector<int>> triplet( vector<int> &arr)
{
 int n=arr.size();
 set<vector<int>> st;
 for(int i=0;i<n;i++){
     set<int> hashmap;
     for(int j=i+1;j<n;j++){
         int thrd=-(arr[i]+arr[j]);
         if(hashmap.find(thrd)!=hashmap.end()){
             vector<int> temp={arr[i],arr[j] ,thrd};
             sort(temp.begin(),temp.end());
             st.insert(temp);
         }
         hashmap.insert(arr[j]);
   
 }
 }
 
  vector<vector<int>> ans(st.begin(),st.end());
 return ans;
}

// Optimal solution
vector<vector<int>> triplet1( vector<int> &arr)
{
    int n=arr.size();
vector<vector<int>> ans;
sort(arr.begin(),arr.end());
for(int i=0;i<n;i++){
    if(i>0 && arr[i]==arr[i-1]) continue;
    int j=i+1;
    int k=n-1;
    while(j<k){
        int sum=arr[i]+arr[j]+arr[k];
        if(sum<0){
            j++;
        }
        else if(sum>0){
            k--;
        }
        else{
            vector<int> temp={arr[i],arr[j],arr[k]};
            ans.push_back(temp);
            j++;
            k--;
            while(j<k && arr[j]==arr[j-1]) j++;
            while(j<k && arr[k]==arr[k+1]) k--;

        }
    }
}
    return ans;
}

// 4 Sum Problem 
// Better Solution
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n ;i++){
        for(int j=i+1;j<n;j++){

            set<long long> hashset; 
            for(int k=j+1;k<n;k++){
                long long sum=nums[i]+nums[j];
                sum+=nums[k];
                long long fourth=target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={nums[i],nums[j],nums[k],(int)(fourth)};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);

            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return  ans;
}

// Optimal Solution

vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;
   
    sort(nums.begin(),nums.end());
    for(int i=0;i<n ;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++,l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;

                }

            
            else if(sum<target) k++;
            else l--;
                }
        } 
    }
 
    return  ans;
}

// Length of the longest subarray with zero Sum

int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> mpp;
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (mpp.find(sum) != mpp.end()) {
            maxLen = max(maxLen, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

// Count the number of subarrays with given xor K
// Brute Force
int subarraysWithSumK1(vector<int> a, int k) {
    int n = a.size(); 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
// Better Solution
int subarraysWithSumK2(vector<int> a, int k) {
    int n = a.size(); 
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ a[j];
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}


// Optimal solution
int subarraysWithSumK3(vector < int > a, int b) {
    
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        xr=xr^a[i];
        int x=xr^b;
        cnt +=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


// Merge Overlapping Sub-intervals
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
		int start=arr[i][0];
		int end=arr[i][1];
		if(!ans.empty() && end <= ans.back()[1]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(arr[j][0]<=end){
				end=max(end,arr[j][1]);
			}
			else{
				break;
			}
		}
		ans.push_back({start,end});
	}
	return ans;

	
}


// Optimal Solution
vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> &arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	for(int i=0;i<n;i++){
	if(ans.empty()|| arr[i][0] >ans.back()[1]){
       ans.push_back(arr[i]);
	}
	else{
		ans.back()[1] =max(ans.back()[1],arr[i][1]);
	}
	} 
	return ans;
}
// Merge two Sorted Arrays Without Extra Space
// Brute Force
void marge(long long arr1[],long long arr2[],int n,int m){
    long long arr3[n+m];
    int left=0;
    int right=0;
    int index=0;
    while (left<n && right<m)
    {
        if(arr1[left]<=arr2[right]){
            arr3[index]=arr1[left];
            index++,left++;

        }
        else{
            arr3[index]=arr2[right];
            index++,right++;
        }
    }
    while(left<n){
        arr3[index++]=arr1[left++];
    }
    while(right<m){
        arr3[index++]=arr2[right++];
    }
    for(int i=0;i<n+m;i++){
        if(i<n) arr1[i]=arr3[i];
        else arr2[i-n]=arr3[i];
    }

    
}

// Optmial Solution :1
void marge1(long long arr1[],long long arr2[],int n,int m){
    int left=n-1;
    int right=0;
    while(left>=0 && right <m){
        if(arr1[left]>= arr2[right]){
            swap(arr1[left],arr2[right]);
            left--,right++;

        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

// Optmial Solution :2
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void marge2(long long arr1[],long long arr2[],int n,int m){
    int len = n + m;

    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }
}

// Find the repeating and missing numbers
// Better
vector<int> findMissingRepeatingNumbers(vector < int > a) {
   int n=a.size();
   int hash[n+1]={0};
   for(int i=0;i<n;i++){
      hash[a[i]]++;
   }
   int repeating=-1,missing=-1;
   for (int i = 1; i <= n; i++) {
     if (hash[i]==2) repeating=i;
     else if (hash[i]==0) missing=i;
     if(repeating !=-1 && missing!=-1){
         break;
     }

   }
   return {repeating,missing};
}

// Optimal Solution:1
vector<int> findMissingRepeatingNumbers1(vector < int > a) {
long long n=a.size();
// S-Sn=x+y
// S2-S2n=
long long Sn=(n*(n+1))/2;
long long S2n=(n*(n+1)*(2*n+1))/6;
long long S=0,S2=0;
for (int i = 0; i < n; i++) {
  S += a[i];
  S2 += (long long)a[i] * (long long)a[i];
}
long long val1 = S - Sn;//x-y
long long val2 = S2 - S2n;//x+y
val2 = val2 / val1;
long long x = (val1 + val2) / 2;
long long y = (x - val1);
return {(int)x, (int)y};
}

// Optimal solution using XOR
vector<int> findMissingRepeatingNumbers2(vector < int > a) {
long long n=a.size();
int xr=0;
for (int i = 0; i < n; i++) {
  xr = xr ^ a[i];
  xr = xr ^ (i + 1);
}
    // int bitNo=0;
    // while (1) {
    //     if((xr &(1<<bitNo))!=0){
    //         break;
    //     }
    //     bitNo++;
    // }

    int number=xr&(~(xr-1));
    int zero=0;
    int one=0;
    for(int  i=0;i<n;i++){
        if((a[i] & number)!=0){
            one=one^a[i];

        }
        else{
            zero=zero^a[i];

        }
    }
    for(int i=1;i<=n;i++){
          if((i & number)!=0){
            one=one^i;

        }
        else{
            zero=zero^i;

        }

    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==zero) cnt++;
    }
    if(cnt==2) return {zero,one};
    return {one,zero};
}

// Count inversions in an array
// Brute force
int Countinversion(vector<int> &a,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) cnt++;
        }
    }
    return cnt;
}
// Optimal Solution

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//
      int cnt=0;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt=0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt+=mergeSort(arr, low, mid);  // left half
    cnt+=mergeSort(arr, mid + 1, high); // right half
   cnt+= merge(arr, low, mid, high);  // merging sorted halves
   return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
  return  mergeSort(a,0,n-1);
 
}


// Count Reverse Pairs
// Brute force
int count(vector<int> &a,int n){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>2*a[j]) cnt++;
        }
    }
    return cnt;
}


int team(vector <int> & skill, int n)
{
   return  count(skill,n);
}

// Optimal solution
void merge1(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(right <= high && arr[i]>2*arr[right]) right++;
        cnt+=(right-(mid+1));

    }
    return cnt;
}
int mergeSort1(vector<int> &arr, int low, int high) {
    int cnt=0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
   cnt+= mergeSort1(arr, low, mid);  // left half
  cnt+=  mergeSort1(arr, mid + 1, high); // right half
   cnt+= countPairs(arr,low,mid,high);
    merge1(arr, low, mid, high);  // merging sorted halves
    return cnt++;
}


int team1(vector <int> & skill, int n)
{
  
   return   mergeSort1(skill,0,n-1);
}


// Maximum Product Subarray in an Array
int subarrayWithMaxProduct(vector<int> &arr){
	int pre=1,suff=1;
	int maxi=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suff==0) suff=1;
		pre=pre*arr[i];
		suff=suff*arr[n-i-1];
		maxi=max(maxi,max(pre,suff));
	}
	return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // Type :1
    // int r=5;
    // int c=3;
    // int element =pascalTriangle(r,c);
    // cout<<"Pascal Triangle (r,c) is => " << element<< " ";
    

    // Type :2
    // int n=6;
    // cout<<"Pascal Tringle row number "<<n<<endl;
    // pascalTriangle1(n);
    
// Type :3
// int n;
// cin>>n;
// vector<vector<int>> ans=pascalTriangle2(n);
// for(auto it:ans){
//     for(auto ele : it){
//         cout<<ele<<" ";

//     }

//     cout<<endl;
// }



// Majority Elements(>N/3 times) 
// vector<int> arr={11,22,33,22,33,22,11,11};
// vector<int> element=majorityElement(arr);
//  cout << "The majority elements are: "<<endl;

// for(auto it : element){
//     cout<<it <<" ";
// }

// 3 sum Problem
// Better solution
// vector <int> num1={-1,0,1,2,-1,-4};
// vector<vector<int>> ans=triplet(num1);
// cout<<" 3 Sum Problem ans is " << endl;
// for(int i=0;i<ans.size();i++){
//     for(int j=0;j<ans[i].size();j++){
//         cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
// }

// Optimal solution
// vector <int> num1={-1,0,1,2,-1,-4,2};
// vector<vector<int>> ans=triplet1(num1);
// cout<<" 3 Sum Problem in optimal solution is " << endl;
// for(int i=0;i<ans.size();i++){
//     for(int j=0;j<ans[i].size();j++){
//         cout<<ans[i][j]<<" ";
//     }
//     cout<<endl;
// }

// 4 Sum Problem 
// vector<int > nums={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
// int target;
// cin>>target;
// vector<vector<int> > ans=fourSum(nums,target);
// cout<<" The quadruplets are: " <<endl;
// for(auto it: ans){
//     cout<<"[ ";
//     for(auto ele :it){
//         cout<<ele<<" ";
//     }
//     cout<<" ]"<<endl;
// }

// Optimal Solution
// vector<int > nums={4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
// int target;
// cin>>target;
// vector<vector<int> > ans=fourSum1(nums,target);
// cout<<" The quadruplets are: " <<endl;
// for(auto it: ans){
//     cout<<"[ ";
//     for(auto ele :it){
//         cout<<ele<<" ";
//     }
//     cout<<" ]"<<endl;
// }


// Length of the longest subarray with zero Sum
//  vector<int> a = {9, -3, 3, -1, 6, -5};
//     cout << solve(a) << endl;

// Count the number of subarrays with given xor K
// vector<int> a={4, 2,3,2, 6, 4};
// int b;
// cin>>b;
// int ans=subarraysWithSumK3(a,b);
// cout<<" The number of subarrays with XOR k is: "<<ans; 


// Merge Overlapping Sub-intervals
//  vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18},{19,22}};
//     vector<vector<int>> ans = mergeOverlappingIntervals1(arr);
//     cout << "The merged intervals are: " << "\n";
//     for (auto it : ans) {
//         cout << "[" << it[0] << ", " << it[1] << "] ";
//     }
//     cout << endl;


// Merge two Sorted Arrays Without Extra Space
// Brute Force
// long long arr1[]={1,3,5,7};
// long long arr2[]={0,2,8,9};
// int n=4,m=4;
// marge(arr1,arr2,n,m);
// cout<<"The merged arrays are: "<<endl;
// cout<<"arr1[]= ";
//  cout<<"[ ";
// for(int i=0;i<n;i++){
   
//     cout<<arr1[i]<<" ";
    
// }
// cout<<" ]";
// cout<<endl;

// cout<<"arr2[]= ";
// cout<<"[ ";
// for(int i=0;i<m;i++){
//     cout<<arr2[i]<<" ";
// }
// cout<<" ]";

// Optimal Solution
// long long arr1[]={1,3,5,7};
// long long arr2[]={0,2,8,9,4,10};
// int n=4,m=6;
// marge2(arr1,arr2,n,m);
// cout<<"The merged arrays are: "<<endl;
// cout<<"arr1[]= ";
//  cout<<"[ ";
// for(int i=0;i<n;i++){
   
//     cout<<arr1[i]<<" ";
    
// }
// cout<<" ]";
// cout<<endl;

// cout<<"arr2[]= ";
// cout<<"[ ";
// for(int i=0;i<m;i++){
//     cout<<arr2[i]<<" ";
// }
// cout<<" ]";

// Find the repeating and missing numbers
//  vector<int> a = {3, 1, 2, 7, 4, 6, 8, 4};
//     vector<int> ans = findMissingRepeatingNumbers1(a);
//     cout << "The repeating and missing numbers are: {"
//          <<"Repeating Number =>"<< ans[0] << ", " <<"Missing Nuber=> "<< ans[1] << "}\n";

// Count inversions in an array
// vector<int> a={5,4,3,2,1};
// int n;
// cin>>n;
// int ans=Countinversion(a,n);
// cout<<"Cout of invers in an array => "<<ans<<endl;

// Opitmal Solution
// vector<int> a={6,5,4,3,2,1};
// int n;
// cin>>n;
// int ans=numberOfInversions(a,n);
// cout<<"Cout of invers in an array => "<<ans<<endl;

// // Count Reverse Pairs
// vector<int> a={5,4,1,2,3,1};
// int n;
// cin>>n;
// int ans=team1(a,n);
// cout<<"Cout of invers in an array => "<<ans<<endl;

// Maximum Product Subarray in an Array
vector<int> arr={1,2,-3,0,-4,-5};
int ans=subarrayWithMaxProduct(arr);
cout<<" Maximum Product Subarray in an Array=> "<<ans<<endl;
return 0;
}