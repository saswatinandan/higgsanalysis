#ifndef RecoJetReader_h
#define RecoJetReader_h

#include "higgsanalysis/Reader/interface/ReaderBase.h"           // ReaderBase
#include "higgsanalysis/Objects/interface/RecoJet.h"              // RecoJet    
#include "higgsanalysis/CommonTools/interface/Era.h" // Era

#include <map>                                                  // std::map

// forward declarations
class TTree;

enum class Btag;
enum class Era;

class RecoJetReader
  : public ReaderBase
{
 public:
  RecoJetReader(Era era,
                bool isMC,
                bool readGenMatching);
  RecoJetReader(Era era,
                bool isMC,
                const std::string & branchName_obj,
                bool readGenMatching);
  ~RecoJetReader() override;

  void
  read_Btag(Btag btag);

  /**
   * @brief Call tree->SetBranchAddress for all RecoJet branches
   */
  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  /**
   * @brief Read branches from tree and use information to fill collection of RecoJet objects
   * @return Collection of RecoJet objects
   */
  std::vector<RecoJet>
  read() const;

  /**
    * @brief Return list of systematic uncertainties supported by RecoJetReader class
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
 
  std::string branchName_pt_;
  std::string branchName_eta_;
  std::string branchName_phi_;
  std::string branchName_mass_;
  std::string branchName_QGDiscr_;
  std::string branchName_bRegCorr_;
  std::string branchName_bRegRes_;
  std::string branchName_BtagScore_;
  std::string branchName_jetId_;
  std::string branchName_puId_;
  std::string branchName_genJetIdx_;
  std::string branchName_partonFlavour_;
  std::string branchName_hadronFlavour_;
  std::string branchName_rawFactor_;
  std::string branchName_area_;
  std::string branchName_neEmEF_;
  std::string branchName_chEmEF_;
  std::string branchName_muonSubtrFactor_;
  bool readGenMatching_;

  std::map<Btag, std::string> branchNames_btag_;

  Btag btag_;

  UInt_t nJets_;
  Float_t * jet_pt_;
  Float_t * jet_eta_;
  Float_t * jet_phi_;
  Float_t * jet_mass_;
  Float_t * jet_QGDiscr_;
  Float_t * jet_bRegCorr_;
  Float_t * jet_bRegRes_;
  Float_t * jet_BtagScore_;
  Int_t * jet_jetId_;
  Int_t * jet_puId_;
  Int_t * jet_genJetIdx_;
  Int_t * jet_partonFlavour_;
  Int_t * jet_hadronFlavour_;
  Float_t * jet_rawFactor_;
  Float_t * jet_area_;
  Float_t * jet_neEmEF_;
  Float_t * jet_chEmEF_;
  Float_t * jet_muonSubtrFactor_;

  // CV: make sure that only one RecoJetReader instance exists for a given branchName,
  //     as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, RecoJetReader *> instances_;
};

#endif // RecoJetReader_h
