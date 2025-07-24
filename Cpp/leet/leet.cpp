#include "leet.h"

#include <iostream>
#include <assert.h>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cstdint>
#include <map>


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

int containerWithMostWater(std::vector<int>& heights) {
    if(heights.size() < 2) {
        return 0;
    }

    int max_i=-1;
    int max_area=-1;

    for(int i=0;i<heights.size()-1;i++) {
        if(max_i>heights[i]) {
            continue;
        } else {
            max_i = heights[i];
        }

        int max_j=-1;

        for(int j=heights.size()-1;j>i;j--) {
            if(max_j>heights[j]) {
                continue;
            } else {
                max_j = heights[j];
            }

            int distance = j-i;
            int area = std::min(heights[i], heights[j]) * distance;

            if(area>max_area) {
                max_area = area;
            }
        }
    }

    return max_area;
}

void loopRoman(int& number, std::string& roman, std::string letter, int value) {
    while(number>=value) {
        roman += letter;
        number -= value;
    }
}

void romanFourFiveNine(int& number, std::string& roman, int divider,
                       std::string four_letter, std::string five_letter, 
                       std::string nine_letter) {
    int digits = number/divider;
    switch(digits) {
        case 4:
            roman += four_letter;
            number -= 4 * divider;
            digits -= 4;
            break;
        case 9: 
            roman += nine_letter;
            number -= 9 * divider;
            digits -= 9;
            break;
    }

    // Must happen after nine, or we get XIIII instead of IX
    if(digits >= 5) {
        roman += five_letter;
        number -= 5 * divider;
    }
}

std::string convertIntToRoman(int number) {
    if(number<=0) {
        number = 1;
    } else if(number>=4000) {
        number = 3999;
    }

    std::string roman;

    loopRoman(number, roman, "M", 1000);
    romanFourFiveNine(number, roman, 100, "CD", "D", "CM");
    loopRoman(number, roman, "C", 100);
    romanFourFiveNine(number, roman, 10, "XL", "L", "XC");
    loopRoman(number, roman, "X", 10);
    romanFourFiveNine(number, roman, 1, "IV", "V", "IX");
    loopRoman(number, roman, "I", 1);
    
    return roman;
}

int convertRomanToInt(std::string roman) {
    int number = 0;

    struct RomanException {
        std::string two_letters;
        int value;
    };

    RomanException roman_exceptions[] = {
        {"CD", 400},
        {"CM", 900},
        {"XL", 40},
        {"XC", 90},
        {"IV", 4},
        {"IX", 9},
    };

    while(!roman.empty()) {
        if(roman.size() > 1) {
            const std::string two_letters = roman.substr(0,2);
            bool found = false;
            for(RomanException roman_exception : roman_exceptions) {
                if(two_letters == roman_exception.two_letters) {
                    found = true;
                    number += roman_exception.value;
                    break;
                }
            }

            if(found) {
                roman = roman.substr(2,roman.size()-2);
                continue;
            }
        }

        char c = roman[0];

        switch(c) {
            case 'I': number++; break;
            case 'V': number+=5; break;
            case 'X': number+=10; break;
            case 'L': number+=50; break;
            case 'C': number+=100; break;
            case 'D': number+= 500; break;
            case 'M': number+= 1000; break;
            default:
            assert(0);
        }

        roman = roman.substr(1,roman.size()-1);
    }

    return number;
}


std::string longestCommonPrefix(const std::vector<std::string> strings) {
    std::string prefix;

    for(int i=0; i < 200;i++) {
        char c = -1;

        for(const std::string& s : strings) {
            // We've reached the end of this string. Exit the function.
            if(i == s.size()) {
                return prefix;
            }

            // First string in loop. Just assign to c
            if(c==-1) {
                c = s[i];
                continue;
            }

            // Exit condition - chars are not the same at this index.
            if(c!=s[i]) {
                return prefix;
            }
        }

        prefix += c;
    }

    return prefix;
}

std::vector<std::vector<int>> threeSome(std::vector<int>& numbers) {
    std::map<std::string, std::vector<int>> three_somes;
    
    // Too small edge case
    if(numbers.size()<3) {
        return std::vector<std::vector<int>>();
    }
    
    for(int i=0;i<numbers.size()-2;i++) {
        for(int j=i+1;j<numbers.size()-1;j++) {
            for(int k=j+1;k<numbers.size();k++) {
                if(numbers[i]+numbers[j]+numbers[k] == 0) {
                    std::vector<int> three_some = {numbers[i], numbers[j], numbers[k]};
                    std::sort(three_some.begin(), three_some.end());
                    std::string key;
                    std::for_each(three_some.begin(), three_some.end(), [&key](int n) {
                        key += std::to_string(n) + "|"; // Ugly but should work.
                    });

                    key = key.substr(0, key.size()-1); // Get rid of last |

                    if (!three_somes.count(key)) {
                        three_somes[key] = three_some;
                    }
                }
            }
        }    
    }

    std::vector<std::vector<int>> three_somes_vector;

    for( std::map<std::string, std::vector<int>>::iterator it = three_somes.begin(); it != three_somes.end(); ++it ) {
        three_somes_vector.push_back( it->second );
    }

    return three_somes_vector;
}


