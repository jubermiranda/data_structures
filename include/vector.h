#ifndef MY_DS_VECTOR_H_
#define MY_DS_VECTOR_H_

#include <functional>
#include <stdexcept>
#include <string>

using std::string;

namespace MY_DS {

const static size_t SIZE_LIMIT = 16384;
const static size_t BLOCK_SIZE = 255;

template <typename DataType> class Vector {
public:
  Vector(size_t max_size);

  bool is_empty() const;
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

  void expand_size_one_block();
};

// --

// IMPL

template <typename DataType> bool Vector<DataType>::is_empty() const {
  return (this->crr_size == 0);
}

template <typename DataType> size_t Vector<DataType>::size() const {
  return this->crr_size;
}

template <typename DataType> size_t Vector<DataType>::max_size() const {
  return this->max;
}

template <typename DataType> void Vector<DataType>::resize(size_t new_size) {
  if (new_size >= SIZE_LIMIT)
    throw std::runtime_error("out of max limit");

  DataType *aux = this->data;

  this->data = new DataType[new_size];
  this->max = new_size;
  for (size_t i = 0; i < this->crr_size; i++)
    this->data[i] = aux[i];

  delete[] aux;
}

template <typename DataType>
void Vector<DataType>::swap(Vector<DataType> &other) {
  std::swap(this->max, other.max);
  std::swap(this->crr_size, other.crr_size);
  std::swap(this->data, other.data);
}

template <typename DataType>
void Vector<DataType>::push_back(const DataType &el) {
  if (this->crr_size == this->max)
    this->resize(this->max + BLOCK_SIZE);

  this->data[this->crr_size++] = el;
}

template <typename DataType>
void Vector<DataType>::insert(size_t index, const DataType &el) {
  if (index >= this->crr_size)
    throw std::out_of_range("index out of range");

  if (this->crr_size == this->max)
    this->expand_size_one_block();

  if (index < this->crr_size) {
    for (size_t i = this->crr_size; i > index; i--)
      this->data[i] = this->data[i - 1];

    this->data[index] = el;
    this->crr_size++;
    return;
  }

  if (index == this->crr_size) {
    this->data[this->crr_size] = el;
    this->crr_size++;
    return;
  }

  throw std::runtime_error("unexpected error");
}

template <typename DataType>
void Vector<DataType>::erase(size_t index) {
  if(index >= this->crr_size)
    throw std::out_of_range("index out of range");

  for(size_t i = index; i < this->crr_size; i++)
    this->data[i] = this->data[i+1];

  this->crr_size--;
}

template <typename DataType> void Vector<DataType>::pop_back() {
  if (this->crr_size > 0) {
    // if target class has dynamic data, should call destructor here
    this->crr_size--;
  }
}

//
//

template <typename DataType>
Vector<DataType>::Vector()

    : data(new DataType[BLOCK_SIZE]), max(BLOCK_SIZE), crr_size(0) {}

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

template <typename DataType> void Vector<DataType>::expand_size_one_block() {
  size_t new_size = this->max + BLOCK_SIZE;
  this->resize(new_size);
}

template <typename DataType>
Vector<DataType> &Vector<DataType>::operator=(const Vector &other) {
  if (*this != other) {
    delete[] this->data;
    this->data = new DataType[other.max];
    this->crr_size = other.crr_size;
    this->max = other.max;
    for (size_t i = 0; i < other.crr_size; i++)
      this->data[i] = other.data[i];
  }
  return *this;
}

template <typename DataType>
Vector<DataType> &Vector<DataType>::operator=(Vector &&other) noexcept {
  this->max = other.max;
  this->crr_size = other.crr_size;
  this->data = other.data;

  other.crr_size = 0;
  other.max = 0;
  other.data = nullptr;
}

template <typename DataType>
const DataType &Vector<DataType>::operator[](size_t i) const {
  if (i >= this->crr_size)
    throw std::out_of_range("index out of vector range");
  return this->data[i];
}

template <typename DataType> DataType &Vector<DataType>::operator[](size_t i) {
  if (i >= this->crr_size)
    throw std::out_of_range("index out of vector range");
  return this->data[i];
}

} // namespace MY_DS
#endif // MY_DS_VECTOR_H_
