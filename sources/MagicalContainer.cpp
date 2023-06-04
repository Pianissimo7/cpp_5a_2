#include "MagicalContainer.hpp"


using namespace ariel;

MagicalContainer::MagicalContainer() {

}
MagicalContainer::~MagicalContainer() {
    
}
void MagicalContainer::addElement(int n) {

}
void MagicalContainer::removeElement(int n) {

}
int& MagicalContainer::get_at(size_t index) {
    return this->container[index];
}
size_t MagicalContainer::size() {
    return 0;
}

int& MagicalContainer::AscendingIterator::operator*() {
    return this->container.get_at(this->currentIndex);
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return *this;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    return *this;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    return *this;
}
bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator& other) const {
    return false;
}
bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator& other) const {
    return false;
}
bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator& other) const {
    return false;
}
bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator& other) const {
    return false;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator& other) {
    return *this;
}

int& MagicalContainer::SideCrossIterator::operator*() {
    return this->container.get_at(this->currentIndex);
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return *this;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    return *this;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}
bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator& other) const {
    return false;
}
bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator& other) const {
    return false;
}
bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator& other) const {
    return false;
}
bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator& other) const {
    return false;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator& other) {
    return *this;
}

int& MagicalContainer::PrimeIterator::operator*() {
    return this->container.get_at(this->currentIndex);
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return *this;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    return *this;
}
bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator& other) const {
    return false;
}
bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator& other) const {
    return false;
}
bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator& other) const {
    return false;
}
bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator& other) const {
    return false;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator& other) {
    return *this;
}
