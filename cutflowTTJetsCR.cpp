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
    _cutFlow.insert(pair<string,int>("6_HasPVJet", 0) );
    _cutFlow.insert(pair<string,int>("7_HasSVJet", 0) );
    _cutFlow.insert(pair<string,int>("8_MET_2", 0) );
    _cutFlow.insert(pair<string,int>("9_SVPVDistance", 0) );

    makeHist( "met", 600, 0., 600., "MET [GeV]", "Number of Events" );
    makeHist( "nJet", 40, 0, 40, "# Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFL", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFM", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_CSVv2IVFT", 10, 0, 10, "# B-Jets", "Number of Events" );     
    makeHist( "nBJet_JPL", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_JPM", 10, 0, 10, "# B-Jets", "Number of Events" ); 
    makeHist( "nBJet_JPT", 10, 0, 10, "# B-Jets", "Number of Events" );
    makeHist( "nBJet_TCHPT", 10, 0, 10, "# B-Jets", "Number of Events" );
    makeHist( "NBJets_CSVv2IVFL_met", 600, 0., 600, "MET [GeV]", "Number of Events" ); 
    makeHist( "NBJets_CSVv2IVFM_met", 600, 0., 600, "MET [GeV]", "Number of Events" ); 
    makeHist( "NBJets_CSVv2IVFT_met", 600, 0., 600, "MET [GeV]", "Number of Events" );     
    makeHist( "NBJets_JPL_met", 600, 0., 600, "MET [GeV]", "Number of Events" ); 
    makeHist( "NBJets_JPM_met", 600, 0., 600, "MET [GeV]", "Number of Events" ); 
    makeHist( "NBJets_JPT_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "NBJets_TCHPT_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "NBJets_CSVv2IVFL_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "NBJets_CSVv2IVFM_nJets", 40, 0, 40, "# Jets", "Number of Events");  
    makeHist( "NBJets_CSVv2IVFT_nJets", 40, 0, 40, "# Jets", "Number of Events");     
    makeHist( "NBJets_JPL_nJets", 40, 0, 40, "# Jets", "Number of Events");  
    makeHist( "NBJets_JPM_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "NBJets_JPT_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "NBJets_TCHPT_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "HasPVJet_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "HasPVJet_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "HasSVJet_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "HasSVJet_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "selected_distances", 40, 0., 40., "Distance between PV and SV [mm]", "Number of PV-SV pairs" );
    makeHist( "selected_met", 50, 0., 500., "MET [GeV]", "Number of Events" );
    makeHist( "selected_nPVJet", 4, -0.5, 3.5, "# PV with at least 1 Jet > 75 GeV", "Number of Events" );
    makeHist( "selected_nJetsToSV", 7, -0.5, 6.5, "# Jets associated to SV", "Number of Vertices" ); 
    makeHist( "selected_nSV", 5, -0.5, 4.5, "# SV with at least 1 Jet", "Number of Events" ); 
    makeHist( "nBjetAtSV", 5, -0.5, 4.5, "Number of b-jets associated to SV", "Number of SV" );
    makeHist( "MET_2_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "MET_2_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    makeHist( "SVPVDistance_met", 600, 0., 600, "MET [GeV]", "Number of Events" );
    makeHist( "SVPVDistance_nJets", 40, 0, 40, "# Jets", "Number of Events"); 
    
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

        int nJets = 0;

        for( unsigned int iJet = 0; iJet < recoJet_pt->size(); ++iJet ) {
            if( recoJet_pt->at(iJet) > JET_PT_CUT_SV && fabs(recoJet_eta->at(iJet)) < JET_ETA_CUT ) nJets += 1;
        }

        _histograms1D.at("nJet").Fill(nJets, evtWeight );

        if ( nJets >= N_JET_CUT ) { 
        	_cutFlow.at( "3_NJets" ) += 1;
        
        	_histograms1D.at("met").Fill(met, evtWeight );

        	if( met > MET_CUT ) { 
        			_cutFlow.at("4_MET") += 1;
        			
        			int nBjets_CSVv2IVFL = 0;
        			int nBjets_CSVv2IVFM = 0;
        			int nBjets_CSVv2IVFT = 0;
        			int nBjets_TCHPT = 0;
        			int nBjets_JPL = 0;
        			int nBjets_JPM = 0;
        			int nBjets_JPT = 0;
            
        			for( unsigned int iiJet = 0; iiJet < recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->size(); ++iiJet ){
        				if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.423 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_CSVv2IVFL += 1;
        				if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.814 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_CSVv2IVFM += 1;
        				if ( recoJet_btag_combinedInclusiveSecondaryVertexV2BJetTags->at(iiJet) > 0.941 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_CSVv2IVFT += 1;
        			}
        			for( unsigned int iiJet = 0; iiJet < recoJet_btag_jetProbabilityBJetTags->size(); ++iiJet ){
        				if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.275 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_JPL += 1;
        				if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.545 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_JPM += 1;
        				if ( recoJet_btag_jetProbabilityBJetTags->at(iiJet) > 0.790 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_JPT += 1;
        			}
        			for( unsigned int iiJet = 0; iiJet < recoJet_btag_trackCountingHighPurBJetTags->size(); ++iiJet ){
        				if ( recoJet_btag_trackCountingHighPurBJetTags->at(iiJet) > 3.41 && recoJet_pt->at(iiJet) > JET_PT_CUT_SV) nBjets_TCHPT += 1;
        			}

        			_histograms1D.at("nBJet_CSVv2IVFL").Fill(nBjets_CSVv2IVFL, evtWeight );
        			_histograms1D.at("nBJet_CSVv2IVFM").Fill(nBjets_CSVv2IVFM, evtWeight );
        			_histograms1D.at("nBJet_CSVv2IVFT").Fill(nBjets_CSVv2IVFT, evtWeight );
        			_histograms1D.at("nBJet_JPT").Fill(nBjets_JPT, evtWeight );
        			_histograms1D.at("nBJet_JPM").Fill(nBjets_JPM, evtWeight );
        			_histograms1D.at("nBJet_JPL").Fill(nBjets_JPL, evtWeight );
        			_histograms1D.at("nBJet_TCHPT").Fill(nBjets_TCHPT, evtWeight );
        			
        			if( nBjets_CSVv2IVFL >= N_BJET_CUT ){ 
        				_cutFlow.at("5_NBJets_CSVv2IVFL") += 1; 
        				_histograms1D.at("NBJets_CSVv2IVFL_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_CSVv2IVFL_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_CSVv2IVFM >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_CSVv2IVFM") += 1; 
                    	_histograms1D.at("NBJets_CSVv2IVFM_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_CSVv2IVFM_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_CSVv2IVFT >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_CSVv2IVFT") += 1; 
                    	_histograms1D.at("NBJets_CSVv2IVFT_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_CSVv2IVFT_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_JPT >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_JPT") += 1; 
                    	_histograms1D.at("NBJets_JPT_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_JPT_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_JPM >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_JPM") += 1; 
                    	_histograms1D.at("NBJets_JPM_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_JPM_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_JPL >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_JPL") += 1; 
                    	_histograms1D.at("NBJets_JPL_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_JPL_nJets").Fill(nJets, evtWeight );
        			}
        			if( nBjets_TCHPT >= N_BJET_CUT ){ 
                    	_cutFlow.at("5_NBJets_TCHPT") += 1; 
                    	_histograms1D.at("NBJets_TCHPT_met").Fill(met, evtWeight );
        				_histograms1D.at("NBJets_TCHPT_nJets").Fill(nJets, evtWeight );
        			}   
                      
            	}
        }    
        
        
        // now assign jets to the vertices:
        vector<int> nJetsToPV( vertex_x->size(), 0 );
        vector<int> nJetsToSV( secVertex_x->size(), 0 );
        vector<vector<int> > idJetsToPV;
        vector<vector<int> > idJetsToSV;
        for( unsigned int iVtx = 0; iVtx < vertex_x->size(); ++iVtx ) {
        	vector<int> idx;
        	idJetsToPV.push_back( idx );
        }
        for( unsigned int iVtx = 0; iVtx < secVertex_x->size(); ++iVtx ) {
        	vector<int> idx;
        	idJetsToSV.push_back( idx );
        }
        
        for( unsigned int iJet = 0; iJet < recoJet_pt->size(); ++iJet ) {
        	if( recoJet_pt->at(iJet) < JET_PT_CUT_SV ) continue;
        	if( fabs(recoJet_eta->at(iJet)) > JET_ETA_CUT ) continue;
            
        	//calculate jet vertex position:
        	unsigned int nCons = 0;
        	double weightednCons = 0.;
        	vector<double> error(3,0.);
        	vector<double> position = CalculateVertex( recoJet_constVertex_x->at(iJet), recoJet_constVertex_y->at(iJet), recoJet_constVertex_z->at(iJet), recoJet_const_pt->at(iJet), recoJet_const_charge->at(iJet), recoJet_const_closestVertex_d->at(iJet), nCons, weightednCons, error );
            
        	int nMatch = 0;
        	for( unsigned int iVtx = 0; iVtx < vertex_x->size(); ++iVtx ) {
        		if( fabs(position.at(0) - vertex_x->at(iVtx) ) < 1.e-10 &&
        			fabs(position.at(1) - vertex_y->at(iVtx) ) < 1.e-10 &&
                	fabs(position.at(2) - vertex_z->at(iVtx) ) < 1.e-10 ) {
                	nJetsToPV.at(iVtx) += 1;
                	idJetsToPV.at(iVtx).push_back( iJet );
                	nMatch += 1;
                	}
            }
            for( unsigned int iVtx = 0; iVtx < secVertex_x->size(); ++iVtx ) {
            	if( fabs(position.at(0) - secVertex_x->at(iVtx) ) < 1.e-10 &&
            		fabs(position.at(1) - secVertex_y->at(iVtx) ) < 1.e-10 &&
                	fabs(position.at(2) - secVertex_z->at(iVtx) ) < 1.e-10 ) {
                
                	nJetsToSV.at(iVtx) += 1;
                	idJetsToSV.at(iVtx).push_back( iJet );
                	nMatch += 1;

                	}
            }
            if( nMatch > 1 ) {
            	cout << "WARNING! ASSOCIATED JET TO MORE THAN 1 VERTEX ?!" << endl;
            }
        }
        
        // now count the number of vertices with jets:
        vector<int> PVWithJet;
        vector<int> SVWithJets;
        vector<int> SVWith2Jets;
        for( unsigned int iPV = 0; iPV < vertex_x -> size(); ++iPV ) {
        	bool hasJetPV = false;
        	for( unsigned int iiJet = 0; iiJet < idJetsToPV.at(iPV).size(); ++iiJet ) {
        		int iJet = idJetsToPV.at(iPV).at(iiJet);
        		if( recoJet_pt->at(iJet) > JET_PT_CUT_PV ) hasJetPV = true;
        	}
        	if( hasJetPV ) PVWithJet.push_back( iPV );
        }
        for( unsigned int iSV = 0; iSV < secVertex_x->size(); ++iSV ) {
        	if( idJetsToSV.at(iSV).size() > 0 ) SVWithJets.push_back( iSV );
        	if( idJetsToSV.at(iSV).size() > 1 ) SVWith2Jets.push_back( iSV );
        }
        
         // and run the selection:
         if( PVWithJet.size() == 1 ) {
         	 _cutFlow.at("6_HasPVJet") += 1;
        
         	 _histograms1D.at("HasPVJet_met").Fill(met, evtWeight );
         	 _histograms1D.at("HasPVJet_nJets").Fill(nJets, evtWeight );

         	 if( SVWithJets.size() > 0 ) {
         	 	 _cutFlow.at("7_HasSVJet") += 1;
            
         	 	 _histograms1D.at("HasSVJet_met").Fill(met, evtWeight );
         	 	 _histograms1D.at("HasSVJet_nJets").Fill(nJets, evtWeight );
            
         	 	 _histograms1D.at("selected_met").Fill( met, evtWeight );
         	 	 _histograms1D.at("selected_nPVJet").Fill( PVWithJet.size(), evtWeight  ); 
         	 	 _histograms1D.at("selected_nSV").Fill( SVWithJets.size(), evtWeight  );
                
         	 	 for( unsigned int iSV = 0; iSV < SVWithJets.size(); ++iSV ) {
         	 	 	 _histograms1D.at("selected_nJetsToSV").Fill( idJetsToSV.at(SVWithJets.at(iSV)).size(), evtWeight  );
         	 	 }
         	 	 vector<double> allDistances;

         	 	 for( unsigned int iPV = 0; iPV < PVWithJet.size(); ++iPV ) {
         	 	 	 double thispv_x = vertex_x->at(PVWithJet.at(iPV));
         	 	 	 double thispv_y = vertex_y->at(PVWithJet.at(iPV));
         	 	 	 double thispv_z = vertex_z->at(PVWithJet.at(iPV));
         	 	 	 for( unsigned int iSV = 0; iSV < SVWithJets.size(); ++iSV ) {
         	 	 	 	double thissv_x = secVertex_x->at(SVWithJets.at(iSV));
         	 	 	 	double thissv_y = secVertex_y->at(SVWithJets.at(iSV));
                    	double thissv_z = secVertex_z->at(SVWithJets.at(iSV));
                    	double dx = thissv_x - thispv_x;
                    	double dy = thissv_y - thispv_y;
                    	double dz = thissv_z - thispv_z;
                    	double dist = 10.*sqrt( dx*dx + dy*dy + dz*dz );
                    	_histograms1D.at("selected_distances").Fill( dist, evtWeight);
                    	allDistances.push_back( dist );

                    	if( met > MET_CUT ) {
                    		_cutFlow.at("8_MET_2") += 1;
                    		
                    		_histograms1D.at("MET_2_met").Fill( met, evtWeight);
                    		_histograms1D.at("MET_2_nJets").Fill( nJets, evtWeight);
                    		
                    	
                    		bool hasLargeDistance = false;
                    		for( unsigned int kDist = 0; kDist < allDistances.size(); ++kDist ) {
                    			if( allDistances.at(kDist) > 5. ) hasLargeDistance = true;	
                    		}
                    	
                    		if( hasLargeDistance ){
                    			_cutFlow.at("9_SVPVDistance") =+ 1;  
                    			
                    			_histograms1D.at("SVPVDistance_met").Fill( met, evtWeight);
                    			_histograms1D.at("SVPVDistance_nJets").Fill( nJets, evtWeight);
                    		}
                    	}
                     }
                 }
             }
         }

        return;
}