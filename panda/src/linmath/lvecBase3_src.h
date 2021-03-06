// Filename: lvecBase3_src.h
// Created by:  drose (08Mar00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//       Class : LVecBase3
// Description : This is the base class for all three-component
//               vectors and points.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_LINMATH FLOATNAME(LVecBase3) {
PUBLISHED:
  typedef const FLOATTYPE *iterator;
  typedef const FLOATTYPE *const_iterator;

  INLINE_LINMATH FLOATNAME(LVecBase3)();
  INLINE_LINMATH FLOATNAME(LVecBase3)(const FLOATNAME(LVecBase3) &copy);
  INLINE_LINMATH FLOATNAME(LVecBase3) &operator = (const FLOATNAME(LVecBase3) &copy);
  INLINE_LINMATH FLOATNAME(LVecBase3) &operator = (FLOATTYPE fill_value);
  INLINE_LINMATH FLOATNAME(LVecBase3)(FLOATTYPE fill_value);
  INLINE_LINMATH FLOATNAME(LVecBase3)(FLOATTYPE x, FLOATTYPE y, FLOATTYPE z);
  INLINE_LINMATH FLOATNAME(LVecBase3)(const FLOATNAME(LVecBase2) &copy, FLOATTYPE z);
  ALLOC_DELETED_CHAIN(FLOATNAME(LVecBase3));

  INLINE_LINMATH static const FLOATNAME(LVecBase3) &zero();
  INLINE_LINMATH static const FLOATNAME(LVecBase3) &unit_x();
  INLINE_LINMATH static const FLOATNAME(LVecBase3) &unit_y();
  INLINE_LINMATH static const FLOATNAME(LVecBase3) &unit_z();

  INLINE_LINMATH ~FLOATNAME(LVecBase3)();

  EXTENSION(INLINE_LINMATH PyObject *__reduce__(PyObject *self) const);
  EXTENSION(INLINE_LINMATH PyObject *__getattr__(const string &attr_name) const);
  EXTENSION(INLINE_LINMATH int __setattr__(PyObject *self, const string &attr_name, PyObject *assign));

  INLINE_LINMATH FLOATTYPE operator [](int i) const;
  INLINE_LINMATH FLOATTYPE &operator [](int i);
  EXTENSION(INLINE_LINMATH void __setitem__(int i, FLOATTYPE v));
  INLINE_LINMATH static int size();

  INLINE_LINMATH bool is_nan() const;

  INLINE_LINMATH FLOATTYPE get_cell(int i) const;
  INLINE_LINMATH FLOATTYPE get_x() const;
  INLINE_LINMATH FLOATTYPE get_y() const;
  INLINE_LINMATH FLOATTYPE get_z() const;

  INLINE_LINMATH void set_cell(int i, FLOATTYPE value);
  INLINE_LINMATH void set_x(FLOATTYPE value);
  INLINE_LINMATH void set_y(FLOATTYPE value);
  INLINE_LINMATH void set_z(FLOATTYPE value);

  INLINE_LINMATH FLOATNAME(LVecBase2) get_xy() const;
  INLINE_LINMATH FLOATNAME(LVecBase2) get_xz() const;
  INLINE_LINMATH FLOATNAME(LVecBase2) get_yz() const;

  // These next functions add to an existing value.
  // i.e. foo.set_x(foo.get_x() + value)
  // These are useful to reduce overhead in scripting
  // languages:
  INLINE_LINMATH void add_to_cell(int i, FLOATTYPE value);
  INLINE_LINMATH void add_x(FLOATTYPE value);
  INLINE_LINMATH void add_y(FLOATTYPE value);
  INLINE_LINMATH void add_z(FLOATTYPE value);

  INLINE_LINMATH const FLOATTYPE *get_data() const;
  INLINE_LINMATH int get_num_components() const;

public:
  INLINE_LINMATH iterator begin();
  INLINE_LINMATH iterator end();

  INLINE_LINMATH const_iterator begin() const;
  INLINE_LINMATH const_iterator end() const;

