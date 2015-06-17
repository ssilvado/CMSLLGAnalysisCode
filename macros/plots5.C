void plots5(){

TFile * ttjets = TFile::Open("TTJets.root");
TFile * ttzjets = TFile::Open("TTZJets.root");
TFile * ttwjets = TFile::Open("TTWJets.root");
TFile * ttbarh = TFile::Open("TTbarH.root");
TFile * ttol_t = TFile::Open("TToLeptons_t.root");
TFile * ttol_s = TFile::Open("TToLeptons_s.root");
TFile * tbartol_t = TFile::Open("TBarToLeptons_t.root");
TFile * tbartol_s = TFile::Open("TBarToLeptons_s.root");
TFile * t_tw = TFile::Open("T_tW.root");
TFile * tbar_tw = TFile::Open("Tbar_tW.root");
TFile * gjetsht100 = TFile::Open("GJets100To200.root");
TFile * gjetsht200 = TFile::Open("GJets200To400.root");
TFile * gjetsht400 = TFile::Open("GJets400To600.root");
TFile * gjetsht600 = TFile::Open("GJets600ToInf.root");
TFile * qcdht100 = TFile::Open("QCD100To250.root");
TFile * qcdht250 = TFile::Open("QCD250To500.root");
TFile * qcdht500 = TFile::Open("QCD500To1000.root");
TFile * qcdht1000 = TFile::Open("QCD1000ToInf.root");
TFile * zz = TFile::Open("ZZ.root");
TFile * wz = TFile::Open("WZ.root");
TFile * dy = TFile::Open("DY.root");
TFile * wjets = TFile::Open("WJets.root");
TFile * zjetsht100 = TFile::Open("ZJets100To200.root");
TFile * zjetsht200 = TFile::Open("ZJets200To400.root");
TFile * zjetsht400 = TFile::Open("ZJets400To600.root");
TFile * zjetsht600 = TFile::Open("ZJets600ToInf.root");

TCanvas *c1 = new TCanvas("c1", "c1", 600, 800);
TCanvas *c2 = new TCanvas("c2", "c2", 600, 800);
TCanvas *c3 = new TCanvas("c3", "c3", 600, 800);
TCanvas *c4 = new TCanvas("c4", "c4", 600, 800);

//c->SetFillColor(42);
//c->Divide(2,2);

TH1F *nBJet_CSVv2IVFM_ttjets  = (TH1F*)ttjets->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttjets   = (TH1F*)ttjets->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttjets->SetLineColor(1);
nBJet_CSVM_ttjets->SetLineColor(1);
nBJet_JPM_ttjets->SetLineColor(1);

TH1F *nBJet_CSVv2IVFM_ttzjets  = (TH1F*)ttzjets->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttzjets   = (TH1F*)ttzjets->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttzjets   = (TH1F*)ttzjets->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttzjets   = (TH1F*)ttzjets->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttzjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttzjets->SetLineColor(1);
nBJet_CSVM_ttzjets->SetLineColor(1);
nBJet_JPM_ttzjets->SetLineColor(1);

nBJet_CSVv2IVFM_ttzjets->SetLineStyle(2);
nBJet_CSVv2IVFL_ttzjets->SetLineStyle(2);
nBJet_CSVM_ttzjets->SetLineStyle(2);
nBJet_JPM_ttzjets->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_ttwjets  = (TH1F*)ttwjets->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttwjets   = (TH1F*)ttwjets->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttwjets   = (TH1F*)ttwjets->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttwjets   = (TH1F*)ttwjets->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttwjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttwjets->SetLineColor(1);
nBJet_CSVM_ttwjets->SetLineColor(1);
nBJet_JPM_ttwjets->SetLineColor(1);

nBJet_CSVv2IVFM_ttwjets->SetLineStyle(3);
nBJet_CSVv2IVFL_ttwjets->SetLineStyle(3);
nBJet_CSVM_ttwjets->SetLineStyle(3);
nBJet_JPM_ttwjets->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_ttbarh  = (TH1F*)ttbarh->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttbarh   = (TH1F*)ttbarh->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttbarh   = (TH1F*)ttbarh->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttbarh   = (TH1F*)ttbarh->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttbarh->SetLineColor(1);
nBJet_CSVv2IVFL_ttbarh->SetLineColor(1);
nBJet_CSVM_ttbarh->SetLineColor(1);
nBJet_JPM_ttbarh->SetLineColor(1);

nBJet_CSVv2IVFM_ttbarh->SetLineStyle(4);
nBJet_CSVv2IVFL_ttbarh->SetLineStyle(4);
nBJet_CSVM_ttbarh->SetLineStyle(4);
nBJet_JPM_ttbarh->SetLineStyle(4);

TH1F *nBJet_CSVv2IVFM_ttol_t  = (TH1F*)ttol_t->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttol_t   = (TH1F*)ttol_t->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttol_t   = (TH1F*)ttol_t->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttol_t   = (TH1F*)ttol_t->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttol_t->SetLineColor(2);
nBJet_CSVv2IVFL_ttol_t->SetLineColor(2);
nBJet_CSVM_ttol_t->SetLineColor(2);
nBJet_JPM_ttol_t->SetLineColor(2);

TH1F *nBJet_CSVv2IVFM_ttol_s  = (TH1F*)ttol_s->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_ttol_s   = (TH1F*)ttol_s->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_ttol_s   = (TH1F*)ttol_s->Get("nBJet_CSVM");
TH1F *nBJet_JPM_ttol_s   = (TH1F*)ttol_s->Get("nBJet_JPM");

nBJet_CSVv2IVFM_ttol_s->SetLineColor(2);
nBJet_CSVv2IVFL_ttol_s->SetLineColor(2);
nBJet_CSVM_ttol_s->SetLineColor(2);
nBJet_JPM_ttol_s->SetLineColor(2);

nBJet_CSVv2IVFM_ttol_s->SetLineStyle(2);
nBJet_CSVv2IVFL_ttol_s->SetLineStyle(2);
nBJet_CSVM_ttol_s->SetLineStyle(2);
nBJet_JPM_ttol_s->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_tbartol_t  = (TH1F*)tbartol_t->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_tbartol_t   = (TH1F*)tbartol_t->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_tbartol_t   = (TH1F*)tbartol_t->Get("nBJet_CSVM");
TH1F *nBJet_JPM_tbartol_t   = (TH1F*)tbartol_t->Get("nBJet_JPM");

nBJet_CSVv2IVFM_tbartol_t->SetLineColor(2);
nBJet_CSVv2IVFL_tbartol_t->SetLineColor(2);
nBJet_CSVM_tbartol_t->SetLineColor(2);
nBJet_JPM_tbartol_t->SetLineColor(2);

nBJet_CSVv2IVFM_tbartol_t->SetLineStyle(3);
nBJet_CSVv2IVFL_tbartol_t->SetLineStyle(3);
nBJet_CSVM_tbartol_t->SetLineStyle(3);
nBJet_JPM_tbartol_t->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_tbartol_s  = (TH1F*)tbartol_s->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_tbartol_s   = (TH1F*)tbartol_s->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_tbartol_s   = (TH1F*)tbartol_s->Get("nBJet_CSVM");
TH1F *nBJet_JPM_tbartol_s   = (TH1F*)tbartol_s->Get("nBJet_JPM");

nBJet_CSVv2IVFM_tbartol_s->SetLineColor(2);
nBJet_CSVv2IVFL_tbartol_s->SetLineColor(2);
nBJet_CSVM_tbartol_s->SetLineColor(2);
nBJet_JPM_tbartol_s->SetLineColor(2);

nBJet_CSVv2IVFM_tbartol_s->SetLineStyle(4);
nBJet_CSVv2IVFL_tbartol_s->SetLineStyle(4);
nBJet_CSVM_tbartol_s->SetLineStyle(4);
nBJet_JPM_tbartol_s->SetLineStyle(4);

TH1F *nBJet_CSVv2IVFM_t_tw  = (TH1F*)t_tw->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_t_tw   = (TH1F*)t_tw->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_t_tw   = (TH1F*)t_tw->Get("nBJet_CSVM");
TH1F *nBJet_JPM_t_tw   = (TH1F*)t_tw->Get("nBJet_JPM");

nBJet_CSVv2IVFM_t_tw->SetLineColor(50);
nBJet_CSVv2IVFL_t_tw->SetLineColor(50);
nBJet_CSVM_t_tw->SetLineColor(50);
nBJet_JPM_t_tw->SetLineColor(50);

TH1F *nBJet_CSVv2IVFM_tbar_tw  = (TH1F*)tbar_tw->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_tbar_tw   = (TH1F*)tbar_tw->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_tbar_tw   = (TH1F*)tbar_tw->Get("nBJet_CSVM");
TH1F *nBJet_JPM_tbar_tw   = (TH1F*)tbar_tw->Get("nBJet_JPM");

nBJet_CSVv2IVFM_tbar_tw->SetLineColor(50);
nBJet_CSVv2IVFL_tbar_tw->SetLineColor(50);
nBJet_CSVM_tbar_tw->SetLineColor(50);
nBJet_JPM_tbar_tw->SetLineColor(50);

nBJet_CSVv2IVFM_tbar_tw->SetLineStyle(2);
nBJet_CSVv2IVFL_tbar_tw->SetLineStyle(2);
nBJet_CSVM_tbar_tw->SetLineStyle(2);
nBJet_JPM_tbar_tw->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_gjetsht100  = (TH1F*)gjetsht100->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_gjetsht100   = (TH1F*)gjetsht100->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_gjetsht100   = (TH1F*)gjetsht100->Get("nBJet_CSVM");
TH1F *nBJet_JPM_gjetsht100  = (TH1F*)gjetsht100->Get("nBJet_JPM");

nBJet_CSVv2IVFM_gjetsht100->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht100->SetLineColor(6);
nBJet_CSVM_gjetsht100->SetLineColor(6);
nBJet_JPM_gjetsht100->SetLineColor(6);

TH1F *nBJet_CSVv2IVFM_gjetsht200  = (TH1F*)gjetsht200->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_gjetsht200   = (TH1F*)gjetsht200->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_gjetsht200   = (TH1F*)gjetsht200->Get("nBJet_CSVM");
TH1F *nBJet_JPM_gjetsht200  = (TH1F*)gjetsht200->Get("nBJet_JPM");

nBJet_CSVv2IVFM_gjetsht200->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht200->SetLineColor(6);
nBJet_CSVM_gjetsht200->SetLineColor(6);
nBJet_JPM_gjetsht200->SetLineColor(6);

nBJet_CSVv2IVFM_gjetsht200->SetLineStyle(2);
nBJet_CSVv2IVFL_gjetsht200->SetLineStyle(2);
nBJet_CSVM_gjetsht200->SetLineStyle(2);
nBJet_JPM_gjetsht200->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_gjetsht400  = (TH1F*)gjetsht400->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_gjetsht400   = (TH1F*)gjetsht400->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_gjetsht400   = (TH1F*)gjetsht400->Get("nBJet_CSVM");
TH1F *nBJet_JPM_gjetsht400  = (TH1F*)gjetsht400->Get("nBJet_JPM");

nBJet_CSVv2IVFM_gjetsht400->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht400->SetLineColor(6);
nBJet_CSVM_gjetsht400->SetLineColor(6);
nBJet_JPM_gjetsht400->SetLineColor(6);

nBJet_CSVv2IVFM_gjetsht400->SetLineStyle(3);
nBJet_CSVv2IVFL_gjetsht400->SetLineStyle(3);
nBJet_CSVM_gjetsht400->SetLineStyle(3);
nBJet_JPM_gjetsht400->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_gjetsht600  = (TH1F*)gjetsht600->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_gjetsht600   = (TH1F*)gjetsht600->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_gjetsht600   = (TH1F*)gjetsht600->Get("nBJet_CSVM");
TH1F *nBJet_JPM_gjetsht600  = (TH1F*)gjetsht600->Get("nBJet_JPM");

nBJet_CSVv2IVFM_gjetsht600->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht600->SetLineColor(6);
nBJet_CSVM_gjetsht600->SetLineColor(6);
nBJet_JPM_gjetsht600->SetLineColor(6);

nBJet_CSVv2IVFM_gjetsht600->SetLineStyle(4);
nBJet_CSVv2IVFL_gjetsht600->SetLineStyle(4);
nBJet_CSVM_gjetsht600->SetLineStyle(4);
nBJet_JPM_gjetsht600->SetLineStyle(4);

TH1F *nBJet_CSVv2IVFM_qcdht100  = (TH1F*)qcdht100->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_qcdht100   = (TH1F*)qcdht100->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_qcdht100   = (TH1F*)qcdht100->Get("nBJet_CSVM");
TH1F *nBJet_JPM_qcdht100  = (TH1F*)qcdht100->Get("nBJet_JPM");

nBJet_CSVv2IVFM_qcdht100->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht100->SetLineColor(8);
nBJet_CSVM_qcdht100->SetLineColor(8);
nBJet_JPM_qcdht100->SetLineColor(8);

nBJet_CSVv2IVFM_qcdht100->SetLineStyle(1);
nBJet_CSVv2IVFL_qcdht100->SetLineStyle(1);
nBJet_CSVM_qcdht100->SetLineStyle(1);
nBJet_JPM_qcdht100->SetLineStyle(1);

TH1F *nBJet_CSVv2IVFM_qcdht250  = (TH1F*)qcdht250->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_qcdht250   = (TH1F*)qcdht250->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_qcdht250   = (TH1F*)qcdht250->Get("nBJet_CSVM");
TH1F *nBJet_JPM_qcdht250  = (TH1F*)qcdht250->Get("nBJet_JPM");

nBJet_CSVv2IVFM_qcdht250->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht250->SetLineColor(8);
nBJet_CSVM_qcdht250->SetLineColor(8);
nBJet_JPM_qcdht250->SetLineColor(8);

nBJet_CSVv2IVFM_qcdht250->SetLineStyle(2);
nBJet_CSVv2IVFL_qcdht250->SetLineStyle(2);
nBJet_CSVM_qcdht250->SetLineStyle(2);
nBJet_JPM_qcdht250->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_qcdht500  = (TH1F*)qcdht500->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_qcdht500   = (TH1F*)qcdht500->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_qcdht500   = (TH1F*)qcdht500->Get("nBJet_CSVM");
TH1F *nBJet_JPM_qcdht500   = (TH1F*)qcdht500->Get("nBJet_JPM");

nBJet_CSVv2IVFM_qcdht500->SetLineStyle(8);
nBJet_CSVv2IVFL_qcdht500->SetLineStyle(8);
nBJet_CSVM_qcdht500->SetLineStyle(8);
nBJet_JPM_qcdht500->SetLineStyle(8);

nBJet_CSVv2IVFM_qcdht500->SetLineStyle(3);
nBJet_CSVv2IVFL_qcdht500->SetLineStyle(3);
nBJet_CSVM_qcdht500->SetLineStyle(3);
nBJet_JPM_qcdht500->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_qcdht1000  = (TH1F*)qcdht1000->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_qcdht1000   = (TH1F*)qcdht1000->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_qcdht1000   = (TH1F*)qcdht1000->Get("nBJet_CSVM");
TH1F *nBJet_JPM_qcdht1000  = (TH1F*)qcdht1000->Get("nBJet_JPM");

nBJet_CSVv2IVFM_qcdht1000->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht1000->SetLineColor(8);
nBJet_CSVM_qcdht1000->SetLineColor(8);
nBJet_JPM_qcdht1000->SetLineColor(8);

nBJet_CSVv2IVFM_qcdht1000->SetLineStyle(4);
nBJet_CSVv2IVFL_qcdht1000->SetLineStyle(4);
nBJet_CSVM_qcdht1000->SetLineStyle(4);
nBJet_JPM_qcdht1000->SetLineStyle(4);

TH1F *nBJet_CSVv2IVFM_zz  = (TH1F*)zz->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_zz   = (TH1F*)zz->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_zz   = (TH1F*)zz->Get("nBJet_CSVM");
TH1F *nBJet_JPM_zz  = (TH1F*)zz->Get("nBJet_JPM");

nBJet_CSVv2IVFM_zz->SetLineStyle(1);
nBJet_CSVv2IVFL_zz->SetLineStyle(1);
nBJet_CSVM_zz->SetLineStyle(1);
nBJet_JPM_zz->SetLineStyle(1);

TH1F *nBJet_CSVv2IVFM_wz  = (TH1F*)wz->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_wz   = (TH1F*)wz->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_wz   = (TH1F*)wz->Get("nBJet_CSVM");
TH1F *nBJet_JPM_wz   = (TH1F*)wz->Get("nBJet_JPM");

nBJet_CSVv2IVFM_wz->SetLineStyle(2);
nBJet_CSVv2IVFL_wz->SetLineStyle(2);
nBJet_CSVM_wz->SetLineStyle(2);
nBJet_JPM_wz->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_dy  = (TH1F*)dy->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_dy   = (TH1F*)dy->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_dy   = (TH1F*)dy->Get("nBJet_CSVM");
TH1F *nBJet_JPM_dy  = (TH1F*)dy->Get("nBJet_JPM");

nBJet_CSVv2IVFM_dy->SetLineStyle(3);
nBJet_CSVv2IVFL_dy->SetLineStyle(3);
nBJet_CSVM_dy->SetLineStyle(3);
nBJet_JPM_dy->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_wjets  = (TH1F*)wjets->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_wjets   = (TH1F*)wjets->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_wjets   = (TH1F*)wjets->Get("nBJet_CSVM");
TH1F *nBJet_JPM_wjets  = (TH1F*)wjets->Get("nBJet_JPM");

nBJet_CSVv2IVFM_wjets->SetLineStyle(4);
nBJet_CSVv2IVFL_wjets->SetLineStyle(4);
nBJet_CSVM_wjets->SetLineStyle(4);
nBJet_JPM_wjets->SetLineStyle(4);

TH1F *nBJet_CSVv2IVFM_zjetsht100  = (TH1F*)zjetsht100->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_zjetsht100   = (TH1F*)zjetsht100->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_zjetsht100   = (TH1F*)zjetsht100->Get("nBJet_CSVM");
TH1F *nBJet_JPM_zjetsht100  = (TH1F*)zjetsht100->Get("nBJet_JPM");

nBJet_CSVv2IVFM_zjetsht100->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht100->SetLineColor(14);
nBJet_CSVM_zjetsht100->SetLineColor(14);
nBJet_JPM_zjetsht100->SetLineColor(14);

TH1F *nBJet_CSVv2IVFM_zjetsht200  = (TH1F*)zjetsht200->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_zjetsht200   = (TH1F*)zjetsht200->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_zjetsht200   = (TH1F*)zjetsht200->Get("nBJet_CSVM");
TH1F *nBJet_JPM_zjetsht200  = (TH1F*)zjetsht200->Get("nBJet_JPM");

nBJet_CSVv2IVFM_zjetsht200->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht200->SetLineColor(14);
nBJet_CSVM_zjetsht200->SetLineColor(14);
nBJet_JPM_zjetsht200->SetLineColor(14);

nBJet_CSVv2IVFM_zjetsht200->SetLineStyle(2);
nBJet_CSVv2IVFL_zjetsht200->SetLineStyle(2);
nBJet_CSVM_zjetsht200->SetLineStyle(2);
nBJet_JPM_zjetsht200->SetLineStyle(2);

TH1F *nBJet_CSVv2IVFM_zjetsht400  = (TH1F*)zjetsht400->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_zjetsht400   = (TH1F*)zjetsht400->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_zjetsht400   = (TH1F*)zjetsht400->Get("nBJet_CSVM");
TH1F *nBJet_JPM_zjetsht400  = (TH1F*)zjetsht400->Get("nBJet_JPM");

nBJet_CSVv2IVFM_zjetsht400->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht400->SetLineColor(14);
nBJet_CSVM_zjetsht400->SetLineColor(14);
nBJet_JPM_zjetsht400->SetLineColor(14);

nBJet_CSVv2IVFM_zjetsht400->SetLineStyle(3);
nBJet_CSVv2IVFL_zjetsht400->SetLineStyle(3);
nBJet_CSVM_zjetsht400->SetLineStyle(3);
nBJet_JPM_zjetsht400->SetLineStyle(3);

TH1F *nBJet_CSVv2IVFM_zjetsht600  = (TH1F*)zjetsht600->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFL_zjetsht600   = (TH1F*)zjetsht600->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVM_zjetsht600   = (TH1F*)zjetsht600->Get("nBJet_CSVM");
TH1F *nBJet_JPM_zjetsht600  = (TH1F*)zjetsht600->Get("nBJet_JPM");

nBJet_CSVv2IVFM_zjetsht600->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht600->SetLineColor(14);
nBJet_CSVM_zjetsht600->SetLineColor(14);
nBJet_JPM_zjetsht600->SetLineColor(14);

nBJet_CSVv2IVFM_zjetsht600->SetLineStyle(4);
nBJet_CSVv2IVFL_zjetsht600->SetLineStyle(4);
nBJet_CSVM_zjetsht600->SetLineStyle(4);
nBJet_JPM_zjetsht600->SetLineStyle(4);

nBJet_CSVv2IVFM_ttjets->GetXaxis()->SetTitle("# Jets");
nBJet_CSVv2IVFL_ttjets->GetXaxis()->SetTitle("# B-Jets");
nBJet_CSVM_ttjets->GetXaxis()->SetTitle("MET (GeV)");
nBJet_JPM_ttjets->GetXaxis()->SetTitle("p_{T} of leading Jet");

TLegend* leg = new TLegend(0.6,0.6,0.9,0.89);
leg->AddEntry(nBJet_CSVv2IVFM_ttjets,"TTJets");
leg->AddEntry(nBJet_CSVv2IVFM_ttzjets,"TTZJets");
leg->AddEntry(nBJet_CSVv2IVFM_ttwjets,"TTWJets");
leg->AddEntry(nBJet_CSVv2IVFM_ttbarh,"TTbarH");
leg->AddEntry(nBJet_CSVv2IVFM_ttol_t,"TToLeptons_t");
leg->AddEntry(nBJet_CSVv2IVFM_ttol_s,"TToLeptons_s");
leg->AddEntry(nBJet_CSVv2IVFM_tbartol_t,"TBarToLeptons_t");
leg->AddEntry(nBJet_CSVv2IVFM_tbartol_s,"TBarToLeptons_s");
leg->AddEntry(nBJet_CSVv2IVFM_t_tw,"T_tW");
leg->AddEntry(nBJet_CSVv2IVFM_tbar_tw,"TBar_tW");
leg->AddEntry(nBJet_CSVv2IVFM_gjetsht100,"GJetsHT100To200");
leg->AddEntry(nBJet_CSVv2IVFM_gjetsht200,"GJetsHT200To400");
leg->AddEntry(nBJet_CSVv2IVFM_gjetsht400,"GJetsHT400To600");
leg->AddEntry(nBJet_CSVv2IVFM_gjetsht600,"GJetsHT600ToInf");
leg->AddEntry(nBJet_CSVv2IVFM_qcdht100,"QCDHT100To250");
leg->AddEntry(nBJet_CSVv2IVFM_qcdht250,"QCDHT250To500");
leg->AddEntry(nBJet_CSVv2IVFM_qcdht500,"QCDHT500To1000");
leg->AddEntry(nBJet_CSVv2IVFM_qcdht1000,"QCDHT1000ToInf");
leg->AddEntry(nBJet_CSVv2IVFM_zz,"ZZTo4L");
leg->AddEntry(nBJet_CSVv2IVFM_wz,"WZJetsTo3LNu");
leg->AddEntry(nBJet_CSVv2IVFM_dy,"DYJetsToLL");
leg->AddEntry(nBJet_CSVv2IVFM_wjets,"WJetsToLNu");
leg->AddEntry(nBJet_CSVv2IVFM_zjetsht100,"ZJetsHT100To200");
leg->AddEntry(nBJet_CSVv2IVFM_zjetsht200,"ZJetsHT200To400");
leg->AddEntry(nBJet_CSVv2IVFM_zjetsht400,"ZJetsHT400To600");
leg->AddEntry(nBJet_CSVv2IVFM_zjetsht600,"ZJetsHT600ToInf");

c1->cd();
nBJet_CSVv2IVFM_wjets->Draw();
nBJet_CSVv2IVFM_ttjets->Draw("same");
nBJet_CSVv2IVFM_ttzjets->Draw("same");
nBJet_CSVv2IVFM_ttwjets->Draw("same");
nBJet_CSVv2IVFM_ttbarh->Draw("same");
nBJet_CSVv2IVFM_ttol_t->Draw("same");
nBJet_CSVv2IVFM_ttol_s->Draw("same");
nBJet_CSVv2IVFM_tbartol_t->Draw("same");
nBJet_CSVv2IVFM_tbartol_s->Draw("same");
nBJet_CSVv2IVFM_t_tw->Draw("same");
nBJet_CSVv2IVFM_tbar_tw->Draw("same");
nBJet_CSVv2IVFM_gjetsht100->Draw("same");
nBJet_CSVv2IVFM_gjetsht200->Draw("same");
nBJet_CSVv2IVFM_gjetsht400->Draw("same");
nBJet_CSVv2IVFM_gjetsht600->Draw("same");
nBJet_CSVv2IVFM_qcdht100->Draw("same");
nBJet_CSVv2IVFM_qcdht250->Draw("same");
nBJet_CSVv2IVFM_qcdht500->Draw("same");
nBJet_CSVv2IVFM_qcdht1000->Draw("same");
nBJet_CSVv2IVFM_zz->Draw("same");
nBJet_CSVv2IVFM_dy->Draw("same");
nBJet_CSVv2IVFM_wz->Draw("same");
nBJet_CSVv2IVFM_zjetsht100->Draw("same");
nBJet_CSVv2IVFM_zjetsht200->Draw("same");
nBJet_CSVv2IVFM_zjetsht400->Draw("same");
nBJet_CSVv2IVFM_zjetsht600->Draw("same");
leg->Draw("same");
c2->cd();
nBJet_CSVv2IVFL_wjets->Draw();
nBJet_CSVv2IVFL_wz->Draw("same");
nBJet_CSVv2IVFL_tbar_tw->Draw("same");
nBJet_CSVv2IVFL_qcdht500->Draw("same");
nBJet_CSVv2IVFL_ttzjets->Draw("same");
nBJet_CSVv2IVFL_ttol_t->Draw("same");
nBJet_CSVv2IVFL_ttwjets->Draw("same");
nBJet_CSVv2IVFL_tbartol_t->Draw("same");
nBJet_CSVv2IVFL_dy->Draw("same");
nBJet_CSVv2IVFL_t_tw->Draw("same");
nBJet_CSVv2IVFL_ttbarh->Draw("same");
nBJet_CSVv2IVFL_ttol_s->Draw("same");
nBJet_CSVv2IVFL_tbartol_s->Draw("same");
nBJet_CSVv2IVFL_gjetsht100->Draw("same");
nBJet_CSVv2IVFL_gjetsht200->Draw("same");
nBJet_CSVv2IVFL_gjetsht400->Draw("same");
nBJet_CSVv2IVFL_gjetsht600->Draw("same");
nBJet_CSVv2IVFL_qcdht100->Draw("same");
nBJet_CSVv2IVFL_qcdht250->Draw("same");
nBJet_CSVv2IVFL_qcdht1000->Draw("same");
nBJet_CSVv2IVFL_zz->Draw("same");
nBJet_CSVv2IVFL_ttjets->Draw("same");
nBJet_CSVv2IVFL_zjetsht100->Draw("same");
nBJet_CSVv2IVFL_zjetsht200->Draw("same");
nBJet_CSVv2IVFL_zjetsht400->Draw("same");
nBJet_CSVv2IVFL_zjetsht600->Draw("same");
leg->Draw("same");
c3->cd();
nBJet_CSVM_wjets->Draw();
nBJet_CSVM_wz->Draw("same");
nBJet_CSVM_ttzjets->Draw("same");
nBJet_CSVM_ttwjets->Draw("same");
nBJet_CSVM_ttbarh->Draw("same");
nBJet_CSVM_ttol_t->Draw("same");
nBJet_CSVM_ttol_s->Draw("same");
nBJet_CSVM_tbartol_t->Draw("same");
nBJet_CSVM_tbartol_s->Draw("same");
nBJet_CSVM_t_tw->Draw("same");
nBJet_CSVM_tbar_tw->Draw("same");
nBJet_CSVM_gjetsht100->Draw("same");
nBJet_CSVM_gjetsht200->Draw("same");
nBJet_CSVM_gjetsht400->Draw("same");
nBJet_CSVM_gjetsht600->Draw("same");
nBJet_CSVM_qcdht100->Draw("same");
nBJet_CSVM_qcdht250->Draw("same");
nBJet_CSVM_qcdht500->Draw("same");
nBJet_CSVM_qcdht1000->Draw("same");
nBJet_CSVM_zz->Draw("same");
nBJet_CSVM_dy->Draw("same");
nBJet_CSVM_ttjets->Draw("same");
nBJet_CSVM_zjetsht100->Draw("same");
nBJet_CSVM_zjetsht200->Draw("same");
nBJet_CSVM_zjetsht400->Draw("same");
nBJet_CSVM_zjetsht600->Draw("same");
leg->Draw("same");
c4->cd();
nBJet_JPM_wjets->Draw();
nBJet_JPM_zjetsht400->Draw("same");
nBJet_JPM_wz->Draw("same");
nBJet_JPM_ttzjets->Draw("same");
nBJet_JPM_ttwjets->Draw("same");
nBJet_JPM_ttbarh->Draw("same");
nBJet_JPM_ttol_t->Draw("same");
nBJet_JPM_ttol_s->Draw("same");
nBJet_JPM_tbartol_t->Draw("same");
nBJet_JPM_tbartol_s->Draw("same");
nBJet_JPM_t_tw->Draw("same");
nBJet_JPM_tbar_tw->Draw("same");
nBJet_JPM_gjetsht100->Draw("same");
nBJet_JPM_gjetsht200->Draw("same");
nBJet_JPM_gjetsht400->Draw("same");
nBJet_JPM_gjetsht600->Draw("same");
nBJet_JPM_qcdht100->Draw("same");
nBJet_JPM_qcdht250->Draw("same");
nBJet_JPM_qcdht500->Draw("same");
nBJet_JPM_qcdht1000->Draw("same");
nBJet_JPM_zz->Draw("same");
nBJet_JPM_dy->Draw("same");
nBJet_JPM_ttjets->Draw("same");
nBJet_JPM_zjetsht100->Draw("same");
nBJet_JPM_zjetsht200->Draw("same");
nBJet_JPM_zjetsht600->Draw("same");
leg->Draw("same");

}
