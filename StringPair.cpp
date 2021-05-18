 /*
 String Pair(Codevita Ques)
 Problem Description
 One person hands over the list of digits to Mr. String, But Mr. String understands only strings. Within strings also he understands only vowels. Mr. String needs your help to find the total number of pairs which add up to a certain digit D.

 The rules to calculate digit D are as follow

 Take all digits and convert them into their textual representation

 Next, sum up the number of vowels i.e. {a, e, i, o, u} from all textual representation

 This sum is digit D

 Now, once digit D is known find out all unordered pairs of numbers in input whose sum is equal to D. Refer example section for better understanding.
 
 Input

 5

 1 2 3 4 5

 Output

 one

 Explanation

 1 -> one -> o, e

 2 -> two -> o

 3 -> three -> e, e

 4 -> four -> o, u

 5 -> five - > i, e

 */
 
 
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    string st[29]={"","one","two","three","four","five","six","seven","eight","nine","ten",
                "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                "eighteen","nineteen","twenty","thirty","fourty","fifty","sixty","seventy","eighty",
                "ninety","hundred"};

    long sum=0;
    string p="";
    for(int i=0;i<n;i++){
        if(arr[i]==100)
            p+="hundred";
        else{
            if(arr[i]<=20)
                p+=st[arr[i]];
            else{
                int k=arr[i]/10;
                p+=st[k+18];
                arr[i]%=10;
                p+=st[arr[i]];
            }
        }
            
    }

    for(int i=0;i<p.length();i++){
        if(p[i]=='a' || p[i]=='e' || p[i]=='o' || p[i]=='i' || p[i]=='u')
            sum++;
    }

    if(sum>100)
        cout << "greater than 100";
    else{
        if(sum==100)
            cout << "hundred\n";
        else{
            if(sum<=20)
                cout << st[sum] << endl;
            else{
                string q="";
                int k=sum/10;
                q+=st[k+18];
                sum%=10;
                q+=st[sum];

                cout << q << endl;
            }
        }
    }

}
