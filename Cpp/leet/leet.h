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
std::string convertIntToRoman(int number);
int convertRomanToInt(std::string roman);
std::string longestCommonPrefix(const std::vector<std::string> strings);
std::vector<std::vector<int>> threeSome(std::vector<int>& numbers);
int threeSomeClosest(std::vector<int>& numbers, int target);
std::vector<std::string> letterCombinations(std::string digits);
std::vector<std::vector<int>> fourSome(std::vector<int>& numbers, int target);
std::list<int> mergeLists(std::vector<std::list<int>> lists);
std::list<int> reverseNodesKGroup(std::list<int> list, int k);

#endif // LEET_LEET_H