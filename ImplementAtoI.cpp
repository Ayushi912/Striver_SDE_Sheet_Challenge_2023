//time complexity-0(n);
//space complexity:0(1);
int atoi(string str) {
    // Write your code here.
    bool flag=false;
    int n=str.length();
    int ans=0;
    if(n==0){
        return 0;
    }
    for(int i=0;i<n;i++){
        if(str[i]=='-' && i==0){
            flag=true;
            continue;
            
        }
        if(str[i]>='0' && str[i]<='9'){
int p=str[i]-'0';
ans=ans*10+p;
        }

        }
        if(flag==true){
       ans=ans*-1;
        }
        return ans;
}
