#include "higgsanalysis/Selector/interface/RecoJetCollectionSelectorAK8.h" // RecoJetSelectorAK8
#include "higgsanalysis/HistManager/interface/CutFlowTableHistManager.h"
#include "higgsanalysis/Objects/interface/analysisAuxFunctions.h"

RecoJetSelectorAK8::RecoJetSelectorAK8(Era era,
                                       int index,
                                       bool debug)
  : era_(era)
  , index_(index)
  , min_pt_(170.)
  , max_absEta_(2.4)
  , min_msoftdrop_(90.)
  , debug_(debug)
{
  cutflow_ = nullptr;
}

void
RecoJetSelectorAK8::set_min_pt(double min_pt)
{
  min_pt_ = min_pt;
}

void
RecoJetSelectorAK8::set_max_absEta(double max_absEta)
{
  max_absEta_ = max_absEta;
}

void
RecoJetSelectorAK8::set_min_msoftdrop(double min_msoftdrop)
{
  min_msoftdrop_ = min_msoftdrop;
}

double
RecoJetSelectorAK8::get_min_pt() const
{
  return min_pt_;
}

double
RecoJetSelectorAK8::get_max_absEta() const
{
  return max_absEta_;
}

double
RecoJetSelectorAK8::get_min_msoftdrop() const
{
  return min_msoftdrop_;
}

bool
RecoJetSelectorAK8::operator()(const RecoJetAK8 & jet) const
{
  if(cutflow_) cutflow_->fillHistograms("Initial", 1);
  if (!jet.getgenmatchFlag()) return false;
  if(cutflow_) cutflow_->fillHistograms("genmatching", 1);
  if (!(jet.pt()     >= min_pt_)) return false;
  if(cutflow_) cutflow_->fillHistograms("pt >minpt", 1);
  if (!(jet.absEta() <= max_absEta_) ) return false;
  if(cutflow_) cutflow_->fillHistograms("eta<maxeta", 1);
  if (!(jet.msoftdrop() >= min_msoftdrop_)) return false;
  if(cutflow_)cutflow_->fillHistograms("softdrop",1);
  //if (!(jet.btagDDBvLV2() > 0.80)) return false;
  if(cutflow_)cutflow_->fillHistograms("btag",1);
  /*  if (!passes) {
    std::cout << "pt: " << jet.pt();
    std::cout << "mass: " << jet.mass();
    std::cout << "msoftdrop: " << jet.msoftdrop();
    std::cout << "btagV2: " << jet.btagDDBvLV2();
    std::cout << "jet.btagDeepB() " << jet.btagDeepB() << std::endl;
    }*/
  if(cutflow_) cutflow_->fillHistograms("Initial", 1);
  return true;
}
