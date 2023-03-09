#ifndef ObjectMultiplicityReader_h
#define ObjectMultiplicityReader_h

#include "higgsanalysis/Reader/interface/ReaderBase.h" // ReaderBase

// forward declarations
class TTree;
class ObjectMultiplicity;

class ObjectMultiplicityReader
  : public ReaderBase
{
public:
  ObjectMultiplicityReader();
  ObjectMultiplicityReader(ObjectMultiplicity * objectMultiplicity);
  ~ObjectMultiplicityReader() override;

  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  void
  setObjectMultiplicity(ObjectMultiplicity * objectMultiplicity);

protected:
  ObjectMultiplicity * objectMultiplicity_;

  std::string branchName_nMuon_;
  std::string branchName_nElectron_;
  std::string branchName_nHadTau_;
};

#endif // ObjectMultiplicityReader_h
