#ifndef hltPathReader_h
#define hltPathReader_h

#include "higgsanalysis/Reader/interface/ReaderBase.h" // ReaderBase

#include <vector> // std::vector<,>

// forward declaration
class hltPath;

class hltPathReader
  : public ReaderBase
{
public:
  hltPathReader(const std::vector<hltPath *> & hltPaths);
  hltPathReader(const std::vector<std::vector<hltPath *>> & hltPaths);
  ~hltPathReader() {}

  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

private:
  std::vector<std::string>
  get_available_branches(TTree * tree) const;

  std::vector<hltPath *> hltPaths_;
};

#endif // hltPathReader_h
