#include "leet.h"

#include <iostream>
#include <numeric>
#include <assert.h>
#include <cstdint>
#include <algorithm>
#include <set>

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

void testSingleRoman(int number, std::string expected_result) {
    std::string result = convertIntToRoman(number);
    std::cout << "convertIntToRoman of " << number << " is " << result << std::endl;
    assert(result == expected_result);

    // A bit ugly, as we're reusing the parameters in the opposite direction
    int number_result = convertRomanToInt(expected_result);
    std::cout << "convertRomanToInt of " << expected_result << " is " << number_result << std::endl;
    assert(number == number_result);
}

void testRoman() {
    struct RomanTestCase {
        int number;
        std::string expected_result;
    };

    RomanTestCase test_cases[] = {
        {1, "I"},
        {2, "II"},
        {3, "III"},
        {4, "IV"},
        {5, "V"},
        {6, "VI"},
        {7, "VII"},
        {8, "VIII"},
        {9, "IX"},
        {10, "X"},
        {11, "XI"},
        {14, "XIV"},
        {15, "XV"},
        {40, "XL"},
        {58, "LVIII"},
        {90, "XC"},
        {400, "CD"},
        {900, "CM"},
        {621, "DCXXI"},
        {1994, "MCMXCIV"},
        {3888, "MMMDCCCLXXXVIII"},
        {3999, "MMMCMXCIX"}
    };

    for(const auto& test : test_cases) {
        testSingleRoman(test.number, test.expected_result);
    }
}

void testSingleLongestPrefix(std::vector<std::string> strings, std::string expected_result) {
    std::string result = longestCommonPrefix(strings);
    std::cout << "longestCommonPrefix is " << result << std::endl;
    assert(result == expected_result);
}

void testLongestPrefix() {
    std::vector<std::pair<std::vector<std::string>, std::string>> test_cases = {
        {{"flower", "flow", "flight"}, "fl"},
        {{"dog", "racecar", "car"}, ""},
        {{""}, ""},
        {{"" ,"abc", "abd"}, ""},
        {{"abc"}, "abc"},
        {{"interstellar", "internet", "internal"}, "inter"},
        {{"prefix", "preach", "present"}, "pre"},
        {{"same", "same", "same"}, "same"},
        {{"antidisestablishmentarianism", "antibiotic", "antique"}, "anti"},
        {std::vector<std::string>(10000, "copilot"), "copilot"}
    };

    for (auto& [input, expected] : test_cases) {
        testSingleLongestPrefix(input, expected);
    }
}

// Utility to normalize triplet results for reliable comparison
void normalize(std::vector<std::vector<int>>& triplets) {
    for (auto& triplet : triplets) {
        std::sort(triplet.begin(), triplet.end());
    }
    std::sort(triplets.begin(), triplets.end());
}

// Comparison helper
bool equalTriplets(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> copyA = a, copyB = b;
    normalize(copyA);
    normalize(copyB);
    return copyA == copyB;
}

void testThreesomes() {
    struct Test {
        std::vector<int> input;
        std::vector<std::vector<int>> expected;
    };

    std::vector<Test> tests = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{0, 1, 1}, {}},
        {{0, 0, 0}, {{0, 0, 0}}},
        {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}},
        {{}, {}},
        {{-1, 1}, {}},
        {{-2, -2, 0, 0, 2, 2}, {{-2, 0, 2}}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto output = threeSome(tests[i].input);
        assert(equalTriplets(output, tests[i].expected));
        std::cout << "✅ Test " << i + 1 << " passed!" << std::endl;
    }

    std::cout << "🎉 All tests completed successfully!" << std::endl;
}

void testThresomeClosest() {
    struct TestCase {
        std::vector<int> nums;
        int target;
        int expected;
    };

    std::vector<TestCase> tests = {
        {{-1, 2, 1, -4}, 1, 2},                     // -1 + 2 + 1 = 2
        {{0, 0, 0}, 1, 0},                          // Only one triplet: 0 + 0 + 0 = 0
        {{1, 1, -1, -1, 3}, -1, -1},                // Closest sum: -1 + -1 + 1 = -1
        {{1, 2, 5, 10, 11}, 12, 13},                // 1 + 2 + 10 = 13
        {{1, 2, 3, 4, 5}, 10, 10},                  // 2 + 3 + 5 = 10
        {{-3, -2, -5, 3, -4}, -1, -2}               // Best: -2 + -4 + 3 = -3 or -5 + 3 + -2 = -4
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        int result = threeSomeClosest(tests[i].nums, tests[i].target);
        assert(result == tests[i].expected);
        std::cout << "✅ Test " << i + 1 << " passed!" << std::endl;
    }

    std::cout << "🎉 All tests completed successfully!" << std::endl;
}

