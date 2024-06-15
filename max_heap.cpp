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



}