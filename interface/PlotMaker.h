#ifndef PlotMaker_h
#define PlotMaker_h

/*  \class PlotMaker
*
*  Class to produce some plots of Off-line variables in the TriggerValidation Code
*
*  Author: Massimiliano Chiorboli      Date: September 2007
//         Maurizio Pierini
//         Maria Spiropulu
*
*/
#include <memory>
#include <string>
#include <iostream>

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Handle.h"


#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/JetReco/interface/Jet.h"
#include "DataFormats/JetReco/interface/CaloJetCollection.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"


//l1extra
#include "DataFormats/L1Trigger/interface/L1EmParticle.h"
#include "DataFormats/L1Trigger/interface/L1EmParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticle.h"
#include "DataFormats/L1Trigger/interface/L1EtMissParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1JetParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"

//#include "DataFormats/L1Trigger/interface/L1ParticleMap.h"

//included for DQM
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"



class PlotMaker {

 public:
  PlotMaker(edm::ParameterSet objectList);
  virtual ~PlotMaker(){};

  void handleObjects(const edm::Event&);
  void fillPlots(const edm::Event&);
  void bookHistos(DQMStore *, std::vector<int>*, std::vector<int>*,std::vector<std::string>*,std::vector<std::string>*);
  //  void writeHistos();


 private:

  std::string dirname_;

  void setBits(std::vector<int>* l1bits, std::vector<int>* hltbits) {l1bits_=l1bits; hltbits_=hltbits;}
  double invariantMass(reco::Candidate*,reco::Candidate*);
  std::vector<int>* l1bits_;
  std::vector<int>* hltbits_;
    
    

  // Define the parameters
  std::string m_l1extra;
  std::string m_electronSrc;
  std::string m_muonSrc;
  std::string m_jetsSrc;
  std::string m_photonSrc;
  std::string m_photonProducerSrc;
  std::string m_calometSrc;


  double def_electronPtMin; 
  double def_muonPtMin    ; 
  double def_jetPtMin     ; 
  double def_photonPtMin  ; 
  
  reco::PixelMatchGsfElectronCollection theElectronCollection;
  reco::MuonCollection                  theMuonCollection    ;
  reco::PhotonCollection                thePhotonCollection  ;
  reco::CaloJetCollection               theCaloJetCollection ;
  reco::CaloMETCollection               theCaloMETCollection ;

  l1extra::L1EmParticleCollection theL1EmIsoCollection, theL1EmNotIsoCollection;
  l1extra::L1MuonParticleCollection theL1MuonCollection;
  l1extra::L1JetParticleCollection theL1CentralJetCollection, theL1ForwardJetCollection, theL1TauJetCollection;
  l1extra::L1EtMissParticleCollection theL1METCollection;

  //histos

