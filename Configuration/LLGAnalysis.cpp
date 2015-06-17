#include "LLGAnalysis.h"
#include "TGraphAsymmErrors.h"
#include <fstream>

LLGAnalysis* LLGAnalysis::GetInstance( char *configFileName ) {
    if( !_instance ) {
        _instance = new LLGAnalysis( configFileName );
    }
    return _instance;
}

LLGAnalysis::LLGAnalysis( char *configFileName ) {
    
    
    // Setup the default values for the cuts:
    JET_PT_CUT = 20;
    JET_ETA_CUT = 5.0;
    MUON_PT_CUT = 10.;
    ELECTRON_PT_CUT = 10.;
    MET_CUT = 150.;
    
    ifstream configFile( configFileName, ios::in );
    while( configFile.good() ) {
        string key, value;
        configFile >> key >> ws >> value;
        if( configFile.eof() ) break;
        if( key == "InputFile"        ) _inputFileNames.push_back( value ); 
        if( key == "InputTree"        ) _inputTreeName = value; 
        if( key == "JET_PT_CUT"       ) JET_PT_CUT = atof(value.c_str());
        if( key == "JET_ETA_CUT"      ) JET_ETA_CUT = atof(value.c_str());
        if( key == "MUON_PT_CUT"      ) MUON_PT_CUT = atof(value.c_str()); 
        if( key == "ELECTRON_PT_CUT"  ) ELECTRON_PT_CUT = atof(value.c_str()); 
        if( key == "MET_CUT"          ) MET_CUT = atof(value.c_str()); 
    }
}

void LLGAnalysis::MakeEfficiencyPlot( TH1D hpass, TH1D htotal, TCanvas *c, string triggerName ) {
    
    TGraphAsymmErrors geff;
    geff.BayesDivide( &hpass, &htotal );
    geff.GetXaxis()->SetTitle( hpass.GetXaxis()->GetTitle() );
    string ytitle = "#varepsilon (" + triggerName + ")";
    geff.GetYaxis()->SetTitle( ytitle.c_str() );
    string efftitle = "efficiency_" + triggerName;
    geff.SetNameTitle(efftitle.c_str(), efftitle.c_str());
    geff.SetMarkerColor(kBlue);
    geff.Draw("APZ"); 
    for( vector<string>::iterator itr_f = _plotFormats.begin(); itr_f != _plotFormats.end(); ++itr_f ) {
        string thisPlotName = efftitle + (*itr_f);
        c->Print( thisPlotName.c_str() );
    }

}

vector<double> LLGAnalysis::CalculateVertex( vector<double> x, vector<double> y, vector<double> z, vector<double> weight, vector<int> charge, vector<double> distance, unsigned int &nConsidered, double &weightednConsidered, vector<double> &error ) {
   
   nConsidered = 0;
   vector<double> diff_x;
   vector<double> diff_y;
   vector<double> diff_z;
   vector<double> score;
   
   for( unsigned int i = 0; i < x.size(); ++i ) {
      if( charge.at(i) == 0 ) continue;
      nConsidered += 1;
      bool knownPoint = false;
      int iKnown = -1;
      for( unsigned int i2 = 0; i2 < diff_x.size(); ++i2 ) {
        if( fabs( diff_x.at(i2) - x.at(i) ) < 1.e-10 && fabs( diff_y.at(i2) - y.at(i) ) < 1.e-10 && fabs( diff_z.at(i2) - z.at(i) ) < 1.e-10 ) {
            knownPoint = true;
            iKnown = i2;
        }
      }
    
      if( knownPoint ) {
        score.at(iKnown) += weight.at(i)/distance.at(i);
      }
      else {
        diff_x.push_back( x.at(i) );
        diff_y.push_back( y.at(i) );
        diff_z.push_back( z.at(i) );
        score.push_back( weight.at(i)/distance.at(i) );
      }
   }
    
   double scoreMax = 0.;
   vector<double> mean(3, -10000.);
   for( unsigned int i = 0; i < diff_x.size(); ++i ) {
        if ( score.at(i) > scoreMax ) {
            scoreMax = score.at(i);
            mean.at(0) = diff_x.at(i);
            mean.at(1) = diff_y.at(i);
            mean.at(2) = diff_z.at(i);
        }
    }
    return mean;
}

