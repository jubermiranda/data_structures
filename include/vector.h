#ifndef MY_DS_VECTOR_H_
#define MY_DS_VECTOR_H_

#include <string>

using std::string;

namespace MY_DS {

const static size_t STD_MAX_SIZE = 255;

template <typename DataType> class Vector {
public:
  Vector(size_t max_size);

  bool is_empty();
  size_t size() const;
  size_t max_size() const;
  void resize(size_t new_size);
  void swap(Vector<DataType> &other);

  void push_back(const DataType &);
  void insert(size_t, const DataType &);
  void erase(size_t i);
  void pop_back();

  const DataType &at(size_t i) const;
  DataType &at(size_t i);

  Vector();
  Vector(const Vector &);
  Vector(Vector &&) noexcept;
  ~Vector();
  Vector &operator=(const Vector &);
  Vector &operator=(Vector &&) noexcept;

  const DataType &operator[](size_t i) const;
  DataType &operator[](size_t i);

private:
  size_t max;
  size_t crr_size;
  DataType *data;
};

// --

// IMPL

template <typename DataType>
Vector<DataType>::Vector()

    : data(new DataType[STD_MAX_SIZE]), max(STD_MAX_SIZE), crr_size(0) {}

template <typename DataType>
Vector<DataType>::Vector(const Vector &other)

    : max(other.max), crr_size(other.crr_size), data(new DataType[other.max]) {

  for (size_t i = 0; i < crr_size; i++)
    this->data[i] = other.data[i];
}

template <typename DataType>
Vector<DataType>::Vector(Vector &&other) noexcept
    : max(other.max), crr_size(other.crr_size), data(other.data) {

  other.max = 0;
  other.crr_size = 0;
  other.data = nullptr;
}

template <typename DataType>
Vector<DataType>::Vector(size_t max)
    : max(max), crr_size(0), data(new DataType[max]) {}

template <typename DataType> Vector<DataType>::~Vector() {
  delete[] this->data;
}

} // namespace MY_DS

#endif // MY_DS_VECTOR_H_
