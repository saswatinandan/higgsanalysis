#ifndef GenParticleReader_h
#define GenParticleReader_h

#include "higgsanalysis/Objects/interface/GenParticle.h" // GenParticle, GenParticleCollection
#include "higgsanalysis/Reader/interface/ReaderBase.h"  // ReaderBase

#include <map>                                                   // std::map

// forward declarations
class TTree;

class GenParticleReader : public ReaderBase
{
 public:
  GenParticleReader();
  GenParticleReader(const std::string & branchName_particles);
  ~GenParticleReader();

  /**
   * @brief Call tree->SetBranchAddress for all GenParticle branches
   */
  std::vector<std::string>
  setBranchAddresses(TTree * tree) override;

  /**
   * @brief Read branches from tree and use information to fill collection of GenParticle objects
   * @return Collection of GenParticle objects
   */
  GenParticleCollection
  read() const;

 protected:
 /**
   * @brief Initialize names of branches to be read from tree
   */
  void
  setBranchNames();

  const unsigned int max_nParticles_;
  std::string branchName_num_;
  std::string branchName_obj_;

  std::string branchName_pt_;
  std::string branchName_eta_;
  std::string branchName_phi_;
  std::string branchName_mass_;
  std::string branchName_pdgId_;
  std::string branchName_status_;
  std::string branchName_statusFlags_;
  std::string branchName_genPartIdxMother_;

  UInt_t nParticles_;
  Float_t * particle_pt_;
  Float_t * particle_eta_;
  Float_t * particle_phi_;
  Float_t * particle_mass_;
  Int_t * particle_pdgId_;
  Int_t * particle_status_;
  Int_t * particle_statusFlags_;
  Int_t * particle_genPartIdxMother_;

  // CV: make sure that only one GenParticleReader instance exists for a given branchName,
  //     as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, GenParticleReader*> instances_;
};

#endif // GenParticleReader_h

