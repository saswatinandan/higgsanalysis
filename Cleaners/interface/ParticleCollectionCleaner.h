#ifndef ParticleCollectionCleaner_h
#define ParticleCollectionCleaner_h

#include "DataFormats/Math/interface/deltaR.h"                        // deltaR()

#include "higgsanalysis/CommonTools/interface/cmsException.h" // get_human_line()

#include <vector>                                                     // std::vector<>
#include <iostream>                                                   // std::cout

template <typename T>
class ParticleCollectionCleaner
{
 public:
  ParticleCollectionCleaner(double dR = 0.4,
                            bool debug = false)
    : dR_(dR)
    , debug_(debug)
  {}
  ~ParticleCollectionCleaner() {}

  /**
   * @brief Select subset of particles not overlapping with any of the other particles passed as function argument
   * @return Collection of non-overlapping particles
   */
  template <typename Toverlap>
  std::vector<const T *>
  operator()(const std::vector<const T *> & particles,
             const std::vector<const Toverlap *> & overlaps) const
  {
    if(debug_)
    {
      std::cout << get_human_line(this, __func__, __LINE__) << '\n';
    }
    std::vector<const T *> cleanedParticles;
    for(const T * particle: particles)
    {
      bool isOverlap = false;
      for(const Toverlap * overlap: overlaps)
      {
        const double dRoverlap = deltaR(particle->eta(), particle->phi(), overlap->eta(), overlap->phi());
        if(dRoverlap < dR_)
        {
          isOverlap = true;
          if(debug_)
          {
            std::cout << "Removed:\n"                    << *particle
                      << "because it overlapped with:\n" << *overlap
                      << " within "                      << dRoverlap
                      << '\n'
            ;
          }
          break;
        }
      }
      if(! isOverlap)
      {
        cleanedParticles.push_back(particle);
      }
    }
    return cleanedParticles;
  }

  template <typename Toverlap,
            typename... Args>
  std::vector<const T *>
  operator()(const std::vector<const T *> & particles,
             const std::vector<const Toverlap *> & overlaps,
             Args... args) const
  {
    std::vector<const T *> cleanedParticles = (*this)(particles, overlaps);
    return (*this)(cleanedParticles, args...);
  }

protected:
  double dR_;
  bool debug_;
};

#include "higgsanalysis/Objects/interface/RecoElectron.h"

typedef ParticleCollectionCleaner<RecoElectron> RecoElectronCollectionCleaner;

#include "higgsanalysis/Objects/interface/RecoMuon.h"

typedef ParticleCollectionCleaner<RecoMuon> RecoMuonCollectionCleaner;

#include "higgsanalysis/Objects/interface/RecoHadTau.h"

typedef ParticleCollectionCleaner<RecoHadTau> RecoHadTauCollectionCleaner;

#include "higgsanalysis/Objects/interface/RecoJet.h"

typedef ParticleCollectionCleaner<RecoJet> RecoJetCollectionCleaner;

#include "higgsanalysis/Objects/interface/RecoJetAK8.h"

typedef ParticleCollectionCleaner<RecoJetAK8> RecoJetCollectionCleanerAK8;

#include "higgsanalysis/Cleaners/interface/RecoJetCollectionCleanerByIndexAK4.h"

#endif // TallinnNtupleProducer_Cleaners_ParticleCollectionCleaner_h