void LLGAnalysis::makeHist( string nametitle, int nbinsx, double xmin, double xmax, int nbinsy, double ymin, double ymax, string xtitle, string ytitle, string ztitle, string drawOption, double xAxisOffset, double yAxisOffset, double zAxisOffset ) {

    TH2D hist(nametitle.c_str(), nametitle.c_str(), nbinsx, xmin, xmax, nbinsy, ymin, ymax );
    hist.GetXaxis()->SetTitle( xtitle.c_str() );
    hist.GetYaxis()->SetTitle( ytitle.c_str() );
    hist.GetZaxis()->SetTitle( ztitle.c_str() );
    hist.GetXaxis()->SetTitleOffset( xAxisOffset );
    hist.GetYaxis()->SetTitleOffset( yAxisOffset );
    hist.GetZaxis()->SetTitleOffset( zAxisOffset );
    _histograms2D.insert( pair<string, TH2D>( nametitle, hist ) );
    _histograms2DDrawOptions.insert( pair<string,string>( nametitle, drawOption ) );

}

void LLGAnalysis::makeHist( string nametitle, int nbins, double xmin, double xmax, string xtitle, string ytitle, string drawOption, double xAxisOffset, double yAxisOffset ) {

    TH1D hist(nametitle.c_str(), nametitle.c_str(), nbins, xmin, xmax );
    hist.GetXaxis()->SetTitle( xtitle.c_str() );
    hist.GetYaxis()->SetTitle( ytitle.c_str() );
    hist.GetYaxis()->SetTitleOffset( yAxisOffset );
    hist.GetXaxis()->SetTitleOffset( xAxisOffset );
    _histograms1D.insert( pair<string, TH1D>( nametitle, hist ) );
    _histograms1DDrawOptions.insert( pair<string,string>( nametitle, drawOption ) );
}

