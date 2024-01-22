#include<bits/stdc++.h>
using namespace std;
int totknight = 0;
char graph[100][100];
char ans[100][100];
int n;
int parbe(int r , int c){
    if(r < n && c >= 0 && r >= 0 && graph[r][c] == 'k')return 0;
    return 1;
}
int x[] = {2 , -2 , -1 , 1 , 2 , -2 , -1 , 1};
int y[] = {-1 , -1 , -2 , -2 , 1 , 1 , 2 , 2};
int asholeiparbe(int r , int c){
    int ans = 1;
    for(int i = 0 ; i < 8 ; i++){
        ans &= (parbe(r + x[i] , c + y[i]));
    }

    return ans;
}
void backtrack(int r , int c){

    if(r == n){
        int knight = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(graph[i][j] == 'k')knight++;
            }
        }
        if(knight >= totknight){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    ans[i][j] = graph[i][j];
                }
            }
            totknight = knight;
        }
        return;

    }
    if(asholeiparbe(r , c)){
            graph[r][c] = 'k';
            if(c == n - 1)backtrack(r + 1 , 0);
            else backtrack(r , c + 1);
        }
        graph[r][c] = '.';
        if(c == n - 1)backtrack(r + 1 , 0);
        else backtrack(r , c + 1);

}
int main(){
    cin>>n;
    backtrack(0 , 0);
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    cout<<totknight<<endl;
}
