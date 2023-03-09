#ifndef RecoJetCollectionSelectorForward_h
#define RecoJetCollectionSelectorForward_h

#include "higgsanalysis/Selector/interface/RecoJetCollectionSelector.h"  // RecoJetSelector, ParticleCollectionSelector, RecoJet, Era

class RecoJetSelectorForward
  : public RecoJetSelector
{
public:
  explicit RecoJetSelectorForward(Era era,
                                  int index = -1,
                                  bool debug = false);
  ~RecoJetSelectorForward() {}

  /**
   * @brief Get cut thresholds
   */
  double get_min_absEta() const;

  /**
   * @brief Check if jet given as function argument passes the selection cuts
   * @return True if jet passes selection; false otherwise
   */
  bool
  operator()(const RecoJet & jet) const;

protected:
  Double_t min_absEta_; ///< upper cut threshold on absolute value of eta
};

typedef ParticleCollectionSelector<RecoJet, RecoJetSelectorForward> RecoJetCollectionSelectorForward;

#endif // RecoJetCollectionSelectorForward_h
