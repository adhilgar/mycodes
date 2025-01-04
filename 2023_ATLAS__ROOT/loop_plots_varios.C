#define ZeeCandidate_cxx
#include "ZeeCandidate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void ZeeCandidate::Loop()
{
    //   In a ROOT session, you can do:
    //      root> .L ZeeCandidate.C
    //      root> ZeeCandidate t
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
    //fChain->SetBranchStatus("*",0);  // disable all branches
    //fChain->SetBranchStatus("elCand2_et",1);  // activate branchname
    //fChain->SetBranchStatus("elCand2_f1",1);  // activate branchname
    // METHOD2: replace line
    //    fChain->GetEntry(jentry);       //read all branches
    //by  b_branchname->GetEntry(ientry); //read only this branch
    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
   /* TH1F *h1 = new TH1F ("h1","h_Et",100,0,1);
    TH1F *h2 = new TH1F ("h2","Et;bins;entries",100,0,1);
    TH1F *h3 = new TH1F ("h3","Et;bins;entries",100,0,1);
    TH1F *h4 = new TH1F ("h4","Et;bins;entries",100,0,1);
    TH1F *h5 = new TH1F ("h5","Et;bins;entries",100,0,1);
    TH1F *h6 = new TH1F ("h6","Et;bins;entries",100,0,1);
    TH1F *h7 = new TH1F ("h7","Et;bins;entries",100,0,1);
    TH1F *h8 = new TH1F ("h8","Et;bins;entries",100,0,1); */
    
    int numbins = 15;
    TH1F *H[numbins];
    for (int j=0;j<numbins;j++){
        char title[100];
        sprintf(title, "H_%d",j);
        H[j]= new TH1F(title,title,100,0,1);
    }
   TCanvas *c1 = new TCanvas ("c1");
    c1->Divide(6,3,0.01,0.01,0);
    
    
    
    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;

        for (int k=0;k<150;k++){
            if(elCand2_et>=k*0.82 && elCand2_et<(k+1)*0.82){
                H[k]->Fill(elCand2_f1);
            }
        }
        
        
        
        
        
        
        
/*
    if(elCand2_et>=0.0 && elCand2_et<=15.38){
        h1->Fill(elCand2_f1);
    } else if(elCand2_et>15.38 && elCand2_et<=30.8){
        h2->Fill(elCand2_f1);
    } else if(elCand2_et>30.8 && elCand2_et<=46.14){
        h3->Fill(elCand2_f1);
    } else if(elCand2_et>46.14 && elCand2_et<=61.52){
        h4->Fill(elCand2_f1);
    } else if(elCand2_et>61.52 && elCand2_et<=76.9){
        h5->Fill(elCand2_f1);
    } else if(elCand2_et>76.9 && elCand2_et<=92.28){
        h6->Fill(elCand2_f1);
    } else if(elCand2_et>92.28 && elCand2_et<=107.66){
        h7->Fill(elCand2_f1);
    } else if(elCand2_et>107.66 && elCand2_et<=123.04){
        h8->Fill(elCand2_f1);
    }
*/ }
       
        // if (Cut(ientry) < 0) continue;
        //for (Int_t j=0;j<nentries;j++) {
        
        //}
    
    /*    hist_Et_1->SetLineColor(kBlack);
        hist_Et_2->SetLineColor(kBlue);
        hist_Et_3->SetLineColor(kRed);
        hist_Et_4->SetLineColor(kYellow);

        hist_Et_1->DrawNormalized();
        hist_Et_2->DrawNormalized("same");
        hist_Et_3->DrawNormalized("same");
        hist_Et_4->DrawNormalized("same");
    
     
    c1->cd(1);
    h1->Draw();
    c1->cd(2);
    h2->Draw();
    c1->cd(3);
    h3->Draw();
    c1->cd(4);
    h4->Draw();
    c1->cd(5);
    h5->Draw();
    c1->cd(6);
    h6->Draw();
    c1->cd(7);
    h7->Draw();
    c1->cd(8);
    h8->Draw(); */
    TGraph *graf = new TGraph();

    for (int n=0;n<150;n++){
        if(H[n]->GetMean()!=0.0){
            graf->AddPoint((n+0.5)*0.82,H[n]->GetMean());
        }}

  /*  for(int m=0;m<15;m++){
        c1->cd(m);
        H[m]->Draw("same");
    } */
    graf->Draw();
}
