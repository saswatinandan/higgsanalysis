#ifndef RecoSubjetAK8_h
#define RecoSubjetAK8_h

/** \class RecoSubjetAK8
 *
 * Class to access information for subjets of jets reconstructed by the anti-kT algorithm with R=1.2 (AK8),
 * used for reconstruction of boosted W bosons (produced in hadronic top decays with resolved b-jets)
 *
 * \author Christian Veelken, Tallin
 *
 */

#include "higgsanalysis/Objects/interface/RecoJetBase.h" // RecoJetBase

class RecoSubjetAK8
  : public RecoJetBase
{
 public:
  RecoSubjetAK8() = default;
  RecoSubjetAK8(const GenJet & particle,
                Float_t rawFactor,
                Float_t BtagCSV,
                Int_t idx);

  virtual ~RecoSubjetAK8();

 /**
   * @brief Funtions to access data-members
   * @return Values of data-members
   */
  Float_t BtagCSV() const;

  bool is_btaggable() const;

 protected:
  Double_t BtagCSV_; ///< CSV b-tagging discriminator value
};

std::ostream &
operator<<(std::ostream & stream,
           const RecoSubjetAK8 & jet);

#endif // RecoSubjetAK8_h
