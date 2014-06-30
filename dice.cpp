#include<iostream>
using namespace std;

int top1[] = {1,4,6,3};
//int top5[] = {5,3,2,4};
int top6[] = {6,4,1,3};
//int top2[] = {2,3,5,5};

int top5[] = {5,4,2,3};
int top2[] = {2,4,5,3};

int main() {

    int r,c;
    cin >> r >> c;

    int row1 , row2 , row3 , row4;

    row1 = row2 = row3 = row4 = (c/4)*14;

    for(int i=0;i<c%4;i++) {

        row1 += top1[i];
        row2 += top5[i];
        row3 += top6[i];
        row4 += top2[i];
    }
    

    cout<<"Row1="<<row1<<endl;
	 cout<<"Row2="<<row2<<endl;
	  cout<<"Row3="<<row3<<endl;
	   cout<<"Row4="<<row4<<endl;
    int ans = (row1 + row2 + row3 + row4) * (r/4);

    if(r%4 == 1)
        ans += row1;
    if(r%4 == 2)
        ans += row2;
    if(r%4 == 3)
        ans += row3;

    cout << ans << endl;
}
