#include "leet.h"

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdint>


std::pair<int, int> twoSum(const std::vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++) {
        for(int j=i+1;j<nums.size();j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j}; // Return the indices of the two numbers
            }
        }
    }
    return {-1, -1}; // Return an invalid pair if no solution is found
}

std::list<int> addTwoNumbers(const std::list<int>& l1, const std::list<int>& l2) {
    std::list<int> result;

    int max_size = std::max(l1.size(), l2.size());
    int overflow = 0;

    std::list<int>::const_iterator it1 = l1.begin();
    std::list<int>::const_iterator it2 = l2.begin();

    for(int i=0;i<max_size;i++) {
        int digit1 = 0;
        int digit2 = 0;

        if(it1 != l1.end()) {
            digit1 = *it1;
            ++it1;
        }

        if(it2 != l2.end()) {
            digit2 = *it2;
            ++it2;
        }

        int sum = digit1 + digit2 + overflow;
        overflow = sum >= 10 ? 1 : 0;
        sum %= 10;

        result.emplace(result.end(), sum);
    }

    std::string resulting_string;
    for(const int& digit :  result) {
        resulting_string += std::to_string(digit);
    }

    std::cout << resulting_string << std::endl;
    return result;
}

std::string longestSubstring(const std::string input_string) {
    int length = input_string.size();

    if(length == 0) {
        return std::string();
    }

    if(length == 1) {
        return input_string;
    }

    char previous_char = input_string.at(0);
    std::string current_string = std::string(1, previous_char);
    std::string longest_string = current_string;
    

    for(int i=1;i<length;i++) {
        char current_char = input_string.at(i);

        if(current_string.find(current_char) != std::string::npos) {
            current_string = std::string(1,current_char);
            continue;
        }

        previous_char = current_char;
        current_string += current_char;

        if(longest_string.size() < current_string.size()) {
            longest_string = current_string;
        }
    }

    return longest_string;
}

// 1 3 4 5 77 88 99
// 34 45 66 

double findMedianSortedSingleArray(std::vector<int> nums) {
    if(nums.size() == 0) { 
        return 0.0;
    } else if(nums.size() == 1) { 
        return nums[0];
    }

    int mid_index = nums.size()/2;
    if(nums.size() % 2) {
        return nums[mid_index];
    } else {
        return (static_cast<double>(nums[mid_index]) + 
                static_cast<double>(nums[mid_index-1]))/2;
    }
}

double findMedianSortedArraysSmall(std::vector<int>& nums1, std::vector<int>& nums2,
                                   int index1, int index2) {
    bool odd = (nums1.size() + nums2.size()) %2;
    std::vector<int> sum_nums;
    
    for(int i = index1; i<index1+2 && i<nums1.size();i++) {
        sum_nums.insert(sum_nums.end(), nums1[i]);
    }

    for(int i = index2; i<index2+2 && i<nums2.size();i++) {
        sum_nums.insert(sum_nums.end(), nums2[i]);
    }

    std::sort(sum_nums.begin(), sum_nums.end());
    
    // Pop last value if original merged vector is odd and new vector isn't.
    if(odd && sum_nums.size() %2 == 0) {
        sum_nums.pop_back();
    }

    // Pop last value if original merged vector is even and new vector isn't.
    else if(!odd && sum_nums.size() %2 == 1) {
        sum_nums.pop_back();
    }

    // Pop last two value if original merged vector is even and new vector is.
    // This is because we only need two values and not four.
    else if(!odd && sum_nums.size() %2 == 0) {
        sum_nums.pop_back();
        sum_nums.pop_back();
    }
    
    return findMedianSortedSingleArray(sum_nums);
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    int min1 = 0;
    int min2 = 0;
    int max1 = nums1.size()-1;
    int max2 = nums2.size()-1;
    int mid1 = (max1+min1)/2;
    int mid2 = (max2+min2)/2;
    int round = 0;

    // Some basic sanity
    if(max1==-1 && max2==-1) {
        return 0;
    } else if(max1==-1) {
        return findMedianSortedSingleArray(nums2);
    } else if(max2==-10) {
        return findMedianSortedSingleArray(nums1);
    }

    do {
        int v1 = nums1[mid1];
        int v2 = nums2[mid2];

        // std::cout << round << std::endl;
        // std::cout << v1 << " : " << min1 << " " << mid1 << " " << max1 << std::endl;
        // std::cout << v2 << " : " << min2 << " " << mid2 << " " << max2 << std::endl;

        if(std::abs(v1-v2) < 5) {
            return findMedianSortedArraysSmall(nums1, nums2, mid1, mid2);
        }

        if(max1-min1 < 5 && max2-min2 < 5) {
            return findMedianSortedArraysSmall(nums1, nums2, min1, min2);
        }

        if(v1 < v2) {
            min1 = mid1;
            max2 = mid2;

        } else {
            max1 = mid1;
            min2 = mid2;
        }

        mid1 = (max1+min1)/2;
        mid2 = (max2+min2)/2;

        round++;
    } while(true);

    assert(0);
}


std::string palindromCheck(std::string *base_string,                      
                           int start, int end) {
    int i=start;
    int j = end;
    while(i < j) {
        if(base_string->at(i) != base_string->at(j)) {
            return std::string();
        }

        i++;
        j--;
    }

    return base_string->substr(start, end-start+1);
}

