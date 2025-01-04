#define myclass_cxx
#include "myclass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void myclass_eta::Loop()
{
//   In a ROOT session, you can do:
//      root> .L myclass.C
//      root> myclass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
    
    //f1
    
    TH1F* f11 = new TH1F("f11", "f11", 100, 0, 0.7);
    TH1F* f12 = new TH1F("f12", "f12", 100, 0, 0.7);
    TH1F* f13 = new TH1F("f13", "f13", 100, 0, 0.7);
    TH1F* f14 = new TH1F("f14", "f14", 100, 0, 0.7);
    
    //f3
    
    TH1F* f31 = new TH1F("f31", "f31", 100, 0, 0.025);
    TH1F* f32 = new TH1F("f32", "f32", 100, 0, 0.025);
    TH1F* f33 = new TH1F("f33", "f33", 100, 0, 0.025);
    TH1F* f34 = new TH1F("f34", "f34", 100, 0, 0.025);
    
    //weta2
    
    TH1F* weta21 = new TH1F("weta21", "weta21", 100, 0, 0.04);
    TH1F* weta22 = new TH1F("weta22", "weta22", 100, 0, 0.04);
    TH1F* weta23 = new TH1F("weta23", "weta23", 100, 0, 0.04);
    TH1F* weta24 = new TH1F("weta24", "weta24", 100, 0, 0.04);
    
    //wstot
    
    TH1F* wstot1 = new TH1F("wsto1", "wstot1", 100, 0.5, 3.5);
    TH1F* wstot2 = new TH1F("wstot2", "wstot2", 100, 0.5, 3.5);
    TH1F* wstot3 = new TH1F("wstot3", "wstot3", 100, 0.5, 3.5);
    TH1F* wstot4 = new TH1F("wstot4", "wstot4", 100, 0.5, 3.5);
    
    //reta
    
    TH1F* reta1 = new TH1F("reta1", "reta1", 100, 0.8, 1.2);
    TH1F* reta2 = new TH1F("reta2", "reta2", 100, 0.8, 1.2);
    TH1F* reta3 = new TH1F("reta3", "reta3", 100, 0.8, 1.2);
    TH1F* reta4 = new TH1F("reta4", "reta4", 100, 0.8, 1.2);
    
    //rhad
    
    TH1F* rhad1 = new TH1F("rhad1", "rhad1", 100, 0, 0.04);
    TH1F* rhad2 = new TH1F("rhad2", "rhad2", 100, 0, 0.04);
    TH1F* rhad3 = new TH1F("rhad3", "rhad3", 100, 0, 0.04);
    TH1F* rhad4 = new TH1F("rhad4", "rhad4", 100, 0, 0.04);
    
    //rphi
    
    TH1F* rphi1 = new TH1F("rphi1", "rphi1", 100, 0.8, 1.2);
    TH1F* rphi2 = new TH1F("rphi2", "rphi2", 100, 0.8, 1.2);
    TH1F* rphi3 = new TH1F("rphi3", "rphi3", 100, 0.8, 1.2);
    TH1F* rphi4 = new TH1F("rphi4", "rphi4", 100, 0.8, 1.2);
    
    //eratio
    
    TH1F* eratio1 = new TH1F("eratio1", "eratio1", 100, 0.8, 1.2);
    TH1F* eratio2 = new TH1F("eratio2", "eratio2", 100, 0.8, 1.2);
    TH1F* eratio3 = new TH1F("eratio3", "eratio3", 100, 0.8, 1.2);
    TH1F* eratio4 = new TH1F("eratio4", "eratio4", 100, 0.8, 1.2);
    
    //d0
    
    TH1F* d01 = new TH1F("d01", "d01", 100, 0, 0.1);
    TH1F* d02 = new TH1F("d02", "d02", 100, 0, 0.1);
    TH1F* d03 = new TH1F("d03", "d03", 100, 0, 0.1);
    TH1F* d04 = new TH1F("d04", "d04", 100, 0, 0.1);
    
    //deltaeta1
    
    TH1F* deltaeta11 = new TH1F("deltaeta11", "deltaeta11", 100, 0, 0.01);
    TH1F* deltaeta12 = new TH1F("deltaeta12", "deltaeta12", 100, 0, 0.01);
    TH1F* deltaeta13 = new TH1F("deltaeta13", "deltaeta13", 100, 0, 0.01);
    TH1F* deltaeta14 = new TH1F("deltaeta14", "deltaeta14", 100, 0, 0.01);
    
    //d0significance
    
    TH1F* d0significance1 = new TH1F("d0significance1", "d0significance1", 100, 0, 1);
    TH1F* d0significance2 = new TH1F("d0significance2", "d0significance2", 100, 0, 1);
    TH1F* d0significance3 = new TH1F("d0significance3", "d0significance3", 100, 0, 1);
    TH1F* d0significance4 = new TH1F("d0significance4", "d0significance4", 100, 0, 1);
    
    //deltapopverp
    
    TH1F* DeltaPOverP1 = new TH1F("DeltaPOverP1", "DeltaPOverP1", 100, 0, 1);
    TH1F* DeltaPOverP2 = new TH1F("DeltaPOverP2", "DeltaPOverP2", 100, 0, 1);
    TH1F* DeltaPOverP3 = new TH1F("DeltaPOverP3", "DeltaPOverP3", 100, 0, 1);
    TH1F* DeltaPOverP4 = new TH1F("DeltaPOverP4", "DeltaPOverP4", 100, 0, 1);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
       
       if (elCand2_eta>0 && elCand2_eta<1){
           f11->Fill(elCand2_f1);
           f31->Fill(elCand2_f3);
           weta21->Fill(elCand2_weta2);
           wstot1->Fill(elCand2_wstot);
           reta1->Fill(elCand2_reta);
           rhad1->Fill(elCand2_rhad);
           rphi1->Fill(elCand2_rphi);
           eratio1->Fill(elCand2_eratio);
           d01->Fill(elCand2_d0);
           deltaeta11->Fill(elCand2_deltaeta1);
           d0significance1->Fill(elCand2_d0significance);
           DeltaPOverP1->Fill(elCand2_DeltaPOverP);
       }else if(elCand2_eta>1 && elCand2_eta<2){
           f12->Fill(elCand2_f1);
           f32->Fill(elCand2_f3);
           weta22->Fill(elCand2_weta2);
           wstot2->Fill(elCand2_wstot);
           reta2->Fill(elCand2_reta);
           rhad2->Fill(elCand2_rhad);
           rphi2->Fill(elCand2_rphi);
           eratio2->Fill(elCand2_eratio);
           d02->Fill(elCand2_d0);
           deltaeta12->Fill(elCand2_deltaeta1);
           d0significance2->Fill(elCand2_d0significance);
           DeltaPOverP2->Fill(elCand2_DeltaPOverP);
       }else if(elCand2_eta>2 && elCand2_eta<3){
           f13->Fill(elCand2_f1);
           f33->Fill(elCand2_f3);
           weta23->Fill(elCand2_weta2);
           wstot3->Fill(elCand2_wstot);
           reta3->Fill(elCand2_reta);
           rhad3->Fill(elCand2_rhad);
           rphi3->Fill(elCand2_rphi);
           eratio3->Fill(elCand2_eratio);
           d03->Fill(elCand2_d0);
           deltaeta13->Fill(elCand2_deltaeta1);
           d0significance3->Fill(elCand2_d0significance);
           DeltaPOverP3->Fill(elCand2_DeltaPOverP);
       }else{
           f14->Fill(elCand2_f1);
           f34->Fill(elCand2_f3);
           weta24->Fill(elCand2_weta2);
           wstot4->Fill(elCand2_wstot);
           reta4->Fill(elCand2_reta);
           rhad4->Fill(elCand2_rhad);
           rphi4->Fill(elCand2_rphi);
           eratio4->Fill(elCand2_eratio);
           d04->Fill(elCand2_d0);
           deltaeta14->Fill(elCand2_deltaeta1);
           d0significance4->Fill(elCand2_d0significance);
           DeltaPOverP4->Fill(elCand2_DeltaPOverP);
       }
       
       
      /*f3->Fill(elCand2_f3);
       weta2->Fill(elCand2_weta2);
       wstot->Fill(elCand2_wstot);
       reta->Fill(elCand2_reta);
       rhad->Fill(elCand2_rhad);
       rphi->Fill(elCand2_rphi);
       eratio->Fill(elCand2_eratio);
       d0->Fill(elCand2_d0);
       deltaeta1->Fill(elCand2_deltaeta1);
       d0significance->Fill(elCand2_d0significance);
       DeltaPOverP->Fill(elCand2_DeltaPOverP);*/
   }
    
    TCanvas* c1 = new TCanvas("c1", "My ROOT ETA Plots", 1500, 500);
    c1->Divide(4,3);
    
    c1->cd(1);
    f11->Draw();
    f11->SetLineColor(kRed);
    f12->Draw("SAME");
    f12->SetLineColor(kGreen);
    f13->Draw("SAME");
    f13->SetLineColor(kBlue);
    f14->Draw("SAME");
    f14->SetLineColor(kBlack);
    
    c1->cd(2);
    f31->Draw();
    f31->SetLineColor(kRed);
    f32->Draw("SAME");
    f32->SetLineColor(kGreen);
    f33->Draw("SAME");
    f33->SetLineColor(kBlue);
    f34->Draw("SAME");
    f34->SetLineColor(kBlack);
    
    c1->cd(3);
    weta21->Draw();
    weta21->SetLineColor(kRed);
    weta22->Draw("SAME");
    weta22->SetLineColor(kGreen);
    weta23->Draw("SAME");
    weta23->SetLineColor(kBlue);
    weta24->Draw("SAME");
    weta24->SetLineColor(kBlack);
    
    c1->cd(4);
    wstot1->Draw();
    wstot1->SetLineColor(kRed);
    wstot2->Draw("SAME");
    wstot2->SetLineColor(kGreen);
    wstot3->Draw("SAME");
    wstot3->SetLineColor(kBlue);
    wstot4->Draw("SAME");
    wstot4->SetLineColor(kBlack);
    
    c1->cd(5);
    reta1->Draw();
    reta1->SetLineColor(kRed);
    reta2->Draw("SAME");
    reta2->SetLineColor(kGreen);
    reta3->Draw("SAME");
    reta3->SetLineColor(kBlue);
    reta4->Draw("SAME");
    reta4->SetLineColor(kBlack);
    
    c1->cd(6);
    rphi1->Draw();
    rphi1->SetLineColor(kRed);
    rphi2->Draw("SAME");
    rphi2->SetLineColor(kGreen);
    rphi3->Draw("SAME");
    rphi3->SetLineColor(kBlue);
    rphi4->Draw("SAME");
    rphi4->SetLineColor(kBlack);
    
    c1->cd(7);
    eratio1->Draw();
    eratio1->SetLineColor(kRed);
    eratio2->Draw("SAME");
    eratio2->SetLineColor(kGreen);
    eratio3->Draw("SAME");
    eratio3->SetLineColor(kBlue);
    eratio4->Draw("SAME");
    eratio4->SetLineColor(kBlack);
    
    c1->cd(8);
    d01->Draw();
    d01->SetLineColor(kRed);
    d02->Draw("SAME");
    d02->SetLineColor(kGreen);
    d03->Draw("SAME");
    d03->SetLineColor(kBlue);
    d04->Draw("SAME");
    d04->SetLineColor(kBlack);
    
    c1->cd(9);
    deltaeta11->Draw();
    deltaeta11->SetLineColor(kRed);
    deltaeta12->Draw("SAME");
    deltaeta12->SetLineColor(kGreen);
    deltaeta13->Draw("SAME");
    deltaeta13->SetLineColor(kBlue);
    deltaeta14->Draw("SAME");
    deltaeta14->SetLineColor(kBlack);
    
    c1->cd(10);
    d0significance1->Draw();
    d0significance1->SetLineColor(kRed);
    d0significance2->Draw("SAME");
    d0significance2->SetLineColor(kGreen);
    d0significance3->Draw("SAME");
    d0significance3->SetLineColor(kBlue);
    d0significance4->Draw("SAME");
    d0significance4->SetLineColor(kBlack);
    
    c1->cd(11);
    rhad1->Draw();
    rhad1->SetLineColor(kRed);
    rhad2->Draw("SAME");
    rhad2->SetLineColor(kGreen);
    rhad3->Draw("SAME");
    rhad3->SetLineColor(kBlue);
    rhad4->Draw("SAME");
    rhad4->SetLineColor(kBlack);
    
    c1->cd(12);
    DeltaPOverP1->Draw();
    DeltaPOverP1->SetLineColor(kRed);
    DeltaPOverP2->Draw("SAME");
    DeltaPOverP2->SetLineColor(kGreen);
    DeltaPOverP3->Draw("SAME");
    DeltaPOverP3->SetLineColor(kBlue);
    DeltaPOverP4->Draw("SAME");
    DeltaPOverP4->SetLineColor(kBlack);
    
    
    
}


