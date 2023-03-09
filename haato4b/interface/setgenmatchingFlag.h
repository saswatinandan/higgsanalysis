#ifndef setgematchingFlag_h
#define setgematchingFlag_h

#include "DataFormats/Math/interface/deltaR.h"                        // deltaR()

#include "higgsanalysis/Objects/interface/GenParticle.h"
#include "higgsanalysis/Objects/interface/RecoJetAK8.h" // RecoJetAK8

void
setgenmatchingFlag(std::vector<RecoJetAK8>& jets, const GenParticleCollection genquarks)
{
  for(auto & jet : jets)
    {
      bool match(true);
      for(auto & genquark : genquarks)
        {
          if( !(deltaR(jet.eta(), jet.phi(), genquark.eta(), genquark.phi()) < 0.8) )
            {
              match = false;
              break;
            }
        }
      if(match) jet.setgenmatchFlag();
    }
}

#endif
