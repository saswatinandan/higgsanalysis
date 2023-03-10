#include "higgsanalysis/Objects/interface/RecoJet.h"
#include "higgsanalysis/CommonTools/interface/cmsException.h" // cmsException() 
#include "higgsanalysis/Objects/interface/analysisAuxFunctions.h" // as_integer()                        

RecoJet::RecoJet(const GenJet & jet,
                       Float_t BtagCSV,
                       Float_t QGDiscr,
                       Float_t bRegCorr,
                       Float_t bRegRes,
                       Int_t jetId,
                       Int_t puId,
                       Float_t rawFactor,
                       Float_t area,
                       Float_t neEmEF,
                       Float_t chEmEF,
                       Float_t muonSubtrFactor,
                       UInt_t idx,
                       Int_t genJetIdx,
                       Btag btag)
  : RecoJetBase(jet, rawFactor, idx)
  , BtagCSV_(BtagCSV)
  , QGDiscr_(QGDiscr)
  , bRegCorr_(bRegCorr)
  , bRegRes_(bRegRes)
  , jetId_(jetId)
  , puId_(puId)
  , area_(area)
  , neEmEF_(neEmEF)
  , chEmEF_(chEmEF)
  , muonSubtrFactor_(muonSubtrFactor)
  , genJetIdx_(genJetIdx)
  , btag_(btag)
  , isBJet_loose_(false)
  , isBJet_medium_(false)
{}

/*RecoJet::RecoJet(const CorrT1METJet & jet,
                       Int_t genJetIdx)
  : RecoJet(
      { jet.pt(), jet.eta(), jet.phi(), jet.mass() },
      -1., -1., -1., -1., 0, -1, 0., jet.area(), 0., 0., jet.muonSubtrFactor(), -1, genJetIdx, Btag::kDeepJet
    )
{}
*/
RecoJet::~RecoJet()
{}

void
RecoJet::set_isBJet_loose() const
{
  isBJet_loose_ = true;
}

void
RecoJet::set_isBJet_medium() const
{
  isBJet_medium_ = true;
}

Float_t
RecoJet::BtagCSV() const
{
  return BtagCSV_;
}

Float_t
RecoJet::BtagCSV(Btag btag) const
{
  if(! BtagCSV_systematics_.count(btag))
  {
    throw cmsException(this, __func__, __LINE__)
      << "No such b-tagging score available: " << as_integer(btag)
    ;
  }
  return BtagCSV_systematics_.at(btag);
}

Float_t
RecoJet::QGDiscr() const
{
  return QGDiscr_;
}

Float_t
RecoJet::bRegCorr() const
{
  return bRegCorr_;
}

Particle::LorentzVector
RecoJet::p4_bRegCorr() const
{
  // scale both pT and mass, so that the pT and energy are scaled by the same amount
  // cf. https://twiki.cern.ch/twiki/bin/viewauth/CMS/HiggsWG/BJetRegression
  //     ("To get corrected jet one has to scale the pT and energy with this correction")
  return math::PtEtaPhiMLorentzVector(this->pt()*bRegCorr_, this->eta(), this->phi(), this->mass()*bRegCorr_);
}

Float_t
RecoJet::bRegRes() const
{
  return bRegRes_;
}

Int_t
RecoJet::jetId() const
{
  return jetId_;
}

Int_t
RecoJet::puId() const
{
  return puId_;
}

Float_t
RecoJet::area() const
{
  return area_;
}

Float_t
RecoJet::neEmEF() const
{
  return neEmEF_;
}

Float_t
RecoJet::chEmEF() const
{
  return chEmEF_;
}

Float_t
RecoJet::muonSubtrFactor() const
{
  return muonSubtrFactor_;
}

Int_t
RecoJet::genJetIdx() const
{
  return genJetIdx_;
}

bool
RecoJet::passesPUID(pileupJetID puIdWP) const
{
  return this->puId() & static_cast<int>(puIdWP);
}

bool
RecoJet::is_PUID_taggable() const
{
  // PU jet ID is applicable only to jets that have pT < 50. GeV
  // https://twiki.cern.ch/twiki/bin/viewauth/CMS/PileupJetID
  return this->pt() < 50.;
}

bool
RecoJet::is_PU() const
{
  return genJetIdx_ < 0;
}

bool
RecoJet::isBJet_loose() const
{
  return isBJet_loose_;
}

bool
RecoJet::isBJet_medium() const
{
  return isBJet_medium_;
}

std::ostream &
operator<<(std::ostream & stream,
           const RecoJet & jet)
{
  stream << static_cast<const RecoJetBase &>(jet)                            << ",\n"
            " genJetIdx = "       << jet.genJetIdx()                         << ","
            " btag score = "      << jet.BtagCSV()                           << ","
            " jet ID = "          << jet.jetId()                             << ","
            " PU ID = "           << jet.puId()                              << ","
            " area = "            << jet.area()                              << ","
            " neEmEF = "          << jet.neEmEF()                            << ","
            " chEmEF = "          << jet.chEmEF()                            << ","
            " muonSubtrFactor = " << jet.muonSubtrFactor()                   << ","
            " QGL = "             << jet.QGDiscr()                           << ","
            " bReg corr (res) = " << jet.bRegCorr() << " (" << jet.bRegRes() << ")\n"
  ;
  return stream;
}
