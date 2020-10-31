#include <iostream>
#include <vector>

/*
 * В базу данных, являющуюся вектором, с клавиатуры приходят целочисленные значения, и помещаются в конец.
 * Однако, эта база может хранить только 20 элементов, а дальше необходимо будет удалять элементы,
 *  которые лежат в базе дольше всех.
 * При вводе -1 с клавиатуры необходимо вывести всё содержимое базы данных (то есть 20 или менее элементов)
 * Попробуйте написать максимально оптимизированное решение данной задачи,
 *  чтобы совершалось как можно меньше расширений и перемещений элементов внутри вектора.
 */

int updateCount(std::vector<int> vec, int value) {
    if (value == vec.size() - 1) {
        value = 0;
    } else {
        value++;
    }
    return value;
}

int printVec(std::vector<int> vec) {
    for (int i = 0; i < vec.size();i++) {
        std::cout << vec[i] << " ";
    }
}

int main() {
    std::vector<int> vec(5);
    int count = 0;
    int number = 0;
    bool fullSize = false;

    while (number != -1) {
        std::cout << "Input your number: ";
        std::cin >> number;
        if (number == -1) break;

        vec[count] = number;
        if (count == vec.capacity() - 1) {
            count = -1;
            fullSize = true;
        }
        count++;
    }
    if (fullSize == false) {
        vec.resize(count);
        printVec(vec);
    } else {
        std::vector<int> newVec(vec.size());
        for (int i = 0; i < newVec.size(); i++) {
            newVec[i] = vec[count];
            count = updateCount(vec, count);
        }
        printVec(newVec);
    }
}
