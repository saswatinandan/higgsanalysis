#include "higgsanalysis/Objects/interface/RecoJetAK8.h"

RecoJetAK8::RecoJetAK8(const GenJet & jet,
                       Float_t msoftdrop,
                       const RecoSubjetAK8* subJet1,
                       const RecoSubjetAK8* subJet2,
                       Float_t tau1,
                       Float_t tau2,
                       Float_t tau3,
                       Float_t tau4,
                       Int_t jetId,
                       Float_t rawFactor,
                       Float_t area,
                       Int_t genJetAK8Idx,
                       Float_t lsf3,
                       Int_t muonIdx3SJ,
                       Int_t electronIdx3SJ,
                       Float_t btagDeepB,
                       Float_t btagDDBvLV2,
                       Float_t deepTagMD_bbvsLight,
                       Float_t particleNetMD_Xbb,
                       UInt_t idx)
  : RecoJetBase(jet, rawFactor, idx)
  , msoftdrop_(msoftdrop)
  , subJet1_(subJet1)
  , subJet2_(subJet2)
  , tau1_(tau1)
  , tau2_(tau2)
  , tau3_(tau3)
  , tau4_(tau4)
  , jetId_(jetId)
  , area_(area)
  , genJetAK8Idx_(genJetAK8Idx)
  , lsf3_(lsf3)
  , muonIdx3SJ_(muonIdx3SJ)
  , electronIdx3SJ_(electronIdx3SJ)
  , btagDeepB_(btagDeepB)
  , btagDDBvLV2_(btagDDBvLV2)
  , deepTagMD_bbvsLight_(deepTagMD_bbvsLight)
  , particleNetMD_Xbb_(particleNetMD_Xbb)
  , genmatchFlag_(false)
{}

RecoJetAK8::~RecoJetAK8()
{}

void
RecoJetAK8::setgenmatchFlag()
{
  genmatchFlag_ = true;
}

bool
RecoJetAK8::getgenmatchFlag() const
{
  return genmatchFlag_;
}

void
RecoJetAK8::set_msoftdrop(double msoftdrop)
{
  msoftdrop_ = msoftdrop;
}

Float_t
RecoJetAK8::msoftdrop() const
{
  return msoftdrop_;
}

const RecoSubjetAK8*
RecoJetAK8::subJet1() const
{
  return subJet1_.get();
}

const RecoSubjetAK8*
RecoJetAK8::subJet2() const
{
  return subJet2_.get();
}

Float_t
RecoJetAK8::tau1() const
{
  return tau1_;
}

Float_t
RecoJetAK8::tau2() const
{
  return tau2_;
}

Float_t
RecoJetAK8::tau3() const
{
  return tau3_;
}

Float_t
RecoJetAK8::tau4() const
{
  return tau4_;
}

Int_t
RecoJetAK8::jetId() const
{
  return jetId_;
}

Float_t
RecoJetAK8::area() const
{
  return area_;
}

Int_t
RecoJetAK8::genJetAK8Idx() const
{
  return genJetAK8Idx_;
}

Float_t
RecoJetAK8::lsf3() const
{
  return lsf3_;
}

Int_t
RecoJetAK8::muonIdx3SJ() const
{
  return muonIdx3SJ_;
}

Int_t
RecoJetAK8::electronIdx3SJ() const
{
  return electronIdx3SJ_;
}

Float_t
RecoJetAK8::btagDeepB() const
{
  return btagDeepB_;
}

Float_t
RecoJetAK8::deepTagMD_bbvsLight() const
{
  return deepTagMD_bbvsLight_;
}

Float_t
RecoJetAK8::particleNetMD_Xbb() const
{
  return particleNetMD_Xbb_;
}

Float_t
RecoJetAK8::btagDDBvLV2() const
{
  return btagDDBvLV2_;
}

std::ostream &
operator<<(std::ostream & stream,
           const RecoJetAK8 & jet)
{
  stream << static_cast<const RecoJetBase &>(jet)            << ",\n"
            " jet ID = "    << jet.jetId()                   << ","
            " msoftdrop = " << jet.msoftdrop()               << ","
            " tau1 = "      << jet.tau1()                    << ","
            " tau2 = "      << jet.tau2()                    << ","
            " tau3 = "      << jet.tau3()                    << ",\n"
            " subjets:";
  stream << "\n  idx1 = " << jet.subJet1();
  if(jet.subJet1())
  {
    stream << ": " << *(jet.subJet1());
  }
  else
  {
    stream << '\n';
  }
  stream << "  idx2 = " << jet.subJet2();
  if(jet.subJet2())
  {
    stream << ": " << *(jet.subJet2());
  }
  else
  {
    stream << '\n';
  }
  return stream;
}
