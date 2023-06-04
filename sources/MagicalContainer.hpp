#include <vector>

namespace ariel {
    class MagicalContainer {
        private:
            std::vector<int> container;
        public:
            MagicalContainer();
            ~MagicalContainer();
            void addElement(int n);
            void removeElement(int n);
            int& get_at(size_t index);
            size_t size();

            class AscendingIterator {
                protected:
                    MagicalContainer& container; // Reference to the container
                    size_t currentIndex; // Current index of the iterator

                public:
                    AscendingIterator(MagicalContainer& cont, int starting_index=0) : container(cont), currentIndex(0) {}

                    // Overload the * operator to get the value at the current index
                    int& operator*();
                    // Function to get the iterator to the beginning of the container
                    AscendingIterator begin();

                    // Function to get the iterator to the end of the container
                    AscendingIterator end();

                    // Overload the ++ operator to move the iterator to the next index
                    AscendingIterator& operator++();

                    // Overload the != operator to check if two iterators are not equal
                    bool operator!=(const AscendingIterator& other) const;
                    bool operator==(const AscendingIterator& other) const;
                    bool operator<(const AscendingIterator& other) const;
                    bool operator>(const AscendingIterator& other) const;
                    AscendingIterator& operator=(const AscendingIterator& other);
            };
            class SideCrossIterator {
                private:
                    MagicalContainer& container; // Reference to the container
                    size_t currentIndex; // Current index of the iterator
                public:
                    SideCrossIterator(MagicalContainer& cont) : container(cont), currentIndex(0) {}
                    
                    // Overload the * operator to get the value at the current index
                    int& operator*();
                    // Function to get the iterator to the beginning of the container
                    SideCrossIterator begin();

                    // Function to get the iterator to the end of the container
                    SideCrossIterator end();

                    // Overload the ++ operator to move the iterator to the next index
                    SideCrossIterator& operator++();

                    // Overload the != operator to check if two iterators are not equal
                    bool operator!=(const SideCrossIterator& other) const;
                    bool operator==(const SideCrossIterator& other) const;
                    bool operator<(const SideCrossIterator& other) const;
                    bool operator>(const SideCrossIterator& other) const;
                    SideCrossIterator& operator=(const SideCrossIterator& other);
            };
            class PrimeIterator {
                private:
                    MagicalContainer& container; // Reference to the container
                    size_t currentIndex; // Current index of the iterator
                public:
                    PrimeIterator(MagicalContainer& cont) : container(cont), currentIndex(0) {}
                    
                    // Overload the * operator to get the value at the current index
                    int& operator*();
                    // Function to get the iterator to the beginning of the container
                    PrimeIterator begin();

                    // Function to get the iterator to the end of the container
                    PrimeIterator end();

                    // Overload the ++ operator to move the iterator to the next index
                    PrimeIterator& operator++();

                    // Overload the != operator to check if two iterators are not equal
                    bool operator!=(const PrimeIterator& other) const;
                    bool operator==(const PrimeIterator& other) const;
                    bool operator<(const PrimeIterator& other) const;
                    bool operator>(const PrimeIterator& other) const;
                    PrimeIterator& operator=(const PrimeIterator& other);
            };
    };
}