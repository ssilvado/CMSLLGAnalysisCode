void MyCalcEff()
{
	TCanvas *c1 = new TCanvas("c1", "c1", 600, 800);
	
	TFile * ttjets = TFile::Open("TTJets.root");
    TFile * all = TFile::Open("all.root");
    
    TH1F *nBJet_CSVv2IVFL_ttjets   = (TH1F*)ttjets->Get("nBJet_CSVv2IVFL");
    TH1F *nBJet_CSVv2IVFL_all   = (TH1F*)all->Get("nBJet_CSVv2IVFL");

	//char *dummy;
	//hist3.Divide(hist2,hist1,hist3,
	hist3->Divide(nBJet_CSVv2IVFL_all,nBJet_CSVv2IVFL_ttjets,(float)1.0,(float)1.0,"B");

	Int_t bins = nBJet_CSVv2IVFL_ttjets->GetNbinsX();
	Float_t histlowedge = nBJet_CSVv2IVFL_ttjets->GetBinCenter(1) - nBJet_CSVv2IVFL_ttjets->GetBinWidth(1)/2.;
	Float_t histupedge =nBJet_CSVv2IVFL_ttjets->GetBinCenter(nbins) + nBJet_CSVv2IVFL_ttjets->GetBinWidth(nbins)/2.
	
	//Output
    TH1F *hist3 = new TH1F("hist3","hist3",bins,histlowedge,histupedge); 
    hist3->Sumw2();

	Double_t error[bins];

	for(Int_t i = 0; i < bins; ++i)
	{
		Double_t h1 = nBJet_CSVv2IVFL_ttjets->GetBinContent(i);
		Double_t h2 = nBJet_CSVv2IVFL_all->GetBinContent(i);
		error[i] = (sqrt((h1 - h1)*h2/h1)/h1);
	}
	hist3->SetError((double *)error);
	
	c1->cd();
    hist3->Draw();
   
}