std::string longestPalindrome(std::string base_string) {
    std::string longest;

    if(base_string.size() == 1) {
        return base_string;
    }

    for(int i=0;i<base_string.size()-1;i++) {
        for(int j=base_string.size()-1;j>i;j--) {
            std::string result= palindromCheck(&base_string, i,j);
            if(result.size() > longest.size()) {
                longest = result;
            }
        }
    }

    return longest;
}

std::string zigZag(std::string input_string, int num_rows) {
    std::vector<std::string> rows;

    if(num_rows == 1) {
        return input_string;
    }

    for(int i=0;i<num_rows;i++) {
        rows.push_back(std::string());
    }

    int mod = 1;
    int i = 0;
    for(const char c : input_string) {
        rows[i]+=c;
        if(mod == 1 && i == num_rows -1) {
            mod = -1;
        } else if(mod == -1 && i == 0) {
            mod = 1;
        }
        i += mod;
    }

    std::string result;
    for(const std::string& s :  rows) {
        result += s;
    }

    return result;
}


int reverseInteger(int number) {
    int reverse = 0;

    std::vector<int> digits;

    if(number == 0) return 0;

    while(number !=0) {
        digits.push_back(number % 10);
        number /= 10;
    }

    int new_number = 0;

    for(int digit : digits) {
        // Overflow checks
        bool had_overflow = __builtin_mul_overflow(new_number, 10, &new_number);
        if(had_overflow) return 0;
        
        had_overflow = __builtin_add_overflow(new_number, digit, &new_number);
        if(had_overflow) return 0;
    }

    return new_number;
}

int stringToInteger(std::string number_string) {
    int number = 0;
    int sign = 1;

    bool prefix_spaces = true;
    bool sign_found = false;
    bool leading_zeros = true;


    for(char digit : number_string) {
        if(digit == ' ' && prefix_spaces) {
            continue;
        }

        prefix_spaces = false;

        if(digit == '-' && !sign_found) {
            sign_found = true;
            sign = -1;
            continue;
        }

        if(digit == '+' && !sign_found) {
            sign_found = true;
            continue;
        }

        sign_found = true;

        if(digit == '0' && leading_zeros) {
            continue;
        }

        leading_zeros = false;

        if(digit < '0' || digit > '9') {
            return number;
        }

        int int_digit = digit - '0';

        bool had_overflow = __builtin_mul_overflow(number, 10, &number);
        if(had_overflow) {
            if(sign == 1) {
                return INT32_MAX;
            } else {
                return INT32_MIN;
            }
        }
        
        had_overflow = __builtin_add_overflow(number, (int_digit * sign), &number);
        if(had_overflow) {
            if(sign == 1) {
                return INT32_MAX;
            } else {
                return INT32_MIN;
            }
        }
    }

    return number;
}

bool palindromeNumber(int number) {
    if(number < 0) return false;

    std::vector<int> digits;

    do {
        if(number == 0) {
            break;
        }

        int digit = number % 10;
        number /= 10;
        digits.push_back(digit);
    } while(true);

    int start = 0;
    int end = digits.size()-1;
    while(start < end) {
        int low_digit = digits[start];
        int high_digit = digits[end];
        
        if(low_digit != high_digit) return false;
        start++;
        end--;
    }

    return true;
}


bool recursiveMatchRegex(std::string text, std::string regex) {
    int regex_len = regex.size();

    // Stop Conditions
    if(text.empty()) {
        if(regex_len == 0) {
            // Classic "" == ""
            return true;
        } else if(regex_len == 1) {
            // Leftover asterisk. Previous step was "x" == "x*"
            return regex[0] == '*';
        } else if(regex[1] == '*' && regex[0] != '*') {
            // Possible case of "" == "x*"
            regex = regex.substr(2, regex.size()-2);
            return recursiveMatchRegex(text, regex);
        } else
        
        // Default mismatch - false
        return false;
    }

    // Standard match    
    if(regex[0]==text[0]) {
        text = text.substr(1, text.size()-1);
        if(regex_len>1 && regex[1]=='*') {
            // Asterisk option - here we try with and without the asterisk to deal 
            // with the following: text=aaa regex=ab*a*c*a
            bool option1 = recursiveMatchRegex(text, regex);
            regex = regex.substr(2, regex.size()-2);
            bool option2 = recursiveMatchRegex(text, regex);
            return option1 || option2;
        } else {
            regex = regex.substr(1, regex.size()-1);
            return recursiveMatchRegex(text, regex);
        }
    }

    // dot match
    char current_char = text[0];
    if('.'==text[0]) {
        text = text.substr(1, text.size()-1);
        if(regex_len>1 && regex[1]=='*') {
            regex[0] = current_char;
            return recursiveMatchRegex(text, regex);
        } else {
            regex = regex.substr(1, regex.size()-1);
            return recursiveMatchRegex(text, regex);
        }
    }

    // Can't match, but this would work if first two chars of regex are <something>*
    if(regex_len>1 && regex[1]=='*') {
        regex = regex.substr(2, regex.size()-2);
        return recursiveMatchRegex(text, regex);
    }

    return false;
}

