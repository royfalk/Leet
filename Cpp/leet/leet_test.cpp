#include "leet.h"

#include <iostream>
#include <numeric>
#include <assert.h>
#include <cstdint>

// Test code
void testAddTwoSum() {
    const std::list<int> l1 = {1,2,3,4,5,6,7,8};
    const std::list<int> l2 = {8,7,6,5,4,3,2,1};
    const std::list<int> expected_result = {9,9,9,9,9,9,9,9};
    const std::list<int> result = addTwoNumbers(l1, l2);
    if(expected_result == result) {
        std::cout << "addTwoNumbers ran successfully.\n";
    } else {
        std::cout << "addTwoNumbers failed to run successfully.\n";
    }

    const std::list<int> l3 = {9,9,9};
    const std::list<int> l4 = {9,9,9,3};
    const std::list<int> expected_result_2 = {8,9,9,4};
    const std::list<int> result_2 = addTwoNumbers(l3, l4);
    if(expected_result_2 == result_2) {
        std::cout << "2 addTwoNumbers ran successfully.\n";
    } else {
        std::cout << "2 addTwoNumbers failed to run successfully.\n";
    }
}

void testLongestString() {
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";
    std::cout << longestSubstring(s1) << std::endl;
    std::cout << longestSubstring(s2) << std::endl;
    std::cout << longestSubstring(s3) << std::endl;
}

void runSingleTestOfMedianOfTwoNumbers(std::vector<int> nums1, 
                                       std::vector<int> nums2,
                                       double expected_result) {
    std::string str1 = std::accumulate(nums1.begin(), nums1.end(), std::string(),
                                         [](const std::string& a, int b) {
                                             return a + std::to_string(b);
                                         });
    std::string str2 = std::accumulate(nums2.begin(), nums2.end(), std::string(),
                                         [](const std::string& a, int b) {
                                             return a + std::to_string(b);
                                         });
    double result = findMedianSortedArrays(nums1, nums2);
    std::cout << "result for {" << str1 << "}, {" << str2 << "} = " << result << " (" << expected_result << ")"<<std::endl;
    assert(result == expected_result);
    std::cout << "test ran successfully\n";
}

void testMedianOfTwoNumbers() {
    // Test Case 1: Basic odd total
    std::vector<int> nums1_1 = {1, 3};
    std::vector<int> nums2_1 = {2};
    // runSingleTestOfMedianOfTwoNumbers(nums1_1, nums2_1, 2);
    
    // Test Case 2: Basic even total
    std::vector<int> nums1_2 = {1, 2};
    std::vector<int> nums2_2 = {3, 4};
    // runSingleTestOfMedianOfTwoNumbers(nums1_2, nums2_2, 2.5);
    
    // Test Case 3: Empty nums1
    std::vector<int> nums1_3 = {};
    std::vector<int> nums2_3 = {1};
    // runSingleTestOfMedianOfTwoNumbers(nums1_3, nums2_3, 1.0);
    
    // Test Case 4: One array significantly larger
    std::vector<int> nums1_4 = {1, 2, 3, 4, 5};
    std::vector<int> nums2_4 = {6};
    runSingleTestOfMedianOfTwoNumbers(nums1_4, nums2_4, 3.5);
    
    // Test Case 5: Overlapping ranges
    std::vector<int> nums1_5 = {1, 5, 9};
    std::vector<int> nums2_5 = {2, 6, 10};
    runSingleTestOfMedianOfTwoNumbers(nums1_5, nums2_5, 5.5);
    
    // Add more test cases as needed based on the scenarios above.

    std::cout << "All tests passed (assuming assertions are uncommented and function is implemented)." << std::endl;
}

void runSingleTestOfLongestPalindrome(std::string test_string, 
                                      std::string expected_result) {
    std::string result = longestPalindrome(test_string);
    std::cout << "Longest Palindrome of " << test_string << " is " << result << std::endl;
    assert(result == expected_result);   
}

void testLongestPalindrome() {
    runSingleTestOfLongestPalindrome("babad","bab");
    runSingleTestOfLongestPalindrome("cbbd","bb");
    runSingleTestOfLongestPalindrome("a","a");
    runSingleTestOfLongestPalindrome("abcdedcba","abcdedcba");
    runSingleTestOfLongestPalindrome("aaaaa","aaaaa");
    runSingleTestOfLongestPalindrome("aaaa","aaaa");
    runSingleTestOfLongestPalindrome("abcba","abcba");
    runSingleTestOfLongestPalindrome("forgeeksskeegfor","geeksskeeg");
    runSingleTestOfLongestPalindrome("a1234321b","1234321");

    std::string test_string;
    for(int i=0;i<100;i++) {
        test_string += "abc";
    }
    test_string += "racecar" + test_string;
    runSingleTestOfLongestPalindrome(test_string, "racecar");
}

void runSingleTestOfZigZag(std::string test_string, int rows,
                           std::string expected_result) {
    std::string result = zigZag(test_string, rows);
    std::cout << "Zigzag of " << test_string << " is " << result << std::endl;
    assert(result == expected_result);
    
}