  //Jets
  MonitorElement* hL1CentralJetMult;
  MonitorElement* hL1ForwardJetMult;
  MonitorElement* hL1TauJetMult;
  MonitorElement* hJetMult;
  std::vector<MonitorElement*> hL1CentralJetMultAfterL1;
  std::vector<MonitorElement*> hL1CentralJetMultAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJetMultAfterL1;
  std::vector<MonitorElement*> hL1ForwardJetMultAfterHLT;
  std::vector<MonitorElement*> hL1TauJetMultAfterL1;
  std::vector<MonitorElement*> hL1TauJetMultAfterHLT;
  std::vector<MonitorElement*> hJetMultAfterL1;
  std::vector<MonitorElement*> hJetMultAfterHLT;
  MonitorElement* hL1CentralJet1Pt;
  MonitorElement* hL1ForwardJet1Pt;
  MonitorElement* hL1TauJet1Pt;
  MonitorElement* hJet1Pt;
  std::vector<MonitorElement*> hL1CentralJet1PtAfterL1;
  std::vector<MonitorElement*> hL1CentralJet1PtAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet1PtAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet1PtAfterHLT;
  std::vector<MonitorElement*> hL1TauJet1PtAfterL1;
  std::vector<MonitorElement*> hL1TauJet1PtAfterHLT;
  std::vector<MonitorElement*> hJet1PtAfterL1;
  std::vector<MonitorElement*> hJet1PtAfterHLT;
  MonitorElement* hL1CentralJet2Pt;
  MonitorElement* hL1ForwardJet2Pt;
  MonitorElement* hL1TauJet2Pt;
  MonitorElement* hJet2Pt;
  std::vector<MonitorElement*> hL1CentralJet2PtAfterL1;
  std::vector<MonitorElement*> hL1CentralJet2PtAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet2PtAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet2PtAfterHLT;
  std::vector<MonitorElement*> hL1TauJet2PtAfterL1;
  std::vector<MonitorElement*> hL1TauJet2PtAfterHLT;
  std::vector<MonitorElement*> hJet2PtAfterL1;
  std::vector<MonitorElement*> hJet2PtAfterHLT;
  MonitorElement* hL1CentralJet1Eta;
  MonitorElement* hL1ForwardJet1Eta;
  MonitorElement* hL1TauJet1Eta;
  MonitorElement* hJet1Eta;
  std::vector<MonitorElement*> hL1CentralJet1EtaAfterL1;
  std::vector<MonitorElement*> hL1CentralJet1EtaAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet1EtaAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet1EtaAfterHLT;
  std::vector<MonitorElement*> hL1TauJet1EtaAfterL1;
  std::vector<MonitorElement*> hL1TauJet1EtaAfterHLT;
  std::vector<MonitorElement*> hJet1EtaAfterL1;
  std::vector<MonitorElement*> hJet1EtaAfterHLT;
  MonitorElement* hL1CentralJet2Eta;
  MonitorElement* hL1ForwardJet2Eta;
  MonitorElement* hL1TauJet2Eta;
  MonitorElement* hJet2Eta;
  std::vector<MonitorElement*> hL1CentralJet2EtaAfterL1;
  std::vector<MonitorElement*> hL1CentralJet2EtaAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet2EtaAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet2EtaAfterHLT;
  std::vector<MonitorElement*> hL1TauJet2EtaAfterL1;
  std::vector<MonitorElement*> hL1TauJet2EtaAfterHLT;
  std::vector<MonitorElement*> hJet2EtaAfterL1;
  std::vector<MonitorElement*> hJet2EtaAfterHLT;
  MonitorElement* hL1CentralJet1Phi;
  MonitorElement* hL1ForwardJet1Phi;
  MonitorElement* hL1TauJet1Phi;
  MonitorElement* hJet1Phi;
  std::vector<MonitorElement*> hL1CentralJet1PhiAfterL1;
  std::vector<MonitorElement*> hL1CentralJet1PhiAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet1PhiAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet1PhiAfterHLT;
  std::vector<MonitorElement*> hL1TauJet1PhiAfterL1;
  std::vector<MonitorElement*> hL1TauJet1PhiAfterHLT;
  std::vector<MonitorElement*> hJet1PhiAfterL1;
  std::vector<MonitorElement*> hJet1PhiAfterHLT;
  MonitorElement* hL1CentralJet2Phi;
  MonitorElement* hL1ForwardJet2Phi;
  MonitorElement* hL1TauJet2Phi;
  MonitorElement* hJet2Phi;
  std::vector<MonitorElement*> hL1CentralJet2PhiAfterL1;
  std::vector<MonitorElement*> hL1CentralJet2PhiAfterHLT;
  std::vector<MonitorElement*> hL1ForwardJet2PhiAfterL1;
  std::vector<MonitorElement*> hL1ForwardJet2PhiAfterHLT;
  std::vector<MonitorElement*> hL1TauJet2PhiAfterL1;
  std::vector<MonitorElement*> hL1TauJet2PhiAfterHLT;
  std::vector<MonitorElement*> hJet2PhiAfterL1;
  std::vector<MonitorElement*> hJet2PhiAfterHLT;

  MonitorElement* hDiJetInvMass;
  std::vector<MonitorElement*> hDiJetInvMassAfterL1;
  std::vector<MonitorElement*> hDiJetInvMassAfterHLT;




