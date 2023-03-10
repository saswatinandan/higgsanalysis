#include "higgsanalysis/Objects/interface/RecoHadTau.h"

#include "higgsanalysis/CommonTools/interface/cmsException.h"       // cmsException()
#include "higgsanalysis/CommonTools/interface/hadTauDefinitions.h"  // TauID
#include "higgsanalysis/Objects/interface/GenJet.h"                 // GenJet
#include "higgsanalysis/CommonTools/interface/as_integer.h"

RecoHadTau::RecoHadTau(const GenHadTau & particle,
                       Double_t corrFactor,
                       Double_t dxy,
                       Double_t dz,
                       Int_t decayMode,
                       Bool_t idDecayMode,
                       Int_t id_mva,
                       Double_t raw_mva,
                       Int_t antiElectron,
                       Int_t antiMuon,
                       Int_t jetIdx,
                       UChar_t  genPartFlav,
                       Int_t genPartIdx)
  : GenHadTau(particle)
  , corrFactor_(corrFactor)
  , dxy_(dxy)
  , dz_(dz)
  , decayMode_(decayMode)
  , idDecayMode_(idDecayMode)
  , id_mva_(id_mva)
  , raw_mva_(raw_mva)
  , antiElectron_(antiElectron)
  , antiMuon_(antiMuon)
  , jetIdx_(jetIdx)
  , genPartFlav_(genPartFlav)
  , genPartIdx_(genPartIdx)
  , genLepton_(nullptr)
  , genHadTau_(nullptr)
  , genJet_(nullptr)
  , isLoose_(false)
  , isFakeable_(false)
  , isTight_(false)
{}

RecoHadTau::~RecoHadTau()
{}

void
RecoHadTau::set_isLoose() const
{
  isLoose_ = true;
}

void
RecoHadTau::set_isFakeable() const
{
  isFakeable_ = true;
}

void
RecoHadTau::set_isTight() const
{
  isTight_ = true;
}

void
RecoHadTau::set_genLepton(const GenParticle * genLepton)
{
  genLepton_ = genLepton;
}

void
RecoHadTau::set_genHadTau(const GenHadTau * genHadTau)
{
  genHadTau_ = genHadTau;
}

void
RecoHadTau::set_genJet(const GenJet * genJet)
{
  genJet_ = genJet;
}

void 
RecoHadTau::set_filterBits(Int_t filterBits)
{
  filterBits_ = filterBits;
}

Double_t
RecoHadTau::corrFactor() const
{
  return corrFactor_;
}

Double_t
RecoHadTau::dxy() const
{
  return dxy_;
}

Double_t
RecoHadTau::dz() const
{
  return dz_;
}

Int_t
RecoHadTau::decayMode() const
{
  return decayMode_;
}

Bool_t
RecoHadTau::idDecayMode() const
{
  return idDecayMode_;
}

Int_t
RecoHadTau::id_mva() const
{
  return id_mva_;
}

Double_t
RecoHadTau::raw_mva() const
{
  return raw_mva_;
}

Int_t
RecoHadTau::id_mva(TauID tauId) const
{
  if(! tauID_ids_.count(tauId))
  {
    throw cmsException(this, __func__, __LINE__)
      << "No such tau ID = " << as_integer(tauId)
    ;
  }
  return tauID_ids_.at(tauId);
}

Double_t
RecoHadTau::raw_mva(TauID tauId) const
{
  if(! tauID_raws_.count(tauId))
  {
    throw cmsException(this, __func__, __LINE__)
      << "No such tau ID = " << as_integer(tauId)
    ;
  }
  return tauID_raws_.at(tauId);
}

Int_t
RecoHadTau::antiElectron() const
{
  return antiElectron_;
}

Int_t
RecoHadTau::antiMuon() const
{
  return antiMuon_;
}

Int_t
RecoHadTau::filterBits() const
{
  return filterBits_;
}

Int_t
RecoHadTau::jetIdx() const
{
  return jetIdx_;
}

UChar_t
RecoHadTau::genPartFlav() const
{
  return genPartFlav_;
}

Int_t
RecoHadTau::genPartIdx() const
{
  return genPartIdx_;
}

const GenParticle *
RecoHadTau::genLepton() const
{
  return genLepton_;
}

const GenHadTau *
RecoHadTau::genHadTau() const
{
  return genHadTau_;
}

const GenJet *
RecoHadTau::genJet() const
{
  return genJet_;
}

bool
RecoHadTau::isGenMatched(bool requireChargeMatch) const
{
  if(requireChargeMatch)
  {
    if(!! genHadTau_)
    {
      return charge() == genHadTau_->charge();
    }
    if(!! genLepton_)
    {
      return charge() == genLepton_->charge();
    }
    return false;
  }
  return !! genHadTau_ || !! genLepton_;
}

bool
RecoHadTau::hasAnyGenMatch() const
{
  return !! genLepton_ || !! genHadTau_ || !! genJet_;
}

bool
RecoHadTau::isLoose() const
{
  return isLoose_;
}

bool
RecoHadTau::isFakeable() const
{
  return isFakeable_;
}

bool
RecoHadTau::isTight() const
{
  return isTight_;
}

std::ostream &
operator<<(std::ostream & stream,
           const RecoHadTau & hadTau)
{
  stream << static_cast<const GenHadTau &>(hadTau)                            << ",\n"
            " decayMode = "        << hadTau.decayMode()                      << ","
            " oldDecayModeID = "   << hadTau.idDecayMode()                    << ","
            " id_mva = "           << hadTau.id_mva()                         <<
            " (raw = "             << hadTau.raw_mva()                        << "),\n"
            " genPartFlav = "      << static_cast<int>(hadTau.genPartFlav())  << ", "
            " genPartIdx = "       << hadTau.genPartIdx()                     << ","
            " antiElectron = "     << hadTau.id_mva(TauID::DeepTau2017v2VSe)  << ","
            " antiMuon = "         << hadTau.id_mva(TauID::DeepTau2017v2VSmu) << ",\n"
            " is loose/fakeable/tight = " << hadTau.isLoose()                 << '/'
                                          << hadTau.isFakeable()              << '/'
                                          << hadTau.isTight()                 << ",\n"
            " gen. matching:";
  stream << ",\n  lepton = " << hadTau.genLepton();
  if(hadTau.genLepton())
  {
    stream << ": " << *(hadTau.genLepton());
  }
  stream << ",\n  hadTau = " << hadTau.genHadTau();
  if(hadTau.genHadTau())
  {
    stream << ": " << *(hadTau.genHadTau());
  }
  stream << ",\n  jet    = " << hadTau.genJet();
  if(hadTau.genJet())
  {
    stream << ": " << *(hadTau.genJet());
  }
  stream << '\n';
  return stream;
}
