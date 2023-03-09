#ifndef genbquark_h
#define genbquark_h

#include "higgsanalysis/Objects/interface/GenParticle.h"

bool
checkmother(GenParticle & genparticle, GenParticleCollection & genparticles)
{
  bool founda(false);
  if(genparticle.momIdx() == -1) return false;
  GenParticle mom = genparticles.at(genparticle.momIdx());
  while(!founda)
  {
    if(mom.absPdgId() == 36) {
      founda = true;
    }
    else {
      if(mom.status() ==21) break;
      if(mom.momIdx() == -1) break;
      mom = genparticles.at(mom.momIdx());
      founda = checkmother(mom, genparticles);
    }
  }
  return founda;
}

void
checkcharge(GenParticleCollection &parts)
{
  assert(parts.size() == 4);
  int charge(0);
  for(auto part : parts) charge += part.charge();
  assert(charge==0);
}

GenParticleCollection
find_genbquarks(GenParticleCollection & genparticles)
{
  GenParticleCollection ret;
  for ( auto genparticle : genparticles)
    {
      if(genparticle.absPdgId() == 5){/* && genparticle.checkStatusFlag(StatusFlag::isLastCopy) ) {
        if(checkmother(genparticle, genparticles)) {
          ret.push_back(genparticle);
          }*/
        if(genparticle.momIdx() == -1) continue;
        if(genparticles.at(genparticle.momIdx()).absPdgId() == 36) ret.push_back(genparticle);
      }
    }
  checkcharge(ret);
  return ret;
}

#endif
