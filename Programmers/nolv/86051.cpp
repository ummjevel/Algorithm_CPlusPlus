#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int sum = 0;
    // 0 ~ 9 까지 다 더하고,
    for (int i = 0; i < 10; i++) {
        sum += i;   
    }
    // 있는 값은 뺀다.
    for (int i = 0; i < numbers.size(); i++) {
        sum -= numbers[i];
    }

    return sum;
}

int main() {

    vector<int> numbers = {1,2,3,4,6,7,8,0};

    solution(numbers);

    return 0;
}