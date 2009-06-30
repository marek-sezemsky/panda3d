// Filename: fileSpec.h
// Created by:  drose (29Jun09)
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

#ifndef FILESPEC_H
#define FILESPEC_H

#include <tinyxml.h>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////////
//       Class : FileSpec
// Description : This simple class is used both within the core API in
//               this module, as well as within the plugin_npapi
//               plugin implementation, to represent a file on disk
//               that may need to be verified or (re)downloaded.
////////////////////////////////////////////////////////////////////
class FileSpec {
public:
  FileSpec();
  void load_xml(TiXmlElement *element);

  inline const string &get_filename() const;
  inline string get_pathname(const string &package_dir) const;
  inline size_t get_size() const;
  
  bool quick_verify(const string &package_dir) const;
  bool full_verify(const string &package_dir) const;
  
  bool check_hash(const string &pathname) const;

private:
  static inline int decode_hexdigit(char c);
  static inline char encode_hexdigit(int c);

  static bool decode_hex(unsigned char *dest, const char *source, size_t size);
  static void encode_hex(char *dest, const unsigned char *source, size_t size);
  static void stream_hex(ostream &out, const unsigned char *source, size_t size);

  enum { hash_size = 16 };

  string _filename;
  size_t _size;
  time_t _timestamp;
  unsigned char _hash[hash_size];
  bool _got_hash;
};

#include "fileSpec.I"

#endif