bool equalSets(const std::vector<std::string>& a, 
               const std::vector<std::string>& b) {
    std::set<std::string> sa(a.begin(), a.end());
    std::set<std::string> sb(b.begin(), b.end());
    return sa == sb;
}

void testLetterCombinations() {
    struct TestCase {
        std::string digits;
        std::vector<std::string> expected;
    };

    std::vector<TestCase> tests = {
        {"2", {"a", "b", "c"}},
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", {}},
        {"7", {"p", "q", "r", "s"}},
        {"9", {"w", "x", "y", "z"}},
        {"234", {
            "adg","adh","adi","aeg","aeh","aei","afg","afh","afi",
            "bdg","bdh","bdi","beg","beh","bei","bfg","bfh","bfi",
            "cdg","cdh","cdi","ceg","ceh","cei","cfg","cfh","cfi"
        }}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto result = letterCombinations(tests[i].digits);
        assert(equalSets(result, tests[i].expected));
        std::cout << "✅ Test " << i + 1 << " passed!" << std::endl;
    }

    std::cout << "🎉 All tests passed successfully!" << std::endl;
}

void normalize4(std::vector<std::vector<int>>& quads) {
    for (auto& quad : quads) {
        sort(quad.begin(), quad.end());
    }
    sort(quads.begin(), quads.end());
}

// Compare two sets of quadruplets
bool equalQuadruplets(const std::vector<std::vector<int>>& a, 
                      const std::vector<std::vector<int>>& b) {
    std::vector<std::vector<int>> copyA = a, copyB = b;
    normalize4(copyA);
    normalize4(copyB);
    return copyA == copyB;
}

void testFourSome() {
    struct TestCase {
        std::vector<int> nums;
        int target;
        std::vector<std::vector<int>> expected;
    };

    std::vector<TestCase> tests = {
        {{1, 0, -1, 0, -2, 2}, 0, {
            {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}
        }},
        {{2, 2, 2, 2, 2}, 8, {
            {2, 2, 2, 2}
        }},
        {{-3, -1, 0, 2, 4, 5}, 2, {
            {-3, -1, 2, 4}
        }},
        {{}, 0, {}},
        {{1, 2, 3, 4}, 100, {}},
        {{0, 0, 0, 0}, 0, {{0, 0, 0, 0}}}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto output = fourSome(tests[i].nums, tests[i].target);
        assert(equalQuadruplets(output, tests[i].expected));
        std::cout << "✅ Test " << i + 1 << " passed!" << std::endl;
    }

    std::cout << "🎉 All tests passed successfully!" << std::endl;
}

// Utility function to compare two std::list<int>
bool areEqual(const std::list<int>& a, const std::list<int>& b) {
    return std::equal(a.begin(), a.end(), b.begin(), b.end());
}

void testMergeKSortedLists() {
    struct TestCase {
        std::vector<std::list<int>> input;
        std::list<int> expected;
    };

    std::vector<TestCase> tests = {
        {
            {
                {1, 4, 5},
                {1, 3, 4},
                {2, 6}
            },
            {1, 1, 2, 3, 4, 4, 5, 6}
        },
        {
            {
                {},
                {},
                {}
            },
            {}
        },
        {
            {
                {5, 10, 15}
            },
            {5, 10, 15}
        },
        {
            {
                {1, 3, 5},
                {},
                {2, 4, 6}
            },
            {1, 2, 3, 4, 5, 6}
        },
        {
            {
                {2},
                {2},
                {2}
            },
            {2, 2, 2}
        }
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        std::list<int> result = mergeLists(tests[i].input);
        assert(areEqual(result, tests[i].expected));
        std::cout << "✅ Test " << i + 1 << " passed!" << std::endl;
    }

    std::cout << "🎉 All tests completed successfully!" << std::endl;
}

