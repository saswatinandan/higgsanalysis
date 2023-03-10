#ifndef RecoJetReaderAK8_h
#define RecoJetReaderAK8_h

#include "higgsanalysis/Reader/interface/ReaderBase.h"           // ReaderBase
#include "higgsanalysis/Objects/interface/RecoJetAK8.h"           // RecoJetAK8
#include "higgsanalysis/CommonTools/interface/Era.h" // Era

#include <map>                                                  // std::map

// forward declarations
class TTree;
class RecoSubjetReaderAK8;

enum class Era;

class RecoJetReaderAK8
  : public ReaderBase
{
 public:
  RecoJetReaderAK8(Era era,
                   bool isMC);
  RecoJetReaderAK8(Era era,
                   bool isMC,
                   const std::string & branchName_jet,
                   const std::string & branchName_subjet);
  ~RecoJetReaderAK8();

  /**
   * @brief Call tree->SetBranchAddress for all RecoJetAK8 branches
   */
  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  /**
   * @brief Read branches from tree and use information to fill collection of RecoJetAK8 objects
   * @return Collection of RecoJetAK8 objects
   */
  std::vector<RecoJetAK8>
  read() const;

  /**
    * @brief Return list of systematic uncertainties supported by RecoJetReaderAK8 class
    */
  static
  std::vector<std::string>
  get_supported_systematics(const edm::ParameterSet & cfg);

 protected:
 /**
   * @brief Initialize names of branches to be read from tree
   */
  void
  setBranchNames();

  Era era_;
  bool isMC_;
  unsigned int max_nJets_;
  std::string branchName_obj_;
  std::string branchName_num_;

  RecoSubjetReaderAK8 * subjetReader_;

  std::string branchName_pt_;
  std::string branchName_eta_;
  std::string branchName_phi_;
  std::string branchName_mass_;
  std::string branchName_msoftdrop_;
  std::string branchName_subJetIdx1_;
  std::string branchName_subJetIdx2_;
  std::string branchName_tau1_;
  std::string branchName_tau2_;
  std::string branchName_tau3_;
  std::string branchName_tau4_;
  std::string branchName_jetId_;
  std::string branchName_rawFactor_;
  std::string branchName_area_;
  std::string branchName_genJetAK8Idx_;
  std::string branchName_lsf3_;
  std::string branchName_muonIdx3SJ_;
  std::string branchName_electronIdx3SJ_;
  std::string branchName_btagDeepB_;
  std::string branchName_btagDDBvLV2_;
  std::string branchName_deepTagMD_bbvsLight_;
  std::string branchName_particleNetMD_Xbb_;

  UInt_t nJets_;
  Float_t * jet_pt_;
  Float_t * jet_eta_;
  Float_t * jet_phi_;
  Float_t * jet_mass_;
  Float_t * jet_msoftdrop_;
  Int_t * subjet_idx1_;
  Int_t * subjet_idx2_;
  Float_t * jet_tau1_;
  Float_t * jet_tau2_;
  Float_t * jet_tau3_;
  Float_t * jet_tau4_;
  Int_t * jet_jetId_;
  Float_t * jet_rawFactor_;
  Float_t * jet_area_;
  Int_t * jet_genJetAK8Idx_;
  Float_t * jet_lsf3_;
  Int_t * jet_muonIdx3SJ_;
  Int_t * jet_electronIdx3SJ_;
  Float_t * jet_btagDeepB_;
  Float_t * jet_btagDDBvLV2_;
  Float_t * jet_deepTagMD_bbvsLight_;
  Float_t * jet_particleNetMD_Xbb_;

  // CV: make sure that only one RecoJetReaderAK8 instance exists for a given branchName,
  //     as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, RecoJetReaderAK8 *> instances_;
};

#endif // RecoJetReaderAK8_h
