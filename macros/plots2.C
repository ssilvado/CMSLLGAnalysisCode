void plots2(){

TFile * ttjets = TFile::Open("TTJets.root");
TFile * all = TFile::Open("all.root");

TCanvas *c1 = new TCanvas("c1", "c1", 600, 800);
TCanvas *c2 = new TCanvas("c2", "c2", 600, 800);
TCanvas *c3 = new TCanvas("c3", "c3", 600, 800);
//TCanvas *c4 = new TCanvas("c4", "c4", 600, 800);

//c->SetFillColor(42);
//c->Divide(2,2);

TH1F *nJet_ttjets  = (TH1F*)ttjets->Get("nJet");
TH1F *nBJet_CSVv2IVFL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFL");
TH1F *met_ttjets   = (TH1F*)ttjets->Get("met");
//TH1F *ptJet_ttjets   = (TH1F*)ttjets->Get("jet1_pt_allEvents");

nJet_ttjets->Sumw2();
nBJet_CSVv2IVFL_ttjets->Sumw2();
met_ttjets->Sumw2();

nJet_ttjets->SetLineColor(2);
nBJet_CSVv2IVFL_ttjets->SetLineColor(2);
met_ttjets->SetLineColor(2);
//ptJet_ttjets->SetLineColor(2);

TH1F *nJet_all  = (TH1F*)all->Get("nJet");
TH1F *nBJet_CSVv2IVFL_all   = (TH1F*)all->Get("nBJet_CSVv2IVFL");
TH1F *met_all   = (TH1F*)all->Get("met");
//TH1F *ptJet_all   = (TH1F*)all->Get("jet1_pt_allEvents");

nJet_all->Sumw2();
nBJet_CSVv2IVFL_all->Sumw2();
met_all->Sumw2();

TH1F *rat_nJet = nJet_all->Clone(); 
TH1F *rat_nBJet_CSVv2IVFL = nBJet_CSVv2IVFL_all->Clone(); 
TH1F *rat_met = met_all->Clone(); 

rat_nJet->SetName("Ration");
rat_nJet->Divide(nJet_ttjets,nJet_all,1.,1.,"B");

rat_nBJet_CSVv2IVFL->SetName("Ration");
rat_nBJet_CSVv2IVFL->Divide(nBJet_CSVv2IVFL_ttjets,nBJet_CSVv2IVFL_all,1.,1.,"B");

rat_met->SetName("Ration");
rat_met->Divide(met_ttjets,met_all,1.,1.,"B");

rat_nJet->GetXaxis()->SetTitle("# Jets");
rat_nBJet_CSVv2IVFL->GetXaxis()->SetTitle("# B-Jets");
rat_met->GetXaxis()->SetTitle("MET (GeV)");

//TLegend* leg = new TLegend(0.6,0.6,0.9,0.89);
//leg->AddEntry(nJet_ttjets,"TTJets");
//leg->AddEntry(nJet_all,"All backgrounds");


c1->cd();
//nJet_all->Draw();
//nJet_ttjets->Draw("same");
rat_nJet->Draw();
//leg->Draw("same");
c2->cd();
rat_nBJet_CSVv2IVFL->Draw();
c3->cd();
rat_met->Draw();


}