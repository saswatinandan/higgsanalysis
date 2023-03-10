#ifndef tthAnalysis_HiggsToTauTau_RecoMuonReader_h
#define tthAnalysis_HiggsToTauTau_RecoMuonReader_h
#include "higgsanalysis/Objects/interface/RecoMuon.h"             // RecoMuon, *_t
#include "higgsanalysis/Reader/interface/ReaderBase.h"           // ReaderBase
#include "higgsanalysis/CommonTools/interface/Era.h"
#include <map> // std::map<,> 
// forward declarations
class TTree;
class RecoLeptonReader;

enum class Era;

class RecoMuonReader : public ReaderBase
{
 public:
  RecoMuonReader(Era era,
                 bool isMC);
  RecoMuonReader(Era era,
                 const std::string & branchName_obj,
                 bool isMC);
  ~RecoMuonReader();

  /**
   * @brief Call tree->SetBranchAddress for all lepton branches specific to RecoMuons
   */
  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  /**
   * @brief Read branches from tree and use information to fill collection of RecoMuon objects
   * @return Collection of RecoMuon objects
   */
  std::vector<RecoMuon>
  read() const;

  /**
   * @brief Set threshold that a muon need to pass in order to qualify as tight lepton
   *        cf. Table 7 in AN/2020-032 v14.pdf
   */
  void
  set_mvaTTH_wp(double mvaTTH_wp);

  /**
    * @brief Return list of systematic uncertainties supported by RecoMuonReader class
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
  std::string branchName_num_;
  std::string branchName_obj_;

  RecoLeptonReader * leptonReader_;

  std::string branchName_mediumIdPOG_;
  std::string branchName_segmentCompatibility_;
  std::string branchName_ptErr_;

  Bool_t  * mediumIdPOG_;
  Float_t * segmentCompatibility_;
  Float_t * ptErr_;

  double mvaTTH_wp_;

  // CV: make sure that only one RecoMuonReader instance exists for a given branchName,
  //     as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, RecoMuonReader *> instances_;
};

#endif // tthAnalysis_HiggsToTauTau_RecoMuonReader_h

