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

process.fwliteInput.fileNames = cms.vstring(['/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/80000/4BB55A0B-2DA5-854E-8A2B-2E3A64FABD38.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2550000/9A7144E1-9AFF-CD44-8034-53759E7E6A3F.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2550000/BEAE0F13-FE0B-C94C-8CBA-DEBF837703EF.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2550000/C28386A1-90CA-2C4C-A5F3-9C41900B6847.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2550000/8735418C-779D-1F47-AC7F-7679EB8A7B1D.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2550000/C04956C0-D9DF-A34F-A465-6B7A5C803760.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2430000/FEAB28AB-BC2E-DC4F-B331-F6E79F6D69CE.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/30000/335C6ECC-A5D1-E745-B2BA-876A11816B06.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2810000/5D7DD936-B044-9944-A1EF-D7C79B765F61.root', '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-12_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2810000/06598E6E-B8E0-9140-AABC-DADD486E927B.root'])
process.fwliteOutput.fileName = cms.string('SUSY_WH_WToAll_HToAATo4B_Pt150_M-12.root')

