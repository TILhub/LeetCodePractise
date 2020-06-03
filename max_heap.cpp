/*https://www.geeksforgeeks.org/insertion-and-deletion-in-heaps/*/
#include <iostream>
using namespace std;
int arr[10000];
int size=0;
int front(){
  if(size==0) return INT_MAX;
  return arr[0];
}
void heapify(int i){
  if(i==0)  return ;
  int parent=(i-1)/2;
  if(arr[i] > arr[parent]){
    swap(arr[i],arr[parent]);
    heapify(parent);
  }
}
void heapifyD(int i){
  int largest=i;
  int l=2*i+1;
  int r=2*i+2;
  if(l<size && arr[l]>arr[largest]) largest=l;
  if(r<size && arr[r]>arr[largest]) largest=r;
  if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(largest);
  }
}
void insert(int val){
  size++;
  arr[size-1]=val;
  heapify(size-1);
}
void deleteRoot(){
  int last=arr[size-1];
  arr[0]=last;
  size--;
  heapifyD(0);
}
int main(){
  for(int i=0;i<10000;i++)  arr[i]=-1;
  cout<<front()<<endl;
  insert(10);
  cout<<front()<<endl;
  insert(101);
  cout<<front()<<endl;
  insert(1110);  
  cout<<front()<<endl;
  deleteRoot();
  cout<<front()<<endl;
  return 0;
}