  //Electrons
  MonitorElement* hL1EmIsoMult;
  MonitorElement* hL1EmNotIsoMult;
  MonitorElement* hElecMult;
  std::vector<MonitorElement*> hL1EmIsoMultAfterL1;
  std::vector<MonitorElement*> hL1EmIsoMultAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIsoMultAfterL1;
  std::vector<MonitorElement*> hL1EmNotIsoMultAfterHLT;
  std::vector<MonitorElement*> hElecMultAfterL1;
  std::vector<MonitorElement*> hElecMultAfterHLT;
  MonitorElement* hL1EmIso1Pt;
  MonitorElement* hL1EmNotIso1Pt;
  MonitorElement* hElec1Pt;
  std::vector<MonitorElement*> hL1EmIso1PtAfterL1;
  std::vector<MonitorElement*> hL1EmIso1PtAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso1PtAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso1PtAfterHLT;
  std::vector<MonitorElement*> hElec1PtAfterL1;
  std::vector<MonitorElement*> hElec1PtAfterHLT;
  MonitorElement* hL1EmIso2Pt;
  MonitorElement* hL1EmNotIso2Pt;
  MonitorElement* hElec2Pt;
  std::vector<MonitorElement*> hL1EmIso2PtAfterL1;
  std::vector<MonitorElement*> hL1EmIso2PtAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso2PtAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso2PtAfterHLT;
  std::vector<MonitorElement*> hElec2PtAfterL1;
  std::vector<MonitorElement*> hElec2PtAfterHLT;
  MonitorElement* hL1EmIso1Eta;
  MonitorElement* hL1EmNotIso1Eta;
  MonitorElement* hElec1Eta;
  std::vector<MonitorElement*> hL1EmIso1EtaAfterL1;
  std::vector<MonitorElement*> hL1EmIso1EtaAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso1EtaAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso1EtaAfterHLT;
  std::vector<MonitorElement*> hElec1EtaAfterL1;
  std::vector<MonitorElement*> hElec1EtaAfterHLT;
  MonitorElement* hL1EmIso2Eta;
  MonitorElement* hL1EmNotIso2Eta;
  MonitorElement* hElec2Eta;
  std::vector<MonitorElement*> hL1EmIso2EtaAfterL1;
  std::vector<MonitorElement*> hL1EmIso2EtaAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso2EtaAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso2EtaAfterHLT;
  std::vector<MonitorElement*> hElec2EtaAfterL1;
  std::vector<MonitorElement*> hElec2EtaAfterHLT;
  MonitorElement* hL1EmIso1Phi;
  MonitorElement* hL1EmNotIso1Phi;
  MonitorElement* hElec1Phi;
  std::vector<MonitorElement*> hL1EmIso1PhiAfterL1;
  std::vector<MonitorElement*> hL1EmIso1PhiAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso1PhiAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso1PhiAfterHLT;
  std::vector<MonitorElement*> hElec1PhiAfterL1;
  std::vector<MonitorElement*> hElec1PhiAfterHLT;
  MonitorElement* hL1EmIso2Phi;
  MonitorElement* hL1EmNotIso2Phi;
  MonitorElement* hElec2Phi;
  std::vector<MonitorElement*> hL1EmIso2PhiAfterL1;
  std::vector<MonitorElement*> hL1EmIso2PhiAfterHLT;
  std::vector<MonitorElement*> hL1EmNotIso2PhiAfterL1;
  std::vector<MonitorElement*> hL1EmNotIso2PhiAfterHLT;
  std::vector<MonitorElement*> hElec2PhiAfterL1;
  std::vector<MonitorElement*> hElec2PhiAfterHLT;
  
  MonitorElement* hDiElecInvMass;
  std::vector<MonitorElement*> hDiElecInvMassAfterL1;
  std::vector<MonitorElement*> hDiElecInvMassAfterHLT;


  //Muons
  MonitorElement* hL1MuonMult;
  MonitorElement* hMuonMult;
  std::vector<MonitorElement*> hL1MuonMultAfterL1;
  std::vector<MonitorElement*> hL1MuonMultAfterHLT;
  std::vector<MonitorElement*> hMuonMultAfterL1;
  std::vector<MonitorElement*> hMuonMultAfterHLT;
  MonitorElement* hL1Muon1Pt;
  MonitorElement* hMuon1Pt;
  std::vector<MonitorElement*> hL1Muon1PtAfterL1;
  std::vector<MonitorElement*> hL1Muon1PtAfterHLT;
  std::vector<MonitorElement*> hMuon1PtAfterL1;
  std::vector<MonitorElement*> hMuon1PtAfterHLT;
  MonitorElement* hL1Muon2Pt;
  MonitorElement* hMuon2Pt;
  std::vector<MonitorElement*> hL1Muon2PtAfterL1;
  std::vector<MonitorElement*> hL1Muon2PtAfterHLT;
  std::vector<MonitorElement*> hMuon2PtAfterL1;
  std::vector<MonitorElement*> hMuon2PtAfterHLT;
  MonitorElement* hL1Muon1Eta;
  MonitorElement* hMuon1Eta;
  std::vector<MonitorElement*> hL1Muon1EtaAfterL1;
  std::vector<MonitorElement*> hL1Muon1EtaAfterHLT;
  std::vector<MonitorElement*> hMuon1EtaAfterL1;
  std::vector<MonitorElement*> hMuon1EtaAfterHLT;
  MonitorElement* hL1Muon2Eta;
  MonitorElement* hMuon2Eta;
  std::vector<MonitorElement*> hL1Muon2EtaAfterL1;
  std::vector<MonitorElement*> hL1Muon2EtaAfterHLT;
  std::vector<MonitorElement*> hMuon2EtaAfterL1;
  std::vector<MonitorElement*> hMuon2EtaAfterHLT;
  MonitorElement* hL1Muon1Phi;
  MonitorElement* hMuon1Phi;
  std::vector<MonitorElement*> hL1Muon1PhiAfterL1;
  std::vector<MonitorElement*> hL1Muon1PhiAfterHLT;
  std::vector<MonitorElement*> hMuon1PhiAfterL1;
  std::vector<MonitorElement*> hMuon1PhiAfterHLT;
  MonitorElement* hL1Muon2Phi;
  MonitorElement* hMuon2Phi;
  std::vector<MonitorElement*> hL1Muon2PhiAfterL1;
  std::vector<MonitorElement*> hL1Muon2PhiAfterHLT;
  std::vector<MonitorElement*> hMuon2PhiAfterL1;
  std::vector<MonitorElement*> hMuon2PhiAfterHLT;

