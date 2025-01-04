//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jul 11 12:40:16 2023 by ROOT version 6.28/04
// from TTree ZeeCandidate/ZeeCandidate
// found on file: Zee.root
//////////////////////////////////////////////////////////

#ifndef myclass_h
#define myclass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class myclass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         elCand2_d0;
   Float_t         elCand2_deltaeta1;
   Float_t         elCand2_d0significance;
   Float_t         elCand2_DeltaPOverP;
   Float_t         elCand2_eProbabilityHT;
   Float_t         elCand2_deltaphiRescaled;
   Float_t         MCPileupWeight;
   Float_t         MCEventWeight;
   Float_t         elCand2_eta;
   Float_t         elCand2_phi;
   Float_t         elCand2_et;
   Float_t         Zcand_M;
   Int_t           isMultiElectronTriggerMatched;
   Int_t           elCand2_VeryLooseLLH_d0z0_DataDriven_Rel21_Smooth_vTest;
   Float_t         elCand2_f1;
   Float_t         elCand2_f3;
   Float_t         elCand2_weta2;
   Float_t         elCand2_wstot;
   Float_t         elCand2_reta;
   Float_t         elCand2_rhad;
   Float_t         elCand2_rphi;
   Float_t         elCand2_eratio;
   Int_t           Nvtx;
   Float_t         actualIntPerXing;
   Float_t         averageIntPerXing;

   // List of branches
   TBranch        *b_elCand2_d0;   //!
   TBranch        *b_elCand2_deltaeta1;   //!
   TBranch        *b_elCand2_d0significance;   //!
   TBranch        *b_elCand2_DeltaPOverP;   //!
   TBranch        *b_elCand2_eProbabilityHT;   //!
   TBranch        *b_elCand2_deltaphiRescaled;   //!
   TBranch        *b_MCPileupWeight;   //!
   TBranch        *b_MCEventWeight;   //!
   TBranch        *b_elCand2_eta;   //!
   TBranch        *b_elCand2_phi;   //!
   TBranch        *b_elCand2_et;   //!
   TBranch        *b_Zcand_M;   //!
   TBranch        *b_isMultiElectronTriggerMatched;   //!
   TBranch        *b_elCand2_VeryLooseLLH_d0z0_DataDriven_Rel21_Smooth_vTest;   //!
   TBranch        *b_elCand2_f1;   //!
   TBranch        *b_elCand2_f3;   //!
   TBranch        *b_elCand2_weta2;   //!
   TBranch        *b_elCand2_wstot;   //!
   TBranch        *b_elCand2_reta;   //!
   TBranch        *b_elCand2_rhad;   //!
   TBranch        *b_elCand2_rphi;   //!
   TBranch        *b_elCand2_eratio;   //!
   TBranch        *b_Nvtx;   //!
   TBranch        *b_actualIntPerXing;   //!
   TBranch        *b_averageIntPerXing;   //!

   myclass(TTree *tree=0);
   virtual ~myclass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myclass_cxx
myclass::myclass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Zee.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Zee.root");
      }
      f->GetObject("ZeeCandidate",tree);

   }
   Init(tree);
}

myclass::~myclass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myclass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myclass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myclass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("elCand2_d0", &elCand2_d0, &b_elCand2_d0);
   fChain->SetBranchAddress("elCand2_deltaeta1", &elCand2_deltaeta1, &b_elCand2_deltaeta1);
   fChain->SetBranchAddress("elCand2_d0significance", &elCand2_d0significance, &b_elCand2_d0significance);
   fChain->SetBranchAddress("elCand2_DeltaPOverP", &elCand2_DeltaPOverP, &b_elCand2_DeltaPOverP);
   fChain->SetBranchAddress("elCand2_eProbabilityHT", &elCand2_eProbabilityHT, &b_elCand2_eProbabilityHT);
   fChain->SetBranchAddress("elCand2_deltaphiRescaled", &elCand2_deltaphiRescaled, &b_elCand2_deltaphiRescaled);
   fChain->SetBranchAddress("MCPileupWeight", &MCPileupWeight, &b_MCPileupWeight);
   fChain->SetBranchAddress("MCEventWeight", &MCEventWeight, &b_MCEventWeight);
   fChain->SetBranchAddress("elCand2_eta", &elCand2_eta, &b_elCand2_eta);
   fChain->SetBranchAddress("elCand2_phi", &elCand2_phi, &b_elCand2_phi);
   fChain->SetBranchAddress("elCand2_et", &elCand2_et, &b_elCand2_et);
   fChain->SetBranchAddress("Zcand_M", &Zcand_M, &b_Zcand_M);
   fChain->SetBranchAddress("isMultiElectronTriggerMatched", &isMultiElectronTriggerMatched, &b_isMultiElectronTriggerMatched);
   fChain->SetBranchAddress("elCand2_VeryLooseLLH_d0z0_DataDriven_Rel21_Smooth_vTest", &elCand2_VeryLooseLLH_d0z0_DataDriven_Rel21_Smooth_vTest, &b_elCand2_VeryLooseLLH_d0z0_DataDriven_Rel21_Smooth_vTest);
   fChain->SetBranchAddress("elCand2_f1", &elCand2_f1, &b_elCand2_f1);
   fChain->SetBranchAddress("elCand2_f3", &elCand2_f3, &b_elCand2_f3);
   fChain->SetBranchAddress("elCand2_weta2", &elCand2_weta2, &b_elCand2_weta2);
   fChain->SetBranchAddress("elCand2_wstot", &elCand2_wstot, &b_elCand2_wstot);
   fChain->SetBranchAddress("elCand2_reta", &elCand2_reta, &b_elCand2_reta);
   fChain->SetBranchAddress("elCand2_rhad", &elCand2_rhad, &b_elCand2_rhad);
   fChain->SetBranchAddress("elCand2_rphi", &elCand2_rphi, &b_elCand2_rphi);
   fChain->SetBranchAddress("elCand2_eratio", &elCand2_eratio, &b_elCand2_eratio);
   fChain->SetBranchAddress("Nvtx", &Nvtx, &b_Nvtx);
   fChain->SetBranchAddress("actualIntPerXing", &actualIntPerXing, &b_actualIntPerXing);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   Notify();
}

Bool_t myclass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myclass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myclass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myclass_cxx
