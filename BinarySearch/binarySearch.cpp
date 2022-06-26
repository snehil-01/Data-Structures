#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<b;i++)

int firstOcc(int* arr,int n,int key){
    int start=0,end=n-1,mid=(start+end)/2;
    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }else if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int lastOcc(int* arr,int n,int key){
    int start=0,end=n-1,mid=(start+end)/2;
    int ans=-1;
    while(start<=end){
        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }else if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return ans;
}

int peakIndex(int* arr,int n){
    int s=0,e=n-1,mid=(s+e)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}

int pivotIndex(int* arr,int n){
    int s=0,e=n-1,mid=(s+e)/2;
    while(s<e){
        if(arr[mid]>arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
        mid=(s+e)/2;
    }
    return s;
}

int searchInRotatedArray(int* arr,int n,int key){
    int pivot=pivotIndex(arr,n);
    if(key>=arr[pivot]&&key<=arr[n-1]){
        // BS(arr,pivot,n-1);
        }else{
        // BS(arr,0,pivot-1);int start=0,end=n-1;
       }
}

int binarySearch(int* arr,int n,int key){
    int start=0,end=n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }else if(key>arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int sqrt(int n){
    int s=0,e=n;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<e){
        if(mid*mid==n){
            return mid;
        }
       if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int floor(int* arr,int n,int k){
    int s=0,e=n-1,mid=(s+e)/2;
    int ans=0;
    while(s<=e){
        if(arr[mid]<=k){
            ans=arr[mid];
            s=mid+1;
        }else if(arr[mid]>k){
            e=mid-1;
        }
        mid=(s+e)/2;
    }
}
int ceil(int* arr,int n,int k){
    int s=0,e=n-1,mid=(s+e)/2;
    int ans=0;
    while(s<=e){
        if(arr[mid]>=k){
            ans=arr[mid];
            e=mid-1;
        }else if(arr[mid]>k){
            e=mid-1;
        }
        mid=(s+e)/2;
    }
}

int infiniteArr(int* arr,int k){
    int s=0,e=1,mid=(s+e)/2;
    /*
    ya fir
    while(k>arr[e]){
        s=e;
        e=e*2;
    }
    BS(arr,s,e,k);
    */
    while(s<=e){
        if(arr[e]<k){
            s=e;
            e=e*2;
        }else{
            while(s<=e){
                mid=(s+e)/2;
                if(arr[mid]==k){
                    return mid;
                }else if(arr[mid]<k){
                    s=mid+1;
                }else{
                    e=mid-1;
                }
            }
            return -1;
        }
            
        
    }
}

int firstOne(int* arr,int n){
    int s=0,e=1,m=(s+e)/2;
    while(arr[e]==0){
        s=e;
        e=e*2;
    }
    //firstOcc(arr,n,k);
}
bool isPossible(vector<int> arr, int n, int m,int mid){
    int pagecnt=0;
    int studcnt=1;
    fo(i,0,n){
        if(pagecnt+arr[i]<=mid){
            pagecnt+=arr[i];
        }else{
            studcnt++;
            if(studcnt>m || arr[i]>mid){
                return false;
            }
            pagecnt=arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    // Write your code here.
//     sort(arr.begin(),arr.end());
    int sum=0;
    fo(i,0,n){
        sum+=arr[i];
    }
    int ans=-1;
    int s=0;
    int e=sum;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int key;
    cin>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binarySearch(arr,n,key);
    // delete [] arr;
    return 0;
}