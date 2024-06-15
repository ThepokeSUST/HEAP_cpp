#include<iostream>
#include<vector>
using namespace std;

class heap{
 
  int capacity;
  vector<int> arr;
  public:
     

  int size;
  heap(int n){

        this->capacity=n;
        this->arr.resize(capacity);
        this->size=0;
    }


    void insert_ele(int ele){
          size++;
          if(capacity==size){
            cout<<"FULL";
            return;
          }
         
         int idx=size;
         arr[idx]=ele;

         while(idx>1){
            int par=idx/2;
            if(arr[par]<arr[idx]){
                swap(arr[par],arr[idx]);
                idx=par;

            }
            else {
                return;
            }
         }


    }
   
   void delete_ele(){
      
      if(size==0){
        cout<<"empty";
        return;
      }
      this->arr[1]=this->arr[size];
      size--;
      int idx=1;

      while(idx<size){
        int left=idx*2;
        int right=idx*2+1;

        if(right<=size ){

              if(arr[idx]<arr[left] and arr[left]>arr[right]){
                swap(arr[idx],arr[left]);
                idx=left;
              }
              else if(arr[idx]<arr[right] and arr[right]>arr[left]){
                swap(arr[idx],arr[right]);
                idx=right;
              }
        }
        else if(left<=size){
            if(arr[idx]<arr[left]){
                swap(arr[idx],arr[left]);
                idx=left;
            }
        }
        else return;
       

      }

   }
    void print(){

        for(int i=1;i<size+1;i++){
            cout<<arr[i]<<" ";
        }
    }


};

int main(){
   
   int n;
   cout<<"Enter heap size ";
   cin>>n;
   //for zero base index.......
   n++;

   heap hp(n);

   hp.insert_ele(12);
   hp.insert_ele(45);
   hp.insert_ele(34);
   hp.insert_ele(0);

   hp.print();
   cout<<endl;

   hp.delete_ele();
   hp.delete_ele();
   hp.print();


}