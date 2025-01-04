//Example of reading data file and plotting
{
    g = new TGraph("data.txt");
    g->SetMarkerStyle(21);
    g->SetLineColor(kRed);
    g->SetTitle("DataPlot with TGRAPH; GW; ms");
    g->Draw("ALP");
}

