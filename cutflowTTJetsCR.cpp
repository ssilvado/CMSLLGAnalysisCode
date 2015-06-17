#include "LLGAnalysis.h"

void LLGAnalysis::SetupTTJetsCR() {

    // setup the cutflow
    _cutFlow.insert(pair<string,int>("0_NoCut", 0) );
    _cutFlow.insert(pair<string,int>("1_Trigger", 0) );
    _cutFlow.insert(pair<string,int>("2_AtLeastOneLepton", 0) );
    _cutFlow.insert(pair<string,int>("3_NJets", 0) );
    _cutFlow.insert(pair<string,int>("4_MET", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_CSVv2IVFL", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_CSVv2IVFT", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_CSVv2IVFM", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_JPL", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_JPT", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_JPM", 0) );
    _cutFlow.insert(pair<string,int>("5_NBJets_TCHPT", 0) );

    makeHist( "met", 50, 0., 500., "MET [GeV]", "Number of Events" );
    makeHist( "nJet", 100, 0, 100, "# Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFL", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFM", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFT", 10, 0, 10, "# B-Jets", "Number of Events" );     
    makeHist( "nBJet_JPL", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_JPM", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_JPT", 10, 0, 10, "# B-Jets", "Number of Events" );
    makeHist( "nBJet_TCHPT", 10, 0, 10, "# B-Jets", "Number of Events" );
    makeHist( "pt_BJet_CSVv2IVFL", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_CSVv2IVFM", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_CSVv2IVFT", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_JPT", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_JPL", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_JPM", 50, 0., 100., "pT B-Jets", "Number of Events" );
    makeHist( "pt_BJet_TCHPT", 50, 0., 100., "pT B-Jets", "Number of Events" );
    
    return;

}

void LLGAnalysis::TTJetsCRSelection() {

    	_cutFlow.at("0_NoCut") += 1;

    	bool passTrigger = false;
    	for( unsigned int iTrig = 0; iTrig < triggerNames->size(); ++iTrig ) {
        	if( (triggerNames->at(iTrig) == "HLT_PFJet260_v1" || triggerNames->at(iTrig) == "HLT_PFMET170_NoiseCleaned_v1") && triggerBits->at(iTrig) == 1 ) passTrigger = true;
        }

    	if( !passTrigger ) return; 
    	_cutFlow.at("1_Trigger") += 1;

        // lepton veto:
        bool hasMuon = false;
        for( unsigned int im = 0; im < muon_px->size(); ++im ) {
            double pt = sqrt(muon_px->at(im)*muon_px->at(im) + muon_py->at(im)*muon_py->at(im));
            if( pt > MUON_PT_CUT ) hasMuon = true;
        }
        
        bool hasElectron = false;
        for( unsigned int im = 0; im < electron_px->size(); ++im ) {
            double pt = sqrt(electron_px->at(im)*electron_px->at(im) + electron_py->at(im)*electron_py->at(im));
            if( pt > ELECTRON_PT_CUT ) hasElectron = true;
        }
        
        if( !hasMuon && !hasElectron ) return;
        _cutFlow.at("2_AtLeastOneLepton") += 1;
        
        //bool hasBjet = false;
        int nBjets_CSVv2IVFL = 0;
        int nBjets_CSVv2IVFM = 0;
        int nBjets_CSVv2IVFT = 0;
        int nBjets_TCHPT = 0;
        int nBjets_JPL = 0;
        int nBjets_JPM = 0;
        int nBjets_JPT = 0;
                
        int nJets = 0;

        for( unsigned int iJet = 0; iJet < recoJet_pt->size(); ++iJet ) {
            if( recoJet_pt->at(iJet) < JET_PT_CUT_SV ) continue;
            if( fabs(recoJet_eta->at(iJet)) > JET_ETA_CUT ) continue;
            
            nJets += 1;

        }

        //int nJets = recoJet_pt->size();
        _histograms1D.at("nJet").Fill(nJets, evtWeight );

        if ( nJets >= N_JET_CUT ) { 
        	_cutFlow.at( "3_NJets" ) += 1;
        
        	_histograms1D.at("met").Fill(met, evtWeight );

        	if( met > MET_CUT ) { 
        			_cutFlow.at("4_MET") += 1;

        			_histograms1D.at("nBJet_CSVv2IVFL").Fill(nBjets_CSVv2IVFL, evtWeight );
        			_histograms1D.at("nBJet_CSVv2IVFM").Fill(nBjets_CSVv2IVFM, evtWeight );
        			_histograms1D.at("nBJet_CSVv2IVFT").Fill(nBjets_CSVv2IVFT, evtWeight );
        			_histograms1D.at("nBJet_JPT").Fill(nBjets_JPT, evtWeight );
        			_histograms1D.at("nBJet_JPM").Fill(nBjets_JPM, evtWeight );
        			_histograms1D.at("nBJet_JPL").Fill(nBjets_JPL, evtWeight );
        			_histograms1D.at("nBJet_TCHPT").Fill(nBjets_TCHPT, evtWeight );
           
                      for( unsigned int iiJet = 0; iiJet < recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->size(); ++iiJet ){
                      	  	_histograms1D.at("pt_BJet_CSVv2IVFL").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	_histograms1D.at("pt_BJet_CSVv2IVFM").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	_histograms1D.at("pt_BJet_CSVv2IVFT").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	
                      	  	if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.423 && recoJet_pt->at(iiJet) > 30.) nBjets_CSVv2IVFL += 1;
                      	  	if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.814 && recoJet_pt->at(iiJet) > 30.) nBjets_CSVv2IVFM += 1;
                      	  	if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.941 && recoJet_pt->at(iiJet) > 30.) nBjets_CSVv2IVFT += 1;
                      }
        
                      for( unsigned int iiJet = 0; iiJet < recoJet_btag_jetProbabilityBJetTags->size(); ++iiJet ){
                      	  	_histograms1D.at("pt_BJet_JPL").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	_histograms1D.at("pt_BJet_JPM").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	_histograms1D.at("pt_BJet_JPT").Fill(recoJet_pt->at(iiJet), evtWeight );

                      	  	if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.275 && recoJet_pt->at(iiJet) > 30.) nBjets_JPL += 1;
                      	  	if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.545 && recoJet_pt->at(iiJet) > 30.) nBjets_JPM += 1;
                      	  	if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.790 && recoJet_pt->at(iiJet) > 30.) nBjets_JPT += 1;
                      }
                      
                      for( unsigned int iiJet = 0; iiJet < recoJet_btag_trackCountingHighPurBJetTags->size(); ++iiJet ){
                      	  	_histograms1D.at("pt_BJet_TCHPT").Fill(recoJet_pt->at(iiJet), evtWeight );
                      	  	if ( recoJet_btag_trackCountingHighPurBJetTags->at(iiJet) > 3.41 && recoJet_pt->at(iiJet) > 30.) nBjets_TCHPT += 1;
                      }
       
                      if( nBjets_CSVv2IVFL >= N_BJET_CUT ) _cutFlow.at("5_NBJets_CSVv2IVFL") += 1;
                      if( nBjets_CSVv2IVFM >= N_BJET_CUT ) _cutFlow.at("5_NBJets_CSVv2IVFM") += 1;
                      if( nBjets_CSVv2IVFT >= N_BJET_CUT ) _cutFlow.at("5_NBJets_CSVv2IVFT") += 1;
                      if( nBjets_JPT >= N_BJET_CUT ) _cutFlow.at("5_NBJets_JPT") += 1;
                      if( nBjets_JPM >= N_BJET_CUT ) _cutFlow.at("5_NBJets_JPM") += 1;
                      if( nBjets_JPL >= N_BJET_CUT ) _cutFlow.at("5_NBJets_JPL") += 1;
                      if( nBjets_TCHPT >= N_BJET_CUT ) _cutFlow.at("5_NBJets_TCHPT") += 1;
                      
            }
        }        

        return;
}