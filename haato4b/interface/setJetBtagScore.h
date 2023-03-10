#ifndef setJetBtagScore_h
#define setJetBtagScore_h

#include "higgsanalysis/Objects/interface/RecoJet.h"
#include "higgsanalysis/Objects/interface/analysisAuxFunctions.h"
#include <assert.h>                                              // assert()
#include <vector>                                                // std::vector

enum class Btag;

template <typename T>
void
setJetBtagScore(std::vector<T> & particles,
                const std::vector<RecoJet> & jets)
{
  const Int_t njets = jets.size();
  //  std::cout << "********" << njets << std::endl;
  for ( T  particle : particles )
  {
    const Int_t jetIdx = particle.jetIdx();
    double btag = ( jetIdx >=0 &&  jetIdx <njets ) ? jets.at(jetIdx).BtagCSV() : -1;
    if(std::isnan(btag))
    {
      btag = -2;
    }
    particle.setjetBtagCSV(btag);
  }
}

#endif // hhAnalysis_bbww_setJetBtagScore_h