// Utility: Print list contents
void printList(const std::list<int>& lst) {
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int testReverseNodeKGroup() {
    struct TestCase {
        std::list<int> input;
        int k;
        std::list<int> expected;
    };

    std::vector<TestCase> tests = {
        {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
        {{1, 2, 3}, 1, {1, 2, 3}},               // k = 1 → no change
        {{1, 2, 3, 4}, 4, {4, 3, 2, 1}},          // full reversal
        {{1, 2, 3, 4, 5, 6}, 2, {2, 1, 4, 3, 6, 5}},
        {{}, 3, {}},                             // empty list
        {{1}, 2, {1}},                           // not enough nodes to reverse
        {{10, 20, 30}, 3, {30, 20, 10}}
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        std::list<int> result = reverseNodesKGroup(tests[i].input, tests[i].k);
        assert(areEqual(result, tests[i].expected));
        std::cout << "✅ Test " << i + 1 << " passed.\n";
    }

    std::cout << "🎉 All test cases completed successfully!\n";
    return 0;
}

void testSubstringWithConcatOfWords() {
    struct TestCase {
        std::string s;
        std::vector<std::string> words;
        std::vector<int> expected;
    };

    std::vector<TestCase> tests = {
        {"barfoothefoobarman", {"foo", "bar"}, {0, 9}},
        {"wordgoodgoodgoodbestword", {"word", "good", "best", "word"}, {}},
        {"barfoofoobarthefoobarman", {"bar","foo","the"}, {6, 9, 12}},
        {"", {"foo", "bar"}, {}},
        {"foobarfoobar", {"foo", "bar"}, {0, 3, 6}},
        {"aaaaaaaaaaaaaa", {"aa", "aa", "aa"}, {0, 1, 2, 3, 4, 5, 6, 7, 8}},
        {"lingmindraboofooowingdingbarrwingmonkeypoundcake", 
         {"fooo","barr","wing","ding","wing"}, {13}},
        {"abcd", {"a", "b", "c", "d"}, {0}},
        {"abcdef", {"gh", "ij"}, {}}
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        std::vector<int> result = findSubstring(tests[i].s, tests[i].words);
        assert(result == tests[i].expected);

        std::cout << "✅ Test " << i + 1 << " passed!\n";
    }

    std::cout << "🎉 All tests completed successfully!\n";
}

void testLongestValidParentheses() {
    struct TestCase {
        std::string input;
        int expected;
    };

    std::vector<TestCase> tests = {
        {"", 0},
        {"(", 0},
        {")", 0},
        {"()", 2},
        {"(()", 2},
        {")()())", 4},
        {"(()())", 6},
        {"()(()", 2},
        {"(()(((()", 2},
        {"((()))", 6},
        {"(()()(()", 4},
        {"(()())())", 6},
        {"())(())", 4},
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        int result = longestValidParentheses(tests[i].input);
        assert(result == tests[i].expected);
        std::cout << "✅ Test " << i + 1 << " passed.\n";
    }

    std::cout << "🎉 All test cases completed successfully!\n";
}

void testTrapWater() {
    struct TestCase {
        std::vector<int> input;
        int expected;
    };

    std::vector<TestCase> tests = {
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
        {{4,2,0,3,2,5}, 9},
        {{2,0,2}, 2},
        {{3,0,0,2,0,4}, 10},
        {{}, 0},
        {{1}, 0},
        {{5,4,1,2}, 1},
        {{2,1,0,1,2}, 4},
        {{0,0,0,0}, 0},
        {{1,2,3,4,5}, 0},
        {{5,4,3,2,1}, 0}
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        int result = trapWater(tests[i].input);
        assert(result == tests[i].expected);
        std::cout << "✅ Test " << i + 1 << " passed.\n";
    }

    std::cout << "🎉 All tests completed successfully!\n";
}

void testFirstPositive() {
    struct TestCase {
        std::vector<int> input;
        int expected;
    };

    std::vector<TestCase> tests = {
        {{1, 2, 0}, 3},
        {{3, 4, -1, 1}, 2},
        {{7, 8, 9, 11, 12}, 1},
        {{}, 1},
        {{-1, -2, -3}, 1},
        {{1}, 2},
        {{2}, 1},
        {{1, 1}, 2},
        {{2, 2}, 1},
        {{1, 2, 3, 4, 5}, 6},
        {{5, 4, 3, 2, 1}, 6},
        {{10, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 11}
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        std::vector<int> inputCopy = tests[i].input; // Copy to preserve original
        int result = firstMissingPositive(inputCopy);
        assert(result == tests[i].expected);
        std::cout << "✅ Test " << i + 1 << " passed.\n";
    }

    std::cout << "🎉 All tests completed successfully!\n";
}



void testWildcardMatching() {
    struct TestCase {
        std::string s;
        std::string p;
        bool expected;
    };

    std::vector<TestCase> tests = {
        {"aa", "a", false},
        {"aa", "*", true},
        {"cb", "?a", false},
        {"adceb", "*a*b", true},
        {"acdcb", "a*c?b", false},
        {"", "*", true},
        {"", "?", false},
        {"abc", "a?c", true},
        {"abc", "a*", true},
        {"abc", "*c", true},
        {"abc", "*b", false},
        {"abc", "*?c", true},
        {"abc", "*?b", false},
        {"abcde", "a*de", true},
        {"abcde", "a*d?", true},
        {"abcde", "a*d", false}
    };

    for (std::size_t i = 0; i < tests.size(); ++i) {
        bool result = recursiveWildcardMatching(tests[i].s, tests[i].p);
        assert(result == tests[i].expected);
        std::cout << "✅ Test " << i + 1 << " passed.\n";
    }

    std::cout << "🎉 All tests completed successfully!\n";
}

