#ifdef __CLING__
#pragma cling optimize(0)
#endif
void c1()
{
//=========Macro generated from canvas: c1/c1
//=========  (Tue Jul 11 16:13:55 2023) by ROOT version 6.28/04
   TCanvas *c1 = new TCanvas("c1", "c1",551,69,700,500);
   c1->Range(-1.248658,0.4526359,1.248658,3.922001);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTopMargin(0.1263158);
   c1->SetBottomMargin(0.07368421);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TF1 *f1 = new TF1("f","x^2-sin(x)*exp(-x/2)+1",-1,1, TF1::EAddToList::kDefault);
   f1->SetFillColor(19);
   f1->SetFillStyle(0);
   f1->SetLineColor(2);
   f1->SetLineWidth(2);
   f1->GetXaxis()->SetLabelFont(42);
   f1->GetXaxis()->SetTitleOffset(1);
   f1->GetXaxis()->SetTitleFont(42);
   f1->GetYaxis()->SetLabelFont(42);
   f1->GetYaxis()->SetTitleFont(42);
   f1->Draw("");
   
   TPaveText *pt = new TPaveText(0.3123496,0.9368947,0.6876504,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *pt_LaTex = pt->AddText("x^2-sin(x)*exp(-x/2)+1");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
