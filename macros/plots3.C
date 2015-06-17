void plots3(){

TFile * ttjets = TFile::Open("TTJets.root");
TFile * all = TFile::Open("all.root");

TCanvas *c1 = new TCanvas("c1", "c1", 600, 800);
TCanvas *c2 = new TCanvas("c2", "c2", 600, 800);
TCanvas *c3 = new TCanvas("c3", "c3", 600, 800);

TH1F *nBJet_CSVv2IVFL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVv2IVFM_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFT_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFT");
TH1F *nBJet_CSVL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVL");
TH1F *nBJet_CSVM_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVM");
TH1F *nBJet_CSVT_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVT");
TH1F *nBJet_JPL_ttjets   = (TH1F*)ttjets->Get("nBJet_JPL");
TH1F *nBJet_JPM_ttjets   = (TH1F*)ttjets->Get("nBJet_JPM");
TH1F *nBJet_JPT_ttjets   = (TH1F*)ttjets->Get("nBJet_JPT");

nBJet_CSVv2IVFL_ttjets->Sumw2();
nBJet_CSVv2IVFM_ttjets->Sumw2();
nBJet_CSVv2IVFT_ttjets->Sumw2();
nBJet_CSVL_ttjets->Sumw2();
nBJet_CSVM_ttjets->Sumw2();
nBJet_CSVT_ttjets->Sumw2();
nBJet_JPL_ttjets->Sumw2();
nBJet_JPM_ttjets->Sumw2();
nBJet_JPT_ttjets->Sumw2();

TH1F *nBJet_CSVv2IVFL_all   = (TH1F*)all->Get("nBJet_CSVv2IVFL");
TH1F *nBJet_CSVv2IVFM_all   = (TH1F*)all->Get("nBJet_CSVv2IVFM");
TH1F *nBJet_CSVv2IVFT_all   = (TH1F*)all->Get("nBJet_CSVv2IVFT");
TH1F *nBJet_CSVL_all   = (TH1F*)all->Get("nBJet_CSVL");
TH1F *nBJet_CSVM_all   = (TH1F*)all->Get("nBJet_CSVM");
TH1F *nBJet_CSVT_all   = (TH1F*)all->Get("nBJet_CSVT");
TH1F *nBJet_JPL_all   = (TH1F*)all->Get("nBJet_JPL");
TH1F *nBJet_JPM_all   = (TH1F*)all->Get("nBJet_JPM");
TH1F *nBJet_JPT_all   = (TH1F*)all->Get("nBJet_JPT");

nBJet_CSVv2IVFL_all->Sumw2();
nBJet_CSVv2IVFM_all->Sumw2();
nBJet_CSVv2IVFT_all->Sumw2();
nBJet_CSVL_all->Sumw2();
nBJet_CSVM_all->Sumw2();
nBJet_CSVT_all->Sumw2();
nBJet_JPL_all->Sumw2();
nBJet_JPM_all->Sumw2();
nBJet_JPT_all->Sumw2();

TH1F *rat_CSVv2IVFL = nBJet_CSVv2IVFL_all->Clone(); 
TH1F *rat_CSVv2IVFM = nBJet_CSVv2IVFM_all->Clone(); 
TH1F *rat_CSVv2IVFT = nBJet_CSVv2IVFT_all->Clone(); 
TH1F *rat_CSVL = nBJet_CSVL_all->Clone(); 
TH1F *rat_CSVM = nBJet_CSVM_all->Clone(); 
TH1F *rat_CSVT = nBJet_CSVT_all->Clone(); 
TH1F *rat_JPL = nBJet_JPL_all->Clone(); 
TH1F *rat_JPM = nBJet_JPM_all->Clone(); 
TH1F *rat_JPT = nBJet_JPT_all->Clone(); 

rat_CSVv2IVFL->SetName("Ratio");
rat_CSVv2IVFL->Divide(nBJet_CSVv2IVFL_ttjets,nBJet_CSVv2IVFL_all,1.,1.,"B");

rat_CSVv2IVFM->SetName("Ratio");
rat_CSVv2IVFM->Divide(nBJet_CSVv2IVFM_ttjets,nBJet_CSVv2IVFM_all,1.,1.,"B");

rat_CSVv2IVFT->SetName("Ratio");
rat_CSVv2IVFT->Divide(nBJet_CSVv2IVFT_ttjets,nBJet_CSVv2IVFT_all,1.,1.,"B");

rat_CSVL->SetName("Ratio");
rat_CSVL->Divide(nBJet_CSVL_ttjets,nBJet_CSVL_all,1.,1.,"B");

rat_CSVM->SetName("Ratio");
rat_CSVM->Divide(nBJet_CSVM_ttjets,nBJet_CSVM_all,1.,1.,"B");

rat_CSVT->SetName("Ratio");
rat_CSVT->Divide(nBJet_CSVT_ttjets,nBJet_CSVT_all,1.,1.,"B");

rat_JPL->SetName("Ratio");
rat_JPL->Divide(nBJet_JPL_ttjets,nBJet_JPL_all,1.,1.,"B");

rat_JPM->SetName("Ratio");
rat_JPM->Divide(nBJet_JPM_ttjets,nBJet_JPM_all,1.,1.,"B");

rat_JPT->SetName("Ratio");
rat_JPT->Divide(nBJet_JPT_ttjets,nBJet_JPT_all,1.,1.,"B");

rat_CSVv2IVFL->GetXaxis()->SetTitle("# B-Jets");

rat_CSVv2IVFL->SetFillColor(1);
rat_CSVv2IVFL->SetLineColor(1);
rat_CSVv2IVFL->SetMarkerColor(1);
rat_CSVL->SetFillColor(2);
rat_CSVL->SetLineColor(2);
rat_CSVL->SetMarkerColor(2);
rat_JPL->SetFillColor(6);
rat_JPL->SetLineColor(6);
rat_JPL->SetMarkerColor(6);

rat_CSVv2IVFM->SetFillColor(1);
rat_CSVv2IVFM->SetLineColor(1);
rat_CSVv2IVFM->SetMarkerColor(1);
rat_CSVM->SetFillColor(2);
rat_CSVM->SetLineColor(2);
rat_CSVM->SetMarkerColor(2);
rat_JPM->SetFillColor(6);
rat_JPM->SetLineColor(6);
rat_JPM->SetMarkerColor(6);

rat_CSVv2IVFT->SetFillColor(1);
rat_CSVv2IVFT->SetLineColor(1);
rat_CSVv2IVFT->SetMarkerColor(1);
rat_CSVT->SetFillColor(2);
rat_CSVT->SetLineColor(2);
rat_CSVT->SetMarkerColor(2);
rat_JPT->SetFillColor(6);
rat_JPT->SetLineColor(6);
rat_JPT->SetMarkerColor(6);



TLegend* leg1 = new TLegend(0.6,0.6,0.9,0.89);
leg1->AddEntry(rat_CSVv2IVFL,"CSVv2IVFL");
leg1->AddEntry(rat_CSVL,"CSVL");
leg1->AddEntry(rat_JPL,"JPL");

TLegend* leg2 = new TLegend(0.6,0.6,0.9,0.89);
leg2->AddEntry(rat_CSVv2IVFM,"CSVv2IVFM");
leg2->AddEntry(rat_CSVM,"CSVM");
leg2->AddEntry(rat_JPM,"JPM");

TLegend* leg3 = new TLegend(0.6,0.6,0.9,0.89);
leg3->AddEntry(rat_CSVv2IVFT,"CSVv2IVFT");
leg3->AddEntry(rat_CSVT,"CSVT");
leg3->AddEntry(rat_JPT,"JPT");

c1->cd();
rat_CSVv2IVFL->Draw();
rat_CSVL->Draw("same");
rat_JPL->Draw("same");
leg1->Draw("same");
c2->cd();
rat_CSVv2IVFM->Draw();
rat_CSVM->Draw("same");
rat_JPM->Draw("same");
leg2->Draw("same");
c3->cd();
rat_CSVv2IVFT->Draw();
rat_CSVT->Draw("same");
rat_JPT->Draw("same");
leg3->Draw("same");



}