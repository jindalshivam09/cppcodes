  /*  U_x = ((A_x^2 + A_y^2)(B_y - C_y) + (B_x^2 + B_y^2)(C_y - A_y) + (C_x^2 + C_y^2)(A_y - B_y)) / D,
    U_y = ((A_x^2 + A_y^2)(C_x - B_x) + (B_x^2 + B_y^2)(A_x - C_x) + (C_x^2 + C_y^2)(B_x - A_x)) / D

with

    D = 2( A_x(B_y - C_y) + B_x(C_y - A_y) + C_x(A_y - B_y)).\,
 */

 #include<iostream>
 #include<iomanip>
 #include<cmath>
 using namespace std;

typedef long long ll;

pair<float,float> circumcenter(int x1,int y1,int x2,int y2,int x3,int y3) {
    float x,y;
    cout << setprecision(6);
    int d = 2*(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    x = float((x1*x1 + y1*y1)*(y2-y3) + (x2*x2 + y2*y2)*(y3-y1) + (x3*x3 + y3*y3)*(y1-y2)) / d;
    y = float((x1*x1 + y1*y1)*(x3-x2) + (x2*x2 + y2*y2)*(x1-x3) + (x3*x3 + y3*y3)*(x2-x1)) / d;
    //cout << x << " " << y << endl;
    return make_pair(x,y);
}

bool isCollinear(int x1,int y1,int x2,int y2,int x3,int y3) {
    return (y2-y1)*(x3-x1) == (y3-y1)*(x2-x1);
}

main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cord[n][2];
        for(int i=0;i<n;i++)
        cin >> cord[i][0] >> cord[i][1];
        //ll tot =
        //cout << setprecision(8);
        int count=0;
        int tot=0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {

                    if(!isCollinear(cord[i][0],cord[i][1],cord[j][0],cord[j][1],cord[k][0],cord[k][1])) {
                        pair<float,float> c = circumcenter(cord[i][0],cord[i][1],cord[j][0],cord[j][1],cord[k][0],cord[k][1]);
                        //cout << c.first << " " << c.second << endl;
                        float x = c.first , y = c.second;
                        //cout << x << " " << y << endl;
                        float radius = (float((x-cord[i][0])*(x-cord[i][0]))+float((y-cord[i][1])*(y-cord[i][1])));
                        float r1 = radius+0.000001, r2 = radius - 0.000001;
                        for(int q=0;q<n;q++) {
                            if((cord[q][0]!=cord[i][0] || cord[q][1]!=cord[i][1])) {
                                if((cord[q][0]!=cord[j][0] || cord[q][1]!=cord[j][1])) {
                                    if((cord[q][0]!=cord[k][0] || cord[q][1]!=cord[k][1])) {
                              //          cout << cord[i][0] << cord[i][1] << endl;
                                //        cout << cord[j][0] << cord[j][1] << endl;
                                  //      cout << cord[k][0] << cord[k][1] << endl;
                                    //    cout << cord[q][0] << cord[q][1] << endl << endl;
                                        //cout << radius <<  " " << ((x-cord[q][0])*(x-cord[q][0])+(y-cord[q][1])*(y-cord[q][1])) << endl << endl;
                                        if(r1 >= float(float((x-cord[q][0])*(x-cord[q][0]))+float((y-cord[q][1])*(y-cord[q][1]))))
                                        count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
      //  cout << count << " " << n << endl;
        cout <<setprecision(7) <<  (float)(count*6)/(n*(n-1)*(n-2)*(n-3)) << endl;
    }
}
