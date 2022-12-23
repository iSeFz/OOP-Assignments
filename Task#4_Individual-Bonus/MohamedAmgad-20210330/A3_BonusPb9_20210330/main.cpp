#include "A3_BonusPb9_20210330.h++"

int main(){
    Set<int> s1;
    s1.insert(1);
    s1.insert(1);
    s1.insert(2);
    s1.insert(4);
    s1.insert(3);
    s1.insert(3);
    s1.print(); // 1 2 3 4
    Set<string> s2;
    s2.insert("Mohamed");
    s2.insert("Mohamed");
    s2.insert("Amgad");
    s2.insert("Mostafa");
    s2.insert("Mostafa");
    s2.insert("Seif");
    s2.erase("Mostafa");
    s2.print(); // Amgad Mohamed Seif
    return 0;
}
