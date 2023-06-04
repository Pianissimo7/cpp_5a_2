#include "doctest.h"
#include "MagicalContainer.hpp"


using namespace std;
using namespace ariel;

TEST_CASE("normal operation of each iterator with no edge cases") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    SUBCASE("Ascending Iterator") {
        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        CHECK_EQ(*it, 2);
        ++it;
        CHECK_EQ(*it, 3);
        ++it;
        CHECK_EQ(*it, 9);
        ++it;
        CHECK_EQ(*it, 17);
        ++it;
        CHECK_EQ(*it, 25);
        ++it;
        CHECK_FALSE(it != ascIter.end());
    }
    SUBCASE("SideCrossOrder Iterator") {
        MagicalContainer::SideCrossIterator crossIter(container);
        auto it = crossIter.begin();
        CHECK_EQ(*it, 2);
        ++it;
        CHECK_EQ(*it, 25);
        ++it;
        CHECK_EQ(*it, 3);
        ++it;
        CHECK_EQ(*it, 17);
        ++it;
        CHECK_EQ(*it, 9);
        ++it;
        CHECK_FALSE(it != crossIter.end());
    }
    SUBCASE("Prime Iterator") {
        MagicalContainer::PrimeIterator primeIter(container);
        auto it = primeIter.begin();
        CHECK_EQ(*it, 2);
        ++it;
        CHECK_EQ(*it, 3);
        ++it;
        CHECK_EQ(*it, 17);
        ++it;
        CHECK_FALSE(it != primeIter.end());

    }
}
TEST_CASE("ascending iterator can deal with negative values") {
    MagicalContainer container;
    container.addElement(-5);
    container.addElement(-2);
    container.addElement(-1);
    container.addElement(0);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator ascIter(container);
    auto it = ascIter.begin();
    CHECK_EQ(*it, -5);
    ++it;
    CHECK_EQ(*it, -2);
    ++it;
    CHECK_EQ(*it, -1);
    ++it;
    CHECK_EQ(*it, 0);
    ++it;
    CHECK_EQ(*it, 1);
    ++it;
    CHECK_EQ(*it, 2);
    ++it;
    CHECK_FALSE(it != ascIter.end());
}
TEST_CASE("prime iterator will not go over negative numbers even if their absolute value is prime") {
    MagicalContainer container;
    container.addElement(-5);
    container.addElement(-2);
    container.addElement(-1);
    container.addElement(0);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::PrimeIterator primeIter(container);
    auto it = primeIter.begin();
    CHECK_EQ(*it, 2);
    ++it;
    CHECK_FALSE(it != primeIter.end());
}
bool is_prime(int n) {
    for (int i = n/2 ; i > 1 ; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
TEST_CASE("make sure the prime iterator finds all prime numbers") {
    MagicalContainer container;
    for (int i = 0 ; i < 1000 ; i++) {
        container.addElement(i);
    }
    MagicalContainer::PrimeIterator primeIter(container);
    auto it = primeIter.begin();
    for (int i = 0 ; i < 168 ; i++) {
        CHECK(is_prime(*it));
        ++it;
    }
    CHECK_FALSE(it != primeIter.end());
}
TEST_CASE("looping over the elements stops when reaching the end") {
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    size_t n = 6;
    MagicalContainer::AscendingIterator ascIter(container);   
    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::PrimeIterator primeIter(container);
    auto ascIt = ascIter.begin();
    auto SCIt = crossIter.begin();
    auto primeIt = primeIter.begin();
    size_t i;
    for (i = 0 ; i < n ; i++) {
        ++ascIt;
    }
    CHECK_EQ(i + 1, 5);
    for (i = 0 ; i < n ; i++) {
        ++SCIt;
    }
    CHECK_EQ(i + 1, 5);
    for (i = 0 ; i < n ; i++) {
        ++primeIt;
    }
    CHECK_EQ(i + 1, 3);
}
TEST_CASE("comparision operators") {
    SUBCASE("== should compare the current placement of the iterator") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);
        auto ascIt1 = ascIter1.begin();
        auto ascIt2 = ascIter2.begin();
        while (true) {
            CHECK(ascIt1 == ascIt2);
            ++ascIt1;
            CHECK_FALSE(ascIt1 == ascIt2);
            ++ascIt2;
        }
    }
    SUBCASE("!= should compare the current placement of the iterator") {
        MagicalContainer container;
        container.addElement(17);
        container.addElement(2);
        container.addElement(25);
        container.addElement(9);
        container.addElement(3);
        MagicalContainer::AscendingIterator ascIter1(container);
        MagicalContainer::AscendingIterator ascIter2(container);
        auto ascIt1 = ascIter1.begin();
        auto ascIt2 = ascIter2.begin();
        while (true) {
            CHECK_FALSE(ascIt1 != ascIt2);
            ++ascIt2;
            CHECK(ascIt1 != ascIt2);
            ++ascIt1;
        }
    }
    SUBCASE("< should compare the current placement of the iterator") {
        // 1,14,2,5,4
        // 5>14, 2>1, 4>14
        MagicalContainer container;
        container.addElement(1);
        container.addElement(14);
        container.addElement(2);
        container.addElement(5);
        container.addElement(4);
        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);
        auto crossIt1 = crossIter1.begin();
        auto crossIt2 = crossIter2.begin();
        ++crossIt1;
        ++crossIt1;
        // now crossIt1 should be placed on 2
        // now crossIt2 should be placed on 1
        CHECK(crossIt1 > crossIt2);
        ++crossIt1;
        ++crossIt1;
        ++crossIt2;
        // now crossIt1 should be placed on 4
        // now crossIt2 should be placed on 14
        CHECK(crossIt1 > crossIt2);
        // reset
        crossIt1 = crossIter1.begin();
        crossIt2 = crossIter2.begin();
        ++crossIt1;
        ++crossIt2;
        ++crossIt2;
        ++crossIt2;
        // now crossIt1 should be placed on 14
        // now crossIt2 should be placed on 5
        CHECK(crossIt1 < crossIt2);

    }
    SUBCASE("> should compare the current placement of the iterator") {
        // 1,14,2,5,4
        // 5>14, 2>1, 4>14
        MagicalContainer container;
        container.addElement(1);
        container.addElement(14);
        container.addElement(2);
        container.addElement(5);
        container.addElement(4);
        MagicalContainer::SideCrossIterator crossIter1(container);
        MagicalContainer::SideCrossIterator crossIter2(container);
        auto crossIt1 = crossIter1.begin();
        auto crossIt2 = crossIter2.begin();
        ++crossIt1;
        ++crossIt1;
        // now crossIt1 should be placed on 2
        // now crossIt2 should be placed on 1
        CHECK(crossIt2 < crossIt1);
        ++crossIt1;
        ++crossIt1;
        ++crossIt2;
        // now crossIt1 should be placed on 4
        // now crossIt2 should be placed on 14
        CHECK(crossIt2 < crossIt1);
        // reset
        crossIt1 = crossIter1.begin();
        crossIt2 = crossIter2.begin();
        ++crossIt1;
        ++crossIt2;
        ++crossIt2;
        ++crossIt2;
        // now crossIt1 should be placed on 14
        // now crossIt2 should be placed on 5
        CHECK(crossIt2 > crossIt1);
    }
}