import FWCore.ParameterSet.Config as cms
import os

#from tthAnalysis.HiggsToTauTau.analysisSettings import *

process = cms.PSet()

process.fwliteInput = cms.PSet(
    fileNames = cms.vstring(),
    maxEvents = cms.int32(-1),
    outputEvery = cms.uint32(100000)
)

process.fwliteOutput = cms.PSet(
    fileName = cms.string('')
)

process.analyze_hh_bb1l = cms.PSet(
    treeName = cms.string('Events'),

    process = cms.string(''),
    histogramDir = cms.string(''),
    era = cms.string(''),

    electronSelection = cms.string(''),
    muonSelection = cms.string(''),
    apply_leptonGenMatching = cms.bool(True),

    apply_pileupJetID = cms.string(''),

    evtCategories = cms.vstring(), # CV: "inclusive" event category is added automatically

    isMC = cms.bool(True),
    central_or_shift = cms.string(''),

    branchName_electrons = cms.string('Electron'),
    branchName_muons = cms.string('Muon'),
    branchName_jets_ak4 = cms.string('Jet'),
    branchName_jets_ak8 = cms.string('FatJet'),
    branchName_subjets_ak8 = cms.string('SubJet'),
    branchName_met = cms.string('MET'),
    branchName_vertex = cms.string('PV'),

    #branchName_memOutput = cms.string('memObjects_hh_bb1l_lepTight'),
    #branchName_memOutput_missingBJet = cms.string('memObjects_hh_bb1l_lepTight_missingBJet'),
    #branchName_memOutput_missingHadWJet = cms.string('memObjects_hh_bb1l_lepTight_missingHadWJet'),
    jetCleaningByIndex = cms.bool(True),

    selEventsFileName_input = cms.string(''),
    selEventsFileName_output = cms.string(''),

    useNonNominal = cms.bool(False),
    isDEBUG = cms.bool(False),
)


# Filled in createCfg_analyze
process.analyze_hh_bb1l.era                                            = cms.string('2016')
process.analyze_hh_bb1l.redoGenMatching                                = cms.bool(False)
process.analyze_hh_bb1l.isDEBUG                                        = cms.bool(False)
process.analyze_hh_bb1l.process                                        = cms.string('signal_ggf_spin0_400_hh')
process.analyze_hh_bb1l.process_hh                                     = cms.string('signal_ggf_spin0_400_hh_bbvv_sl')
process.analyze_hh_bb1l.isMC                                           = cms.bool(True)
process.analyze_hh_bb1l.central_or_shift                               = cms.string('central')
process.analyze_hh_bb1l.central_or_shifts_local                        = cms.vstring(['central'])
process.analyze_hh_bb1l.evtCategories                                  = cms.vstring(['hh_bb1l'])
process.analyze_hh_bb1l.electronSelection                              = cms.string('Tight')
process.analyze_hh_bb1l.muonSelection                                  = cms.string('Tight')
process.analyze_hh_bb1l.lep_mva_cut_mu                                 = cms.double(0.5)
process.analyze_hh_bb1l.lep_mva_cut_e                                  = cms.double(0.3)
process.analyze_hh_bb1l.lep_mva_wp                                     = cms.string('hh_multilepton')
process.analyze_hh_bb1l.histogramDir                                   = cms.string('hh_bb1l_Tight')
process.analyze_hh_bb1l.applyFakeRateWeights                           = cms.string('disabled')
process.analyze_hh_bb1l.selEventsFileName_output                       = cms.string('/local/snandan/hhAnalysis/2016/test/output_rle/hh_bb1l/Tight/signal_ggf_spin0_400_hh_2b2v_sl/rle_signal_ggf_spin0_400_hh_2b2v_sl_Tight_central_1.txt')
process.analyze_hh_bb1l.useNonNominal                                  = cms.bool(False)
process.analyze_hh_bb1l.jetCleaningByIndex                             = cms.bool(False)
process.analyze_hh_bb1l.apply_pileupJetID                              = cms.string('loose')
process.analyze_hh_bb1l.disable_ak8_corr                               = cms.vstring(['PUPPI'])
process.analyze_hh_bb1l.useAssocJetBtag                                = cms.bool(False)
