#include<iostream>
#include<vector>

using namespace std;

void make_heap(vector<int> &vec,int idx,int size){

 //  cout<<"ok\n";
  while(idx<=size){
     int left=2*idx;
    int right=idx*2+1;

    if(right<=size){
        if(vec[idx]<vec[left] and vec[left]>vec[right]){
            swap(vec[idx],vec[left]);
            idx=left;
        }
        else if(vec[idx]<vec[right]){
            swap(vec[idx],vec[right]);
            idx=right;
        }
        else break;
    }
    else if(left<=size){
        if(vec[idx]<vec[left]){
            swap(vec[idx],vec[left]);
            idx=left;
        }
        else break;
    }
    else break;

}

}
void heapify(vector<int> &vec,int size){
    int leaf=size/2+1;
    int st=leaf-1;

    for(int i=st;i>0;i--){
       make_heap(vec,i,size);
    }



}


//for one base indexing......
int main(){
    int  n;
    cin>>n;
    n++;
    vector<int> vec(n);
    
    for(int i=1;i<n;i++){
        cin>>vec[i];
    }

    heapify(vec,n-1);

   for(int i=1;i<n;i++) cout<<vec[i]<<" ";


}