#ifndef L1PreFiringWeightReader_h
#define L1PreFiringWeightReader_h

#include "higgsanalysis/Reader/interface/ReaderBase.h" // ReaderBase
#include "higgsanalysis/CommonTools/interface/Era.h" // Era

#include <Rtypes.h> // Int_t, Double_t

#include <string> // std::string
#include <map> // std::map<,>

// forward declarations
enum class L1PreFiringWeightSys;

/**
 * @brief Reads L1 prefiring weights for 2016 & 2017 MC
 *
 * @see https://github.com/cms-sw/cmssw/pull/25380
 */
class L1PreFiringWeightReader
  : public ReaderBase
{
public:
  L1PreFiringWeightReader(Era era);
  ~L1PreFiringWeightReader();

  /**
   * @brief Call tree->SetBranchAddress for all branches containing LHE (scale and PDF) information
   */
  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  double
  getWeight(L1PreFiringWeightSys option) const;

protected:
  /**
    * @brief Initialize names of branches to be read from tree
    */
   void
   setBranchNames();

  Era era_;

  std::string branchName_l1PreFiringWeight_;

  Float_t l1PreFiringWeight_nominal_;
  Float_t l1PreFiringWeight_up_;
  Float_t l1PreFiringWeight_down_;

  // make sure that only one L1PreFiringWeightReader instance exists for a given branchName,
  // as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, L1PreFiringWeightReader *> instances_;
};

#endif // L1PreFiringWeightReader_h