bool LLGAnalysis::Init() {
    
    gROOT->ProcessLine(".L Loader.C+");
    gROOT->ProcessLine("#include <vector>");
    gSystem->Load("Loader_C.so");
    setStyle(1.0,true,0.15);
   
    _inputTree = new TChain(_inputTreeName.c_str());
    for( vector<string>::iterator itr = _inputFileNames.begin(); itr != _inputFileNames.end(); ++itr ) {
        _inputTree -> Add( (*itr).c_str() );  
    }

    // create the histograms and add them to the list
    makeHist( "selected_distances", 40, 0., 40., "Distance between PV and SV [mm]", "Number of PV-SV pairs" );
    makeHist( "selected_met", 50, 0., 500., "MET [GeV]", "Number of Events" );
    makeHist( "selected_nPV75", 4, -0.5, 3.5, "# PV with at least 1 Jet > 75 GeV", "Number of Events" );
    makeHist( "selected_nJetsToSV", 7, -0.5, 6.5, "# Jets associated to SV", "Number of Vertices" ); 
    makeHist( "selected_nSV", 5, -0.5, 4.5, "# SV with at least 1 Jet", "Number of Events" ); 
    makeHist( "MET_allEvents", 50, 0., 2000., "MET [GeV]", "Number of Events" );
    makeHist( "MET_HLT_PFMET170_NoiseCleaned_v1", 50, 0., 2000., "MET [GeV]", "Number of Events" );
    makeHist( "jet1_pt_allEvents", 50, 0., 1000., "Leading Jet p_{T} [GeV]", "Number of Events");
    makeHist( "jet1_pt_HLT_PFJet260_v1", 50, 0., 1000., "Leading Jet p_{T} [GeV]", "Number of Events");

    // allocate memory for all the variables
    recoJet_pt = new vector<double>;
    recoJet_phi = new vector<double>;
    recoJet_eta = new vector<double>;
    recoJet_secVertex3D = new vector<double>;
    recoJet_secVertexSig = new vector<double>;
    recoJet_bJetTag = new vector<double>;
    recoJet_closestVertex_x = new vector<double>;
    recoJet_closestVertex_y = new vector<double>;
    recoJet_closestVertex_z = new vector<double>;
    
    muon_px = new vector<double>;
    muon_py = new vector<double>;
    muon_pz = new vector<double>;
    muon_phi = new vector<double>;
    muon_eta = new vector<double>;
    
    electron_px = new vector<double>;
    electron_py = new vector<double>;
    electron_pz = new vector<double>;
    electron_phi = new vector<double>;
    electron_eta = new vector<double>;
    
    triggerBits = new vector<int>;
    triggerNames = new vector<string>;
    
    recoJet_constVertex_x = new vector<vector<double> >;
    recoJet_constVertex_y = new vector<vector<double> >;
    recoJet_constVertex_z = new vector<vector<double> >;
    recoJet_constclosestVertex_x = new vector<vector<double> >;
    recoJet_constclosestVertex_y = new vector<vector<double> >;
    recoJet_constclosestVertex_z = new vector<vector<double> >;
    recoJet_const_pt = new vector<vector<double> >;
    recoJet_const_closestVertex_dxy = new vector<vector<double> >;
    recoJet_const_closestVertex_dz = new vector<vector<double> >;
    recoJet_const_closestVertex_d = new vector<vector<double> >;
    recoJet_const_charge = new vector<vector<int> >;

    vertex_x = new vector<double>;
    vertex_y = new vector<double>;
    vertex_z = new vector<double>;
    secVertex_x = new vector<double>;
    secVertex_y = new vector<double>;
    secVertex_z = new vector<double>;
    vertex_nTracks = new vector<double>;
    vertex_pt = new vector<double>;
    
    // and set the branch addresses
    _inputTree->SetBranchAddress("RecoMuon_px", &muon_px );
    _inputTree->SetBranchAddress("RecoMuon_py", &muon_py );
    _inputTree->SetBranchAddress("RecoMuon_pz", &muon_pz );
    _inputTree->SetBranchAddress("RecoMuon_eta", &muon_eta );
    _inputTree->SetBranchAddress("RecoMuon_phi", &muon_phi );
    _inputTree->SetBranchAddress("RecoElectron_px", &electron_px );
    _inputTree->SetBranchAddress("RecoElectron_py", &electron_py );
    _inputTree->SetBranchAddress("RecoElectron_pz", &electron_pz );
    _inputTree->SetBranchAddress("RecoElectron_eta", &electron_eta );
    _inputTree->SetBranchAddress("RecoElectron_phi", &electron_phi );
    _inputTree->SetBranchAddress("TriggerNames", &triggerNames );
    _inputTree->SetBranchAddress("TriggerBits", &triggerBits );
    _inputTree->SetBranchAddress("RecoJet_pt", &recoJet_pt );
    _inputTree->SetBranchAddress("RecoJet_eta", &recoJet_eta );
    _inputTree->SetBranchAddress("RecoJet_phi", &recoJet_phi );
    _inputTree->SetBranchAddress("RecoJet_secVertex3D", &recoJet_secVertex3D );
    _inputTree->SetBranchAddress("RecoJet_secVertexSig", &recoJet_secVertexSig );
    _inputTree->SetBranchAddress("RecoJet_bJetTag", &recoJet_bJetTag );
    _inputTree->SetBranchAddress("RecoJet_closestVertex_x", &recoJet_closestVertex_x);
    _inputTree->SetBranchAddress("RecoJet_closestVertex_y", &recoJet_closestVertex_y);
    _inputTree->SetBranchAddress("RecoJet_closestVertex_z", &recoJet_closestVertex_z);
    _inputTree->SetBranchAddress("RecoJet_constVertex_x", &recoJet_constVertex_x );
    _inputTree->SetBranchAddress("RecoJet_constVertex_y", &recoJet_constVertex_y );
    _inputTree->SetBranchAddress("RecoJet_constVertex_z", &recoJet_constVertex_z );
    _inputTree->SetBranchAddress("RecoJet_constclosestVertex_x", &recoJet_constclosestVertex_x );
    _inputTree->SetBranchAddress("RecoJet_constclosestVertex_y", &recoJet_constclosestVertex_y );
    _inputTree->SetBranchAddress("RecoJet_constclosestVertex_z", &recoJet_constclosestVertex_z );
    _inputTree->SetBranchAddress("RecoJet_const_pt", &recoJet_const_pt );
    _inputTree->SetBranchAddress("RecoJet_const_charge", &recoJet_const_charge );
    _inputTree->SetBranchAddress("RecoJet_const_closestVertex_dxy", &recoJet_const_closestVertex_dxy );
    _inputTree->SetBranchAddress("RecoJet_const_closestVertex_dz", &recoJet_const_closestVertex_dz );
    _inputTree->SetBranchAddress("RecoJet_const_closestVertex_d", &recoJet_const_closestVertex_d );
    _inputTree->SetBranchAddress("RecoVertex_x", &vertex_x );
    _inputTree->SetBranchAddress("RecoVertex_y", &vertex_y );
    _inputTree->SetBranchAddress("RecoVertex_z", &vertex_z );
    _inputTree->SetBranchAddress("RecoSecVertex_x", &secVertex_x );
    _inputTree->SetBranchAddress("RecoSecVertex_y", &secVertex_y );
    _inputTree->SetBranchAddress("RecoSecVertex_z", &secVertex_z );
    _inputTree->SetBranchAddress("RecoVertex_nTracks", &vertex_nTracks );
    _inputTree->SetBranchAddress("RecoVertex_pt", &vertex_pt );
    _inputTree->SetBranchAddress("MET", &met );


    // setup the cutflow
    _cutFlow.insert(pair<string,int>("NoCut", 0) );
    _cutFlow.insert(pair<string,int>("Trigger", 0) );
    _cutFlow.insert(pair<string,int>("MuonVeto", 0) );
    _cutFlow.insert(pair<string,int>("ElectronVeto", 0) );
    _cutFlow.insert(pair<string,int>("HasPV75", 0) );
    _cutFlow.insert(pair<string,int>("HasSV20", 0) );
    _cutFlow.insert(pair<string,int>("MET", 0) );
    _cutFlow.insert(pair<string,int>("SVPVDistance", 0) );
    
    // crate eps, png and pdf in the end
    _plotFormats.push_back(".eps");
    _plotFormats.push_back(".png");
    _plotFormats.push_back(".pdf");

    // finally set the style
    setStyle();

    return true;
}

