#define myclass_cxx
#include "myclass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>

#include "AtlasStyle.C"
#include "AtlasLabels.C"
#include "AtlasUtils.C"


void myclass::Loop()
{
    
    SetAtlasStyle();
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
       
     if (elCand2_et>0 && elCand2_et<25){
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
       }else if(elCand2_et>25 && elCand2_et<50){
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
       }else if(elCand2_et>50 && elCand2_et<75){
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
       
       
     
   }
    
    TCanvas* c1 = new TCanvas("c1", "My ROOT Plots", 1500, 500);
    c1->Divide(4,3);
    
    c1->cd(1);
    f11->SetLineColor(kRed);
    f12->SetLineColor(kGreen+2);
    f13->SetLineColor(kBlue);
    f14->SetLineColor(kBlack);
    f11->GetXaxis()->SetTitle("f_{1}");
    f11->GetYaxis()->SetTitle("Normalized count");
    f11->DrawNormalized();
    f12->DrawNormalized("SAME");
    f13->DrawNormalized("SAME");
    f14->DrawNormalized("SAME");
    
    
    auto l1 = new TLegend(0.1,0.7,0.48,0.9);
    
    l1->SetBorderSize(0);
      //l1->SetTextFont(1);
      l1->SetFillColor(0);
      l1->SetFillStyle(0);
      l1->SetLineColor(0);
        l1->AddEntry(f11,"0<E_{T}<25","l");
        l1->AddEntry(f12,"25<E_{T}<50","l");
        l1->AddEntry(f13,"50<E_{T}<75","l");
        l1->AddEntry(f14,"75<E_{T}","l");
    l1->Draw();
    
    c1->cd(2);
    f31->SetLineColor(kRed);
    f32->SetLineColor(kGreen+2);
    f33->SetLineColor(kBlue);
    f34->SetLineColor(kBlack);
    f31->GetXaxis()->SetTitle("f_{3}");
    f31->GetYaxis()->SetTitle("Normalized count");
    
    f31->DrawNormalized();
    f32->DrawNormalized("SAME");
    f33->DrawNormalized("SAME");
    f34->DrawNormalized("SAME");
    
    
    auto l2 = new TLegend(0.1,0.7,0.48,0.9);
    l2->SetBorderSize(0);
      //l1->SetTextFont(1);
      l2->SetFillColor(0);
      l2->SetFillStyle(0);
      l2->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l2->AddEntry(f11,"0<E_{T}<25","l");
    l2->AddEntry(f12,"25<E_{T}<50","l");
    l2->AddEntry(f13,"50<E_{T}<75","l");
    l2->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
       l2->Draw();
    
    
    c1->cd(3);
    weta21->SetLineColor(kRed);
    weta22->SetLineColor(kGreen+2);
    weta23->SetLineColor(kBlue);
    weta24->SetLineColor(kBlack);
    weta21->GetXaxis()->SetTitle("w_{#eta 2}");
    weta21->GetYaxis()->SetTitle("Normalized count");
    weta21->DrawNormalized();
    weta22->DrawNormalized("SAME");
    weta23->DrawNormalized("SAME");
    weta24->DrawNormalized("SAME");
    
    auto l3 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l3->SetBorderSize(0);
      //l1->SetTextFont(1);
      l3->SetFillColor(0);
      l3->SetFillStyle(0);
      l3->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l3->AddEntry(f11,"0<E_{T}<25","l");
    l3->AddEntry(f12,"25<E_{T}<50","l");
    l3->AddEntry(f13,"50<E_{T}<75","l");
    l3->AddEntry(f14,"75<E_{T}","l");
       l3->Draw();
    
    c1->cd(4);
    wstot1->SetLineColor(kRed);
    wstot2->SetLineColor(kGreen+2);
    wstot3->SetLineColor(kBlue);
    wstot4->SetLineColor(kBlack);
    wstot1->GetXaxis()->SetTitle("w_{#stot}");
    wstot1->GetYaxis()->SetTitle("Normalized count");
    wstot1->DrawNormalized();
    wstot2->DrawNormalized("SAME");
    wstot3->DrawNormalized("SAME");
    wstot4->DrawNormalized("SAME");
    
    auto l4 = new TLegend(0.1,0.7,0.48,0.9);
    l4->SetBorderSize(0);
      //l1->SetTextFont(1);
      l4->SetFillColor(0);
      l4->SetFillStyle(0);
      l4->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l4->AddEntry(f11,"0<E_{T}<25","l");
    l4->AddEntry(f12,"25<E_{T}<50","l");
    l4->AddEntry(f13,"50<E_{T}<75","l");
    l4->AddEntry(f14,"75<E_{T}","l");
    l4->Draw();
    
    c1->cd(5);
    reta1->SetLineColor(kRed);
    reta2->SetLineColor(kGreen+2);
    reta3->SetLineColor(kBlue);
    reta4->SetLineColor(kBlack);
    reta1->GetXaxis()->SetTitle("R_{#eta}");
    reta1->GetYaxis()->SetTitle("Normalized count");
    reta1->DrawNormalized();
    reta2->DrawNormalized("SAME");
    reta3->DrawNormalized("SAME");
    reta4->DrawNormalized("SAME");
    
    auto l5 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l5->SetBorderSize(0);
      //l1->SetTextFont(1);
      l5->SetFillColor(0);
      l5->SetFillStyle(0);
      l5->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l5->AddEntry(f11,"0<E_{T}<25","l");
    l5->AddEntry(f12,"25<E_{T}<50","l");
    l5->AddEntry(f13,"50<E_{T}<75","l");
    l5->AddEntry(f14,"75<E_{T}","l");
    l5->Draw();
    
    
    c1->cd(6);
    rphi1->SetLineColor(kRed);
    rphi2->SetLineColor(kGreen+2);
    rphi3->SetLineColor(kBlue);
    rphi4->SetLineColor(kBlack);
    rphi1->GetXaxis()->SetTitle("R_{#phi}");
    rphi1->GetYaxis()->SetTitle("Normalized count");
    rphi1->DrawNormalized();
    rphi2->DrawNormalized("SAME");
    rphi3->DrawNormalized("SAME");
    rphi4->DrawNormalized("SAME");
    
    auto l6 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l6->SetBorderSize(0);
      //l1->SetTextFont(1);
      l6->SetFillColor(0);
      l6->SetFillStyle(0);
      l6->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l6->AddEntry(f11,"0<E_{T}<25","l");
    l6->AddEntry(f12,"25<E_{T}<50","l");
    l6->AddEntry(f13,"50<E_{T}<75","l");
    l6->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l6->Draw();
    
    c1->cd(7);
    eratio1->SetLineColor(kRed);
    eratio2->SetLineColor(kGreen+2);
    eratio3->SetLineColor(kBlue);
    eratio4->SetLineColor(kBlack);
    eratio1->GetXaxis()->SetTitle("e_{ratio}");
    eratio1->GetYaxis()->SetTitle("Normalized count");
    eratio1->DrawNormalized();
    eratio2->DrawNormalized("SAME");
    eratio3->DrawNormalized("SAME");
    eratio4->DrawNormalized("SAME");
    
    auto l7 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l7->SetBorderSize(0);
      //l1->SetTextFont(1);
      l7->SetFillColor(0);
      l7->SetFillStyle(0);
      l7->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l7->AddEntry(f11,"0<E_{T}<25","l");
    l7->AddEntry(f12,"25<E_{T}<50","l");
    l7->AddEntry(f13,"50<E_{T}<75","l");
    l7->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l7->Draw();
    
    c1->cd(8);
    d01->SetLineColor(kRed);
    d02->SetLineColor(kGreen+2);
    d03->SetLineColor(kBlue);
    d04->SetLineColor(kBlack);
    d01->GetXaxis()->SetTitle("d_{0}");
    d01->GetYaxis()->SetTitle("Normalized count");
    d01->DrawNormalized();
    d02->DrawNormalized("SAME");
    d03->DrawNormalized("SAME");
    d04->DrawNormalized("SAME");
    
    auto l8 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l8->SetBorderSize(0);
      //l1->SetTextFont(1);
      l8->SetFillColor(0);
      l8->SetFillStyle(0);
      l8->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l8->AddEntry(f11,"0<E_{T}<25","l");
    l8->AddEntry(f12,"25<E_{T}<50","l");
    l8->AddEntry(f13,"50<E_{T}<75","l");
    l8->AddEntry(f14,"75<E_{T}","l");
    //abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l8->Draw();
    
    c1->cd(9);
    deltaeta11->SetLineColor(kRed);
    deltaeta12->SetLineColor(kGreen+2);
    deltaeta13->SetLineColor(kBlue);
    deltaeta14->SetLineColor(kBlack);
    deltaeta11->GetXaxis()->SetTitle("#Delta #eta_{1}");
    deltaeta11->GetYaxis()->SetTitle("Normalized count");
    deltaeta11->DrawNormalized();
    deltaeta12->DrawNormalized("SAME");
    deltaeta13->DrawNormalized("SAME");
    deltaeta14->DrawNormalized("SAME");
    
    auto l9 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l9->SetBorderSize(0);
      //l1->SetTextFont(1);
      l9->SetFillColor(0);
      l9->SetFillStyle(0);
      l9->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l9->AddEntry(f11,"0<E_{T}<25","l");
    l9->AddEntry(f12,"25<E_{T}<50","l");
    l9->AddEntry(f13,"50<E_{T}<75","l");
    l9->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l9->Draw();
    
    c1->cd(10);
    d0significance1->SetLineColor(kRed);
    d0significance2->SetLineColor(kGreen+2);
    d0significance3->SetLineColor(kBlue);
    d0significance4->SetLineColor(kBlack);
    d0significance1->GetXaxis()->SetTitle("d_{0sig}");
    d0significance1->GetYaxis()->SetTitle("Normalized count");
    d0significance1->DrawNormalized();
    d0significance2->DrawNormalized("SAME");
    d0significance3->DrawNormalized("SAME");
    d0significance4->DrawNormalized("SAME");
    
    auto l10 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l10->SetBorderSize(0);
      //l1->SetTextFont(1);
      l10->SetFillColor(0);
      l10->SetFillStyle(0);
      l10->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l10->AddEntry(f11,"0<E_{T}<25","l");
    l10->AddEntry(f12,"25<E_{T}<50","l");
    l10->AddEntry(f13,"50<E_{T}<75","l");
    l10->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l10->Draw();
    
    c1->cd(11);
    rhad1->SetLineColor(kRed);
    rhad2->SetLineColor(kGreen+2);
    rhad3->SetLineColor(kBlue);
    rhad4->SetLineColor(kBlack);
    rhad1->GetXaxis()->SetTitle("R_{had}");
    rhad1->GetYaxis()->SetTitle("Normalized count");
    rhad1->DrawNormalized();
    rhad2->DrawNormalized("SAME");
    rhad3->DrawNormalized("SAME");
    rhad4->DrawNormalized("SAME");
    
    auto l11 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l11->SetBorderSize(0);
      //l1->SetTextFont(1);
      l11->SetFillColor(0);
      l11->SetFillStyle(0);
      l11->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l11->AddEntry(f11,"0<E_{T}<25","l");
    l11->AddEntry(f12,"25<E_{T}<50","l");
    l11->AddEntry(f13,"50<E_{T}<75","l");
    l11->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l11->Draw();
    
    c1->cd(12);
    DeltaPOverP1->SetLineColor(kRed);
    DeltaPOverP2->SetLineColor(kGreen+2);
    DeltaPOverP3->SetLineColor(kBlue);
    DeltaPOverP4->SetLineColor(kBlack);
    DeltaPOverP1->GetXaxis()->SetTitle("#Delta p/p");
    DeltaPOverP1->GetYaxis()->SetTitle("Normalized count");
    DeltaPOverP1->DrawNormalized();
    DeltaPOverP2->DrawNormalized("SAME");
    DeltaPOverP3->DrawNormalized("SAME");
    DeltaPOverP4->DrawNormalized("SAME");
    
    auto l12 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l12->SetBorderSize(0);
      //l1->SetTextFont(1);
      l12->SetFillColor(0);
      l12->SetFillStyle(0);
      l12->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l12->AddEntry(f11,"0<E_{T}<25","l");
    l12->AddEntry(f12,"25<E_{T}<50","l");
    l12->AddEntry(f13,"50<E_{T}<75","l");
    l12->AddEntry(f14,"75<E_{T}","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l12->Draw();
    

    
 /*      if (elCand2_eta>0 && elCand2_eta<1){
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
       
   }
    
    TCanvas* c2 = new TCanvas("c2", "My ROOT Plots", 1500, 500);
    c2->Divide(4,3);
    
    c2->cd(1);
    f11->SetLineColor(kRed);
    f12->SetLineColor(kGreen+2);
    f13->SetLineColor(kBlue);
    f14->SetLineColor(kBlack);
    f11->GetXaxis()->SetTitle("f_{1}");
    f11->GetYaxis()->SetTitle("Normalized count");
    f11->DrawNormalized();
    f12->DrawNormalized("SAME");
    f13->DrawNormalized("SAME");
    f14->DrawNormalized("SAME");
    
    
    auto l1 = new TLegend(0.1,0.7,0.48,0.9);
    
    l1->SetBorderSize(0);
      //l1->SetTextFont(1);
      l1->SetFillColor(0);
      l1->SetFillStyle(0);
      l1->SetLineColor(0);
        l1->AddEntry(f11,"0<|#eta|<1","l");
        l1->AddEntry(f12,"1<|#eta|<2","l");
        l1->AddEntry(f13,"2<|#eta|<3","l");
        l1->AddEntry(f14,"3<|#eta|","l");
    l1->Draw();
    
    c2->cd(2);
    f31->SetLineColor(kRed);
    f32->SetLineColor(kGreen+2);
    f33->SetLineColor(kBlue);
    f34->SetLineColor(kBlack);
    f31->GetXaxis()->SetTitle("f_{3}");
    f31->GetYaxis()->SetTitle("Normalized count");
    
    f31->DrawNormalized();
    f32->DrawNormalized("SAME");
    f33->DrawNormalized("SAME");
    f34->DrawNormalized("SAME");
    
    
    auto l2 = new TLegend(0.1,0.7,0.48,0.9);
    l2->SetBorderSize(0);
      //l1->SetTextFont(1);
      l2->SetFillColor(0);
      l2->SetFillStyle(0);
      l2->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l2->AddEntry(f11,"0<|#eta|<1","l");
     l2->AddEntry(f12,"1<|#eta|<2","l");
     l2->AddEntry(f13,"2<|#eta|<3","l");
     l2->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
       l2->Draw();
    
    
    c2->cd(3);
    weta21->SetLineColor(kRed);
    weta22->SetLineColor(kGreen+2);
    weta23->SetLineColor(kBlue);
    weta24->SetLineColor(kBlack);
    weta21->GetXaxis()->SetTitle("w_{#eta 2}");
    weta21->GetYaxis()->SetTitle("Normalized count");
    weta21->DrawNormalized();
    weta22->DrawNormalized("SAME");
    weta23->DrawNormalized("SAME");
    weta24->DrawNormalized("SAME");
    
    auto l3 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l3->SetBorderSize(0);
      //l1->SetTextFont(1);
      l3->SetFillColor(0);
      l3->SetFillStyle(0);
      l3->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l3->AddEntry(f11,"0<|#eta|<1","l");
     l3->AddEntry(f12,"1<|#eta|<2","l");
     l3->AddEntry(f13,"2<|#eta|<3","l");
     l3->AddEntry(f14,"3<|#eta|","l");
       l3->Draw();
    
    c2->cd(4);
    wstot1->SetLineColor(kRed);
    wstot2->SetLineColor(kGreen+2);
    wstot3->SetLineColor(kBlue);
    wstot4->SetLineColor(kBlack);
    wstot1->GetXaxis()->SetTitle("w_{#stot}");
    wstot1->GetYaxis()->SetTitle("Normalized count");
    wstot1->DrawNormalized();
    wstot2->DrawNormalized("SAME");
    wstot3->DrawNormalized("SAME");
    wstot4->DrawNormalized("SAME");
    
    auto l4 = new TLegend(0.1,0.7,0.48,0.9);
    l4->SetBorderSize(0);
      //l1->SetTextFont(1);
      l4->SetFillColor(0);
      l4->SetFillStyle(0);
      l4->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l4->AddEntry(f11,"0<|#eta|<1","l");
     l4->AddEntry(f12,"1<|#eta|<2","l");
     l4->AddEntry(f13,"2<|#eta|<3","l");
     l4->AddEntry(f14,"3<|#eta|","l");
    l4->Draw();
    
    c2->cd(5);
    reta1->SetLineColor(kRed);
    reta2->SetLineColor(kGreen+2);
    reta3->SetLineColor(kBlue);
    reta4->SetLineColor(kBlack);
    reta1->GetXaxis()->SetTitle("R_{#eta}");
    reta1->GetYaxis()->SetTitle("Normalized count");
    reta1->DrawNormalized();
    reta2->DrawNormalized("SAME");
    reta3->DrawNormalized("SAME");
    reta4->DrawNormalized("SAME");
    
    auto l5 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l5->SetBorderSize(0);
      //l1->SetTextFont(1);
      l5->SetFillColor(0);
      l5->SetFillStyle(0);
      l5->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l5->AddEntry(f11,"0<|#eta|<1","l");
     l5->AddEntry(f12,"1<|#eta|<2","l");
     l5->AddEntry(f13,"2<|#eta|<3","l");
     l5->AddEntry(f14,"3<|#eta|","l");
    l5->Draw();
    
    
    c2->cd(6);
    rphi1->SetLineColor(kRed);
    rphi2->SetLineColor(kGreen+2);
    rphi3->SetLineColor(kBlue);
    rphi4->SetLineColor(kBlack);
    rphi1->GetXaxis()->SetTitle("R_{#phi}");
    rphi1->GetYaxis()->SetTitle("Normalized count");
    rphi1->DrawNormalized();
    rphi2->DrawNormalized("SAME");
    rphi3->DrawNormalized("SAME");
    rphi4->DrawNormalized("SAME");
    
    auto l6 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l6->SetBorderSize(0);
      //l1->SetTextFont(1);
      l6->SetFillColor(0);
      l6->SetFillStyle(0);
      l6->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l6->AddEntry(f11,"0<|#eta|<1","l");
     l6->AddEntry(f12,"1<|#eta|<2","l");
     l6->AddEntry(f13,"2<|#eta|<3","l");
     l6->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l6->Draw();
    
    c2->cd(7);
    eratio1->SetLineColor(kRed);
    eratio2->SetLineColor(kGreen+2);
    eratio3->SetLineColor(kBlue);
    eratio4->SetLineColor(kBlack);
    eratio1->GetXaxis()->SetTitle("e_{ratio}");
    eratio1->GetYaxis()->SetTitle("Normalized count");
    eratio1->DrawNormalized();
    eratio2->DrawNormalized("SAME");
    eratio3->DrawNormalized("SAME");
    eratio4->DrawNormalized("SAME");
    
    auto l7 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l7->SetBorderSize(0);
      //l1->SetTextFont(1);
      l7->SetFillColor(0);
      l7->SetFillStyle(0);
      l7->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l7->AddEntry(f11,"0<|#eta|<1","l");
     l7->AddEntry(f12,"1<|#eta|<2","l");
     l7->AddEntry(f13,"2<|#eta|<3","l");
     l7->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l7->Draw();
    
    c2->cd(8);
    d01->SetLineColor(kRed);
    d02->SetLineColor(kGreen+2);
    d03->SetLineColor(kBlue);
    d04->SetLineColor(kBlack);
    d01->GetXaxis()->SetTitle("d_{0}");
    d01->GetYaxis()->SetTitle("Normalized count");
    d01->DrawNormalized();
    d02->DrawNormalized("SAME");
    d03->DrawNormalized("SAME");
    d04->DrawNormalized("SAME");
    
    auto l8 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l8->SetBorderSize(0);
      //l1->SetTextFont(1);
      l8->SetFillColor(0);
      l8->SetFillStyle(0);
      l8->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l8->AddEntry(f11,"0<|#eta|<1","l");
     l8->AddEntry(f12,"1<|#eta|<2","l");
     l8->AddEntry(f13,"2<|#eta|<3","l");
     l8->AddEntry(f14,"3<|#eta|","l");
    //abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l8->Draw();
    
    c2->cd(9);
    deltaeta11->SetLineColor(kRed);
    deltaeta12->SetLineColor(kGreen+2);
    deltaeta13->SetLineColor(kBlue);
    deltaeta14->SetLineColor(kBlack);
    deltaeta11->GetXaxis()->SetTitle("#Delta #eta_{1}");
    deltaeta11->GetYaxis()->SetTitle("Normalized count");
    deltaeta11->DrawNormalized();
    deltaeta12->DrawNormalized("SAME");
    deltaeta13->DrawNormalized("SAME");
    deltaeta14->DrawNormalized("SAME");
    
    auto l9 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l9->SetBorderSize(0);
      //l1->SetTextFont(1);
      l9->SetFillColor(0);
      l9->SetFillStyle(0);
      l9->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l9->AddEntry(f11,"0<|#eta|<1","l");
     l9->AddEntry(f12,"1<|#eta|<2","l");
     l9->AddEntry(f13,"2<|#eta|<3","l");
     l9->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l9->Draw();
    
    c2->cd(10);
    d0significance1->SetLineColor(kRed);
    d0significance2->SetLineColor(kGreen+2);
    d0significance3->SetLineColor(kBlue);
    d0significance4->SetLineColor(kBlack);
    d0significance1->GetXaxis()->SetTitle("d_{0sig}");
    d0significance1->GetYaxis()->SetTitle("Normalized count");
    d0significance1->DrawNormalized();
    d0significance2->DrawNormalized("SAME");
    d0significance3->DrawNormalized("SAME");
    d0significance4->DrawNormalized("SAME");
    
    auto l10 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l10->SetBorderSize(0);
      //l1->SetTextFont(1);
      l10->SetFillColor(0);
      l10->SetFillStyle(0);
      l10->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l10->AddEntry(f11,"0<|#eta|<1","l");
     l10->AddEntry(f12,"1<|#eta|<2","l");
     l10->AddEntry(f13,"2<|#eta|<3","l");
     l10->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l10->Draw();
    
    c2->cd(11);
    rhad1->SetLineColor(kRed);
    rhad2->SetLineColor(kGreen+2);
    rhad3->SetLineColor(kBlue);
    rhad4->SetLineColor(kBlack);
    rhad1->GetXaxis()->SetTitle("R_{had}");
    rhad1->GetYaxis()->SetTitle("Normalized count");
    rhad1->DrawNormalized();
    rhad2->DrawNormalized("SAME");
    rhad3->DrawNormalized("SAME");
    rhad4->DrawNormalized("SAME");
    
    auto l11 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l11->SetBorderSize(0);
      //l1->SetTextFont(1);
      l11->SetFillColor(0);
      l11->SetFillStyle(0);
      l11->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l11->AddEntry(f11,"0<|#eta|<1","l");
     l11->AddEntry(f12,"1<|#eta|<2","l");
     l11->AddEntry(f13,"2<|#eta|<3","l");
     l11->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l11->Draw();
    
    c2->cd(12);
    DeltaPOverP1->SetLineColor(kRed);
    DeltaPOverP2->SetLineColor(kGreen+2);
    DeltaPOverP3->SetLineColor(kBlue);
    DeltaPOverP4->SetLineColor(kBlack);
    DeltaPOverP1->GetXaxis()->SetTitle("#Delta p/p");
    DeltaPOverP1->GetYaxis()->SetTitle("Normalized count");
    DeltaPOverP1->DrawNormalized();
    DeltaPOverP2->DrawNormalized("SAME");
    DeltaPOverP3->DrawNormalized("SAME");
    DeltaPOverP4->DrawNormalized("SAME");
    
    auto l12 = new TLegend(0.1,0.7,0.48,0.9);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l12->SetBorderSize(0);
      //l1->SetTextFont(1);
      l12->SetFillColor(0);
      l12->SetFillStyle(0);
      l12->SetLineColor(0);
       //legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
    l12->AddEntry(f11,"0<|#eta|<1","l");
     l12->AddEntry(f12,"1<|#eta|<2","l");
     l12->AddEntry(f13,"2<|#eta|<3","l");
     l12->AddEntry(f14,"3<|#eta|","l");
       //legend->AddEntry("f1","Function abs(#frac{sin(x)}{x})","l");
       //legend->AddEntry("gr","Graph with error bars","lep");
    l12->Draw();
    */

  
    
}


