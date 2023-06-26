int NthRoot(int n, int m) {
  // Write your code here.
    int i=0;
    int j=m+1;
    while(i+1<j){
        int a=(i+j)/2;
        if(pow(a,n)>m){
        j=a;
        }
        else{
        i=a;
        }
    }
    if(pow(i,n)==m){
        return i;
    }
    else{
        return -1;
    }
}