void LLGAnalysis::RunEventLoop( int nEntriesMax ) {

    if( nEntriesMax < 0 ) nEntriesMax = _inputTree -> GetEntries();
    
    for( int i = 0; i < nEntriesMax; ++i ) {
        
        
        cout << "NOW RUNNING EVENT " << i << endl;
        cout << "====================" << endl;

        _inputTree->GetEntry(i);
        _cutFlow.at("NoCut") += 1;
        

        _histograms1D.at("MET_allEvents").Fill( met );
        int leadingJet = -1;
        double leadingJetPt = 0.;
        for( unsigned int iJet = 0; iJet < recoJet_pt->size(); ++iJet ) {
            if( recoJet_pt->at(iJet) > leadingJetPt ) {
                leadingJetPt = recoJet_pt->at(iJet);
                leadingJet = iJet;
            }
        }
        if( leadingJet >= 0 ) _histograms1D.at("jet1_pt_allEvents").Fill( recoJet_pt->at(leadingJet) );


        bool passTrigger = false;
        for( unsigned int iTrig = 0; iTrig < triggerNames->size(); ++iTrig ) {
            if( (triggerNames->at(iTrig) == "HLT_PFJet260_v1" || triggerNames->at(iTrig) == "HLT_PFMET170_NoiseCleaned_v1") && triggerBits->at(iTrig) == 1 ) passTrigger = true;
            
            if( triggerNames->at(iTrig) == "HLT_PFMET170_NoiseCleaned_v1" && triggerBits->at(iTrig) == 1 ) {
                _histograms1D.at("MET_HLT_PFMET170_NoiseCleaned_v1").Fill( met );
            }
            if( triggerNames->at(iTrig) == "HLT_PFJet260_v1" && triggerBits->at(iTrig) == 1 ) {
                _histograms1D.at("jet1_pt_HLT_PFJet260_v1" ).Fill( recoJet_pt->at(leadingJet) );
            }
        }
        
        if( !passTrigger ) continue;
        _cutFlow.at("Trigger") += 1;

        // lepton veto:
        bool hasMuon = false;
        for( unsigned int im = 0; im < muon_px->size(); ++im ) {
            double pt = sqrt(muon_px->at(im)*muon_px->at(im) + muon_py->at(im)*muon_py->at(im));
            if( pt > MUON_PT_CUT ) hasMuon = true;
        }
        if( hasMuon ) continue;
        _cutFlow.at("MuonVeto") += 1;
        
        
        bool hasElectron = false;
        for( unsigned int im = 0; im < electron_px->size(); ++im ) {
            double pt = sqrt(electron_px->at(im)*electron_px->at(im) + electron_py->at(im)*electron_py->at(im));
            if( pt > ELECTRON_PT_CUT ) hasElectron = true;
        }
        if( hasElectron ) continue;
        _cutFlow.at("ElectronVeto") += 1;




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
            if( recoJet_pt->at(iJet) < JET_PT_CUT ) continue;
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
        vector<int> PVWithJets75;
        vector<int> SVWithJets;
        for( unsigned int iPV = 0; iPV < vertex_x -> size(); ++iPV ) {
            bool hasJet75 = false;
            for( unsigned int iiJet = 0; iiJet < idJetsToPV.at(iPV).size(); ++iiJet ) {
                int iJet = idJetsToPV.at(iPV).at(iiJet);
                if( recoJet_pt->at(iJet) > 75. ) hasJet75 = true;
            }
            if( hasJet75 ) PVWithJets75.push_back( iPV );
        }
        for( unsigned int iSV = 0; iSV < secVertex_x->size(); ++iSV ) {
            if( idJetsToSV.at(iSV).size() > 0 ) SVWithJets.push_back( iSV );
        }
        

        // and run the selection:
        if( PVWithJets75.size() == 1 ) {
            _cutFlow.at("HasPV75") += 1;
            if( SVWithJets.size() > 0 ) {
                _cutFlow.at("HasSV20") += 1;
                
                _histograms1D.at("selected_met").Fill(met);
                _histograms1D.at("selected_nPV75").Fill( PVWithJets75.size() ); 
                _histograms1D.at("selected_nSV").Fill( SVWithJets.size() );
                
                for( unsigned int iSV = 0; iSV < SVWithJets.size(); ++iSV ) {
                    _histograms1D.at("selected_nJetsToSV").Fill( idJetsToSV.at(SVWithJets.at(iSV)).size() );
                }
                vector<double> allDistances;

                for( unsigned int iPV = 0; iPV < PVWithJets75.size(); ++iPV ) {
                    double thispv_x = vertex_x->at(PVWithJets75.at(iPV));
                    double thispv_y = vertex_y->at(PVWithJets75.at(iPV));
                    double thispv_z = vertex_z->at(PVWithJets75.at(iPV));
                    for( unsigned int iSV = 0; iSV < SVWithJets.size(); ++iSV ) {
                        double thissv_x = secVertex_x->at(SVWithJets.at(iSV));
                        double thissv_y = secVertex_y->at(SVWithJets.at(iSV));
                        double thissv_z = secVertex_z->at(SVWithJets.at(iSV));
                        double dx = thissv_x - thispv_x;
                        double dy = thissv_y - thispv_y;
                        double dz = thissv_z - thispv_z;
                        double dist = 10.*sqrt( dx*dx + dy*dy + dz*dz );
                        _histograms1D.at("selected_distances").Fill(dist);
                        allDistances.push_back( dist );
                    }
                }
                if( met > MET_CUT ) {
                    _cutFlow.at("MET") += 1;
                    bool hasLargeDistance = false;
                    for( unsigned int kDist = 0; kDist < allDistances.size(); ++kDist ) {
                        if( allDistances.at(kDist) > 5. ) hasLargeDistance = true;
                    }
                    if( hasLargeDistance ) {
                        _cutFlow.at("SVPVDistance") += 1;
                    }
                }
            }
        }   
    }
}   

