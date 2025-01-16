/* File: OnlyConnect.cpp
 *
 * 返回的是去除掉phrase的非辅音字母，标点符号，空格等等，注意：去除后返回的string 不包括y
 * Example:
 * phrase: Elena Kagan
 * return string: LNKGN
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include "strlib.h"
#include <cctype>
using namespace std;


const string VOWEL = "aeiouAEIOU";
string onlyConnectize(string phrase) {
    if (phrase.length() == 0) {
        return "";
    } else if (VOWEL.find(phrase[0]) != VOWEL.npos) {
        return onlyConnectize(phrase.substr(1, phrase.size()));
    } else {
        if (isalpha(phrase[0])) {
            return toUpperCase(phrase[0]) + onlyConnectize(phrase.substr(1, phrase.size()));
        } else {
            return onlyConnectize(phrase.substr(1, phrase.size()));
        }

    }
}






/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
STUDENT_TEST("Combine Provided_test.") {
    EXPECT_EQUAL(onlyConnectize("A+Qlowercase2.71828"), "QLWRCS");
}