int threeSomeClosest(std::vector<int>& numbers, int target) {
    int closest_value = 1000000;
    int distance = 1000000;
    
    for(int i=0;i<numbers.size()-2;i++) {
        for(int j=i+1;j<numbers.size()-1;j++) {
            for(int k=j+1;k<numbers.size();k++) {
                int current_value = numbers[i]+numbers[j]+numbers[k];
                int current_distance = std::abs(target-current_value);
                
                if(current_distance == 0) {
                    return current_value;
                }
                
                if(current_distance < distance) {
                    distance = current_distance;
                    closest_value = current_value;
                }
            }
        }    
    }

    return closest_value;
}

// This is a recursion
std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> combinations;
    int indices[] = {0,3,6,9,12,15,19,22};

    for(char c : digits) {
        std::vector<std::string> new_combinations;

        int limit = (c == '9' || c == '7' ? 4 : 3);
        char start = 'a' + indices[c - '2'];
        for(char i=0;i<limit;i++) {
            if(combinations.empty()) {
                std::string new_combination(1, start + i);
                new_combinations.push_back(new_combination);
            } else for(std::string combination :  combinations) {
                char new_letter = start + i;
                std::string new_combination = combination + new_letter;
                new_combinations.push_back(new_combination);
            }
        }

        combinations = new_combinations;
    }
    

    return combinations;
}


std::vector<std::vector<int>> fourSome(std::vector<int>& numbers, int target) {
    std::map<std::string, std::vector<int>> four_somes;
    
    // Too small edge case
    if(numbers.size()<4) {
        return std::vector<std::vector<int>>();
    }
    
    for(int i=0;i<numbers.size()-3;i++) {
        for(int j=i+1;j<numbers.size()-2;j++) {
            for(int k=j+1;k<numbers.size()-1;k++) {
                for(int l=k+1;l<numbers.size();l++) {
                    if(numbers[i]+numbers[j]+numbers[k]+numbers[l] == target) {
                        std::vector<int> four_some = {numbers[i], numbers[j], numbers[k], numbers[l]};
                        std::sort(four_some.begin(), four_some.end());
                        std::string key;
                        std::for_each(four_some.begin(), four_some.end(), [&key](int n) {
                            key += std::to_string(n) + "|"; // Ugly but should work.
                        });

                        key = key.substr(0, key.size()-1); // Get rid of last |

                        if (!four_somes.count(key)) {
                            four_somes[key] = four_some;
                        }
                    }
                }
            }
        }    
    }

    std::vector<std::vector<int>> four_somes_vector;

    for( std::map<std::string, std::vector<int>>::iterator it = four_somes.begin(); it != four_somes.end(); ++it ) {
        four_somes_vector.push_back( it->second );
    }

    return four_somes_vector;
}

void removeEmptyLists(std::vector<std::list<int>>& lists) {
    std::vector<int> empty_indices;

    for(int i=0;i<lists.size();i++) {
        if(lists[i].empty()) {
            empty_indices.push_back(i);
        }
    }

    for(int i=empty_indices.size()-1;i>=0;i--) {
        lists.erase(lists.begin() + empty_indices[i]);
    }
}

std::list<int> mergeLists(std::vector<std::list<int>> lists) {
    std::list<int> return_list;

    removeEmptyLists(lists);

    while(!lists.empty()) {
        int min_value = 1000000;
        int min_index = -1;

        for(int i=0;i<lists.size();i++) {
            if(i==0) {
                min_value = lists[0].front();
                min_index = 0;
            } else if(min_value > lists[i].front()) {
                min_value = lists[i].front();
                min_index = i;
            }
        }

        return_list.push_back(min_value);
        lists[min_index].pop_front();
        if(lists[min_index].empty()) {
            lists.erase(lists.begin() + min_index);
        }
    }

    return return_list;
}

std::list<int> reverseNodesKGroup(std::list<int> list, int k) {
    if(list.empty() || list.size() < k) {
        return list;
    }

    std::list<int>::iterator it = list.begin();
    
    while(std::distance(it, list.end()) >= k) {
        for(int i=1;i<k;i++) {
            std::list<int>::iterator forward_it = it;
            std::list<int>::iterator backward_it = it;
            forward_it++;
            for(int j=1;j<i;j++) backward_it--;
            int value = *forward_it;
            list.erase(forward_it);
            list.insert(backward_it, value);
        }

        it++;
    }

    return list;
}
