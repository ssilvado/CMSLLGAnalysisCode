void plots(){

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

TH1F *nJet_ttjets  = (TH1F*)ttjets->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFL");
TH1F *met_ttjets   = (TH1F*)ttjets->Get("met");
TH1F *ptJet_ttjets   = (TH1F*)ttjets->Get("jet1_pt_allEvents");

nJet_ttjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttjets->SetLineColor(1);
met_ttjets->SetLineColor(1);
ptJet_ttjets->SetLineColor(1);

TH1F *nJet_ttzjets  = (TH1F*)ttzjets->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttzjets   = (TH1F*)ttzjets->Get("nBJet_CSVv2IVFL");
TH1F *met_ttzjets   = (TH1F*)ttzjets->Get("met");
TH1F *ptJet_ttzjets   = (TH1F*)ttzjets->Get("jet1_pt_allEvents");

nJet_ttzjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttzjets->SetLineColor(1);
met_ttzjets->SetLineColor(1);
ptJet_ttzjets->SetLineColor(1);

nJet_ttzjets->SetLineStyle(2);
nBJet_CSVv2IVFL_ttzjets->SetLineStyle(2);
met_ttzjets->SetLineStyle(2);
ptJet_ttzjets->SetLineStyle(2);

TH1F *nJet_ttwjets  = (TH1F*)ttwjets->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttwjets   = (TH1F*)ttwjets->Get("nBJet_CSVv2IVFL");
TH1F *met_ttwjets   = (TH1F*)ttwjets->Get("met");
TH1F *ptJet_ttwjets   = (TH1F*)ttwjets->Get("jet1_pt_allEvents");

nJet_ttwjets->SetLineColor(1);
nBJet_CSVv2IVFL_ttwjets->SetLineColor(1);
met_ttwjets->SetLineColor(1);
ptJet_ttwjets->SetLineColor(1);

nJet_ttwjets->SetLineStyle(3);
nBJet_CSVv2IVFL_ttwjets->SetLineStyle(3);
met_ttwjets->SetLineStyle(3);
ptJet_ttwjets->SetLineStyle(3);

TH1F *nJet_ttbarh  = (TH1F*)ttbarh->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttbarh   = (TH1F*)ttbarh->Get("nBJet_CSVv2IVFL");
TH1F *met_ttbarh   = (TH1F*)ttbarh->Get("met");
TH1F *ptJet_ttbarh   = (TH1F*)ttbarh->Get("jet1_pt_allEvents");

nJet_ttbarh->SetLineColor(1);
nBJet_CSVv2IVFL_ttbarh->SetLineColor(1);
met_ttbarh->SetLineColor(1);
ptJet_ttbarh->SetLineColor(1);

nJet_ttbarh->SetLineStyle(4);
nBJet_CSVv2IVFL_ttbarh->SetLineStyle(4);
met_ttbarh->SetLineStyle(4);
ptJet_ttbarh->SetLineStyle(4);

TH1F *nJet_ttol_t  = (TH1F*)ttol_t->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttol_t   = (TH1F*)ttol_t->Get("nBJet_CSVv2IVFL");
TH1F *met_ttol_t   = (TH1F*)ttol_t->Get("met");
TH1F *ptJet_ttol_t   = (TH1F*)ttol_t->Get("jet1_pt_allEvents");

nJet_ttol_t->SetLineColor(2);
nBJet_CSVv2IVFL_ttol_t->SetLineColor(2);
met_ttol_t->SetLineColor(2);
ptJet_ttol_t->SetLineColor(2);

TH1F *nJet_ttol_s  = (TH1F*)ttol_s->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttol_s   = (TH1F*)ttol_s->Get("nBJet_CSVv2IVFL");
TH1F *met_ttol_s   = (TH1F*)ttol_s->Get("met");
TH1F *ptJet_ttol_s   = (TH1F*)ttol_s->Get("jet1_pt_allEvents");

nJet_ttol_s->SetLineColor(2);
nBJet_CSVv2IVFL_ttol_s->SetLineColor(2);
met_ttol_s->SetLineColor(2);
ptJet_ttol_s->SetLineColor(2);

nJet_ttol_s->SetLineStyle(2);
nBJet_CSVv2IVFL_ttol_s->SetLineStyle(2);
met_ttol_s->SetLineStyle(2);
ptJet_ttol_s->SetLineStyle(2);

TH1F *nJet_tbartol_t  = (TH1F*)tbartol_t->Get("nJet");
TH1F *nBJet_CSVv2IVFL_tbartol_t   = (TH1F*)tbartol_t->Get("nBJet_CSVv2IVFL");
TH1F *met_tbartol_t   = (TH1F*)tbartol_t->Get("met");
TH1F *ptJet_tbartol_t   = (TH1F*)tbartol_t->Get("jet1_pt_allEvents");

nJet_tbartol_t->SetLineColor(2);
nBJet_CSVv2IVFL_tbartol_t->SetLineColor(2);
met_tbartol_t->SetLineColor(2);
ptJet_tbartol_t->SetLineColor(2);

nJet_tbartol_t->SetLineStyle(3);
nBJet_CSVv2IVFL_tbartol_t->SetLineStyle(3);
met_tbartol_t->SetLineStyle(3);
ptJet_tbartol_t->SetLineStyle(3);

TH1F *nJet_tbartol_s  = (TH1F*)tbartol_s->Get("nJet");
TH1F *nBJet_CSVv2IVFL_tbartol_s   = (TH1F*)tbartol_s->Get("nBJet_CSVv2IVFL");
TH1F *met_tbartol_s   = (TH1F*)tbartol_s->Get("met");
TH1F *ptJet_tbartol_s   = (TH1F*)tbartol_s->Get("jet1_pt_allEvents");

nJet_tbartol_s->SetLineColor(2);
nBJet_CSVv2IVFL_tbartol_s->SetLineColor(2);
met_tbartol_s->SetLineColor(2);
ptJet_tbartol_s->SetLineColor(2);

nJet_tbartol_s->SetLineStyle(4);
nBJet_CSVv2IVFL_tbartol_s->SetLineStyle(4);
met_tbartol_s->SetLineStyle(4);
ptJet_tbartol_s->SetLineStyle(4);

TH1F *nJet_t_tw  = (TH1F*)t_tw->Get("nJet");
TH1F *nBJet_CSVv2IVFL_t_tw   = (TH1F*)t_tw->Get("nBJet_CSVv2IVFL");
TH1F *met_t_tw   = (TH1F*)t_tw->Get("met");
TH1F *ptJet_t_tw   = (TH1F*)t_tw->Get("jet1_pt_allEvents");

nJet_t_tw->SetLineColor(50);
nBJet_CSVv2IVFL_t_tw->SetLineColor(50);
met_t_tw->SetLineColor(50);
ptJet_t_tw->SetLineColor(50);

TH1F *nJet_tbar_tw  = (TH1F*)tbar_tw->Get("nJet");
TH1F *nBJet_CSVv2IVFL_tbar_tw   = (TH1F*)tbar_tw->Get("nBJet_CSVv2IVFL");
TH1F *met_tbar_tw   = (TH1F*)tbar_tw->Get("met");
TH1F *ptJet_tbar_tw   = (TH1F*)tbar_tw->Get("jet1_pt_allEvents");

nJet_tbar_tw->SetLineColor(50);
nBJet_CSVv2IVFL_tbar_tw->SetLineColor(50);
met_tbar_tw->SetLineColor(50);
ptJet_tbar_tw->SetLineColor(50);

nJet_tbar_tw->SetLineStyle(2);
nBJet_CSVv2IVFL_tbar_tw->SetLineStyle(2);
met_tbar_tw->SetLineStyle(2);
ptJet_tbar_tw->SetLineStyle(2);

TH1F *nJet_gjetsht100  = (TH1F*)gjetsht100->Get("nJet");
TH1F *nBJet_CSVv2IVFL_gjetsht100   = (TH1F*)gjetsht100->Get("nBJet_CSVv2IVFL");
TH1F *met_gjetsht100   = (TH1F*)gjetsht100->Get("met");
TH1F *ptJet_gjetsht100  = (TH1F*)gjetsht100->Get("jet1_pt_allEvents");

nJet_gjetsht100->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht100->SetLineColor(6);
met_gjetsht100->SetLineColor(6);
ptJet_gjetsht100->SetLineColor(6);

TH1F *nJet_gjetsht200  = (TH1F*)gjetsht200->Get("nJet");
TH1F *nBJet_CSVv2IVFL_gjetsht200   = (TH1F*)gjetsht200->Get("nBJet_CSVv2IVFL");
TH1F *met_gjetsht200   = (TH1F*)gjetsht200->Get("met");
TH1F *ptJet_gjetsht200  = (TH1F*)gjetsht200->Get("jet1_pt_allEvents");

nJet_gjetsht200->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht200->SetLineColor(6);
met_gjetsht200->SetLineColor(6);
ptJet_gjetsht200->SetLineColor(6);

nJet_gjetsht200->SetLineStyle(2);
nBJet_CSVv2IVFL_gjetsht200->SetLineStyle(2);
met_gjetsht200->SetLineStyle(2);
ptJet_gjetsht200->SetLineStyle(2);

TH1F *nJet_gjetsht400  = (TH1F*)gjetsht400->Get("nJet");
TH1F *nBJet_CSVv2IVFL_gjetsht400   = (TH1F*)gjetsht400->Get("nBJet_CSVv2IVFL");
TH1F *met_gjetsht400   = (TH1F*)gjetsht400->Get("met");
TH1F *ptJet_gjetsht400  = (TH1F*)gjetsht400->Get("jet1_pt_allEvents");

nJet_gjetsht400->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht400->SetLineColor(6);
met_gjetsht400->SetLineColor(6);
ptJet_gjetsht400->SetLineColor(6);

nJet_gjetsht400->SetLineStyle(3);
nBJet_CSVv2IVFL_gjetsht400->SetLineStyle(3);
met_gjetsht400->SetLineStyle(3);
ptJet_gjetsht400->SetLineStyle(3);

TH1F *nJet_gjetsht600  = (TH1F*)gjetsht600->Get("nJet");
TH1F *nBJet_CSVv2IVFL_gjetsht600   = (TH1F*)gjetsht600->Get("nBJet_CSVv2IVFL");
TH1F *met_gjetsht600   = (TH1F*)gjetsht600->Get("met");
TH1F *ptJet_gjetsht600  = (TH1F*)gjetsht600->Get("jet1_pt_allEvents");

nJet_gjetsht600->SetLineColor(6);
nBJet_CSVv2IVFL_gjetsht600->SetLineColor(6);
met_gjetsht600->SetLineColor(6);
ptJet_gjetsht600->SetLineColor(6);

nJet_gjetsht600->SetLineStyle(4);
nBJet_CSVv2IVFL_gjetsht600->SetLineStyle(4);
met_gjetsht600->SetLineStyle(4);
ptJet_gjetsht600->SetLineStyle(4);

TH1F *nJet_qcdht100  = (TH1F*)qcdht100->Get("nJet");
TH1F *nBJet_CSVv2IVFL_qcdht100   = (TH1F*)qcdht100->Get("nBJet_CSVv2IVFL");
TH1F *met_qcdht100   = (TH1F*)qcdht100->Get("met");
TH1F *ptJet_qcdht100  = (TH1F*)qcdht100->Get("jet1_pt_allEvents");

nJet_qcdht100->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht100->SetLineColor(8);
met_qcdht100->SetLineColor(8);
ptJet_qcdht100->SetLineColor(8);

nJet_qcdht100->SetLineStyle(1);
nBJet_CSVv2IVFL_qcdht100->SetLineStyle(1);
met_qcdht100->SetLineStyle(1);
ptJet_qcdht100->SetLineStyle(1);

TH1F *nJet_qcdht250  = (TH1F*)qcdht250->Get("nJet");
TH1F *nBJet_CSVv2IVFL_qcdht250   = (TH1F*)qcdht250->Get("nBJet_CSVv2IVFL");
TH1F *met_qcdht250   = (TH1F*)qcdht250->Get("met");
TH1F *ptJet_qcdht250  = (TH1F*)qcdht250->Get("jet1_pt_allEvents");

nJet_qcdht250->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht250->SetLineColor(8);
met_qcdht250->SetLineColor(8);
ptJet_qcdht250->SetLineColor(8);

nJet_qcdht250->SetLineStyle(2);
nBJet_CSVv2IVFL_qcdht250->SetLineStyle(2);
met_qcdht250->SetLineStyle(2);
ptJet_qcdht250->SetLineStyle(2);

TH1F *nJet_qcdht500  = (TH1F*)qcdht500->Get("nJet");
TH1F *nBJet_CSVv2IVFL_qcdht500   = (TH1F*)qcdht500->Get("nBJet_CSVv2IVFL");
TH1F *met_qcdht500   = (TH1F*)qcdht500->Get("met");
TH1F *ptJet_qcdht500   = (TH1F*)qcdht500->Get("jet1_pt_allEvents");

nJet_qcdht500->SetLineStyle(8);
nBJet_CSVv2IVFL_qcdht500->SetLineStyle(8);
met_qcdht500->SetLineStyle(8);
ptJet_qcdht500->SetLineStyle(8);

nJet_qcdht500->SetLineStyle(3);
nBJet_CSVv2IVFL_qcdht500->SetLineStyle(3);
met_qcdht500->SetLineStyle(3);
ptJet_qcdht500->SetLineStyle(3);

TH1F *nJet_qcdht1000  = (TH1F*)qcdht1000->Get("nJet");
TH1F *nBJet_CSVv2IVFL_qcdht1000   = (TH1F*)qcdht1000->Get("nBJet_CSVv2IVFL");
TH1F *met_qcdht1000   = (TH1F*)qcdht1000->Get("met");
TH1F *ptJet_qcdht1000  = (TH1F*)qcdht1000->Get("jet1_pt_allEvents");

nJet_qcdht1000->SetLineColor(8);
nBJet_CSVv2IVFL_qcdht1000->SetLineColor(8);
met_qcdht1000->SetLineColor(8);
ptJet_qcdht1000->SetLineColor(8);

nJet_qcdht1000->SetLineStyle(4);
nBJet_CSVv2IVFL_qcdht1000->SetLineStyle(4);
met_qcdht1000->SetLineStyle(4);
ptJet_qcdht1000->SetLineStyle(4);

TH1F *nJet_zz  = (TH1F*)zz->Get("nJet");
TH1F *nBJet_CSVv2IVFL_zz   = (TH1F*)zz->Get("nBJet_CSVv2IVFL");
TH1F *met_zz   = (TH1F*)zz->Get("met");
TH1F *ptJet_zz  = (TH1F*)zz->Get("jet1_pt_allEvents");

nJet_zz->SetLineStyle(1);
nBJet_CSVv2IVFL_zz->SetLineStyle(1);
met_zz->SetLineStyle(1);
ptJet_zz->SetLineStyle(1);

TH1F *nJet_wz  = (TH1F*)wz->Get("nJet");
TH1F *nBJet_CSVv2IVFL_wz   = (TH1F*)wz->Get("nBJet_CSVv2IVFL");
TH1F *met_wz   = (TH1F*)wz->Get("met");
TH1F *ptJet_wz   = (TH1F*)wz->Get("jet1_pt_allEvents");

nJet_wz->SetLineStyle(2);
nBJet_CSVv2IVFL_wz->SetLineStyle(2);
met_wz->SetLineStyle(2);
ptJet_wz->SetLineStyle(2);

TH1F *nJet_dy  = (TH1F*)dy->Get("nJet");
TH1F *nBJet_CSVv2IVFL_dy   = (TH1F*)dy->Get("nBJet_CSVv2IVFL");
TH1F *met_dy   = (TH1F*)dy->Get("met");
TH1F *ptJet_dy  = (TH1F*)dy->Get("jet1_pt_allEvents");

nJet_dy->SetLineStyle(3);
nBJet_CSVv2IVFL_dy->SetLineStyle(3);
met_dy->SetLineStyle(3);
ptJet_dy->SetLineStyle(3);

TH1F *nJet_wjets  = (TH1F*)wjets->Get("nJet");
TH1F *nBJet_CSVv2IVFL_wjets   = (TH1F*)wjets->Get("nBJet_CSVv2IVFL");
TH1F *met_wjets   = (TH1F*)wjets->Get("met");
TH1F *ptJet_wjets  = (TH1F*)wjets->Get("jet1_pt_allEvents");

nJet_wjets->SetLineStyle(4);
nBJet_CSVv2IVFL_wjets->SetLineStyle(4);
met_wjets->SetLineStyle(4);
ptJet_wjets->SetLineStyle(4);

TH1F *nJet_zjetsht100  = (TH1F*)zjetsht100->Get("nJet");
TH1F *nBJet_CSVv2IVFL_zjetsht100   = (TH1F*)zjetsht100->Get("nBJet_CSVv2IVFL");
TH1F *met_zjetsht100   = (TH1F*)zjetsht100->Get("met");
TH1F *ptJet_zjetsht100  = (TH1F*)zjetsht100->Get("jet1_pt_allEvents");

nJet_zjetsht100->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht100->SetLineColor(14);
met_zjetsht100->SetLineColor(14);
ptJet_zjetsht100->SetLineColor(14);

TH1F *nJet_zjetsht200  = (TH1F*)zjetsht200->Get("nJet");
TH1F *nBJet_CSVv2IVFL_zjetsht200   = (TH1F*)zjetsht200->Get("nBJet_CSVv2IVFL");
TH1F *met_zjetsht200   = (TH1F*)zjetsht200->Get("met");
TH1F *ptJet_zjetsht200  = (TH1F*)zjetsht200->Get("jet1_pt_allEvents");

nJet_zjetsht200->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht200->SetLineColor(14);
met_zjetsht200->SetLineColor(14);
ptJet_zjetsht200->SetLineColor(14);

nJet_zjetsht200->SetLineStyle(2);
nBJet_CSVv2IVFL_zjetsht200->SetLineStyle(2);
met_zjetsht200->SetLineStyle(2);
ptJet_zjetsht200->SetLineStyle(2);

TH1F *nJet_zjetsht400  = (TH1F*)zjetsht400->Get("nJet");
TH1F *nBJet_CSVv2IVFL_zjetsht400   = (TH1F*)zjetsht400->Get("nBJet_CSVv2IVFL");
TH1F *met_zjetsht400   = (TH1F*)zjetsht400->Get("met");
TH1F *ptJet_zjetsht400  = (TH1F*)zjetsht400->Get("jet1_pt_allEvents");

nJet_zjetsht400->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht400->SetLineColor(14);
met_zjetsht400->SetLineColor(14);
ptJet_zjetsht400->SetLineColor(14);

nJet_zjetsht400->SetLineStyle(3);
nBJet_CSVv2IVFL_zjetsht400->SetLineStyle(3);
met_zjetsht400->SetLineStyle(3);
ptJet_zjetsht400->SetLineStyle(3);

TH1F *nJet_zjetsht600  = (TH1F*)zjetsht600->Get("nJet");
TH1F *nBJet_CSVv2IVFL_zjetsht600   = (TH1F*)zjetsht600->Get("nBJet_CSVv2IVFL");
TH1F *met_zjetsht600   = (TH1F*)zjetsht600->Get("met");
TH1F *ptJet_zjetsht600  = (TH1F*)zjetsht600->Get("jet1_pt_allEvents");

nJet_zjetsht600->SetLineColor(14);
nBJet_CSVv2IVFL_zjetsht600->SetLineColor(14);
met_zjetsht600->SetLineColor(14);
ptJet_zjetsht600->SetLineColor(14);

nJet_zjetsht600->SetLineStyle(4);
nBJet_CSVv2IVFL_zjetsht600->SetLineStyle(4);
met_zjetsht600->SetLineStyle(4);
ptJet_zjetsht600->SetLineStyle(4);

nJet_ttjets->GetXaxis()->SetTitle("# Jets");
nBJet_CSVv2IVFL_ttjets->GetXaxis()->SetTitle("# B-Jets");
met_ttjets->GetXaxis()->SetTitle("MET (GeV)");
ptJet_ttjets->GetXaxis()->SetTitle("p_{T} of leading Jet");

TLegend* leg = new TLegend(0.6,0.6,0.9,0.89);
leg->AddEntry(nJet_ttjets,"TTJets");
leg->AddEntry(nJet_ttzjets,"TTZJets");
leg->AddEntry(nJet_ttwjets,"TTWJets");
leg->AddEntry(nJet_ttbarh,"TTbarH");
leg->AddEntry(nJet_ttol_t,"TToLeptons_t");
leg->AddEntry(nJet_ttol_s,"TToLeptons_s");
leg->AddEntry(nJet_tbartol_t,"TBarToLeptons_t");
leg->AddEntry(nJet_tbartol_s,"TBarToLeptons_s");
leg->AddEntry(nJet_t_tw,"T_tW");
leg->AddEntry(nJet_tbar_tw,"TBar_tW");
leg->AddEntry(nJet_gjetsht100,"GJetsHT100To200");
leg->AddEntry(nJet_gjetsht200,"GJetsHT200To400");
leg->AddEntry(nJet_gjetsht400,"GJetsHT400To600");
leg->AddEntry(nJet_gjetsht600,"GJetsHT600ToInf");
leg->AddEntry(nJet_qcdht100,"QCDHT100To250");
leg->AddEntry(nJet_qcdht250,"QCDHT250To500");
leg->AddEntry(nJet_qcdht500,"QCDHT500To1000");
leg->AddEntry(nJet_qcdht1000,"QCDHT1000ToInf");
leg->AddEntry(nJet_zz,"ZZTo4L");
leg->AddEntry(nJet_wz,"WZJetsTo3LNu");
leg->AddEntry(nJet_dy,"DYJetsToLL");
leg->AddEntry(nJet_wjets,"WJetsToLNu");
leg->AddEntry(nJet_zjetsht100,"ZJetsHT100To200");
leg->AddEntry(nJet_zjetsht200,"ZJetsHT200To400");
leg->AddEntry(nJet_zjetsht400,"ZJetsHT400To600");
leg->AddEntry(nJet_zjetsht600,"ZJetsHT600ToInf");

c1->cd();
nJet_wjets->Draw();
nJet_ttjets->Draw("same");
nJet_ttzjets->Draw("same");
nJet_ttwjets->Draw("same");
nJet_ttbarh->Draw("same");
nJet_ttol_t->Draw("same");
nJet_ttol_s->Draw("same");
nJet_tbartol_t->Draw("same");
nJet_tbartol_s->Draw("same");
nJet_t_tw->Draw("same");
nJet_tbar_tw->Draw("same");
nJet_gjetsht100->Draw("same");
nJet_gjetsht200->Draw("same");
nJet_gjetsht400->Draw("same");
nJet_gjetsht600->Draw("same");
nJet_qcdht100->Draw("same");
nJet_qcdht250->Draw("same");
nJet_qcdht500->Draw("same");
nJet_qcdht1000->Draw("same");
nJet_zz->Draw("same");
nJet_dy->Draw("same");
nJet_wz->Draw("same");
nJet_zjetsht100->Draw("same");
nJet_zjetsht200->Draw("same");
nJet_zjetsht400->Draw("same");
nJet_zjetsht600->Draw("same");
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
met_wjets->Draw();
met_wz->Draw("same");
met_ttzjets->Draw("same");
met_ttwjets->Draw("same");
met_ttbarh->Draw("same");
met_ttol_t->Draw("same");
met_ttol_s->Draw("same");
met_tbartol_t->Draw("same");
met_tbartol_s->Draw("same");
met_t_tw->Draw("same");
met_tbar_tw->Draw("same");
met_gjetsht100->Draw("same");
met_gjetsht200->Draw("same");
met_gjetsht400->Draw("same");
met_gjetsht600->Draw("same");
met_qcdht100->Draw("same");
met_qcdht250->Draw("same");
met_qcdht500->Draw("same");
met_qcdht1000->Draw("same");
met_zz->Draw("same");
met_dy->Draw("same");
met_ttjets->Draw("same");
met_zjetsht100->Draw("same");
met_zjetsht200->Draw("same");
met_zjetsht400->Draw("same");
met_zjetsht600->Draw("same");
leg->Draw("same");
c4->cd();
ptJet_zjetsht400->Draw();
ptJet_ttjets->Draw("same");
ptJet_wz->Draw("same");
ptJet_ttzjets->Draw("same");
ptJet_ttwjets->Draw("same");
ptJet_ttbarh->Draw("same");
ptJet_ttol_t->Draw("same");
ptJet_ttol_s->Draw("same");
ptJet_tbartol_t->Draw("same");
ptJet_tbartol_s->Draw("same");
ptJet_t_tw->Draw("same");
ptJet_tbar_tw->Draw("same");
ptJet_gjetsht100->Draw("same");
ptJet_gjetsht200->Draw("same");
ptJet_gjetsht400->Draw("same");
ptJet_gjetsht600->Draw("same");
ptJet_qcdht100->Draw("same");
ptJet_qcdht250->Draw("same");
ptJet_qcdht500->Draw("same");
ptJet_qcdht1000->Draw("same");
ptJet_zz->Draw("same");
ptJet_dy->Draw("same");
ptJet_wjets->Draw("same");
ptJet_zjetsht100->Draw("same");
ptJet_zjetsht200->Draw("same");
ptJet_zjetsht600->Draw("same");
leg->Draw("same");

}
