#ifndef LEET_LEET_H
#define LEET_LEET_H

#include <utility>
#include <vector>
#include <list>
#include <string>

std::list<int> addTwoNumbers(const std::list<int>& l1, const std::list<int>& l2);
std::string longestSubstring(const std::string input_string);
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
std::string longestPalindrome(std::string base_string);
std::string zigZag(std::string input_string, int num_rows);
int reverseInteger(int number);
int stringToInteger(std::string number_string);
bool palindromeNumber(int number);
bool recursiveMatchRegex(std::string text, std::string regex);
int containerWithMostWater(std::vector<int>& heights);

#endif // LEET_LEET_H