// Filename: modelPool.I
// Created by:  drose (12Mar02)
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
//     Function: ModelPool::has_model
//       Access: Public, Static
//  Description: Returns true if the model has ever been loaded,
//               false otherwise.
////////////////////////////////////////////////////////////////////
INLINE bool ModelPool::
has_model(const Filename &filename) {
  return get_ptr()->ns_has_model(filename);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::verify_model
//       Access: Public, Static
//  Description: Loads the given filename up as a model, if it has
//               not already been loaded, and returns true to indicate
//               success, or false to indicate failure.  If this
//               returns true, it is probable that a subsequent call
//               to load_model() with the same model name will
//               return a valid PandaNode.
//
//               However, even if this returns true, it is still
//               possible for a subsequent call to load_model() to
//               fail.  This can happen if cache-check-timestamps is
//               true, and the on-disk file is subsequently modified
//               to replace it with an invalid model.
////////////////////////////////////////////////////////////////////
INLINE bool ModelPool::
verify_model(const Filename &filename) {
  return load_model(filename) != (ModelRoot *)NULL;
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::load_model
//       Access: Public, Static
//  Description: Loads the given filename up as a model, if it has
//               not already been loaded, and returns the new model.
//               If a model with the same filename was previously
//               loaded, returns that one instead (unless
//               cache-check-timestamps is true and the file has
//               recently changed).  If the model file cannot be
//               found, or cannot be loaded for some reason, returns
//               NULL.
////////////////////////////////////////////////////////////////////
INLINE ModelRoot *ModelPool::
load_model(const Filename &filename, const LoaderOptions &options) {
  return get_ptr()->ns_load_model(filename, options);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::add_model
//       Access: Public, Static
//  Description: Adds the indicated already-loaded model to the
//               pool.  The model will replace any previously-loaded
//               model in the pool that had the same filename.
//
//               This two-parameter version of this method is
//               deprecated; use the one-parameter add_model(model)
//               instead.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
add_model(const Filename &filename, ModelRoot *model) {
  get_ptr()->ns_add_model(filename, model);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::release_model
//       Access: Public, Static
//  Description: Removes the indicated model from the pool,
//               indicating it will never be loaded again; the model
//               may then be freed.  If this function is never called,
//               a reference count will be maintained on every model
//               every loaded, and models will never be freed.
//
//               This version of this method is deprecated; use
//               release_model(model) instead.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
release_model(const Filename &filename) {
  get_ptr()->ns_release_model(filename);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::add_model
//       Access: Public, Static
//  Description: Adds the indicated already-loaded model to the
//               pool.  The model will replace any previously-loaded
//               model in the pool that had the same filename.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
add_model(ModelRoot *model) {
  get_ptr()->ns_add_model(model);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::release_model
//       Access: Public, Static
//  Description: Removes the indicated model from the pool,
//               indicating it will never be loaded again; the model
//               may then be freed.  If this function (and
//               garbage_collect()) is never called, a reference count
//               will be maintained on every model every loaded, and
//               models will never be freed.
//
//               The model's get_fullpath() value should not have been
//               changed during its lifetime, or this function may
//               fail to locate it in the pool.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
release_model(ModelRoot *model) {
  get_ptr()->ns_release_model(model);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::release_all_models
//       Access: Public, Static
//  Description: Releases all models in the pool and restores the
//               pool to the empty state.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
release_all_models() {
  get_ptr()->ns_release_all_models();
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::garbage_collect
//       Access: Public, Static
//  Description: Releases only those models in the pool that have a
//               reference count of exactly 1; i.e. only those
//               models that are not being used outside of the pool.
//               Returns the number of models released.
////////////////////////////////////////////////////////////////////
INLINE int ModelPool::
garbage_collect() {
  return get_ptr()->ns_garbage_collect();
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::list_contents
//       Access: Public, Static
//  Description: Lists the contents of the model pool to the
//               indicated output stream.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
list_contents(ostream &out) {
  get_ptr()->ns_list_contents(out);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::list_contents
//       Access: Public, Static
//  Description: Lists the contents of the model pool to cout.
////////////////////////////////////////////////////////////////////
INLINE void ModelPool::
list_contents() {
  get_ptr()->ns_list_contents(cout);
}

////////////////////////////////////////////////////////////////////
//     Function: ModelPool::Constructor
//       Access: Private
//  Description: The constructor is not intended to be called
//               directly; there's only supposed to be one ModelPool
//               in the universe and it constructs itself.
////////////////////////////////////////////////////////////////////
INLINE ModelPool::
ModelPool() {
}
