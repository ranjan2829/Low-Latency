#include <iostream>
#include <forward_list>
#include <algorithm>
#include <string>

int num_hamlet(const std::forward_list<std::string>& books) {
    return std::count(books.begin(), books.end(), "Hamlet");
}

int main() {
    std::forward_list<std::string> books = {"Hamlet", "Macbeth", "Romeo and Juliet", "Hamlet"};

    int count = num_hamlet(books);

    std::cout << "Number of occurrences of 'Hamlet': " << count << std::endl;

    return 0;
}
