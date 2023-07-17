#ifndef BUBBLESORT
#define BUBBLESORT
template <class T>
void BubbleSort(T begin, T end){
  int n = end - begin;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(*(begin+j-1)>*(begin+j)){
        std::swap(*(begin+j-1),*(begin+j));
      }
    }
  }
}
template <class T, class C>
void BubbleSort(T begin, T end, C compare){
  int n = end - begin;
  for(int i=n-1;i>0;i--){ // Teacher's version, updated on 2020.12.07
    for(int j=0;j<=i-1;j++){
      if(compare(*(begin+j), *(begin+j+1))){
        std::swap(*(begin+j),*(begin+j+1));
      }
    }
  }
}

#endif
