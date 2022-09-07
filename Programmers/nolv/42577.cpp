#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// for 문을 한 번만 써야 효율성 테스트 통과 가능함. 질문하기 참고함.
bool solution(vector<string> phone_book) {
    
    if(phone_book.size() == 1)
        return true;
    
    sort(phone_book.begin(), phone_book.end());
    int i = 0;
    while(true) {
        if (i == phone_book.size() - 1)
                break;
        
        string current = phone_book[i];
        string next = phone_book[i + 1];

        if (current == next.substr(0, current.size()))
            return false;
        i++;
    }
    
    return true;
}

// 효율성 3,4 에서 실패..

// bool solution(vector<string> phone_book) {
    
//     sort(phone_book.begin(), phone_book.end());
//     int i = 0;
//     int j;
//     while(true) {
//         if (i == phone_book.size())
//                 break;
        
//         string current = phone_book[i];
//         j = i + 1;
//         while(true) {
//             if (j == phone_book.size())
//                 break;
            
//             string next = phone_book[j];
            
//             if (current == next.substr(0, current.size()))
//                 return false;
//             j++;
//         }
//         i++;
//     }
    
//     return true;
// }

int main() {

    vector<string> phone_book = {"934793", "34", "44", "9347"};
    solution(phone_book);
    return 0;
}