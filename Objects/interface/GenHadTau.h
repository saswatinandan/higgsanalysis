#ifndef GenHadTau_h
#define GenHadTau_h

#include "higgsanalysis/Objects/interface/GenParticle.h" // GenParticle

class GenHadTau
  : public GenParticle
{
public:
  GenHadTau() = default;
  GenHadTau(Double_t pt,
            Double_t eta,
            Double_t phi,
            Double_t mass,
            Int_t charge,
            Int_t status = -1);

  virtual ~GenHadTau() {}
};

std::ostream &
operator<<(std::ostream & stream,
           const GenHadTau & hadTau);

#endif // GenHadTau_h
