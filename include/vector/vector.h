#pragma once

#include <stdexcept>
#include <utility>

using std::string;

namespace MY_DS {

const static size_t SIZE_LIMIT = 16384;
const static size_t BLOCK_SIZE = 255;

template <typename DataType> class Vector {
public:
  Vector(size_t max_size = SIZE_LIMIT);
  Vector(const Vector &);
  Vector(Vector &&) noexcept;
  ~Vector();
  Vector &operator=(const Vector &);
  Vector &operator=(Vector &&) noexcept;

  bool is_empty() const;
  size_t size() const;
  size_t max_size() const;
  void resize(size_t new_size);
  void swap(Vector<DataType> &other);

  void push_back(const DataType &);
  void pop_back();
  void insert(size_t, const DataType &);
  void erase(size_t i);

  const DataType &at(size_t i) const;
  DataType &at(size_t i);

  const DataType &operator[](size_t i) const;
  DataType &operator[](size_t i);

private:
  size_t max;
  size_t crr_size;
  DataType *data;

  void expand_size_one_block();
};

} // namespace MY_DS

// IMPL
#include "vector.tpp"