PUBLISHED:
  INLINE_LINMATH void fill(FLOATTYPE fill_value);
  INLINE_LINMATH void set(FLOATTYPE x, FLOATTYPE y, FLOATTYPE z);

  INLINE_LINMATH FLOATTYPE dot(const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH FLOATTYPE length_squared() const;

#ifndef FLOATTYPE_IS_INT
  INLINE_LINMATH FLOATTYPE length() const;
  INLINE_LINMATH bool normalize();
  INLINE_LINMATH FLOATNAME(LVecBase3) project(const FLOATNAME(LVecBase3) &onto) const;
#endif

  INLINE_LINMATH FLOATNAME(LVecBase3) cross(const FLOATNAME(LVecBase3) &other) const;

  INLINE_LINMATH bool operator < (const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH bool operator == (const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH bool operator != (const FLOATNAME(LVecBase3) &other) const;

  INLINE_LINMATH FLOATNAME(LVecBase3) get_standardized_hpr() const;

  INLINE_LINMATH int compare_to(const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH size_t get_hash() const;
  INLINE_LINMATH size_t add_hash(size_t hash) const;
  INLINE_LINMATH void generate_hash(ChecksumHashGenerator &hashgen) const;

#ifndef FLOATTYPE_IS_INT
  INLINE_LINMATH int compare_to(const FLOATNAME(LVecBase3) &other,
                                FLOATTYPE threshold) const;
  INLINE_LINMATH size_t get_hash(FLOATTYPE threshold) const;
  INLINE_LINMATH size_t add_hash(size_t hash, FLOATTYPE threshold) const;
  INLINE_LINMATH void generate_hash(ChecksumHashGenerator &hashgen,
                                    FLOATTYPE threshold) const;
#endif

  INLINE_LINMATH FLOATNAME(LVecBase3) operator - () const;

  INLINE_LINMATH FLOATNAME(LVecBase3)
  operator + (const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH FLOATNAME(LVecBase3)
  operator - (const FLOATNAME(LVecBase3) &other) const;

  INLINE_LINMATH FLOATNAME(LVecBase3) operator * (FLOATTYPE scalar) const;
  INLINE_LINMATH FLOATNAME(LVecBase3) operator / (FLOATTYPE scalar) const;

  INLINE_LINMATH void operator += (const FLOATNAME(LVecBase3) &other);
  INLINE_LINMATH void operator -= (const FLOATNAME(LVecBase3) &other);

  INLINE_LINMATH void operator *= (FLOATTYPE scalar);
  INLINE_LINMATH void operator /= (FLOATTYPE scalar);

  INLINE_LINMATH void componentwise_mult(const FLOATNAME(LVecBase3) &other);

  EXTENSION(INLINE_LINMATH FLOATNAME(LVecBase3) __pow__(FLOATTYPE exponent) const);
  EXTENSION(INLINE_LINMATH PyObject *__ipow__(PyObject *self, FLOATTYPE exponent));

  INLINE_LINMATH FLOATNAME(LVecBase3) fmax(const FLOATNAME(LVecBase3) &other) const;
  INLINE_LINMATH FLOATNAME(LVecBase3) fmin(const FLOATNAME(LVecBase3) &other) const;

  INLINE_LINMATH void cross_into(const FLOATNAME(LVecBase3) &other);

  INLINE_LINMATH bool almost_equal(const FLOATNAME(LVecBase3) &other,
                           FLOATTYPE threshold) const;
  INLINE_LINMATH bool almost_equal(const FLOATNAME(LVecBase3) &other) const;

  INLINE_LINMATH void output(ostream &out) const;
  EXTENSION(INLINE_LINMATH void python_repr(ostream &out, const string &class_name) const);

  INLINE_LINMATH void write_datagram_fixed(Datagram &destination) const;
  INLINE_LINMATH void read_datagram_fixed(DatagramIterator &source);
  INLINE_LINMATH void write_datagram(Datagram &destination) const;
  INLINE_LINMATH void read_datagram(DatagramIterator &source);

public:
  // The underlying implementation is via the Eigen library, if available.

  // We don't bother to align LVecBase3, since it won't benefit from
  // SSE2 optimizations anyway (it's an add number of floats).
  typedef UNALIGNED_LINMATH_MATRIX(FLOATTYPE, 1, 3) EVector3;
  EVector3 _v;

  INLINE_LINMATH FLOATNAME(LVecBase3)(const EVector3 &v) : _v(v) { }

private:
  static const FLOATNAME(LVecBase3) _zero;
  static const FLOATNAME(LVecBase3) _unit_x;
  static const FLOATNAME(LVecBase3) _unit_y;
  static const FLOATNAME(LVecBase3) _unit_z;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type();
 
private:
  static TypeHandle _type_handle;
};


INLINE ostream &operator << (ostream &out, const FLOATNAME(LVecBase3) &vec) {
  vec.output(out);
  return out;
};

#include "lvecBase3_src.I"
