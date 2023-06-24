#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

template<typename T>
class HashTable {
private:
    std::vector<std::string> hashKeys;
    std::vector<T> hashVals;

public:
    void insert(std::string key, T value);
    T get(std::string key);
};


float add(float x, float y) {return x + y;}
float substract(float x, float y) {return x - y;}
float multiply(float x, float y) {return x * y;}
float divide(float x, float y) {return x / y;}

int main(int argc, char **argv) {
  HashTable operationHashTable = *new HashTable<float>;
  float x, y;
  std::string op;

  if (argc == 2) {
    std::cerr << "Too Low Arguments!" << '\n';
    exit(1);
  }

  x = atof(argv[1]);
  op = argv[2];
  y = atof(argv[3]);

  operationHashTable.insert("+", add(x,y));
  operationHashTable.insert("-", substract(x, y));
  operationHashTable.insert("*", multiply(x, y));
  operationHashTable.insert("/", divide(x, y));

  float result = operationHashTable.get(op);

  std::cout << x << ' ' << op << ' ' << y << ' ' << '=' << ' ' << result << '\n';
}

template<class T>
void HashTable<T>::insert(std::string key, T value) {
    this->hashKeys.push_back(key);
    this->hashVals.push_back(value);
}

template<class T>
T HashTable<T>::get(std::string key) {
    int m_val = 0;
    for (int i = 0; i < this->hashKeys.size(); ++i) {
        if (key == this->hashKeys.at(i)) {
            m_val = this->hashVals.at(i);
            break;
        }
    }

    return m_val;
}
