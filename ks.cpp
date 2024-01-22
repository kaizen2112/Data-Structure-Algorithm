#include<bits/stdc++.h>
using namespace std;
int minimumV ;
int knapsack(int ind , int w  , int v , vector<int> &wt , vector<int> &val , vector<int>&vol , vector<vector<vector<int>>>&dp ){

    if(ind==0){
        if(wt[0] <= w && (v < minimumV || vol[0]>minimumV)) return val[0];
        else return 0 ;
    }

    int noTake = knapsack(ind-1 , w , v , wt , val , vol , dp) ;
    int take = 0 ;
    if(wt[ind]<=w) take = val[ind] + knapsack(ind-1, w-wt[ind],v + vol[ind] , wt , val , vol , dp);
    return  max(take , noTake) ;

}


int main(){
    int n ; cin>>n ;
    vector<int> wt(n) , val(n) , vol(n) ;
    for(int i = 0 ; i < n ;i++){
        cin>>wt[i]>>val[i]>>vol[i] ;
    }
    int w , v ; cin>>w>>v ;
    minimumV = v ;
    cout<<endl;
    vector<vector<vector<int> > > dp(n+1 , vector<vector<int> >(n+1 , vector<int>(n+1 , -1)));
    cout<<"val: "<<knapsack(n-1 , w , 0, wt , val , vol , dp) ;

}
