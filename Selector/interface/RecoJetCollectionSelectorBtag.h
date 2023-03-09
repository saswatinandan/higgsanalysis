#ifndef RecoJetCollectionSelectorBtag_h
#define RecoJetCollectionSelectorBtag_h

#include "higgsanalysis/Selector/interface/RecoJetCollectionSelector.h"  // RecoJetSelector, ParticleCollectionSelector, RecoJet, Era

class RecoJetSelectorBtag
  : public RecoJetSelector
{
public:
  explicit RecoJetSelectorBtag(Era era,
                               int index,
                               bool debug);

  /**
   * @brief Get cut thresholds
   */
  double get_min_BtagCSV() const;

  /**
   * @brief Check if jet given as function argument passes the selection cuts
   * @return True if jet passes selection; false otherwise
   */
  bool
  operator()(const RecoJet & jet) const;

protected:
  Double_t min_BtagCSV_; ///< lower cut threshold on CSV b-tagging discriminator value
};

class RecoJetSelectorBtagLoose
  : public RecoJetSelectorBtag
{
public:
  explicit RecoJetSelectorBtagLoose(Era era, int index = -1, bool debug = false);
};

typedef ParticleCollectionSelector<RecoJet, RecoJetSelectorBtagLoose> RecoJetCollectionSelectorBtagLoose;

class RecoJetSelectorBtagMedium 
  : public RecoJetSelectorBtag
{
public:
  explicit RecoJetSelectorBtagMedium(Era era, int index = -1, bool debug = false);
};

typedef ParticleCollectionSelector<RecoJet, RecoJetSelectorBtagMedium> RecoJetCollectionSelectorBtagMedium;

#endif // RecoJetCollectionSelectorBtag_h

