#ifndef MY_DS_VECTOR_H_
#define MY_DS_VECTOR_H_

#include <string>

using std::string;

namespace MY_DS {

const static size_t STD_VECTOR_SIZE = 255;

template <typename DataType> class Vector {
public:
  Vector();
  Vector(const Vector &);
  Vector(Vector &&) noexcept;
  ~Vector();
  Vector &operator=(const Vector &);
  Vector &operator=(Vector &&) noexcept;
  //

  Vector(size_t);

  size_t size() const;
  size_t capacity() const;

private:
  size_t total_size;
  size_t crr_size;
  DataType *data;
};

// --

// IMPL

template <typename DataType>
Vector<DataType>::Vector()

    : data(new DataType[STD_VECTOR_SIZE]), total_size(STD_VECTOR_SIZE),
      crr_size(0) {}

template <typename DataType>
Vector<DataType>::Vector(const Vector &other)

    : total_size(other.total_size), crr_size(other.crr_size),
      data(new DataType[other.total_size]) {

  for (size_t i = 0; i < crr_size; i++)
    this->data[i] = other.data[i];
}

template <typename DataType>
Vector<DataType>::Vector(Vector &&other) noexcept
    : total_size(other.total_size), crr_size(other.crr_size), data(other.data) {

  other.total_size = 0;
  other.crr_size = 0;
  other.data = nullptr;
}

template <typename DataType>
Vector<DataType>::Vector(size_t total)
    : total_size(total), crr_size(0), data(new DataType[total]) {}

template <typename DataType> Vector<DataType>::~Vector() {
  delete[] this->data;
}

} // namespace MY_DS

#endif // MY_DS_VECTOR_H_
