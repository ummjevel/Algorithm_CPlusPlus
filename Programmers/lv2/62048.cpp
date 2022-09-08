
using namespace std;

long gcd(int big, int small) {
    long temp = small;
    while(true) {
        if (small % temp == 0 && big % temp == 0)
            break;
        temp--;
    }

    return temp;
}

long long solution(int w,int h) {
    // return w * h - floor(sqrt(pow(w, 2) + pow(h, 2)));
    // 최대공약수를 두 수 합에서 뺀 것
    long small, big;
    if (w < h) {
        small = w;
        big = h;
    } else {
        small = h;
        big = w;
    }
    return (long long)w*h - (w+h-gcd(big, small));
}

int main() {
    solution(8, 12);
    return 0;
}