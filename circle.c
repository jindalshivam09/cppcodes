
  /*  U_x = ((A_x^2 + A_y^2)(B_y - C_y) + (B_x^2 + B_y^2)(C_y - A_y) + (C_x^2 + C_y^2)(A_y - B_y)) / D,
    U_y = ((A_x^2 + A_y^2)(C_x - B_x) + (B_x^2 + B_y^2)(A_x - C_x) + (C_x^2 + C_y^2)(B_x - A_x)) / D

with

    D = 2( A_x(B_y - C_y) + B_x(C_y - A_y) + C_x(A_y - B_y)).\,
 */

 #include<iostream>
 using namespace std;



void circumcenter(int x1,int y1,int x2,int y2,int x3,int y3) {
    float x,y;
    int d = 2(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    x = ((x1*x1 + y1*y1)(y2-y3) + (x2*x2 + y2*y2)(y3-y1) + (x3*x3 + y3*y3)(y1-y2)) / d;
    cout << x << " " << y;
}

main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cord[n][2];
        for(int i=0;i<n;i++)
        cin >> cord[i][0] >> cod[i][1];

    }
}