void LLGAnalysis::FinishRun() {

    
    TCanvas c("","");
    for( map<string,TH1D>::iterator itr_h = _histograms1D.begin(); itr_h != _histograms1D.end(); ++itr_h ) {
        (*itr_h).second.Draw( (_histograms1DDrawOptions.at((*itr_h).first)).c_str() );
        for( vector<string>::iterator itr_f = _plotFormats.begin(); itr_f != _plotFormats.end(); ++itr_f ) {
            string thisPlotName = (*itr_h).first + (*itr_f);
            c.Print( thisPlotName.c_str() );
        }
    }
    
    for( map<string,TH2D>::iterator itr_h = _histograms2D.begin(); itr_h != _histograms2D.end(); ++itr_h ) {
        (*itr_h).second.Draw( (_histograms2DDrawOptions.at((*itr_h).first)).c_str()  );
        for( vector<string>::iterator itr_f = _plotFormats.begin(); itr_f != _plotFormats.end(); ++itr_f ) {
            string thisPlotName = (*itr_h).first + (*itr_f);
            c.Print( thisPlotName.c_str() );
        }
    }
    
    MakeEfficiencyPlot( _histograms1D.at("MET_HLT_PFMET170_NoiseCleaned_v1"), _histograms1D.at("MET_allEvents"), &c, "HLT_PFMET170_NoiseCleaned_v1" ); 
    MakeEfficiencyPlot( _histograms1D.at("jet1_pt_HLT_PFJet260_v1"), _histograms1D.at("jet1_pt_allEvents"), &c, "HLT_PFJet260_v1" ); 

    cout << endl << "RECO CUT FLOW " << endl;
    cout << "-----------------------------" << endl;
    for( map<string,int>::iterator itr = _cutFlow.begin(); itr != _cutFlow.end(); ++itr ) {
        cout << (*itr).first << " " << (*itr).second << endl;
    }

    delete _inputTree;
    delete recoJet_pt;
    delete recoJet_phi;
    delete recoJet_eta;
    delete recoJet_secVertex3D;
    delete recoJet_secVertexSig;
    delete recoJet_bJetTag;
    delete recoJet_closestVertex_x;
    delete recoJet_closestVertex_y;
    delete recoJet_closestVertex_z;
    delete muon_px;
    delete muon_py;
    delete muon_pz;
    delete muon_phi;
    delete muon_eta;
    delete electron_px;
    delete electron_py;
    delete electron_pz;
    delete electron_phi;
    delete electron_eta;
    delete triggerBits;
    delete triggerNames;
    delete recoJet_constVertex_x;
    delete recoJet_constVertex_y;
    delete recoJet_constVertex_z;
    delete recoJet_constclosestVertex_x;
    delete recoJet_constclosestVertex_y;
    delete recoJet_constclosestVertex_z;
    delete recoJet_const_pt;
    delete recoJet_const_closestVertex_dxy;
    delete recoJet_const_closestVertex_dz;
    delete recoJet_const_closestVertex_d;
    delete recoJet_const_charge;

    delete vertex_x;
    delete vertex_y;
    delete vertex_z;
    delete secVertex_x;
    delete secVertex_y;
    delete secVertex_z;
    delete vertex_nTracks;
    delete vertex_pt;

} 


