#include <iostream>
#include <atomic>
#include <mutex>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>

class SynchronizedArray {
private:
    std::vector<unsigned int> array;
    std::mutex lock;
public:
    SynchronizedArray(const std::vector<unsigned int> &array)
        : array(array) {}

    unsigned int get(size_t index) {
        std::lock_guard<std::mutex> guard(lock);
        return array[index];
    }
    void set(size_t index, unsigned int value) {
        std::lock_guard<std::mutex> guard(lock);
        array[index] = value;
    }
    size_t size() {
        return array.size();
    }
};

SynchronizedArray qi_energy({1,2,3,4,5});

class ContestManager {
private:

    static size_t get_winner(std::vector<int> &indexes, size_t l, size_t r) {
        if (l == r - 1) {
            qi_energy.set(l, qi_energy.get(l) * 2);
            return l;
        } else if (l == r - 2) {
            unsigned int first = qi_energy.get(l);
            unsigned int second = qi_energy.get(l + 1);
            if (first > second) {
                qi_energy.set(l, first + second);
                return l;
            } else if (second > first) {
                qi_energy.set(l + 1, first + second);
                return l + 1;
            } else {
                size_t winner = l + rand() % 2;
                qi_energy.set(winner, first + second);
                return winner;
            }
        }
        std::random_shuffle(indexes.begin() + l, indexes.begin() + r);
        size_t mid = (l + r) / 2;
        auto first_half_future = std::async(get_winner, std::ref(indexes), l, mid);
        auto second_half_future = std::async(get_winner, std::ref(indexes), mid, r);
        size_t first_index = first_half_future.get();
        size_t second_index = second_half_future.get();
        unsigned int first = qi_energy.get(first_index);
        unsigned int second = qi_energy.get(second_index);
        if (first > second) {
            qi_energy.set(first_index, first + second);
            return first_index;
        } else if (second > first) {
            qi_energy.set(second_index, first + second);
            return second_index;
        } else {
            size_t winner = rand() % 2 ? first_index : second_index;
            qi_energy.set(winner, first + second);
            return winner;
        }
    }

public:
    ContestManager(std::vector<unsigned int> arr) {
    }

    size_t start_contest() {
        std::vector<int> indexes(qi_energy.size());
        for (int i = 0; i < qi_energy.size(); i++) {
            indexes[i] = i;
        }
        return get_winner(indexes, 0, indexes.size());
    }
};

int main() {
    ContestManager manager({1, 2, 3, 4, 5});
    std::cout << manager.start_contest();
}