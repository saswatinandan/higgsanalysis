import argparse
import glob
import os
parser = argparse.ArgumentParser()
parser.add_argument("--input_sample", type=str, dest="input_sample", help="path of root file")
options = parser.parse_args()
input_sample = options.input_sample

def create_cfg(cfg_file_original, cfg_file_modified, lines):
    """Auxiliary function to clone config file.                                             
       The lines given as argument are added to the end of the cloned file,                 
       overwriting some of the configuration parameters defined in the original file.       
    """
    f_original = open(cfg_file_original, "r")
    cfg_original = f_original.read()
    f_original.close()
    cfg_modified = cfg_original
    cfg_modified += "\n"
    for line in lines:
        cfg_modified += "%s\n" % line
    cfg_modified += "\n"
    f_modified = open(cfg_file_modified, "w")
    f_modified.write(cfg_modified)
    f_modified.close()

for m in [12,20,25,30,35,40,45, 50, 55, 60]: #for 60, WH sample assert error for b size 5
    if input_sample == 'WH':
        input_path = '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_WH_WToAll_HToAATo4B_Pt150_M-%s_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/' %m
    elif input_sample == 'ZH':
        input_path = '/store/mc/RunIISummer20UL18NanoAODv9/SUSY_ZH_ZToAll_HToAATo4B_Pt150_M-%s_TuneCP5_13TeV_madgraph_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/' %m
    files = glob.glob('%s/*/*' %input_path)
    sample_name = '_'.join([i for i in input_path.split('/')[4].split('_')[:6]])
    line = ["process.fwliteInput.fileNames = cms.vstring(%s)" %files]
    line.append("process.fwliteOutput.fileName = cms.string('%s.root')" %sample_name)
    create_cfg('template_cfg.py', 'analyze_%s_cfg.py'%sample_name, line)
    print('*****creating cfg file')
    if input_sample == 'WH':
        os.system('analyze_haa_1l analyze_%s_cfg.py' %sample_name)
    elif input_sample == 'ZH':
        os.system('analyze_haa_2l analyze_%s_cfg.py' %sample_name)