void LLGAnalysis::setStyle( double ytoff, bool marker, double left_margin ) {
// use plain black on white colors
Int_t icol=0;
gStyle->SetFrameBorderMode(icol);
gStyle->SetCanvasBorderMode(icol);
gStyle->SetPadBorderMode(icol);
gStyle->SetPadColor(icol);
gStyle->SetCanvasColor(icol);
gStyle->SetStatColor(icol);
gStyle->SetTitleFillColor(icol);
// set the paper & margin sizes
gStyle->SetPaperSize(20,26);
gStyle->SetPadTopMargin(0.10);
gStyle->SetPadRightMargin(0.15);
gStyle->SetPadBottomMargin(0.16);
gStyle->SetPadLeftMargin(0.15);
// use large fonts
Int_t font=62;
Double_t tsize=0.04;
gStyle->SetTextFont(font);
gStyle->SetTextSize(tsize);
gStyle->SetLabelFont(font,"x");
gStyle->SetTitleFont(font,"x");
gStyle->SetLabelFont(font,"y");
gStyle->SetTitleFont(font,"y");
gStyle->SetLabelFont(font,"z");
gStyle->SetTitleFont(font,"z");
gStyle->SetLabelSize(tsize,"x");
gStyle->SetTitleSize(tsize,"x");
gStyle->SetLabelSize(tsize,"y");
gStyle->SetTitleSize(tsize,"y");
gStyle->SetLabelSize(tsize,"z");
gStyle->SetTitleSize(tsize,"z");
gStyle->SetTitleBorderSize(0);
//use bold lines and markers
if ( marker ) {
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.2);
}
gStyle->SetHistLineWidth(Width_t(3.));
// postscript dashes
gStyle->SetLineStyleString(2,"[12 12]");
gStyle->SetOptStat(0);
gStyle->SetOptFit(1111);
// put tick marks on top and RHS of plots
gStyle->SetPadTickX(1);
gStyle->SetPadTickY(1);
// DLA overrides
gStyle->SetPadLeftMargin(left_margin);
gStyle->SetPadBottomMargin(0.13);
gStyle->SetTitleYOffset(ytoff);
gStyle->SetTitleXOffset(1.0);
gStyle->SetOptTitle(0);
//gStyle->SetStatStyle(0);
//gStyle->SetStatFontSize();
gStyle->SetStatW(0.17);

}

LLGAnalysis *LLGAnalysis::_instance = 0;