  MonitorElement* hDiMuonInvMass;
  std::vector<MonitorElement*> hDiMuonInvMassAfterL1;
  std::vector<MonitorElement*> hDiMuonInvMassAfterHLT;


  //Photons
  MonitorElement* hPhotonMult;
  std::vector<MonitorElement*> hPhotonMultAfterL1;
  std::vector<MonitorElement*> hPhotonMultAfterHLT;
  MonitorElement* hPhoton1Pt;
  std::vector<MonitorElement*> hPhoton1PtAfterL1;
  std::vector<MonitorElement*> hPhoton1PtAfterHLT;
  MonitorElement* hPhoton2Pt;
  std::vector<MonitorElement*> hPhoton2PtAfterL1;
  std::vector<MonitorElement*> hPhoton2PtAfterHLT;
  MonitorElement* hPhoton1Eta;
  std::vector<MonitorElement*> hPhoton1EtaAfterL1;
  std::vector<MonitorElement*> hPhoton1EtaAfterHLT;
  MonitorElement* hPhoton2Eta;
  std::vector<MonitorElement*> hPhoton2EtaAfterL1;
  std::vector<MonitorElement*> hPhoton2EtaAfterHLT;
  MonitorElement* hPhoton1Phi;
  std::vector<MonitorElement*> hPhoton1PhiAfterL1;
  std::vector<MonitorElement*> hPhoton1PhiAfterHLT;
  MonitorElement* hPhoton2Phi;
  std::vector<MonitorElement*> hPhoton2PhiAfterL1;
  std::vector<MonitorElement*> hPhoton2PhiAfterHLT;
  
  MonitorElement* hDiPhotonInvMass;
  std::vector<MonitorElement*> hDiPhotonInvMassAfterL1;
  std::vector<MonitorElement*> hDiPhotonInvMassAfterHLT;

  
  //MET
  MonitorElement* hL1MET;
  MonitorElement* hMET;
  MonitorElement* hL1METphi;
  MonitorElement* hMETphi;
  MonitorElement* hL1METx;
  MonitorElement* hMETx;
  MonitorElement* hL1METy;
  MonitorElement* hMETy;
  MonitorElement* hL1SumEt;
  MonitorElement* hSumEt;
  MonitorElement* hL1METSignificance;
  MonitorElement* hMETSignificance;

  std::vector<MonitorElement*> hL1METAfterL1;
  std::vector<MonitorElement*> hL1METAfterHLT;
  std::vector<MonitorElement*> hMETAfterL1;
  std::vector<MonitorElement*> hMETAfterHLT;
  std::vector<MonitorElement*> hL1METphiAfterL1;
  std::vector<MonitorElement*> hL1METphiAfterHLT;
  std::vector<MonitorElement*> hMETphiAfterL1;
  std::vector<MonitorElement*> hMETphiAfterHLT;
  std::vector<MonitorElement*> hL1METxAfterL1;
  std::vector<MonitorElement*> hL1METxAfterHLT;
  std::vector<MonitorElement*> hMETxAfterL1;
  std::vector<MonitorElement*> hMETxAfterHLT;
  std::vector<MonitorElement*> hL1METyAfterL1;
  std::vector<MonitorElement*> hL1METyAfterHLT;
  std::vector<MonitorElement*> hMETyAfterL1;
  std::vector<MonitorElement*> hMETyAfterHLT;
  std::vector<MonitorElement*> hL1SumEtAfterL1;
  std::vector<MonitorElement*> hL1SumEtAfterHLT;
  std::vector<MonitorElement*> hSumEtAfterL1;
  std::vector<MonitorElement*> hSumEtAfterHLT;
  std::vector<MonitorElement*> hL1METSignificanceAfterL1;
  std::vector<MonitorElement*> hL1METSignificanceAfterHLT;
  std::vector<MonitorElement*> hMETSignificanceAfterL1;
  std::vector<MonitorElement*> hMETSignificanceAfterHLT;





  string myHistoName;
  string myHistoTitle;

};


#endif
