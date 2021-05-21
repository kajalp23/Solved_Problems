/*

Program To Find How Many Total Valid Parenthesis Sequence Will Be Formed 

Same Program to find Unique BST

*/


#include <iostream>
using namespace std;

int Para(int n){
    int cata[n+1];
    cata[0]=1;
    for(int i=1;i<=n;i++){
        cata[i]=0;
        for(int j=0;j<i;j++){
            cata[i]+=(cata[j]*cata[i-j-1]);
        }
    }

    return cata[n];
}

int main() {
    int n;
    cin >> n;

    cout << "Total Valid Parenthesis:" << Para(n);

}
