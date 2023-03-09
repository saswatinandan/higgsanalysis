#ifndef READERBASE_H
#define READERBASE_H

#include "FWCore/ParameterSet/interface/ParameterSet.h" // edm::ParameterSet
class TTree; // forward declaration

#include <string> // std::string
#include <vector> // std::vector<,>

class ReaderBase
{
public:
  ReaderBase() = default;
  virtual ~ReaderBase() {}

  virtual std::vector<std::string>
  setBranchAddresses(TTree * tree) = 0;
};

#endif // READERBASE_H
