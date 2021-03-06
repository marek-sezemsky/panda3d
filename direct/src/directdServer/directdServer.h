// Filename: directdServer.h
// Created by:  skyler 2002.04.08
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

#include "queuedConnectionReader.h"
#include "directd.h"

// Description: Start a directdServer on each of the machines you
//              which to start panda on.
//              
//              Start a directdClient on the controlling machine
//              or import ShowBaseGlobal with the xxxxx flag in
//              your Configrc.  The client will connact each of
//              the servers in the xxxxx list in your Configrc.
class DirectDServer: public DirectD {
public:
  DirectDServer();
  ~DirectDServer();
  
  void run_server(int port);

protected:
  void read_command(string& cmd);
  virtual void handle_command(const string& cmd);
};

