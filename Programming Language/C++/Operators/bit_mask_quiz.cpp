#include <iostream>
#include <bitset>

using namespace std;
/*
1. 다음의 경우에 대해 플래그를 바꿔보세요
    기사를 봤을 때
    기사의 좋아요를 클릭했을 때
    기사의 좋아요를 다시 클릭했을 때
    본 기사만 삭제할 때
2. 두 줄이 왜 동일하게 작동하는지 설명해보세요
*/
int main() {
// 1.
    unsigned char option_viewd   = 0x01;
    unsigned char option_edited  = 0x02;
    unsigned char option_liked   = 0x04;
    unsigned char option_shared  = 0x08;
    unsigned char option_deleted = 0x80;
    
    unsigned char my_article_flags = 0;
    
    // view the article
    my_article_flags |= option_viewd;
    cout << bitset<8>(my_article_flags) << endl; // 00000001
    // like the article
    my_article_flags |= option_liked;
    cout << bitset<8>(my_article_flags) << endl; // 00000101
    // like the article again
    my_article_flags &= (~option_liked);
    cout << bitset<8>(my_article_flags) << endl; // 00000001
    // delete the article viewed
    my_article_flags &= (~option_viewd);
    cout << bitset<8>(my_article_flags) << endl; // 00000000
// 2.
/* Same expression
    myflags &= ~(option4 | option5);
    myflags &= ~option4 & ~option5;
*/
    unsigned char option4 = 0b0100;
    unsigned char option5 = 0b0101;

    unsigned char myflag = 0;
    
    cout << bitset<8>(option4 | option5) << endl; // 00000101

    // 11111011                          // 11111010
    cout << bitset<8>(~option4) << endl << bitset<8>(~option5) << endl;

    return 0;
}