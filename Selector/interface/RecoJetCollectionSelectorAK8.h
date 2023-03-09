#ifndef RecoJetCollectionSelectorAK8_h
#define RecoJetCollectionSelectorAK8_h

#include "higgsanalysis/Selector/interface/ParticleCollectionSelector.h" // ParticleCollectionSelector
#include "higgsanalysis/Objects/interface/RecoJetAK8.h"                 // RecoJetAK8
#include "higgsanalysis/Objects/interface/analysisAuxFunctions.h"       // Era
#include "higgsanalysis/HistManager/interface/CutFlowTableHistManager.h"

class RecoJetSelectorAK8
{
public:
  explicit RecoJetSelectorAK8(Era era,
                              int index,
                              bool debug = false);
  ~RecoJetSelectorAK8() {}

  /**
   * @brief Set cut thresholds
   */
  void set_min_pt(double min_pt);
  void set_max_absEta(double max_absEta);
  void set_min_msoftdrop(double min_msoftdrop);

  /**
   * @brief Get cut thresholds
   */
  double get_min_pt() const;
  double get_max_absEta() const;
  double get_min_msoftdrop() const;
  /**
   * @brief Check if jet given as function argument passes pT and eta cuts (pT > 25 GeV and |eta| < 2.4, cf. Section 3.1 of AN-2015/321)
   * @return True if jet passes selection; false otherwise
   */
  bool
  operator()(const RecoJetAK8 & jet) const;

  void
    setcutFlowTable(CutFlowTableHistManager * cutflow) {cutflow_ = cutflow;}
protected:
  Era era_;
  const int index_;
  Double_t min_pt_;     ///< lower cut threshold on pT
  Double_t max_absEta_; ///< upper cut threshold on absolute value of eta
  Double_t min_msoftdrop_;
  bool debug_;
  CutFlowTableHistManager* cutflow_;
};

typedef ParticleCollectionSelector<RecoJetAK8, RecoJetSelectorAK8> RecoJetCollectionSelectorAK8;

#endif // tthAnalysis_HiggsToTauTau_RecoJetCollectionSelectorAK8_h