void testZigZag() {
    runSingleTestOfZigZag("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    runSingleTestOfZigZag("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    runSingleTestOfZigZag("A", 1, "A");
    runSingleTestOfZigZag("Ab", 1, "Ab");
    runSingleTestOfZigZag("AbCd", 1, "AbCd");
    runSingleTestOfZigZag("ABCDEFGHIJKL", 5, "AIBHJCGKDFLE");

    std::string all_x(100, 'x');
    runSingleTestOfZigZag(all_x, 15, all_x);
}

void testSingleReverseInteger(int number, int expected_result) {
    int result = reverseInteger(number);
    std::cout << "reverseInteger of " << number << " is " << result << std::endl;
    assert(result == expected_result);
}

void testReverseInteger() {
    testSingleReverseInteger(123, 321);
    testSingleReverseInteger(-123, -321);
    testSingleReverseInteger(120, 21);
    testSingleReverseInteger(0, 0);
    testSingleReverseInteger(1000000003, 0);
    testSingleReverseInteger(-1000000003, 0);
    testSingleReverseInteger(3223, 3223);
    testSingleReverseInteger(-3223, -3223);
    testSingleReverseInteger(2147483647, 0);
    testSingleReverseInteger(-2147483647, 0);
}

void testSingleStringToInt(std::string number_string, int expected_result) {
    int result = stringToInteger(number_string);
    std::cout << "stringToInteger of " << number_string << " is " << result << std::endl;
    assert(result == expected_result);
}

void testStringToInt() {
    testSingleStringToInt("42", 42);
    testSingleStringToInt("-42", -42);
    testSingleStringToInt("   +042", 42);
    testSingleStringToInt("   -042", -42);
    testSingleStringToInt("   0-42", 0);
    testSingleStringToInt("4193 with words", 4193);
    testSingleStringToInt("words and 987", 0);
    testSingleStringToInt("-91283472332", INT32_MIN);
    testSingleStringToInt("91283472332", INT32_MAX);
}

void testSinglePalindromeNumber(int number, bool expected_result) {
    bool result = palindromeNumber(number);
    std::cout << "palindromeNumber of " << number << " is " << result << std::endl;
    assert(result == expected_result);
}

void testPalidromeNumber() {
    testSinglePalindromeNumber(121,true);
    testSinglePalindromeNumber(0,true);
    testSinglePalindromeNumber(1001,true);
    testSinglePalindromeNumber(12344321,true);
    testSinglePalindromeNumber(123404321,true);
    testSinglePalindromeNumber(123,false);
    testSinglePalindromeNumber(-121,false);
    testSinglePalindromeNumber(10,false);
    testSinglePalindromeNumber(-101,false);
    testSinglePalindromeNumber(100,false);
}

void testSingleRegex(std::string text, std::string regex, bool expected_result) {
    bool result = recursiveMatchRegex(text, regex);
    std::cout << "recursiveMatchRegex of " << text << " and " << regex << " is " << result << std::endl;
    assert(result == expected_result);
}

void testRegex() {
    testSingleRegex("aa", "a", false);
    testSingleRegex("aa", "a*", true);
    testSingleRegex("ab", ".*", false);
    testSingleRegex("aaa", "c*a*b", false);
    testSingleRegex("mississippi", "mis*is*p*.", false);
    testSingleRegex("", ".*", true);
    testSingleRegex("", "", true);
    testSingleRegex("a", ".*", false);
    testSingleRegex("aaa", "ab*a*c*a", true);
    testSingleRegex("abcd", "d*", false);
    testSingleRegex("abc", ".*c", false);
    testSingleRegex("a", "ab*", true);
    testSingleRegex(std::string(100,'a'), "a*", true);
    testSingleRegex(std::string(100,'a') + 'b', "a*b", true);
}

void testSingleContainerWithMostWater(std::vector<int>& heights, std::string height_text, int expected_area) {
    int result = containerWithMostWater(heights);
    std::cout << "containerWithMostWater of " << height_text << " is " << result << std::endl;
    assert(result == expected_area);
}

void testContainerWithMostWater() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    testSingleContainerWithMostWater(height, "[1,8,6,2,5,4,8,3,7]", 49);
    height = {1,1};
    testSingleContainerWithMostWater(height, "[1,1]", 1);
    height = {100};
    testSingleContainerWithMostWater(height, "[100]", 0);
    height = {};
    testSingleContainerWithMostWater(height, "[]", 0);
    height = {4, 3, 2, 1, 4};
    testSingleContainerWithMostWater(height, "[4, 3, 2, 1, 4]", 16);
    height = {1, 2, 1};
    testSingleContainerWithMostWater(height, "[1, 2, 1]", 2);
    height = std::vector<int>(10000, 5);
    testSingleContainerWithMostWater(height, "[5 ... 5]", 49995);
    height = {1, 3, 2, 5, 25, 24, 5};
    testSingleContainerWithMostWater(height, "[1, 3, 2, 5, 25, 24, 5]", 24);
    height = {10, 9, 8, 7, 6, 5, 4};
    testSingleContainerWithMostWater(height, "[10, 9, 8, 7, 6, 5, 4]", 25);
}