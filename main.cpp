#include <iostream>
#include <cmath>

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
float regeron(float a, float c){
    return sqrtf(((c*c) - (a*a)));
}

int t1084(){
    float len_square, len_rope;
    float pi = 3.1415926535;

    cin >> len_square >> len_rope;
    if (len_rope <= len_square * 0.5){
        cout << fixed;
        cout.precision(3);
        cout << (pi) * len_rope * len_rope;
    } else if (len_rope >= (len_square * sqrt(2)) * 0.5) {
        cout << fixed;
        cout.precision(3);
        cout << len_square * len_square;
    } else {
        float a = (len_square / 2);
        float b = regeron(a, len_rope);
        cout << fixed;
        cout.precision(3);
        cout << (a * b * 4.) + ((((pi * len_rope * len_rope) * (((pi / 2.) - 2 * (acosf(a / len_rope))) * (180 / pi))) / 360) * 4) << '\n';
    }

    return 0;
}
//----------------------------------------------------------------------------------------------------------------------
int t1409(){
    int a, b;
    cin >> a >> b;
    cout << (b - 1) << ' ' << (a - 1);
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------

int t1885(){
    float h, t, v, x;
    cin >> h >> t >> v >> x;
    cout << (t * v - h) / (v - x) << h / (x + 1);

}

//----------------------------------------------------------------------------------------------------------------------


int main() {
    t1885();
    return 0;
}