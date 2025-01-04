// Our first ROOT macro

/*
 jdnednen
 jdenj
 xknekx
 */
{
    c1 = new TCanvas("c1", "My ROOT Plots", 1500, 500);
    c1->Divide(3,1);
    
    c1->cd(1);
    f1 = new TF1("f1", "sin(x)",-5,5);
    f1->SetLineColor(kBlue+2);
    f1->SetTitle("My Function; X (fathoms); Y(miles)");
    f1->Draw();
    
    c1->cd(2);
    f2 = new TF1("f2", "cos(x)",-5,5);
    f2->SetLineColor(kRed);
    f2->SetTitle("My Function; X (fathoms); Y(miles)");
    f2->Draw(); //"SAME"
    
    c1->cd(3);
    f3 = new TF2("f3", "10*cos(x)*sin(y)",-3,3,0,10);
    f3->SetTitle("3D plot");
    f3->Draw("surf2");
    
}

