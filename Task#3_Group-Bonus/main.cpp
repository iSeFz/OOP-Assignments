/**
 * @file main.cpp
 * @author Mohamed Amgad and Seif Yahia
 * @brief 
 * @version 2.0
 * @date 2022-12-22
 * 
 */

#include "msVector.hpp"
#include <unistd.h>
/**
 * @brief Main function
 * 
 * @return int 
 */
int main(){
    MSVector<int> nums1;
    MSVector<int> nums2;
    nums1.push_back(5);
    nums1.push_back(9);
    nums1.push_back(8);
    cout << "nums1 contents:\n" << nums1;
    cout << "nums1[2] = " << nums1[2] << endl;
    cout << "Deleted item: " << nums1.pop_back() << endl;
    cout << "nums1 contents:\n" << nums1;
    nums2 = nums1;
    cout << "Copied nums1 into nums2\n";
    cout << "nums2 contents:\n" << nums2;
    nums2.push_back(19);
    cout << "Added 19 to nums2\n";
    cout << "nums1 contents:\n" << nums1;
    cout << "nums2 contents:\n" << nums2;
    MSVector<int> nums3 = nums2;
    cout << "nums3 contents:\n" << nums3;
    nums1.Clear();
    cout << "Cleared nums1\n";
    cout << "nums1 contents:\n" << nums1;

    cout << "Wait for testing another data type...\n\n";
    sleep(3);

    MSVector <string> v1;
    v1.push_back((string) "Vector");
    v1.push_back((string) "C++");
    v1.push_back((string) "OOP");
    v1.push_back((string) "Programming");
    cout << v1;
    cout << "Capcity before adding: " << v1.Capacity() << endl; // 4
    v1.push_back((string) "testing");
    cout << "Capcity after adding: " << v1.Capacity() << endl; // 8
    cout << "Size after adding: " << v1.Size() << endl; // 5
    v1.erase(v1.begin() + 1, v1.begin() + 3);
    cout << v1;
    cout << "Size after erasing from 1 to 3 = " << v1.Size() << endl; // 3
    v1.insert(v1.end(),"insertedAtEnd");
    v1.insert(v1.begin(),"insertedAtBegin");
    cout << v1;
    v1.erase(v1.begin());
    v1.push_back("FinalTest");
    cout << v1;
    cout << "Capcity after adding: " << v1.Capacity() << endl; // 8
    cout << "Size after adding: " << v1.Size() << endl; // 5
    return 0;
}
