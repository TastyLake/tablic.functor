#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T>
class simple_functor {
    int sum;
    int count;
public:

    simple_functor() : sum(0), count(0) {}

    int get_count() const { return count; }
    int get_sum() const { return sum; }

    void operator()(int val) {
        sum += val;
        count++;
    }
};

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    Table(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols));
    }

    std::vector<T>& operator[](int row) {
        if (row < 0 || row >= rows) { 
            throw std::out_of_range("Неправильный индекс");
        }
        return data[row];
    }

    const std::vector<T>& operator[](int row) const {
        if (row < 0 || row >= rows) {
            throw std::out_of_range("Неправильный индекс");
        }
        return data[row];
    }

    int Size() const {
        return rows * cols;
    }
};

int main() {
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
 
    simple_functor<int> counter; 
    std::for_each(numbers.begin(), numbers.end(), counter);
    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

    Table<int> table(3, 4); 
    table[1][2] = 5;        
    std::cout << table[1][2] << std::endl; 

    return 0;
}
